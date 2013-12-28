/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MAP_CALL_BACK_H
#define MAP_CALL_BACK_H

#include "DescCallBack.h"
#include <map>
#include "DescCallBack.h"

class SHARE_EI TMapCallBack
{
  typedef std::map<int,TDescCallBack> TMapIntDescCB;
  typedef TMapIntDescCB::iterator TMapIntDescCBIt;

  TMapIntDescCB mMapTypeCallBack;
public:
  TMapCallBack();
  virtual ~TMapCallBack();

  template <typename F, class C>
  void Register(int type, F f, C pObject);

  template <typename Type0, typename F, class C>
  void Register(int type, F f, C pObject);

  template <typename Type0,typename Type1, typename F, class C>
  void Register(int type, F f, C pObject);
public:
  void Notify(int type);

  template <typename Type0>
  void Notify(int type, Type0 t0);

  template <typename Type0,typename Type1>
  void Notify(int type, Type0 t0, Type1 t1);
public:
  void AddCallBack(int type, TCallBackRegistrator0* pCB);

  template <typename Type0>
  void AddCallBack(int type, TCallBackRegistrator1<Type0>* pCB);

  template <typename Type0, typename Type1>
  void AddCallBack(int type, TCallBackRegistrator2<Type0, Type1>* pCB);
private:
  TDescCallBack* FindDesc(int type);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
template <typename F, class C>
void TMapCallBack::Register(int type, F f, C pObject)
{
  FindDesc(type)->Register(f, pObject);
}
//------------------------------------------------------------
template <typename Type0, typename F, class C>
void TMapCallBack::Register(int type, F f, C pObject)
{
  FindDesc(type)->Register<Type0>(f, pObject);
}
//------------------------------------------------------------
template <typename Type0,typename Type1, typename F, class C>
void TMapCallBack::Register(int type, F f, C pObject)
{
  FindDesc(type)->Register<Type0,Type1>(f, pObject);
}
//------------------------------------------------------------
template <typename Type0>
void TMapCallBack::Notify(int type, Type0 t0)
{
  FindDesc(type)->Notify<Type0>(t0);
}
//--------------------------------------------------------------
template <typename Type0,typename Type1>
void TMapCallBack::Notify(int type, Type0 t0, Type1 t1)
{
  FindDesc(type)->Notify<Type0, Type1>(t0, t1);
}
//--------------------------------------------------------------
template <typename Type0>
void TMapCallBack::AddCallBack(int type, TCallBackRegistrator1<Type0>* pCB)
{
  mMapTypeCallBack.insert(TMapIntDescCB::value_type(type,TDescCallBack()));
  FindDesc(type)->Set(pCB);
}
//--------------------------------------------------------------
template <typename Type0, typename Type1>
void TMapCallBack::AddCallBack(int type, TCallBackRegistrator2<Type0, Type1>* pCB)
{
  mMapTypeCallBack.insert(TMapIntDescCB::value_type(type,TDescCallBack()));
  FindDesc(type)->Set(pCB);
}
//--------------------------------------------------------------

#endif
