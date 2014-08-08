/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeObjectH
#define PrototypeObjectH

#include "PrototypeList.h"
#include "CallBackRegistrator.h"
#include "TypeDef.h"

class DllExport PrototypeObject
{
  TCallBackRegistrator2<PrototypeObject*,int> mCallBack;
public:
  PrototypeObject();
  virtual ~PrototypeObject();
  // если один из прототипов сделает изменения в объекте, то
  // он обязан вызвать Update для оповещения своих изменений других прототипов
	template <typename F, class A1>
  void RegisterForUpdate(F pFunc, A1 pObject)
  {
    mCallBack.Register(pFunc, pObject);
  }
  void NotifyUpdate(int type_event);
};

#endif
