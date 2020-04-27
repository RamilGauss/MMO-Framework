/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

class DllExport IDriver
{
public:
  virtual bool Open( std::string host, unsigned short port, std::string login, std::string password ) = 0;
  virtual void Close() = 0;

  virtual void Execute( std::string& str) = 0;
};