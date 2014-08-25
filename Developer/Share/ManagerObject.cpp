/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerObject.h"

TManagerObject::TManagerObject()
{

}
//------------------------------------------------------------------------
TManagerObject::~TManagerObject()
{

}
//------------------------------------------------------------------------
void TManagerObject::Add(unsigned int id, void* pObject)
{
  mMapID_Object.insert(TMapUintPtr::value_type(id, pObject));
}
//------------------------------------------------------------------------
void TManagerObject::Remove(unsigned int id)
{
  mMapID_Object.erase(id);
}
//------------------------------------------------------------------------
void* TManagerObject::Find(unsigned int id)
{
  TMapUintPtrIt fit = mMapID_Object.find(id);
  if(fit==mMapID_Object.end())
    return NULL;
  return fit->second;
}
//------------------------------------------------------------------------
int TManagerObject::GetCount()
{
  return mMapID_Object.size();
}
//------------------------------------------------------------------------
void TManagerObject::Clear()
{
  mMapID_Object.clear();
}
//------------------------------------------------------------------------
