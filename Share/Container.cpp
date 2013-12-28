/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Container.h"

#include <memory.h>
#include <stddef.h>
#include "BL_Debug.h"

TContainer::TContainer(const TContainer& c)
{
  pData = NULL;
  size  = 0;

  if(c.GetPtr() || c.GetSize())
  {
    BL_FIX_BUG();
  }
}
//---------------------------------------------------------------
TContainer& TContainer::operator=(const TContainer& c)
{
  if(c.GetPtr() || c.GetSize())
  {
    BL_FIX_BUG();
  }
  return *this;
}
//---------------------------------------------------------------
TContainer::TContainer()
{
  pData = NULL;
  size  = 0;
}
//---------------------------------------------------------------
TContainer::~TContainer()
{
  Done();
}
//---------------------------------------------------------------
void TContainer::Done()
{
  delete[]pData;
  pData = NULL;
  size  = 0;
}
//---------------------------------------------------------------
void TContainer::SetData(char* p, int s)
{
  Done();
  size  = s;
  pData = new char[size];
  if(p)
    memcpy(pData,p,size);
}
//---------------------------------------------------------------
char* TContainer::GetData(int &s)
{
  s = size;
  return pData;
}
//---------------------------------------------------------------
void* TContainer::GetPtr()const
{
  return pData;
}
//---------------------------------------------------------------
int TContainer::GetSize()const
{
  return size;
}
//---------------------------------------------------------------
void TContainer::Unlink()
{
  pData = NULL;
  size = 0;
}
//---------------------------------------------------------------
void TContainer::Entrust(char* p, int s)
{
  Done();
  size  = s;
  pData = p;
}
//---------------------------------------------------------------
