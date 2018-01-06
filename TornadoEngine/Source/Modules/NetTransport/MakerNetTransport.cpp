/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MakerNetTransport.h"
#include "NetTransport_Boost.h"

nsMMOEngine::INetTransport* TMakerNetTransport::New()
{
  return new TNetTransport_Boost();
}
//-----------------------------------------------------------------------------
void TMakerNetTransport::Delete(nsMMOEngine::INetTransport* pTransport)
{
  delete pTransport;
}
//-----------------------------------------------------------------------------