/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <map>
#include "TypeInfo.h"

class TTypeManager
{
public:
  typedef std::map<std::string, std::shared_ptr<TTypeInfo>> TStrPtrMap;// type - type info
  typedef std::map<std::string, std::shared_ptr<TStrPtrMap>> TStrPairMap;// namespace - type

  TStrPairMap mNameSpaceTypesMap;

  void Add( std::string& nameSpaceName, TTypeInfo& typeInfo );

protected:
  TTypeManager() { };
  friend class TSingletonManager;// for singleton pattern
};
