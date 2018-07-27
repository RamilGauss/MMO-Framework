/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include "IMakerTransport.h"

class DllExport TMakerNetTransport : public nsMMOEngine::IMakerTransport
{
public:
  virtual nsMMOEngine::INetTransport* New();
  virtual void Delete(nsMMOEngine::INetTransport* pTransport);
};
