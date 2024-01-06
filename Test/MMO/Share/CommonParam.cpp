/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CommonParam.h"
#include "Base/Common/Logger.h"
#include "MMOEngine/include/EnumMMO.h"

void InitLogger(const char* loggerName)
{
    // обязательно инициализировать лог
    nsBase::nsCommon::GetLogger()->Register(STR_NAME_MMO_ENGINE);
    nsBase::nsCommon::GetLogger()->Register(STR_NAME_NET_TRANSPORT);
    nsBase::nsCommon::GetLogger()->Register(loggerName);

    nsBase::nsCommon::GetLogger()->Init(loggerName);
    nsBase::nsCommon::GetLogger()->SetPrintf(false);
    nsBase::nsCommon::GetLogger()->SetEnable(false);
    //#ifdef _DEBUG
    nsBase::nsCommon::GetLogger()->Get(loggerName)->SetEnable(true);
    nsBase::nsCommon::GetLogger()->Get(loggerName)->SetPrintf(true);

    //nsBase::nsCommon::GetLogger()->Get( STR_NAME_MMO_ENGINE )->SetEnable( true );
    //nsBase::nsCommon::GetLogger()->Get( STR_NAME_MMO_ENGINE )->SetPrintf( true );
    //nsBase::nsCommon::GetLogger()->Get( STR_NAME_NET_TRANSPORT )->SetEnable( true );
    //nsBase::nsCommon::GetLogger()->Get( STR_NAME_NET_TRANSPORT )->SetPrintf( true );
    //#endif
}

