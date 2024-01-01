/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include "ComponentContainer.h"
#include "Config.h"
#include "Base/Common/BL_Debug.h"
#include "Base/Common/ColanderVector.h"
#include "IComponent.h"

namespace nsECSFramework
{
    class DllExport TEntity
    {
        using TCollectionVec = TColanderVector<TLinkToList<TEntityID>*>;

        TCollectionVec mHasCollectionVec;
        TCollectionVec mValueCollectionVec;

        using TComponentVec = TColanderVector<TComponentContainer*>;// from memory pool
        TComponentVec mComponents;

        std::list<TypeIndexType> mComponentIndexInUse;

        TMemoryObjectPool<TComponentContainer>* mComponentInfoMemoryPool;
    public:
        TEntity();

        template<typename Component>
        Component* AddComponent(int index);
        bool HasComponent(int index);
        IComponent* GetComponent(int index);
        void RemoveComponent(int index);

        static const int NONE_INDEX = -1;
        int GetFirstComponentIndex();

        const std::list<TypeIndexType>* GetComponentIndexInUse() const;

        void AddHasCollectionInfo(TLinkToList<TEntityID>* pLTL, int collectionIndex);
        TLinkToList<TEntityID>* RemoveHasCollectionInfo(int collectionIndex);

        void AddValueCollectionInfo(TLinkToList<TEntityID>* pLTL, int collectionIndex);
        TLinkToList<TEntityID>* RemoveValueCollectionInfo(int collectionIndex);
    private:
    };
    //---------------------------------------------------------------------------------------
    template<typename Component>
    Component* TEntity::AddComponent(int index)
    {
        auto pCI = mComponents[index];
        if ( pCI != nullptr ) {
            BL_FIX_BUG();
            return (Component*) pCI->p;
        }
        mComponentIndexInUse.push_front(index);

        pCI = mComponentInfoMemoryPool->Pop();
        mComponents[index] = pCI;

        pCI->Init<Component>();
        auto it = mComponentIndexInUse.begin();
        pCI->mLinkToList.Set(mComponentIndexInUse, it);
        return (Component*) pCI->p;
    }
    //---------------------------------------------------------------------------------------
}