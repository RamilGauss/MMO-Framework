#ifndef BasePacketH
#define BasePacketH

#include "IMarkUpContainer.h"
#include "ContainerTypes.h"
#include <vector>

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

  void GetStrDesc(std::vector<std::string>& vecStr);
private:
  void GetStrDescItem(std::vector<std::string>& vecStr, int sizeStack);
};
#endif
