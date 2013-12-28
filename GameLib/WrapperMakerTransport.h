/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WRAPPER_MAKER_TRANSPORT_H
#define WRAPPER_MAKER_TRANSPORT_H

#include "IMakerTransport.h"
#include "MakerNetTransport.h"

class TWrapperMakerTransport : public nsMMOEngine::IMakerTransport
{
  TMakerNetTransport_Boost maker;
public:
	TWrapperMakerTransport();
	virtual ~TWrapperMakerTransport();

	virtual INetTransport* New();
	virtual void Delete(INetTransport* pTransport);
};

#endif