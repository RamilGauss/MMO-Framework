/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HandlerMMOH
#define HandlerMMOH

#include "DstEvent.h"
#include "BaseEvent.h"
#include <set>

class THandlerMMO : public TDstEvent
{
public:
  enum TypeMMO{eClient, eSlave, eMaster, eSuperServer};

  THandlerMMO( TypeMMO type );
  void Work();

  virtual void WorkInherit()
  {};

  auto GetCountConnection();

  void AddConnection( unsigned int sessionID );
  void RemoveConnection( unsigned int sessionID );

  void AddClient( unsigned int clientID );
  void RemoveClient( unsigned int clientID ); 

  void AddTryConnectClientToMaster( unsigned int sessionID );
protected:
  virtual void HandleFromMMOEngine( nsEvent::TEvent* pEvent ) = 0;
public:
  static void PrintCC( const char* loggerName );
private:
  TypeMMO mType;
};

#endif
