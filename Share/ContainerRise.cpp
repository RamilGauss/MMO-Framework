/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <stddef.h>
#include <memory.h>

#include "ContainerRise.h"

TContainerRise::TContainerRise()
{
  mSizeUse = 0;
}
//----------------------------------------------------------
char* TContainerRise::GetPtr()
{
	return (char*)mC.GetPtr();
}
//----------------------------------------------------------
int TContainerRise::GetSize()
{
  return mSizeUse;
}
//----------------------------------------------------------
void TContainerRise::Alloc(int new_size)
{
  if(mC.GetSize() < new_size)
    mC.SetData(NULL, new_size);
  mSizeUse = new_size;
}
//----------------------------------------------------------
void TContainerRise::Realloc( int new_size)
{
  if(mC.GetSize() < new_size)
  {
    int oldSize = mC.GetSize();
    if(oldSize)
    {
      void* pOld = mC.GetPtr();
			mC.Unlink();
			mC.SetData(NULL, new_size);
			void* pNew = mC.GetPtr();
			memcpy(pNew, pOld, mSizeUse);
			TContainer::Free((char*)pOld);
    }
  }
  mSizeUse = new_size;
}
//----------------------------------------------------------
void TContainerRise::SetData(char* p, int size)
{
	if(size>mSizeUse)
		Alloc(size);
	else
		mSizeUse = size;
  if(p)
	  memcpy(mC.GetPtr(), p, mSizeUse);
}
//----------------------------------------------------------
void TContainerRise::AddData(char*p, int size)
{
  int oldSize = GetSize();
  int newSize = oldSize + size;
  Realloc(newSize);
  char* pBound = GetPtr();
  memcpy(pBound + oldSize, p, size);
}
//----------------------------------------------------------
