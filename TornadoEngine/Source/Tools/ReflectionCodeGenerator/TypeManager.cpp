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
  if ( fitType == fit->second->end() )
  {
    fit->second->insert( TStrPtrMap::value_type( typeInfo.mName, std::shared_ptr<TTypeInfo>( new TTypeInfo( typeInfo ) ) ) );
  }
  else
    fitType->second.get() [0] = typeInfo;
}
//--------------------------------------------------------------------------------------