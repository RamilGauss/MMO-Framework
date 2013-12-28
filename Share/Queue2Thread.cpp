/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Queue2Thread.h"

TQueue2Thread::TQueue2Thread(int queue_count)
{
	mCount = queue_count;

	pQueue = new TContainer[mCount];

	mBeginPos = 0;
	mEndPos = 0;
	mCurrentCount = 0;
};
//---------------------------------------------------------------------------
TQueue2Thread::~TQueue2Thread()
{
   Clear();
};
//---------------------------------------------------------------------------
bool TQueue2Thread::Push(void* buffer, int size)
{
  if(mCurrentCount==mCount) {BL_FIX_BUG();return false;}

  pQueue[mEndPos].SetData((char*)buffer,size);
	
	if(++mEndPos == mCount) mEndPos = 0;
  mCurrentCount++;

  return true;
}
//---------------------------------------------------------------------------
bool TQueue2Thread::Pop(void* buffer,int &size)
{
  if(mCurrentCount == 0) 
    return false;

	size = pQueue[mBeginPos].GetSize();
  memcpy(buffer, pQueue[mBeginPos].GetPtr(), size);
	pQueue[mBeginPos].Done();

  if(++mBeginPos == mCount) mBeginPos = 0;
  mCurrentCount--;

  return true;
}
//---------------------------------------------------------------------------
void TQueue2Thread::Clear()
{
  delete[] pQueue;

  mBeginPos = 0;
  mEndPos = 0;
  mCurrentCount = 0;
}
//---------------------------------------------------------------------------
