/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MakerTransport.h"
#include "MakerNetTransport.h"

INetTransport* TMakerTransport::New()
{
  TMakerNetTransport_Boost maker;
  INetTransport* pNetTransport = maker.New();
  return pNetTransport;
}
//-----------------------------------------------------------------------------
void TMakerTransport::Delete(INetTransport* pTransport)
{
  TMakerNetTransport_Boost maker;
  maker.Delete(pTransport);
}
//-----------------------------------------------------------------------------