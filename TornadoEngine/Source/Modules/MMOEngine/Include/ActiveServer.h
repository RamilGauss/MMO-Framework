/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseServer.h"

namespace nsMMOEngine
{
  class DllExport TActiveServer : public TBaseServer
  {

  public:
    TActiveServer();
    virtual ~TActiveServer();
    
    virtual void ConnectUp( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet = 0) = 0;
  };
}