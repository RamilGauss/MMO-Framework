/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "HandlerMMO.h"
#include "ClientDesc.h"
#include <set>

class THandlerMMO_Client : public THandlerMMO
{
public:
  typedef std::map<nsMMOEngine::TClient*, TClientDesc*> TPtrPtrMap;
  typedef TPtrPtrMap::value_type TPtrPtrMapVT;

  std::vector<TClientDesc*> mArrClient;

  TPtrPtrMap mClientDescMap;

  unsigned int mBestPing  = 0xFFFFFFFF;
  unsigned int mWorthPing = 0;
  unsigned int mPingSumma = 0;
  int mPingCounter = 0;

  THandlerMMO_Client();
protected:
  virtual void HandleFromMMOEngine( nsEvent::TEvent* pEvent );

  virtual void WorkInherit() override;
};
