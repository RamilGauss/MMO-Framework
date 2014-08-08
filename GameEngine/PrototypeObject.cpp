/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PrototypeObject.h"

PrototypeObject::PrototypeObject()
{

}
//-----------------------------------------------------------------
PrototypeObject::~PrototypeObject()
{

}
//-----------------------------------------------------------------
void PrototypeObject::NotifyUpdate(int type_event)
{
  mCallBack.Notify(this, type_event);
}
//-----------------------------------------------------------------