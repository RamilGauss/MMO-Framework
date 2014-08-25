/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PrototypeDev.h"

#include <stddef.h>

PrototypeDev::PrototypeDev()
{
  mSrcEvent = NULL;
}
//-----------------------------------------------------------------
PrototypeDev::~PrototypeDev()
{

}
//-----------------------------------------------------------------
void PrototypeDev::SetSrcEvent(TSrcEvent* pSrcEvent)
{
  mSrcEvent = pSrcEvent;
}
//-----------------------------------------------------------------
TSrcEvent* PrototypeDev::GetSrcEvent()
{
  return mSrcEvent;
}
//-----------------------------------------------------------------
