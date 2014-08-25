/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WrapperMakerTransport.h"
#include "MakerNetTransport.h"


TWrapperMakerTransport::TWrapperMakerTransport()
{

}
//-------------------------------------------------------------------------
TWrapperMakerTransport::~TWrapperMakerTransport()
{

}
//-------------------------------------------------------------------------
INetTransport* TWrapperMakerTransport::New()
{
  // указать создателя интерфейса и сам интерфейс
  TMakerNetTransport_Boost maker;
  return maker.New();
}
//-------------------------------------------------------------------------
void TWrapperMakerTransport::Delete(INetTransport* pTransport)
{
  TMakerNetTransport_Boost maker;
  maker.Delete(pTransport);
}
//-------------------------------------------------------------------------

