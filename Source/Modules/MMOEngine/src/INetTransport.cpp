/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "INetTransport.h"
#include "Base/Common/Logger.h"
#include "EnumMMO.h"

namespace nsMMOEngine
{
    INetTransport::INetTransport()
    {
        nsBase::nsCommon::GetLogger()->Register(STR_NAME_NET_TRANSPORT);
    }
    //---------------------------------------------------------------------------
    INetTransport::~INetTransport()
    {

    }
    //---------------------------------------------------------------------------
}