/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HeaderTCPH
#define HeaderTCPH

enum
  {
    eHeader = 0xCC5C,
  };

#ifdef WIN32
#pragma pack(push, 1)
#endif
struct THeaderTCP
{
  short header;
  int   size;
  THeaderTCP(){header = short(eHeader);}
};
#ifdef WIN32
#pragma pack(pop)
#endif


#endif