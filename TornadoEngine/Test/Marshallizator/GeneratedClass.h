/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GeneratedClassH
#define GeneratedClassH

#include "ISerializable.h"

class GeneratedClass : public ISerializable
{
public:// member region
  int mID;
public:
  virtual void Serialize( TPushMaster* pPushMaster );
  virtual void Deserialize( TPopMaster* pPopMaster );
  virtual short GetSerializableUniqueID();
};

#endif
