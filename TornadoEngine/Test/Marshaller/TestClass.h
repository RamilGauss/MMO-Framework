/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TestClassH
#define TestClassH

#include <vector>
#include <list>
#include "ParamClass.h"

class TPushMaster;
class TPopMaster;

class TTestClass
{
public:// member region
  std::vector<TParamClass> vParam;
public:
  void Serialize( TPushMaster* pPushMaster ) const;
  void Deserialize( TPopMaster* pPopMaster );
  short GetSerializableUniqueID();
};

#endif
