/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HeaderTCPH
#define HeaderTCPH

#ifdef WIN32
#pragma pack(push, 1)
#endif
struct THeaderTCP
{
  //int size;
  unsigned char size[3];
}_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif


#endif