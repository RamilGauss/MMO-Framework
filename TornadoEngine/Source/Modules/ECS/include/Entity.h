/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "ComponentInfo.h"
#include "Config.h"
#include "BL_Debug.h"
#include "ColanderVector.h"
#include "IComponent.h"

namespace nsECSFramework
{
  class DllExport TEntity
  {
    typedef TColanderVector<TLinkToList<TEntityID>*> TCollectionVec;
    
    TCollectionVec mHasCollectionVec;
    TCollectionVec mValueCollectionVec;
  
    typedef TColanderVector<TComponentInfo*> TComponentVec;// from memory pool
    TComponentVec mComponents;

    std::list<short> mComponentIndexInUse;

    TMemoryObjectPool<TComponentInfo>* mComponentInfoMemoryPool;
  public:
    TEntity();

    template<typename Component>
    Component* AddComponent( int index );
    bool HasComponent( int index );
    IComponent* GetComponent( int index );
    void RemoveComponent( int index );

    static const int NoneIndex = -1;
    int GetFirstComponentIndex();

    void AddHasCollectionInfo( TLinkToList<TEntityID>* pLTL, int collectionIndex );
    TLinkToList<TEntityID>* RemoveHasCollectionInfo( int collectionIndex );

    void AddValueCollectionInfo( TLinkToList<TEntityID>* pLTL, int collectionIndex );
    TLinkToList<TEntityID>* RemoveValueCollectionInfo( int collectionIndex );
  private:
  };
  //---------------------------------------------------------------------------------------
  template<typename Component>
  Component* TEntity::AddComponent( int index )
  {
    auto pCI = mComponents[index];
    if ( pCI != nullptr )
    {
      BL_FIX_BUG();
      return nullptr;//???
    }
    mComponentIndexInUse.push_front( index );
    
    pCI = mComponentInfoMemoryPool->Pop();
    mComponents[index] = pCI;

    pCI->Init<Component>();
    auto it = mComponentIndexInUse.begin();
    pCI->mLinkToList.Set( mComponentIndexInUse, it );
    return (Component*)pCI->p;
  }
  //---------------------------------------------------------------------------------------
}