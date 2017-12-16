/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TestClassH
#define TestClassH

#include "ISerializable.h"
#include <vector>
#include <list>
#include "ParamClass.h"

class TestClass : public ISerializable
{
public:// member region
  std::vector<ParamClass> vParam;
public:
  virtual void Serialize( TPushMaster* pPushMaster );
  virtual void Deserialize( TPopMaster* pPopMaster );
  virtual short GetSerializableUniqueID();
};

#endif
