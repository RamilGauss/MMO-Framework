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
protected:
	template <typename F>
	void CallBackModule(int id_module, F pFunc);
};
//---------------------------------------------------------------------------
template <typename Func>
void TModuleLogic::CallBackModule(int id_module, Func pFunc)
{
	TLogicEventCallBack* pLCB = new TLogicEventCallBack;
	pLCB->mCB.Register( pFunc, this );
	TSynchroAbonent::AddEventWithoutCopy(id_module, pLCB);
}
//---------------------------------------------------------------------------
#endif
