/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "IDriver.h"

class DllExport TPostgresDriver : public IDriver
{
public:
  bool Open( std::string host, unsigned short port, std::string login, std::string password ) override;
  void Close() override;

  void Execute( std::string& str ) override;
};