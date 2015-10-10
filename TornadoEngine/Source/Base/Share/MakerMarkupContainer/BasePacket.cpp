#include "BasePacket.h"
#include "MarkUpContainer.h"

TBasePacket::TBasePacket()
{
  mMarkUp = new TMarkUpContainer;
  mRootDesc = new IMarkUpContainer::TDesc;
}
//--------------------------------------------------------------------------------
TBasePacket::~TBasePacket()
{
  delete mMarkUp;
  delete mRootDesc;
}
//--------------------------------------------------------------------------------
int TBasePacket::Set(char* p, int size)
{
  return mMarkUp->Set(p, size);
}
//--------------------------------------------------------------------------------
TContainer TBasePacket::GetData()
{
  TContainer c;
  mMarkUp->Collect();
  c.SetData((char*)mMarkUp->GetPtr(), mMarkUp->GetSize());
  return c;
}
//--------------------------------------------------------------------------------
