/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PCS_TypePacket.h"
#include "BreakPacket.h"

using namespace nsPCS;

TBasePacket_PCS::TBasePacket_PCS(unsigned char _type)
{ 
  mType = _type;
}
//----------------------------------------------------------------------------------
TContainer TBasePacket_PCS::Pack()
{
  mBP.Reset();
  mBP.PushBack( (char*)&mType, sizeof(mType));
  TContainer fromInherit = PackInherit();
  mBP.PushBack( fromInherit.GetPtr(), fromInherit.GetSize() );
  mBP.Collect();
  TContainer result;
  result.Entrust( (char*)mBP.GetCollectPtr(), mBP.GetSize() );
  mBP.UnlinkCollect();
  return result;
}
//----------------------------------------------------------------------------------
void TBasePacket_PCS::Unpack(TContainer c)
{
  char* p  = c.GetPtr()  + sizeof(mType);
  int size = c.GetSize() - sizeof(mType);
  UnpackInherit(p, size);
}
//----------------------------------------------------------------------------------
