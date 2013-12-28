/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevProtocol.h"

using namespace nsDevProtocol;

//-----------------------------------------------------------
TExit::TExit()
{
  type = Exit;
}
//-----------------------------------------------------------
TCreateGroup::TCreateGroup()
{
  type = CreateGroup;
}
//-----------------------------------------------------------
TDisconnectUp_Client::TDisconnectUp_Client()
{
  type = DisconnectUp_Client;
}
//-----------------------------------------------------------
