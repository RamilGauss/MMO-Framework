/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ORMEngine.h"
#include "IDriver.h"

TORMEngine::TORMEngine( IDriver* pDriver )
{
  mDriver = pDriver;
}
//----------------------------------------------------------------------------------------------
bool TORMEngine::Open( std::string host, unsigned short port, std::string login, std::string password )
{
  return mDriver->Open( host, port, login, password );
}
//----------------------------------------------------------------------------------------------