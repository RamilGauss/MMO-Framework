/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

//#define SHOW_STAT

#include "EntityManager.h"
#include "SingletonManager.h"
#include "Entity.h"

using namespace nsECSFramework;

namespace dll = boost::dll;
namespace bexp = boost::dll::experimental;

// const 
const std::string templateBegin = "<";

const char leftCornerLiteral = '<';
const char rightCornerLiteral = '>';
const char commaLiteral = ',';
const char spaceLiteral = ' ';

const std::string typeIndexMethodName = "TypeIndex";

const std::string getByHasMethodName = "GetByHas";

//----------------------------------------------------------------------------------------------------
TEntityManager::TEntityManager(int entityCount)
{
    mEntities.mVec.resize(entityCount);
    mEntityMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntity>>();
    mComplexTypeMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TComplexType>>();
    mLinkToListMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TLinkToList<TEntityID>>>();
    mEntityListMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntityList>>();
    mUniqueMapMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TUniqueMap>>();
    mComplexTypePtrListPtrMapMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TComplexTypePtrListPtrMap>>();

    mTypeIndex = SingletonManager()->Get<TRunTimeTypeIndex<TEntityManager>>();
}
//----------------------------------------------------------------------------------------------------
TEntityManager::~TEntityManager()
{

}
//----------------------------------------------------------------------------------------------------
void TEntityManager::Fill(const std::string& methodName, std::string& demangled, TStrSet& strSet)
{
    auto beginFound = demangled.find(methodName);

    auto pData = demangled.data();
    auto argsBeginIndex = demangled.find(templateBegin, beginFound);
    auto beginTypesIndex = argsBeginIndex + templateBegin.size();
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
            case leftCornerLiteral:
                cornerBalance++;
                break;
            case rightCornerLiteral:
                cornerBalance--;
                break;
            case commaLiteral:
                if (cornerBalance == 1) {
                    addFunc(i);
                    offset += sizeof(commaLiteral);
                    if (pData[i + 1] == spaceLiteral)
                        offset += sizeof(spaceLiteral);
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
        if (beginFound == std::string::npos)
            continue;

        TStrSet strSet;
        Fill(methodName, demangled, strSet);

        if (strSet.size() > 0)
            resultList.push_back(strSet);
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
        if (beginFound == std::string::npos)
            continue;

        TStrSet strSet;
        Fill(methodName, demangled, strSet);

        if (strSet.size() > 0)
            resultMap.insert({strSet, demangled});
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

    FindTypesOfMethod(getByHasMethodName, mHasComponentList);

    FindTypeIndex(typeIndexMethodName, mTypeIndexNameFuncMap);

    auto showWarning = mHasComponentList.size() == 0 && mTypeIndexNameFuncMap.size() == 0;
    if (showWarning) {
        printf("Warning! TEntityManager Setup not found reflection info.\n");
    }
#ifdef SHOW_STAT
    printf("uniqueCnt = %u, hasCnt = %u, valueCnt = %u, typeIndexCount = %u\n",
        mUniqueSet.size(), mHasComponentList.size(), mValueComponentList.size(), mTypeIndexNameFuncMap.size());
#endif

    using TypeIndexFunc = unsigned int(TEntityManager::*)(void);
    for (auto strSetFunc : mTypeIndexNameFuncMap) {
        auto& demangled = strSetFunc.second;

        auto beginFound = demangled.find(typeIndexMethodName);
        if (beginFound == std::string::npos) {
            continue;
        }

        auto endFound = demangled.find("(");
        if (endFound == std::string::npos) {
            continue;
        }

        auto funcName = demangled.substr(beginFound, endFound - beginFound);

        try {
            auto func = bexp::import_mangled<nsECSFramework::TEntityManager, unsigned int(void)>(mLib, funcName.data());
            auto typeIndexFunc = func(this);

            //      printf( "%s => %u\n", funcName.data(), typeIndexFunc );

            mComponentsTypeIndexMap.insert({strSetFunc.first, typeIndexFunc});
        } catch (std::exception e) {
            printf(e.what());
        }
    }

    // все типы изо всех коллекций
    TStrSet hasSet;

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
}
//-------------------------------------------------------------------------------------------------------
TEntityID TEntityManager::CreateEntity()
{
    auto id = (TEntityID) mEntities.mCounter;

    auto newEntity = mEntityMemoryPool->Pop();
    if (mReserverIndexInEntities.size() > 0) {
        id = mReserverIndexInEntities.back();
        mReserverIndexInEntities.pop_back();
        mEntities.mVec[id] = newEntity;
    } else {
        mEntities.Append(newEntity);
    }
    return id;
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::DestroyEntity(TEntityID eid)
{
    auto pEntity = GetEntity(eid);
#ifdef _DEBUG
    if (pEntity == nullptr) {
        BL_FIX_BUG();
        return;
    }
#endif
    auto index = pEntity->GetFirstComponentIndex();
    while (index != TEntity::NoneIndex) {
        RemoveComponent(eid, pEntity, index);
        index = pEntity->GetFirstComponentIndex();
    }

    mEntityMemoryPool->Push(pEntity);

    mReserverIndexInEntities.push_back(eid);
    mEntities.mVec[eid] = nullptr;
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::Clear()
{
    auto cnt = mEntities.mCounter;
    for (size_t eid = 0; eid < cnt; eid++) {
        if (GetEntity(eid)) {
            DestroyEntity(eid);
        }
    }
}
//----------------------------------------------------------------------------------------------------
TEntity* TEntityManager::GetEntity(TEntityID eid) const
{
    return mEntities.mVec[eid];
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::RemoveComponent(TEntityID eid, TEntity* pEntity, int index)
{
    TryRemoveFromHas(eid, index, pEntity);
    pEntity->RemoveComponent(index);
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
        hasList->push_front(eid);
        auto frontIt = hasList->begin();

        auto pLTL = mLinkToListMemoryPool->Pop();
        pLTL->Set(*hasList, frontIt);
        pEntity->AddHasCollectionInfo(pLTL, collectionIndex);
    }
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