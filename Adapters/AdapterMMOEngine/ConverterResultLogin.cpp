/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ConverterResultLogin.h"

TConverterResultLogin::TConverterResultLogin()
{

}
//----------------------------------------------------------------------------------------
TConverterResultLogin::~TConverterResultLogin()
{

}
//----------------------------------------------------------------------------------------
PrototypeMMOMaster::tResultLogin TConverterResultLogin::Work(nsMMOEngine::TMaster::tResultLogin resLogin)
{
  PrototypeMMOMaster::tResultLogin res = PrototypeMMOMaster::eAccept;
  switch(resLogin)
  {
    case nsMMOEngine::TMaster::eAccept:
      res = PrototypeMMOMaster::eAccept;
      break;
    case nsMMOEngine::TMaster::eReject:
      res = PrototypeMMOMaster::eReject;
      break;
  }
  return res;
}
//----------------------------------------------------------------------------------------
