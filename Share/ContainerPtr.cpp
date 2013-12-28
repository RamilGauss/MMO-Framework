/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContainerPtr.h"

#include <memory.h>
#include <stddef.h>

TContainerPtr::TContainerPtr()
{
  pData = NULL;
  size  = 0;
}
//---------------------------------------------------------------
TContainerPtr::~TContainerPtr()
{
  Unlink();
}
//---------------------------------------------------------------
void TContainerPtr::SetData(char* p, int s)
{
  Unlink();
  size  = s;
  pData = p;
}
//---------------------------------------------------------------
char* TContainerPtr::GetData(int &s)
{
  s = size;
  return pData;
}
//---------------------------------------------------------------
void* TContainerPtr::GetPtr()const
{
  return pData;
}
//---------------------------------------------------------------
int TContainerPtr::GetSize()const
{
  return size;
}
//---------------------------------------------------------------
void TContainerPtr::Unlink()
{
  pData = NULL;
  size = 0;
}
//---------------------------------------------------------------
