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
#include "LogicEventCallBack.h"

class DllExport TModuleLogic : public TModuleDev
{
	volatile bool flgNeedExit;
protected:
	TComponents mComp;
public:
	TModuleLogic();
	void SetComponents(TComponents components);
	TComponents* GetC();

	static TModuleLogic* Get();

	void Exit( int reason = 0);

	template <typename F>
	void CallBackModule(int id_module, F pFunc);
	template <typename F, class A1>
	void CallBackModule(int id_module, F pFunc, A1 pObject);
protected:
	bool NeedExit();
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
template <typename Func, class A1>
void TModuleLogic::CallBackModule(int id_module, Func pFunc, A1 pObject)
{
	TLogicEventCallBack* pLCB = new TLogicEventCallBack;
	pLCB->mCB.Register( pFunc, pObject );
	TSynchroAbonent::AddEventWithoutCopy(id_module, pLCB);
}
//---------------------------------------------------------------------------
#endif
