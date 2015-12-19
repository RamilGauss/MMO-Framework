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

  virtual int Set(char* p, int size);
  virtual TContainer GetData();

  virtual int         GetID()   = 0;
  virtual std::string GetName() = 0;

  virtual void GetStrContent(std::vector<std::string>& vecStr);
private:
  void GetStrDescItem(std::vector<std::string>& vecStr, int sizeStack);
protected:  
  virtual std::string GetStrDescConstItem(std::string name) = 0;
};
#endif
