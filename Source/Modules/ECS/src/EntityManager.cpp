/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#define SHOW_STAT

#include "EntityManager.h"
#include "SingletonManager.h"
#include "Entity.h"

#include "EntityManagerMaster.h"

using namespace nsECSFramework;

namespace dll = boost::dll;
namespace bexp = boost::dll::experimental;

// const 
const std::string TEMPLATE_BEGIN = "<";

const char LEFT_CORNER_LITERAL = '<';
const char RIGHT_CORNER_LITERAL = '>';
const char COMMA_LITERAL = ',';
const char SPACE_LITERAL = ' ';

const std::string TYPE_INDEX_METHOD_NAME = "TypeIndex";

const std::string GET_BY_UNIQUE_METHOD_NAME = "GetByUnique";
const std::string GET_BY_HAS_METHOD_NAME = "GetByHas";
const std::string GET_BY_VALUE_METHOD_NAME = "GetByValue";


//----------------------------------------------------------------------------------------------------
TEntityManager::TEntityManager(const std::string& name, int entityCount)
{
    mName = name;

    SingletonManager()->Get<TEntityManagerMaster>()->AddEntityManager(this);

    mEntities.Init(entityCount);
    mEntities.onDestroy = [&](TEntityID eid, TEntity* pEntity)
    {
        auto components = *(pEntity->GetComponentIndexInUse());

        for (auto& index : components) {
            auto pC = (IComponent*)pEntity->GetComponent(index);
            NotifyOnRemoveComponent(index, eid, pC);
        }

        for (auto& index : components) {
            RemoveComponent(eid, pEntity, index, false);
        }

        mEntityMemoryPool->Push(pEntity);
    };

    // MemoryPools must be singleton, because it uses shared pointers 
    mEntityMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntity>>();
    mComplexTypeMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TComplexType>>();
    mLinkToListMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TLinkToList<TEntityID>>>();
    mEntityListMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntityList>>();
    mUniqueMapMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TUniqueMap>>();
    mComplexTypePtrListPtrMapMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TComplexTypePtrListPtrMap>>();

    mTypeIndex = SingletonManager()->Get<TRunTimeTypeIndex<>>();
}
//----------------------------------------------------------------------------------------------------
std::string TEntityManager::GetName() const
{
    return mName;
}
//----------------------------------------------------------------------------------------------------
TEntityManager::~TEntityManager()
{
    Destroy(mAddCBVector);
    Destroy(mUpdateCBVector);
    Destroy(mRemoveCBVector);

    DestroyEventCollector(mAddCollector);
    DestroyEventCollector(mUpdateCollector);

    Clear();

    SingletonManager()->Get<TEntityManagerMaster>()->RemoveEntityManager(this);
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::Fill(const std::string& methodName, std::string& demangled, TStrSet& strSet)
{
    auto beginFound = demangled.find(methodName);

    auto pData = demangled.data();
    auto argsBeginIndex = demangled.find(TEMPLATE_BEGIN, beginFound);
    auto beginTypesIndex = argsBeginIndex + TEMPLATE_BEGIN.size();
    auto offset = beginTypesIndex;

    // функция для добавления
    auto addFunc = [&](int index)
    {
        // конец template
        auto type = demangled.substr(offset, index - offset);
        strSet.insert(type);
        offset = index;
    };

    auto cornerBalance = 0;
    for (int i = argsBeginIndex; i < demangled.size(); i++) {
        auto symbol = pData[i];
        switch (symbol) {
        case LEFT_CORNER_LITERAL:
            cornerBalance++;
            break;
        case RIGHT_CORNER_LITERAL:
            cornerBalance--;
            break;
        case COMMA_LITERAL:
            if (cornerBalance == 1) {
                addFunc(i);
                offset += sizeof(COMMA_LITERAL);
                if (pData[i + 1] == SPACE_LITERAL)
                    offset += sizeof(SPACE_LITERAL);
            }
            break;
        }

        if (cornerBalance == 0) {
            // конец template
            addFunc(i);
            break;
        }
    }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::FindTypesOfMethod(const std::string& methodName, TStrSetList& resultList)
{
    auto symbolStorage = mLib.symbol_storage().get_storage();
    TStrList classList;
    for (auto s : symbolStorage) {
        auto demangled = s.demangled;
        auto pData = demangled.data();

        auto beginFound = demangled.find(methodName);
        if (beginFound == std::string::npos) {
            continue;
        }

        TStrSet strSet;
        Fill(methodName, demangled, strSet);

        if (strSet.size() > 0) {
            resultList.push_back(strSet);
        }
    }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::FindTypeIndex(const std::string& methodName, TStrSetStrMap& resultMap)
{
    auto symbolStorage = mLib.symbol_storage().get_storage();
    TStrList classList;
    for (auto s : symbolStorage) {
        auto demangled = s.demangled;

        auto beginFound = demangled.find(methodName);
        if (beginFound == std::string::npos) {
            continue;
        }

        TStrSet strSet;
        Fill(methodName, demangled, strSet);

        if (strSet.size() > 0) {
            resultMap.insert({ strSet, demangled });
        }
    }
}
//----------------------------------------------------------------------------------------------------
// рефлексия (boost::dll), поиск применения функций фильтрации для подготовки к накоплению карт кэширования использования компонентов
// reflection magic
void TEntityManager::Setup(const std::list<std::string>& pathList)
{
    for (auto& path : pathList) {
        Setup(path);
    }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::Setup(std::string libName)
{
    mLib.load(libName);

    // для разделения пространства имен классов, на случай когда более чем один EntityManager
    auto entMngClassName = typeid(*this).name();

    mUniqueSet.clear();
    mHasComponentList.clear();
    mValueComponentList.clear();
    mTypeIndexNameFuncMap.clear();

    FindTypesOfMethod(GET_BY_UNIQUE_METHOD_NAME, mUniqueSet);
    FindTypesOfMethod(GET_BY_HAS_METHOD_NAME, mHasComponentList);
    FindTypesOfMethod(GET_BY_VALUE_METHOD_NAME, mValueComponentList);

    FindTypeIndex(TYPE_INDEX_METHOD_NAME, mTypeIndexNameFuncMap);

    auto showWarning = mUniqueSet.size() == 0 && mHasComponentList.size() == 0 && mValueComponentList.size() == 0 && mTypeIndexNameFuncMap.size() == 0;
    if (showWarning) {
        printf("Warning! TEntityManager Setup not found reflection info.\n");
    }
#ifdef SHOW_STAT
    printf("uniqueCnt = %u, hasCnt = %u, valueCnt = %u, typeIndexCount = %u\n",
        mUniqueSet.size(), mHasComponentList.size(), mValueComponentList.size(), mTypeIndexNameFuncMap.size());
#endif

    std::string excFunc;

    using TypeIndexFunc = unsigned int(TEntityManager::*)(void);
    for (auto strSetFunc : mTypeIndexNameFuncMap) {
        try {
            auto& demangled = strSetFunc.second;

            auto beginFound = demangled.find(TYPE_INDEX_METHOD_NAME);
            if (beginFound == std::string::npos) {
                continue;
            }

            auto endFound = demangled.find("(");
            if (endFound == std::string::npos) {
                continue;
            }

            auto funcName = demangled.substr(beginFound, endFound - beginFound);

            auto cornerCount = std::count(funcName.begin(), funcName.end(), '<');
            if (cornerCount != 1) {
                continue;
            }
            excFunc = funcName;

            auto func = bexp::import_mangled<nsECSFramework::TEntityManager, unsigned int(void)>(mLib, funcName.c_str());
            auto typeIndexFunc = func(this);

            //printf( "%s => %u\n", funcName.data(), typeIndexFunc );

            mComponentsTypeIndexMap.insert({ strSetFunc.first, typeIndexFunc });
        }
        catch (std::exception e) {
#ifdef _DEBUG
            printf("func=%s, %s\n", excFunc.c_str(), e.what());
#endif
        }
    }

    for (auto& strSet : mUniqueSet) {
        auto fit = mComponentsTypeIndexMap.find(strSet);
        if (fit == mComponentsTypeIndexMap.end()) {
            BL_FIX_BUG();
            continue;
        }
        auto index = fit->second;
        mUniqueMapVec[index] = mUniqueMapMemoryPool->Pop();
    }

    // все типы изо всех коллекций
    TStrSet hasSet;
    TStrSet valueSet;

    for (auto& strSet : mHasComponentList) {
        auto fit = mComponentsTypeIndexMap.find(strSet);
        if (fit == mComponentsTypeIndexMap.end()) {
            BL_FIX_BUG();
            continue;
        }
        auto index = fit->second;
        mHasCollectionVec[index] = mEntityListMemoryPool->Pop();

        TShortList typeList;
        for (auto type : strSet) {
            hasSet.insert(type);

            TStrSet forSearch;
            forSearch.insert(type);
            auto typeIndexIt = mComponentsTypeIndexMap.find(forSearch);
            typeList.push_back(typeIndexIt->second);
        }
        mHasCollectionWithTypes[index] = typeList;
    }

    for (auto& strSet : mValueComponentList) {
        auto fit = mComponentsTypeIndexMap.find(strSet);
        if (fit == mComponentsTypeIndexMap.end()) {
            BL_FIX_BUG();
            continue;
        }
        auto index = fit->second;
        mValueCollectionVec[index] = mComplexTypePtrListPtrMapMemoryPool->Pop();

        TShortList typeList;
        for (auto type : strSet) {
            valueSet.insert(type);

            TStrSet forSearch;
            forSearch.insert(type);
            auto typeIndexIt = mComponentsTypeIndexMap.find(forSearch);
            typeList.push_back(typeIndexIt->second);
        }
        mValueCollectionWithTypes[index] = typeList;
    }

    // выяснить в каких коллекциях учавствует тип
    for (auto type : hasSet) {
        TShortList typeList;
        for (auto collectionType : mHasComponentList) {
            if (collectionType.find(type) == collectionType.end())
                continue;
            auto collectionIndex = mComponentsTypeIndexMap.find(collectionType);
            typeList.push_back(collectionIndex->second);
        }

        BL_ASSERT(typeList.size() > 0);

        TStrSet forSearchIndex;
        forSearchIndex.insert(type);
        auto typeIndexIt = mComponentsTypeIndexMap.find(forSearchIndex);

        mHasTypeInCollection[typeIndexIt->second] = typeList;
    }

    for (auto type : valueSet) {
        TShortList typeList;
        for (auto collectionType : mValueComponentList) {
            if (collectionType.find(type) == collectionType.end()) {
                continue;
            }
            auto collectionIndex = mComponentsTypeIndexMap.find(collectionType);
            typeList.push_back(collectionIndex->second);
        }

        BL_ASSERT(typeList.size() > 0);

        TStrSet forSearchIndex;
        forSearchIndex.insert(type);
        auto typeIndexIt = mComponentsTypeIndexMap.find(forSearchIndex);

        mValueTypeInCollection[typeIndexIt->second] = typeList;
    }
}
//-------------------------------------------------------------------------------------------------------
TEntityID TEntityManager::CreateEntity()
{
    auto newEntity = mEntityMemoryPool->Pop();
    return mEntities.Create(newEntity);
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::DestroyEntity(TEntityID eid)
{
    mEntities.Destroy(eid);
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::GetAllEntities(std::list<TEntityID>& entities) const
{
    entities.clear();
    auto& entitiesContainer = mEntities.GetVector();

    TEntityID eid = 0;
    for (auto& pEntity : entitiesContainer) {
        if (pEntity != nullptr) {
            entities.push_back(eid);
        }

        eid++;
    }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::Clear()
{
    mEntities.Clear();
}
//----------------------------------------------------------------------------------------------------
TEntity* TEntityManager::GetEntity(TEntityID eid) const
{
    return mEntities.GetElement(eid);
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::RemoveComponent(TEntityID eid, TEntity* pEntity, int index, bool isNotify)
{
    auto pC = (IComponent*)pEntity->GetComponent(index);

    // Notify before the removing
    if (isNotify) {
        NotifyOnRemoveComponent(index, eid, pC);
    }

    TryRemoveFromUnique(eid, pC, index);
    TryRemoveFromHas(eid, index, pEntity);
    TryRemoveFromValue(eid, index, pEntity);

    pEntity->RemoveComponent(index);
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryAddInUnique(TEntityID eid, IComponent* pC, int index)
{
    auto pMap = mUniqueMapVec[index];
    if (pMap == nullptr) {
        return;
    }
#ifdef _DEBUG
    if (pMap->end() != pMap->find(pC)) {
        BL_FIX_BUG();
        return;
    }
#endif
    pMap->insert({ pC, eid });
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryAddInHas(TEntityID eid, int index, TEntity* pEntity)
{
    auto& collectionList = mHasTypeInCollection[index];
    for (auto& collectionIndex : collectionList) {
        auto hasList = mHasCollectionVec[collectionIndex];
        if (hasList == nullptr) {
            BL_FIX_BUG();
            continue;
        }

        auto hasAllTypes = true;
        auto& typesInCollection = mHasCollectionWithTypes[collectionIndex];
        for (auto& typeInCollection : typesInCollection) {
            if (pEntity->HasComponent(typeInCollection) == false) {
                hasAllTypes = false;
                break;
            }
        }

        if (hasAllTypes == false) {
            continue;
        }
        hasList->push_back(eid);
        auto backIt = hasList->end();
        backIt--;

        auto pLTL = mLinkToListMemoryPool->Pop();
        pLTL->Set(*hasList, backIt);
        pEntity->AddHasCollectionInfo(pLTL, collectionIndex);
    }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryAddInValue(TEntityID eid, int index, TEntity* pEntity)
{
    auto& collectionList = mValueTypeInCollection[index];
    for (auto& collectionIndex : collectionList) {
        auto ctListMap = mValueCollectionVec[collectionIndex];
        if (ctListMap == nullptr) {
            BL_FIX_BUG();
            continue;
        }

        auto hasAllTypes = true;
        auto pComplexType = mComplexTypeMemoryPool->Pop();

        auto& typesInCollection = mValueCollectionWithTypes[collectionIndex];
        for (auto& typeInCollection : typesInCollection) {
            auto pC = pEntity->GetComponent(typeInCollection);
            if (pC == nullptr) {
                hasAllTypes = false;
                break;
            }
            pComplexType->parts[typeInCollection] = pC;
            pComplexType->mComponentTypeIdentifierList.push_back(typeInCollection);
        }

        if (hasAllTypes == false) {
            pComplexType->Done();
            mComplexTypeMemoryPool->Push(pComplexType);
            continue;
        }

        TEntityList* pList = nullptr;
        auto fit = ctListMap->find(pComplexType);
        if (fit == ctListMap->end()) {
            pList = mEntityListMemoryPool->Pop();
            pList->push_back(eid);// original
            ctListMap->insert({ pComplexType, pList });
        } else {
            pComplexType->Done();
            mComplexTypeMemoryPool->Push(pComplexType);

            pList = fit->second;
            pList->push_back(eid);
        }

        auto backIt = pList->end();
        backIt--;

        auto pLTL = mLinkToListMemoryPool->Pop();
        pLTL->Set(*pList, backIt);
        pEntity->AddValueCollectionInfo(pLTL, collectionIndex);
    }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryRemoveFromUnique(TEntityID eid, IComponent* pC, int index)
{
    auto pMap = mUniqueMapVec[index];
    if (pMap == nullptr) {
        return;
    }
#ifdef _DEBUG
    if (pMap->end() == pMap->find(pC)) {
        BL_FIX_BUG();
        return;
    }
#endif
    pMap->erase(pC);
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryRemoveFromHas(TEntityID eid, int index, TEntity* pEntity)
{
    auto& collectionList = mHasTypeInCollection[index];
    for (auto& collectionIndex : collectionList) {
        auto& hasList = mHasCollectionVec[collectionIndex];
        if (hasList == nullptr) {
            BL_FIX_BUG();
            continue;
        }

        auto pLTL = pEntity->RemoveHasCollectionInfo(collectionIndex);
        if (pLTL == nullptr) {
            continue;
        }
        pLTL->Erase();
        mLinkToListMemoryPool->Push(pLTL);
    }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryRemoveFromValue(TEntityID eid, int index, TEntity* pEntity)
{
    auto& collectionList = mValueTypeInCollection[index];
    for (auto& collectionIndex : collectionList) {
        auto pLTL = pEntity->RemoveValueCollectionInfo(collectionIndex);
        if (pLTL == nullptr) {
            continue;
        }
        auto ctListMap = mValueCollectionVec[collectionIndex];
        if (ctListMap == nullptr) {
            BL_FIX_BUG();
            continue;
        }
        // найти удаляется ли оригинал (front()) из листа, если оригинал, то занести следующий из списка
        auto pList = pLTL->GetList();
        auto isFrontEntity = (pList->front() == eid);
        pLTL->Erase();
        mLinkToListMemoryPool->Push(pLTL);

        if (isFrontEntity == false) {
            continue;
        }
        auto& typesInCollection = mValueCollectionWithTypes[collectionIndex];
        auto pComplexType = mComplexTypeMemoryPool->Pop();// сформировать для поиска в map
        for (auto& typeInCollection : typesInCollection) {
            auto pC = pEntity->GetComponent(typeInCollection);
            if (pC == nullptr) {
                BL_FIX_BUG();
                break;
            }
            pComplexType->parts[typeInCollection] = pC;
            pComplexType->mComponentTypeIdentifierList.push_back(typeInCollection);
        }
        auto fit = ctListMap->find(pComplexType);
        if (fit == ctListMap->end()) {
            BL_FIX_BUG();
            continue;
        }
        auto pOriginalComplexType = fit->first;
        pComplexType->Done();
        mComplexTypeMemoryPool->Push(pComplexType);
        pOriginalComplexType->Done();
        ctListMap->erase(fit);
        if (pList->size() == 0) { // удаляется оригинал
            mEntityListMemoryPool->Push(pList);
            mComplexTypeMemoryPool->Push(pOriginalComplexType);
            continue;
        }

        // pList->size() > 0
        auto nextEid = pList->front();
        auto pNextEntity = GetEntity(nextEid);

        for (auto& typeInCollection : typesInCollection) {
            auto pC = pNextEntity->GetComponent(typeInCollection);
            if (pC == nullptr) {
                BL_FIX_BUG();
                break;
            }
            pOriginalComplexType->parts[typeInCollection] = pC;
            pOriginalComplexType->mComponentTypeIdentifierList.push_back(typeInCollection);
        }
        ctListMap->insert({ pOriginalComplexType, pList });
    }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::GetComponentList(TEntityID eid, std::list<TypeIndexType>& typeIdentifierList)
{
    typeIdentifierList.clear();

    auto pEntity = GetEntity(eid);
    if (pEntity == nullptr) {
        return;
    }

    auto pComponentList = pEntity->GetComponentIndexInUse();
    typeIdentifierList = *pComponentList;
}
//---------------------------------------------------------------------------------------
void TEntityManager::Destroy(TCBVector& cbVector)
{
    auto size = cbVector.Size();
    for (int i = 0; i < size; i++) {
        delete cbVector[i];
        cbVector[i] = nullptr;
    }
}
//---------------------------------------------------------------------------------------
void TEntityManager::DestroyEventCollector(TComponentEventsVector& eventColector)
{
    auto size = eventColector.Size();
    for (int i = 0; i < size; i++) {
        delete eventColector[i];
        eventColector[i] = nullptr;
    }
}
//---------------------------------------------------------------------------------------
void TEntityManager::NotifyOnAddComponent(int index, TEntityID entity, const IComponent* pC)
{
    NotifyComponent(index, entity, pC, mAddCBVector);
}
//---------------------------------------------------------------------------------------
void TEntityManager::NotifyOnUpdateComponent(int index, TEntityID entity, const IComponent* pC)
{
    NotifyComponent(index, entity, pC, mUpdateCBVector);
}
//---------------------------------------------------------------------------------------
void TEntityManager::NotifyOnRemoveComponent(int index, TEntityID entity, const IComponent* pC)
{
    NotifyComponent(index, entity, pC, mRemoveCBVector);
}
//---------------------------------------------------------------------------------------
void TEntityManager::NotifyComponent(int index, TEntityID entity, const IComponent* pC, TCBVector& cbVector)
{
    auto pCB = &cbVector[index];
    if (pCB[0] == nullptr) {
        return;
    }
    pCB[0]->Notify(entity, pC);
}
//---------------------------------------------------------------------------------------
