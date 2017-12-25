/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WBreakPacket.h"

#include <stddef.h>
#include "BreakPacket.h"

WBreakPacket::WBreakPacket()
{
  mBP = new TBreakPacket();
}
//-------------------------------------------------------------------------
WBreakPacket::~WBreakPacket()
{

}
//-------------------------------------------------------------------------
void WBreakPacket::PushBack(char* p,int size)
{
  mBP->PushBack( p, size );
}
//-------------------------------------------------------------------------
void WBreakPacket::PushFront(char* p,int size)
{
  mBP->PushFront( p, size );
}
//-------------------------------------------------------------------------
void WBreakPacket::Collect()
{
  mBP->Collect();
}
//-------------------------------------------------------------------------
void* WBreakPacket::GetCollectPtr()
{
  return mBP->GetCollectPtr();
}
//-------------------------------------------------------------------------
int WBreakPacket::GetSize()
{
  return mBP->GetSize();
}
//-------------------------------------------------------------------------
void WBreakPacket::UnlinkCollect()
{
  mBP->UnlinkCollect();
}
//-------------------------------------------------------------------------
void WBreakPacket::Reset()
{
  mBP->Reset();
}
//-------------------------------------------------------------------------
