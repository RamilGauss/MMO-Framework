/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GeneratedClassH
#define GeneratedClassH

class TPushMaster;
class TPopMaster;

class TGeneratedClass
{
public:// member region
  int mID;
public:
  void Serialize( TPushMaster* pPushMaster ) const;
  void Deserialize( TPopMaster* pPopMaster );
  short GetSerializableUniqueID();
};

#endif
