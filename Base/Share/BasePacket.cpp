/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BasePacket.h"

TBasePacket::TBasePacket()
{

}
//---------------------------------------------------------------------
TBasePacket::~TBasePacket()
{

}
//---------------------------------------------------------------------
bool TBasePacket::Set(void* p, int size)
{
  return mC.Set(p,size);
}
//---------------------------------------------------------------------
void* TBasePacket::Get(int &size)
{
  size = mC.GetSize();
  return mC.GetPtr();
}
//---------------------------------------------------------------------
void TBasePacket::SetData(void* pData, int size)
{
	mC.SetDataAppendix(pData, size);
}
//---------------------------------------------------------------------
void* TBasePacket::GetData(int& size)
{
	return mC.GetDataAppendix(size);
}
//---------------------------------------------------------------------


