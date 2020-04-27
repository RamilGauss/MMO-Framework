/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <string>

class IDriver;

class DllExport TORMEngine
{
  IDriver* mDriver;

public:
  TORMEngine( IDriver* pDriver );

  bool Open( std::string host, unsigned short port, std::string login, std::string password );


protected:
};