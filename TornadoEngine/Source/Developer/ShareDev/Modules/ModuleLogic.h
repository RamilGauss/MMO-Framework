/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleLogicH
#define ModuleLogicH

#include "ModuleDev.h"
#include "Components.h"

class DllExport TModuleLogic : public TModuleDev
{
protected:
	TComponents mComp;
public:
	void SetComponents(TComponents components);
};

#endif
