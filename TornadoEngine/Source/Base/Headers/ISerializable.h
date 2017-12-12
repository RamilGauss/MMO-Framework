/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ISerializableH
#define ISerializableH

#include "TypeDef.h"

class TPushMaster;
class TPopMaster;

class DllExport ISerializable
{
public:
  virtual ~ISerializable(){}

  virtual void Serialize( TPushMaster* pPushMaster ) = 0;
  virtual void Deserialize( TPopMaster* pPopMaster ) = 0;
  virtual short GetSerializableUniqueID() = 0;
};

#endif
