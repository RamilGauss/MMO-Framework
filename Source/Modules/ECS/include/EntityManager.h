/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "Entity.h"
#include <list>
#include <vector>
#include <type_traits>

#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/dll/smart_library.hpp>
#include <boost/dll/import_class.hpp>
#include <boost/dll/shared_library.hpp>

#include "RunTimeTypeIndex.h"
#include "SingletonManager.h"

#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "ColanderVector.h"
#include "ComplexType.h"
#include "HelpStructs.h"

namespace nsECSFramework
{
    class DllExport TEntityManager
    {
        typedef TRunTimeTypeIndex<TEntityManager> TTypeID;
        TTypeID* mTypeIndex;
    public:
        TEntityManager(int entityCount = 1024);
        virtual ~TEntityManager();

        void Setup(const std::list<std::string>& pathList);
        void Setup(std::string path = boost::dll::this_line_location().string());

        // entity
        TEntityID CreateEntity();
        void DestroyEntity(TEntityID id);

        void Clear();

        // components
        template <typename Component>
        void SetComponent(TEntityID eid, Component& c);// => add or update event

        template <typename Component>
        Component* ViewComponent(TEntityID eid);// for view, fast,
        template <typename Component>
        void UpdateComponent(TEntityID eid, Component* pC);// => update event

        template <typename Component>
        bool GetComponent(TEntityID eid, Component& c);// for change, copy, with check
        template <typename Component>
        Component GetComponent(TEntityID eid);// for change, copy
        template <typename Component>
        void RemoveComponent(TEntityID eid);// => remove event
        template <typename Component>
        bool HasComponent(TEntityID eid);

        void GetComponentList(TEntityID eid, std::list<TypeIndexType>& typeIdentifierList);

        // filters
        template <typename Component>
        DllExport TEntityID NoInline GetByUnique(Component& c)
        {// definition must be after declaration!
            auto index = TypeIndex<Component>();
            auto pMap = mUniqueMapVec[index];
            if (pMap == nullptr) {
                return None;
            }
            auto fit = pMap->find(&c);
            if (fit == pMap->end()) {
                return None;
            }
            return fit->second;
        }
        template <typename ... Args>
        DllExport TEntityList* NoInline GetByValue(Args& ... args)
        {// definition must be after declaration!
            auto index = TypeIndex<Args...>();
            auto pMap = mValueCollectionVec[index];
            if (pMap == nullptr) {
                return nullptr;
            }

            TEntityList* pResult = nullptr;
            auto pComplexType = mComplexTypeMemoryPool->Pop();
            Fill(pComplexType, args ...);// берем адреса из стека, безопасно, потому что переменные еще существуют в методе
            auto fit = pMap->find(pComplexType);
            if (fit != pMap->end()) {
                pResult = fit->second;
            }

            // вернуть обратно в пул
            pComplexType->Done();
            mComplexTypeMemoryPool->Push(pComplexType);
            return pResult;
        }
        template <typename ... Args>
        DllExport TEntityList* NoInline GetByHas()
        {// definition must be after declaration!
            auto index = TypeIndex<Args...>();
            auto pList = (TEntityList*) mHasCollectionVec[index];
            return pList;
        }

        // events - instant reactions
        template<typename Component>
        TCallBackRegistrator2<TEntityID, IComponent*>* RegisterOnAddComponent();
        template<typename Component>
        TCallBackRegistrator2<TEntityID, IComponent*>* RegisterOnUpdateComponent();
        template<typename Component>
        TCallBackRegistrator2<TEntityID, IComponent*>* RegisterOnRemoveComponent();
    private:
        using TCB_EntPtrCom = TCallBackRegistrator2<TEntityID, IComponent*>;
        using TCBVector = TColanderVector<TCB_EntPtrCom*>;

        TCBVector mAddCBVector;
        TCBVector mUpdateCBVector;
        TCBVector mRemoveCBVector;

        template<typename Component>
        TCallBackRegistrator2<TEntityID, IComponent*>* RegisterOnComponent(TCBVector& cbVector);

        using TComplexTypePtrListPtrMap = std::map<TComplexType*, TEntityList*, ptr_less<TComplexType*>>;
        using TComplexTypePtrListPtrMapPtrVec = TColanderVector<TComplexTypePtrListPtrMap*>;

        using TVoidPtrVector = TColanderVector<void*>;
        using TListPtrVector = TColanderVector<TEntityList*>;

        using TUniqueMap = std::map<IComponent*, TEntityID, component_ptr_less<IComponent*>>;
        using TUniqueMapPtrVector = TColanderVector<TUniqueMap*>;

        TListPtrVector mHasCollectionVec;// fill in setup
        TComplexTypePtrListPtrMapPtrVec mValueCollectionVec;// fill in setup
        TUniqueMapPtrVector mUniqueMapVec;// fill in setup

        TMemoryObjectPool<TEntity>* mEntityMemoryPool;
        TMemoryObjectPool<TComplexType>* mComplexTypeMemoryPool;
        TMemoryObjectPool<TLinkToList<TEntityID>>* mLinkToListMemoryPool;
        TMemoryObjectPool<TEntityList>* mEntityListMemoryPool;
        TMemoryObjectPool<TUniqueMap>* mUniqueMapMemoryPool;
        TMemoryObjectPool<TComplexTypePtrListPtrMap>* mComplexTypePtrListPtrMapMemoryPool;


        TEntityList mReserverIndexInEntities;
        TVectorRise<TEntity*> mEntities;

        TListPtrVector mOnAddCallBack;
        TListPtrVector mOnUpdateCallBack;
        TListPtrVector mOnRemoveCallBack;

        using TShortList = std::list<short>;
        using TListVector = TColanderVector<TShortList>;

        // в каких коллекциях участвует данный тип
        TListVector mHasTypeInCollection;// fill in setup
        TListVector mValueTypeInCollection;// fill in setup

        // из каких типов состоит коллекция
        TListVector mHasCollectionWithTypes;// fill in setup
        TListVector mValueCollectionWithTypes;// fill in setup

    public:// inner use
#pragma GCC push_options
#pragma GCC optimize ("O0")
        template <typename ... Args>
        BOOST_SYMBOL_EXPORT unsigned int NoInline TypeIndex()
        {
            return mTypeIndex->type<Args...>();
        }
#pragma GCC pop_options
    private:
        TEntity* GetEntity(TEntityID id) const;

        void RemoveComponent(TEntityID eid, TEntity* pEntity, int index);

        template<typename T0>
        void Fill(TComplexType* pComplexType, T0& t0);
        template<typename T0, typename T1, typename ... Args>
        void Fill(TComplexType* pComplexType, T0& t0, T1& t1, Args& ... args);

        void TryAddInUnique(TEntityID eid, IComponent* pC, int index);
        void TryRemoveFromUnique(TEntityID eid, IComponent* pC, int index);

        void TryAddInHas(TEntityID eid, int index, TEntity* pEntity);
        void TryAddInValue(TEntityID eid, int index, TEntity* pEntity);

        void TryRemoveFromHas(TEntityID eid, int index, TEntity* pEntity);
        void TryRemoveFromValue(TEntityID eid, int index, TEntity* pEntity);

        void NotifyOnAddComponent(int index, TEntityID entity, IComponent* pC);
        void NotifyOnUpdateComponent(int index, TEntityID entity, IComponent* pC);
        void NotifyOnRemoveComponent(int index, TEntityID entity, IComponent* pC);

        void NotifyComponent(int index, TEntityID entity, IComponent* pC, TCBVector& cbVector);

    private:
        boost::dll::experimental::smart_library mLib;

        typedef std::list<std::string> TStrList;
        typedef std::set<std::string> TStrSet;
        typedef std::list<TStrSet> TStrSetList;
        typedef std::map<TStrSet, TStrList> TStrSetStrListMap;
        typedef std::map<TStrSet, int> TStrSetIntMap;
        typedef std::map<TStrSet, std::string> TStrSetStrMap;

        TStrSetStrMap mTypeIndexNameFuncMap;
        TStrSetIntMap mComponentsTypeIndexMap;
        // после поиска использования функций
        TStrSetList mUniqueSet;
        TStrSetList mHasComponentList;
        TStrSetList mValueComponentList;

        void Fill(const std::string& methodName, std::string& demangled, TStrSet& strSet);
        void FindTypesOfMethod(const std::string& methodName, TStrSetList& resultList);
        void FindTypeIndex(const std::string& methodName, TStrSetStrMap& resultMap);
    };
    //---------------------------------------------------------------------------------------
    template <typename Component>
    void TEntityManager::SetComponent(TEntityID eid, Component& c)
    {
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if (pEntity == nullptr) {
            BL_FIX_BUG();
            return;
        }
#endif
        Component* pC = nullptr;
        const auto index = TypeIndex<Component>();
        auto const has = pEntity->HasComponent(index);
        if (has) {
            pC = (Component*) pEntity->GetComponent(index);

            TryRemoveFromUnique(eid, pC, index);
            TryRemoveFromValue(eid, index, pEntity);
        } else {
            pC = pEntity->AddComponent<Component>(index);
            TryAddInHas(eid, index, pEntity);
        }

        *pC = c;
        TryAddInUnique(eid, pC, index);
        TryAddInValue(eid, index, pEntity);

        if (has) {
            NotifyOnUpdateComponent(index, eid, pC);
        } else {
            NotifyOnAddComponent(index, eid, pC);
        }
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    void TEntityManager::UpdateComponent(TEntityID eid, Component* pC)
    {
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if (pEntity == nullptr) {
            BL_FIX_BUG();
            return;
        }
#endif
        const auto index = TypeIndex<Component>();
#ifdef _DEBUG
        // Checking
        auto pOriginal = (Component*) pEntity->GetComponent(index);
        if (pOriginal != pC) {
            BL_FIX_BUG();
        }
#endif
        TryRemoveFromUnique(eid, pC, index);
        TryRemoveFromValue(eid, index, pEntity);
        TryAddInUnique(eid, pC, index);
        TryAddInValue(eid, index, pEntity);

        NotifyOnUpdateComponent(index, eid, pC);
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    Component* TEntityManager::ViewComponent(TEntityID eid)
    {
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if (pEntity == nullptr) {
            BL_FIX_BUG();
            return nullptr;
        }
#endif
        const auto index = TypeIndex<Component>();
        auto pC = (Component*) pEntity->GetComponent(index);
        return pC;
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    bool TEntityManager::GetComponent(TEntityID eid, Component& c)
    {
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if (pEntity == nullptr) {
            BL_FIX_BUG();
            return false;
        }
#endif
        const auto index = TypeIndex<Component>();
        auto pC = (Component*) pEntity->GetComponent(index);
        if (pC == nullptr)
            return false;
        c = *pC;
        return true;
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    Component TEntityManager::GetComponent(TEntityID eid)
    {
        Component c;
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if (pEntity == nullptr) {
            BL_FIX_BUG();
            return c;
        }
#endif
        const auto index = TypeIndex<Component>();
        auto pC = (Component*) pEntity->GetComponent(index);
        if (pC == nullptr) {
            return c;
        }
        c = *pC;
        return c;
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    void TEntityManager::RemoveComponent(TEntityID eid)
    {
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if (pEntity == nullptr) {
            BL_FIX_BUG();
            return;
        }
#endif
        const auto index = TypeIndex<Component>();
        auto pC = (Component*) pEntity->GetComponent(index);

        NotifyOnRemoveComponent(index, eid, pC);

        RemoveComponent(eid, pEntity, index);
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    bool TEntityManager::HasComponent(TEntityID eid)
    {
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if (pEntity == nullptr) {
            BL_FIX_BUG();
            return false;
        }
#endif
        const auto index = TypeIndex<Component>();
        return pEntity->HasComponent(index);
    }
    //---------------------------------------------------------------------------------------
    template<typename T0>
    void TEntityManager::Fill(TComplexType* pComplexType, T0& t0)
    {
        const auto index = TypeIndex<T0>();
        pComplexType->parts[index] = &t0;
        pComplexType->mComponentTypeIdentifierList.push_back(index);
    }
    //---------------------------------------------------------------------------------------
    template<typename T0, typename T1, typename ... Args>
    void TEntityManager::Fill(TComplexType* pComplexType, T0& t0, T1& t1, Args& ... args)
    {
        Fill(pComplexType, t0);
        Fill(pComplexType, t1, args ...);
    }
    //---------------------------------------------------------------------------------------
    template<typename Component>
    TCallBackRegistrator2<TEntityID, IComponent*>* TEntityManager::RegisterOnAddComponent()
    {
        return RegisterOnComponent<Component>(mAddCBVector);
    }
    //---------------------------------------------------------------------------------------
    template<typename Component>
    TCallBackRegistrator2<TEntityID, IComponent*>* TEntityManager::RegisterOnUpdateComponent()
    {
        return RegisterOnComponent<Component>(mUpdateCBVector);
    }
    //---------------------------------------------------------------------------------------
    template<typename Component>
    TCallBackRegistrator2<TEntityID, IComponent*>* TEntityManager::RegisterOnRemoveComponent()
    {
        return RegisterOnComponent<Component>(mRemoveCBVector);
    }
    //---------------------------------------------------------------------------------------
    template<typename Component>
    TCallBackRegistrator2<TEntityID, IComponent*>* TEntityManager::RegisterOnComponent(TCBVector& cbVector)
    {
        const auto index = TypeIndex<Component>();
        auto pCB = cbVector[index];
        if (pCB == nullptr) {
            pCB = new TCB_EntPtrCom();
            cbVector[index] = pCB;
        }
        return pCB;
    }
    //---------------------------------------------------------------------------------------
}