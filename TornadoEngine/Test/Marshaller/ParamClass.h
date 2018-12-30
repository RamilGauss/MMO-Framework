/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"

class TBinaryPushMaster;
class TBinaryPopMaster;

#ifdef WIN32
#pragma pack(push, 1)
#endif

struct TFloat3
{
  float x = 1.2345678f;
  float y = 2.2345678f;
  float z = 3.2345678f;
}_PACKED;

struct TFloat4
{
  float x = 1.2345678f;
  float y = 2.2345678f;
  float z = 3.2345678f;
  float w = 4.2345678f;
}_PACKED;

class TParamClass
{
public:// member region
  int id;
  TFloat3 pos;
  TFloat4 rot;
  TFloat3 vel;
public:
  void Serialize( TBinaryPushMaster* pPushMaster ) const;
  void Deserialize( TBinaryPopMaster* pPopMaster );
  short GetSerializableUniqueID();
}_PACKED;

#ifdef WIN32
#pragma pack(pop)
#endif
