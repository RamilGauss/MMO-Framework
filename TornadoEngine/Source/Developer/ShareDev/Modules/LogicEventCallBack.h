/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef LogicEventCallBackH
#define LogicEventCallBackH

#include "BaseLogicPacket.h"
#include "CallBackRegistrator.h"

struct DllExport TLogicEventCallBack0 : public TBaseLogicPacket
{
  TLogicEventCallBack0()
  {
    type = nsBaseLogicPacket::eCallBack0;
  }
  TCallBackRegistrator0 mCB; 
};
//-----------------------------------------------------------------
template < typename P >
struct DllExport TLogicEventCallBack1 : public TBaseLogicPacket
{
  P* pParam;

  TLogicEventCallBack1()
  {
    pParam = NULL;
    type = nsBaseLogicPacket::eCallBack1;
  }
  ~TLogicEventCallBack1()
  {
    delete pParam;
  }
  TCallBackRegistrator1<P> mCB; 
};
//-----------------------------------------------------------------
#endif
