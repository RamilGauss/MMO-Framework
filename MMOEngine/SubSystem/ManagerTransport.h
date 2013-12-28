/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MANAGER_TRANSPORT_H
#define MANAGER_TRANSPORT_H

#include <map>

class INetTransport;

namespace nsMMOEngine
{
	class TReciverTransport;
	class IMakerTransport;
	class TManagerSession;
  class TManagerTransport
  {
		typedef std::map<unsigned char,INetTransport*> TMapUcharPtr;
		typedef TMapUcharPtr::iterator TMapUcharPtrIt;
	
		typedef std::map<TReciverTransport*,INetTransport*> TMapPtrPtr;
		typedef TMapPtrPtr::iterator TMapPtrPtrIt;

		TMapUcharPtr mMapSubNetTransport;
		TMapPtrPtr   mMapReciverTransport;

		IMakerTransport* mMakerTransport;
		TManagerSession* mMngSession;

  public:
    TManagerTransport(TManagerSession* pMS);
    ~TManagerTransport();

		void SetTransport(IMakerTransport* pMT);

		INetTransport* FindBySubNet( unsigned char v);
		INetTransport* FindByReciver( TReciverTransport* pRT);

		INetTransport* Add(unsigned char subNet);
	private:

		void Done();
  };
}

#endif