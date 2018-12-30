/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <vector>
#include <list>
#include "ParamClass.h"

class TBinaryPushMaster;
class TBinaryPopMaster;

class TTestClass
{
public:// member region
  std::vector<TParamClass> vParam;
public:
  void Serialize( TBinaryPushMaster* pPushMaster ) const;
  void Deserialize( TBinaryPopMaster* pPopMaster );
  short GetSerializableUniqueID();
};