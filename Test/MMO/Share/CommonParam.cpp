/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CommonParam.h"
#include "Base/Common/Logger.h"
#include "MMOEngine/include/EnumMMO.h"

void InitLogger( const char* loggerName )
{
  // обязательно инициализировать лог
  GetLogger()->Register( STR_NAME_MMO_ENGINE );
  GetLogger()->Register( STR_NAME_NET_TRANSPORT );
  GetLogger()->Register( loggerName );

  GetLogger()->Init( loggerName );
  GetLogger()->SetPrintf( false );
  GetLogger()->SetEnable( false );
//#ifdef _DEBUG
  GetLogger()->Get( loggerName )->SetEnable( true );
  GetLogger()->Get( loggerName )->SetPrintf( true );

  //GetLogger()->Get( STR_NAME_MMO_ENGINE )->SetEnable( true );
  //GetLogger()->Get( STR_NAME_MMO_ENGINE )->SetPrintf( true );
  //GetLogger()->Get( STR_NAME_NET_TRANSPORT )->SetEnable( true );
  //GetLogger()->Get( STR_NAME_NET_TRANSPORT )->SetPrintf( true );
  //#endif
}

