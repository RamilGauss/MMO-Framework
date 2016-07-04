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
  TBreakPacket bp;
  bp.PushBack( (char*)&mType, sizeof(mType));
  TContainer fromInherit = PackInherit();
  bp.PushBack( fromInherit.GetPtr(), fromInherit.GetSize() );
  bp.Collect();
  TContainer result;
  result.Entrust( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
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
