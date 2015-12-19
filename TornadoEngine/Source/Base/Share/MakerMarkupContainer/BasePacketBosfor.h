#ifndef BasePacketBosforH
#define BasePacketBosforH

#include "BasePacket.h"

class TBasePacketBosfor : public TBasePacket
{
protected:
  virtual std::string GetStrDescConstItem(std::string name);
};
#endif
