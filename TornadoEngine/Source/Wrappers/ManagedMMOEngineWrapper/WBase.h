/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WrapperMMOEngineBaseH
#define WrapperMMOEngineBaseH

#include "WIP_Port.h"

//class IMakerTransport;
//class TDstEvent;

//namespace nsMMOEngine
//{
//  class TBase;
//}

namespace WrapperMMOEngine
{
  class WDescOpen;
  //class WBaseEvent;

  public ref class WBase
  {
    //nsMMOEngine::TBase* mBase;
    //IMakerTransport* mMakerTransport;

    //TDstEvent* mDstEvent;
  public:
    WBase( /*nsMMOEngine::TBase* pBase*/ );
    virtual ~WBase();

    void Init();
    bool Open( WDescOpen* pDesc, int count );
    void DisconnectUp();
    void SendUp( char* p, int size, bool check );
    void Work();
    bool IsConnectUp();
    bool IsConnect( unsigned int id );
    void SetLoad( int procent );
    void SetTimeLiveSession( unsigned int time_ms );
    bool GetInfoSession( unsigned int id_session, WIP_Port^ ip_port );
  public:
    //WBaseEvent* GetEvent();
  protected:
    //nsMMOEngine::TBase* GetBase();
  };
}

#endif