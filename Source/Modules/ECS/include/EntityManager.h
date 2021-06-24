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
#include "ContainerForReactive.h"
#include "HelpStructs.h"

namespace nsECSFramework
{
    class DllExport TEntityManager
    {
        using TTypeID = TRunTimeTypeIndex<TEntityManager>;
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
        void AddComponent(TEntityID eid, Component& c);// => add event
        template <typename Component>
        void UpdateComponent(TEntityID eid);// => update event
        template <typename Component>
        Component* GetComponent(TEntityID eid);// for view, fast,
        template <typename Component>
        void RemoveComponent(TEntityID eid);// => remove event
        template <typename Component>
        bool HasComponent(TEntityID eid);

        void GetComponentList(TEntityID eid, std::list<TypeIndexType>& typeIdentifierList);

        template <typename ... Args>
        DllExport TEntityList* NoInline GetByHas()
        {// definition must be after declaration!
            const auto index = TypeIndex<Args...>();
            return (TEntityList*) mHasCollectionVec[index];
        }
    protected:
        // events
        friend class TReactiveOnAddSystem;
        friend class TReactiveOnUpdateSystem;
        friend class TReactiveOnRemoveSystem;

        TContainerForReactive mAddCollector;
        TContainerForReactive mUpdateCollector;
        TContainerForReactive mRemoveCollector;

        template<typename Component>
        int OnAdd();
        template<typename Component>
        int OnUpdate();
        template<typename Component>
        int OnRemove();
    private:
        using TComplexTypePtrListPtrMap = std::map<TComplexType*, TEntityList*, ptr_less<TComplexType*>>;
        using TComplexTypePtrListPtrMapPtrVec = TColanderVector<TComplexTypePtrListPtrMap*>;

        using TVoidPtrVector = TColanderVector<void*>;
        using TListPtrVector = TColanderVector<TEntityList*>;

        using TUniqueMap = std::map<IComponent*, TEntityID, component_ptr_less<IComponent*>>;
        using TUniqueMapPtrVector = TColanderVector<TUniqueMap*>;

        TListPtrVector mHasCollectionVec;// fill in setup

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

        using TCB_EntPtrCom = TCallBackRegistrator2<TEntityID, IComponent*>;
        using TCBVector = TColanderVector<TCB_EntPtrCom*>;

        TCBVector mRemoveCBVector;
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
        inline TEntity* GetEntity(TEntityID id) const;

        void RemoveComponent(TEntityID eid, TEntity* pEntity, int index);

        template<typename T0>
        void Fill(TComplexType* pComplexType, T0& t0);
        template<typename T0, typename T1, typename ... Args>
        void Fill(TComplexType* pComplexType, T0& t0, T1& t1, Args& ... args);

        void TryAddInHas(TEntityID eid, int index, TEntity* pEntity);
        void TryRemoveFromHas(TEntityID eid, int index, TEntity* pEntity);

    private:
        boost::dll::experimental::smart_library mLib;

        using TStrList = std::list<std::string>;
        using TStrSet = std::set<std::string>;
        using TStrSetList = std::list<TStrSet>;
        using TStrSetStrListMap = std::map<TStrSet, TStrList>;
        using TStrSetIntMap = std::map<TStrSet, int>;
        using TStrSetStrMap = std::map<TStrSet, std::string>;

        TStrSetStrMap mTypeIndexNameFuncMap;
        TStrSetIntMap mComponentsTypeIndexMap;
        // после поиска использования функций
        TStrSetList mHasComponentList;

        void Fill(const std::string& methodName, std::string& demangled, TStrSet& strSet);
        void FindTypesOfMethod(const std::string& methodName, TStrSetList& resultList);
        void FindTypeIndex(const std::string& methodName, TStrSetStrMap& resultMap);
    };
    //---------------------------------------------------------------------------------------
    template <typename Component>
    void TEntityManager::AddComponent(TEntityID eid, Component& c)
    {
        auto pEntity = GetEntity(eid);
        if ( pEntity == nullptr ) {
            BL_FIX_BUG();
            return;
        }

        const auto index = TypeIndex<Component>();
        auto pC = pEntity->AddComponent<Component>(index);

        *pC = c;

        TryAddInHas(eid, index, pEntity);
        mAddCollector.Set(index, eid);
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    void TEntityManager::UpdateComponent(TEntityID eid)
    {
        const auto index = TypeIndex<Component>();
        mUpdateCollector.Set(index, eid);
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    Component* TEntityManager::GetComponent(TEntityID eid)
    {
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if ( pEntity == nullptr ) {
            BL_FIX_BUG();
            return nullptr;
        }
#endif
        const auto index = TypeIndex<Component>();
        return (Component*) pEntity->GetComponent(index);
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    void TEntityManager::RemoveComponent(TEntityID eid)
    {
        auto pEntity = GetEntity(eid);
#ifdef _DEBUG
        if ( pEntity == nullptr ) {
            BL_FIX_BUG();
            return;
        }
#endif
        const auto index = TypeIndex<Component>();
        mRemoveCollector.Set(index, eid);
        RemoveComponent(eid, pEntity, index);
    }
    //---------------------------------------------------------------------------------------
    template <typename Component>
    bool TEntityManager::HasComponent(TEntityID eid)
    {
        auto pEntity = GetEntity(eid);
        if ( pEntity == nullptr ) {
            BL_FIX_BUG();
            return false;
        }
        const auto index = TypeIndex<Component>();
        return pEntity->HasComponent(index);
    }
    //---------------------------------------------------------------------------------------
    template<typename Component>
    int TEntityManager::OnAdd()
    {
        const auto index = TypeIndex<Component>();
        return mAddCollector.Register(index);
    }
    //---------------------------------------------------------------------------------------
    template<typename Component>
    int TEntityManager::OnUpdate()
    {
        const auto index = TypeIndex<Component>();
        return mUpdateCollector.Register(index);
    }
    //---------------------------------------------------------------------------------------
    template<typename Component>
    int TEntityManager::OnRemove()
    {
        const auto index = TypeIndex<Component>();
        return mRemoveCollector.Register(index);
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
}