/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HandlerMMOH
#define HandlerMMOH

#include "DstEvent.h"
#include "Master.h"
#include "Slave.h"
#include "BaseEvent.h"

class THandlerMMO : public TDstEvent
{
  nsMMOEngine::TMaster* mMaster;
  nsMMOEngine::TSlave*  mSlave;

  int mCountConnection;
public:
  THandlerMMO();
  void SetServerMMO(nsMMOEngine::TMaster* pMaster, 
                    nsMMOEngine::TSlave* pSlave);
  void Work();
protected:
  void HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE);
  std::string GetStrError(int code);
};

#endif
