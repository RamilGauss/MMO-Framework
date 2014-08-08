/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MapCallBack.h"
#include "BL_Debug.h"

//--------------------------------------------------------------
TMapCallBack::TMapCallBack()
{

}
//--------------------------------------------------------------
TMapCallBack::~TMapCallBack()
{

}
//--------------------------------------------------------------
TDescCallBack* TMapCallBack::FindDesc(int type)
{
  TMapIntDescCBIt fit = mMapTypeCallBack.find(type);
  if(fit==mMapTypeCallBack.end())
  {
    BL_FIX_BUG();
    return NULL;
  }
  return &(fit->second);
}
//--------------------------------------------------------------
void TMapCallBack::AddCallBack(int type, TCallBackRegistrator0* pCB)
{
  mMapTypeCallBack.insert(TMapIntDescCB::value_type(type,TDescCallBack()));
  FindDesc(type)->Set(pCB);
}
//--------------------------------------------------------------
void TMapCallBack::Notify(int type)
{
  FindDesc(type)->Notify();
}
//--------------------------------------------------------------
