/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ArrContainer.h"


TArrContainer::TArrContainer()
{

}
//-----------------------------------------------------------------------------
TArrContainer::~TArrContainer()
{

}
//-----------------------------------------------------------------------------
void TArrContainer::GetElem( char*& p, int& size, int index) 
{
  p    = NULL;
  size = 0 ;
  if(int(mVec.size())<=index) return;
  p    = (char*)mVec[index].GetPtr();
  size = mVec[index].GetSize();
}
//-----------------------------------------------------------------------------
void TArrContainer::SetElem( char* p, int size, int index)
{
  if(int(mVec.size())<=index) return;
  mVec[index].SetData(p,size);
}
//-----------------------------------------------------------------------------
void TArrContainer::SetCount(int v)
{
  mVec.clear();
  for(int i = 0 ; i < v ; i++)
    mVec.push_back(TContainer());
}
//-----------------------------------------------------------------------------
int TArrContainer::GetCount()
{
  return mVec.size();
}
//-----------------------------------------------------------------------------
char* TArrContainer::GetPtr()
{
  Collect();
  return (char*)mFC.GetPtr();
}
//-----------------------------------------------------------------------------
int TArrContainer::GetSize()
{
  int size = 0;
  int cnt = mVec.size(); 
  for(int i = 0 ; i < cnt ; i++ )
    size += mVec[i].GetSize();

  return size;
}
//-----------------------------------------------------------------------------
void TArrContainer::Collect()
{
  int size = GetSize();
  mFC.SetData(NULL,size);
  char* p = (char*)mFC.GetPtr();
  int cnt = mVec.size(); 
  for(int i = 0 ; i < cnt ; i++ )
  {
    int sizeElem = mVec[i].GetSize();
    memcpy(p,mVec[i].GetPtr(),sizeElem);
    p += sizeElem;
  } 
}
//-----------------------------------------------------------------------------
