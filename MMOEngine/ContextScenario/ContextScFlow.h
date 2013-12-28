/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTEXT_SC_FLOW_H
#define CONTEXT_SC_FLOW_H

#include "IContextScenario.h"
#include "BreakPacket.h"

namespace nsMMOEngine
{
  // сценарии, содержащиеся в контейнере взаимно блокируются
  class TContextScFlow : public IContextScenario
	{
    struct TSavePacket
    {
      TBreakPacket bp;
      bool check;
      TContainer c;
    };

    typedef std::list<TSavePacket*> TListPtr;
    TListPtr mListSave;

	public:
		TContextScFlow();
    virtual ~TContextScFlow();

    void Send( TBreakPacket& bp, bool check);
    void SaveBreakPacket(TBreakPacket& bp, bool check);
    void SendAndRemoveFirst();
  private:
    void Done();
	};
}  
#endif