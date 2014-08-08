/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeServerH
#define PrototypeServerH

#include "PrototypeBaseModule.h"

class DllExport PrototypeServer : public PrototypeBaseModule
{
public:
  PrototypeServer();
  virtual ~PrototypeServer();
	virtual int GetVersionPrototype();
};

#endif
