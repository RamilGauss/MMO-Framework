/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DESC_CALLBACK_H
#define DESC_CALLBACK_H

#include "TypeDef.h"

#include "CallBackRegistrator.h"

class SHARE_EI TDescCallBack
{
  void* mPtrCallBack;
public:
  TDescCallBack();
  ~TDescCallBack();

  // установить
  void Set(void* pCB);

  // регистрация
  template <typename F, class C>
  void Register(F f, C pObject);

  template <typename Type0, typename F, class C>
  void Register(F f, C pObject);

  template <typename Type0,typename Type1, typename F, class C>
  void Register(F f, C pObject);

  // уведомление
  void Notify();

  template <typename Type0>
  void Notify(Type0 t0);

  template <typename Type0, typename Type1>
  void Notify(Type0 t0, Type1 t1);
};
//------------------------------------------------------------------
//------------------------------------------------------------------
template <typename F, class C>
void TDescCallBack::Register(F f, C pObject)
{
  ((TCallBackRegistrator0*)mPtrCallBack)->Register(f, pObject);
}
//------------------------------------------------------------------
template <typename Type0, typename F, class C>
void TDescCallBack::Register(F f, C pObject)
{
  ((TCallBackRegistrator1<Type0>*)mPtrCallBack)->Register(f, pObject);
}
//------------------------------------------------------------------
template <typename Type0,typename Type1, typename F, class C>
void TDescCallBack::Register(F f, C pObject)
{
  ((TCallBackRegistrator2<Type0,Type1>*)mPtrCallBack)->Register(f, pObject);
}
//------------------------------------------------------------------
template <typename Type0>
void TDescCallBack::Notify(Type0 t0)
{
  ((TCallBackRegistrator1<Type0>*)mPtrCallBack)->Notify(t0);
}
//------------------------------------------------------------------
template <typename Type0, typename Type1>
void TDescCallBack::Notify(Type0 t0, Type1 t1)
{
  ((TCallBackRegistrator2<Type0,Type1>*)mPtrCallBack)->Notify(t0,t1);
}
//------------------------------------------------------------------

#endif
