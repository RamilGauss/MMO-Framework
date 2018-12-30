/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

class TBinaryPushMaster;
class TBinaryPopMaster;

class TGeneratedClass
{
public:// member region
  int mID;
public:
  void Serialize( TBinaryPushMaster* pPushMaster ) const;
  void Deserialize( TBinaryPopMaster* pPopMaster );
  short GetSerializableUniqueID();
};
