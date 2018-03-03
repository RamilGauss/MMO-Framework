/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTEXT_SC_SEND_TO_CLIENT_H
#define CONTEXT_SC_SEND_TO_CLIENT_H

#include "IScenarioContext.h"
#include "BreakPacket.h"
#include <list>

namespace nsMMOEngine
{
  // сценарии, содержащиеся в контейнере взаимно блокируются
  class TContextScSendToClient : public IScenarioContext
  {
    struct TSavePacket
    {
      TContainer c;
    };

    typedef std::list<TSavePacket*> TListPtr;
    TListPtr mListSave;

  public:
    TContextScSendToClient();
    virtual ~TContextScSendToClient();

    void SaveBreakPacket(TBreakPacket& bp);
    void SendAndRemoveFirst();

  private:
    void Done();
  };
}  
#endif