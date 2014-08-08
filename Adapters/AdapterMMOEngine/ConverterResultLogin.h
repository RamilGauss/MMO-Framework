/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ConverterResultLoginH
#define ConverterResultLoginH

#include "PrototypeMMOMaster.h"
#include "Master.h"

class TConverterResultLogin
{
public:
  TConverterResultLogin();
  virtual ~TConverterResultLogin();

  PrototypeMMOMaster::tResultLogin Work(nsMMOEngine::TMaster::tResultLogin resLogin);
};

#endif
