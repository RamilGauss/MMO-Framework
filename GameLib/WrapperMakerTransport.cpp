/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WrapperMakerTransport.h"
#include "INetTransport.h"

using namespace nsMMOEngine;

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
	return maker.New();
}
//-------------------------------------------------------------------------
void TWrapperMakerTransport::Delete(INetTransport* pTransport)
{
  maker.Delete(pTransport);
}
//-------------------------------------------------------------------------

