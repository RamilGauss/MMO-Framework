/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Entity.h"

using namespace nsECSFramework;

TEntity::TEntity()
{
    mComponentInfoMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TComponentContainer>>();
}
//---------------------------------------------------------------------------------------
int TEntity::GetFirstComponentIndex()
{
    if ( mComponentIndexInUse.size() == 0 ) {
        return NONE_INDEX;
    }
    auto bit = mComponentIndexInUse.begin();
    auto index = *bit;
    return index;
}
//---------------------------------------------------------------------------------------
void TEntity::RemoveComponent(int index)
{
    auto pCI = mComponents[index];
    if ( pCI == nullptr ) {
        return;
    }

    mComponents[index] = nullptr;
    pCI->Done();
    mComponentInfoMemoryPool->Push(pCI);
}
//---------------------------------------------------------------------------------------
bool TEntity::HasComponent(int index)
{
    return mComponents[index] != nullptr;
}
//---------------------------------------------------------------------------------------
void TEntity::AddHasCollectionInfo(TLinkToList<TEntityID>* pLTL, int collectionIndex)
{
    mHasCollectionVec[collectionIndex] = pLTL;
}
//---------------------------------------------------------------------------------------
TLinkToList<TEntityID>* TEntity::RemoveHasCollectionInfo(int collectionIndex)
{
    auto pLTL = mHasCollectionVec[collectionIndex];
    mHasCollectionVec[collectionIndex] = nullptr;
    return pLTL;
}
//---------------------------------------------------------------------------------------
void TEntity::AddValueCollectionInfo(TLinkToList<TEntityID>* pLTL, int collectionIndex)
{
    mValueCollectionVec[collectionIndex] = pLTL;
}
//---------------------------------------------------------------------------------------
TLinkToList<TEntityID>* TEntity::RemoveValueCollectionInfo(int collectionIndex)
{
    auto pLTL = mValueCollectionVec[collectionIndex];
    mValueCollectionVec[collectionIndex] = nullptr;
    return pLTL;
}
//---------------------------------------------------------------------------------------
IComponent* TEntity::GetComponent(int index)
{
    auto pCI = mComponents[index];
    if ( pCI == nullptr ) {
        return nullptr;
    }
    return pCI->p;
}
//---------------------------------------------------------------------------------------
const std::list<TypeIndexType>* TEntity::GetComponentIndexInUse() const
{
    return &mComponentIndexInUse;
}
//---------------------------------------------------------------------------------------
bool TEntity::IsJustCreatedComponent(int index)
{
    auto pCI = mComponents[index];
    if (pCI == nullptr) {
        return false;
    }
    return pCI->isJustCreated;
}
//---------------------------------------------------------------------------------------
void TEntity::ApplyChangesComponent(int index)
{
    auto pCI = mComponents[index];
    if (pCI == nullptr) {
        return;
    }
    pCI->isJustCreated = false;
}
//---------------------------------------------------------------------------------------