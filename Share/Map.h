/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef __MAPH
#define __MAPH

class TMap
{

  unsigned short mID;// идентификатор карты

public:
  TMap();
  ~TMap();

  unsigned short GetID();
  void SetID(unsigned short val);

};

#endif
