/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ParamClassH
#define ParamClassH

#include "ISerializable.h"
#include <vector>

class ParamClass : public ISerializable
{
public:// member region
  int id;
  float x;
  float y;
  float z;

  float angle;

  float vx;
  float vy;
  float vz;
public:
  virtual void Serialize( TPushMaster* pPushMaster );
  virtual void Deserialize( TPopMaster* pPopMaster );
  virtual short GetSerializableUniqueID();
};

#endif
