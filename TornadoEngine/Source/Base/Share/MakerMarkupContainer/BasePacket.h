#ifndef BasePacketH
#define BasePacketH

#include "IMarkUpContainer.h"
#include "ContainerTypes.h"

class TBasePacket
{
protected:
  IMarkUpContainer*        mMarkUp;
  IMarkUpContainer::TDesc* mRootDesc;
public:
  TBasePacket();
  virtual ~TBasePacket();

  int Set(char* p, int size);
  TContainer GetData();
};
#endif
