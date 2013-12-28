/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevProtocolH
#define DevProtocolH

namespace nsDevProtocol
{
  //-----------------------------------------------------------
  enum
  {
    Exit,
    CreateGroup,
    DisconnectUp_Client,
  };
  //-----------------------------------------------------------
  struct TBase
  {
    unsigned short type;
  };
  //-----------------------------------------------------------
  struct TExit : public TBase
  {
    TExit();
  };
  //-----------------------------------------------------------
  struct TCreateGroup : public TBase
  {
    TCreateGroup();
  };
  //-----------------------------------------------------------
  struct TDisconnectUp_Client : public TBase
  {
    TDisconnectUp_Client();
  };
  //-----------------------------------------------------------
}
#endif
