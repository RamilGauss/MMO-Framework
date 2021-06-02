/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef BaseLogicPacketH
#define BaseLogicPacketH

#include "TypeDef.h"

struct DllExport TBaseLogicPacket
{
  TBaseLogicPacket();
  virtual ~TBaseLogicPacket();
  int type;
};

namespace nsBaseLogicPacket
{
  enum
  {
    eUndef,
    eCallBack0,
    eCallBack1,
  };
};

#endif
