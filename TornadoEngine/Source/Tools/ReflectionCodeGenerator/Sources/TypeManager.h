/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include "TypeInfo.h"

class TTypeManager
{
  typedef std::map<std::string, TTypeInfo*> TStrTypeInfoPtrMap;
  TStrTypeInfoPtrMap mNameTypeInfoPtrMap;

public:
  typedef std::map<std::string, std::shared_ptr<TTypeInfo>> TStrPtrMap;// fileName - type info
  typedef std::map<std::string, std::shared_ptr<TStrPtrMap>> TStrPairMap;// namespace - { fileName, type info }

  TStrPairMap mNameSpaceTypesMap;

  void Add( std::string& nameSpaceName, TTypeInfo& typeInfo );

  TTypeInfo* FindTypeInfo( std::string& typeName );

protected:
  TTypeManager() { };
  friend class TSingletonManager;// for singleton pattern
};
