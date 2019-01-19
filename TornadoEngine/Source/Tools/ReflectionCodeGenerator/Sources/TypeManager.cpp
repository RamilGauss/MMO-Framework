/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TypeManager.h"

//--------------------------------------------------------------------------------------
void TTypeManager::Add( std::string& nameSpaceName, TTypeInfo& typeInfo )
{
  auto fit = mNameSpaceTypesMap.find( nameSpaceName );
  if ( fit == mNameSpaceTypesMap.end() )
    mNameSpaceTypesMap.insert( TStrPairMap::value_type( nameSpaceName, std::shared_ptr<TStrPtrMap>( new TStrPtrMap() ) ) );
  fit = mNameSpaceTypesMap.find( nameSpaceName );

  auto fitType = fit->second->find( typeInfo.mName );
  TTypeInfo* pTypeInfo = nullptr;

  if ( fitType == fit->second->end() )
  {
    pTypeInfo = new TTypeInfo( typeInfo );
    fit->second->insert( TStrPtrMap::value_type( typeInfo.mName, std::shared_ptr<TTypeInfo>( pTypeInfo ) ) );
  }
  else
  {
    pTypeInfo = fitType->second.get();
    pTypeInfo[0] = typeInfo;
  }

  mNameTypeInfoPtrMap.insert( {pTypeInfo->mName, pTypeInfo} );
}
//--------------------------------------------------------------------------------------
TTypeInfo* TTypeManager::FindTypeInfo( std::string& typeName )
{
  auto fit = mNameTypeInfoPtrMap.find( typeName );
  if ( fit == mNameTypeInfoPtrMap.end() )
    return nullptr;
  return fit->second;
}
//--------------------------------------------------------------------------------------
