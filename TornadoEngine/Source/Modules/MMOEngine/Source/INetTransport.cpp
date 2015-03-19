/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "INetTransport.h"
#include "Logger.h"

INetTransport::INetTransport()
{
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);
}
//---------------------------------------------------------------------------
INetTransport::~INetTransport()
{

}
//---------------------------------------------------------------------------
