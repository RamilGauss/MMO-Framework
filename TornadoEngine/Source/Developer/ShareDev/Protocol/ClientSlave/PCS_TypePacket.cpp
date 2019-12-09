/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PCS_TypePacket.h"
#include "BreakPacket.h"

using namespace nsPCS;

TBasePacket_PCS::TBasePacket_PCS(unsigned char _type)
{ 
  mType = _type;
}
//----------------------------------------------------------------------------------
TContainerRise TBasePacket_PCS::Pack()
{
  mBP.Reset();
  mBP.PushBack( (char*)&mType, sizeof(mType));
  TContainerRise fromInherit = PackInherit();
  mBP.PushBack( fromInherit.GetPtr(), fromInherit.GetSize() );
  
  TContainerRise result;
  mBP.CopyInBuffer(result);
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
