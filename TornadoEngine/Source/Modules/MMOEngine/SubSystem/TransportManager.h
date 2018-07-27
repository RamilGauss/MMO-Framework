/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <map>

namespace nsMMOEngine
{
  class INetTransport;
  class IMakerTransport;
  class TReceiverTransport;
  class TSessionManager;
  class TTransportManager
  {
    typedef std::map<unsigned char,INetTransport*> TMapUcharPtr;
    typedef TMapUcharPtr::iterator TMapUcharPtrIt;
  
    typedef std::map<TReceiverTransport*,INetTransport*> TMapPtrPtr;
    typedef TMapPtrPtr::iterator TMapPtrPtrIt;

    TMapUcharPtr mMapSubNetTransport;
    TMapPtrPtr   mMapReciverTransport;

    IMakerTransport* mMakerTransport;
    TSessionManager* mMngSession;

  public:
    TTransportManager(TSessionManager* pMS);
    ~TTransportManager();

    void SetTransport(IMakerTransport* pMT);

    INetTransport* FindBySubNet( unsigned char v);
    INetTransport* FindByReciver( TReceiverTransport* pRT);

    INetTransport* Add(unsigned char subNet);
  private:

    void Done();
  };
}
