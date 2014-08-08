/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IManagerObjectGeneral.h"
#include "BL_Debug.h"

IManagerObjectGeneral::IManagerObjectGeneral()
{

}
//--------------------------------------------------------
IManagerObjectGeneral::~IManagerObjectGeneral()
{

}
//--------------------------------------------------------
void IManagerObjectGeneral::AddObject(IBaseObjectGeneral* pObject)
{
  mVectorObject.push_back(pObject);
}
//--------------------------------------------------------
// отдать объект на изменение свойств объекта
IBaseObjectGeneral* IManagerObjectGeneral::Get(int index)
{
  BL_ASSERT(mVectorObject.size() > (unsigned int)index);
  IBaseObjectGeneral* pObject = mVectorObject.at(index);
  return pObject;
}
//--------------------------------------------------------
int IManagerObjectGeneral::GetCountObject()
{
  return mVectorObject.size();
}
//--------------------------------------------------------
