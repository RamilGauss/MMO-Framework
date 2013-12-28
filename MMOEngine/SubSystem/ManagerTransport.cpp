/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerTransport.h"

#include "ReciverTransport.h"
#include "IMakerTransport.h"
#include "INetTransport.h"
#include "BL_Debug.h"
#include "Logger.h"
#include "Base.h"
#include <boost/foreach.hpp>

using namespace nsMMOEngine;
using namespace std;

TManagerTransport::TManagerTransport(TManagerSession* pMS)
{
	mMakerTransport = NULL;
	mMngSession     = pMS;
}
//------------------------------------------------------------------------------------
TManagerTransport::~TManagerTransport()
{
	Done();
}
//------------------------------------------------------------------------------------
void TManagerTransport::SetTransport(IMakerTransport* pMT)
{
	mMakerTransport = pMT;
}
//------------------------------------------------------------------------------------
INetTransport* TManagerTransport::FindBySubNet( unsigned char v)
{
	TMapUcharPtrIt fit = mMapSubNetTransport.find(v);
	if(fit==mMapSubNetTransport.end())
	{
		GetLogger(STR_NAME_MMO_ENGINE)->
			WriteF_time("TManagerTransport::FindBySubNet(%u) not found.\n", v);
		BL_FIX_BUG();
		return NULL;
	}
	return fit->second;
}
//------------------------------------------------------------------------------------
INetTransport* TManagerTransport::FindByReciver( TReciverTransport* pRT)
{
	TMapPtrPtrIt fit = mMapReciverTransport.find(pRT);
	if(fit==mMapReciverTransport.end())
	{
		GetLogger(STR_NAME_MMO_ENGINE)->
			WriteF_time("TManagerTransport::FindByReciver(0x%X) not found.\n", pRT);
		BL_FIX_BUG();
		return NULL;
	}
	return fit->second;
}
//------------------------------------------------------------------------------------
INetTransport* TManagerTransport::Add(unsigned char subNet)
{
	BL_ASSERT(mMakerTransport);
	INetTransport* pTransport = mMakerTransport->New();
	TReciverTransport* pRT = new TReciverTransport(pTransport, mMngSession);

	mMapSubNetTransport. insert(TMapUcharPtr::value_type(subNet,pTransport));
	mMapReciverTransport.insert(TMapPtrPtr::value_type(pRT,pTransport));

	return pTransport;
}
//------------------------------------------------------------------------------------
void TManagerTransport::Done()
{
	BOOST_FOREACH(TMapPtrPtr::value_type& it, mMapReciverTransport)
	{
		it.second->Stop();// stop transport
		mMakerTransport->Delete(it.second);// transport
		
    delete it.first;// reciver
	}

  mMapSubNetTransport.clear();
  mMapReciverTransport.clear();
}
//------------------------------------------------------------------------------------
