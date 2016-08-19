/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BasePacketBosforH
#define BasePacketBosforH

#include "BasePacket.h"

class TBasePacketBosfor : public TBasePacket
{
protected:
  virtual std::string GetStrDescConstItem(std::string name);
};
#endif
