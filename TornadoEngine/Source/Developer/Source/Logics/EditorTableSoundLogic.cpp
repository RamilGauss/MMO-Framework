/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorTableSoundLogic.h"
#include "ListModules.h"
#include "Logger.h"

#include "ModuleTimer.h"
#include "ModuleGraphicEngine.h"
#include "ModulePhysicEngine.h"

TEditorTableSoundLogic::TEditorTableSoundLogic()
{

}
//-------------------------------------------------------------------
TEditorTableSoundLogic::~TEditorTableSoundLogic()
{

}
//-------------------------------------------------------------------
void TEditorTableSoundLogic::StartEvent()
{
	CallBackModule(nsListModules::Timer, &TEditorTableSoundLogic::StartTimer);
	CallBackModule(nsListModules::GraphicEngine, &TEditorTableSoundLogic::InitForms);

	CallBackModule(nsListModules::PhysicEngine, &TEditorTableSoundLogic::InitPhysic);

	mComp.pGraphicEngine->GetCBBeginWork()->Register( &TEditorTableSoundLogic::GraphicBeginWork ,this);

	mComp.pGraphicEngine->GetCBStopEvent()->Register( &TEditorTableSoundLogic::FreeGraphicResource,this);

	mComp.pPhysicEngine->GetCBBeginWork()->Register( &TEditorTableSoundLogic::PhysicBeginWork ,this);
	mComp.pPhysicEngine->GetCBEndWork()->Register( &TEditorTableSoundLogic::PhysicEndWork ,this);
}
//-------------------------------------------------------------------
void TEditorTableSoundLogic::InitLog()
{
	GetLogger()->Register("Inner");// для логирования внутренних событий
	GetLogger()->Init("EditorTableSound");
}
//-------------------------------------------------------------------
bool TEditorTableSoundLogic::WorkClient()
{
	return true;
}
//-------------------------------------------------------------------
void TEditorTableSoundLogic::Input(int id_sender, void* p, int size)
{
	switch(id_sender)
	{
		case nsListModules::GraphicEngine:
			break;
		case nsListModules::PhysicEngine:
			break;
		case nsListModules::Timer:
			break;
		default:BL_FIX_BUG();
	}
}
//-------------------------------------------------------------------
void TEditorTableSoundLogic::StartTimer()
{
	// вызовется из потока таймера
	unsigned int mID_Timer = mComp.pTimer->New(10);
}
//----------------------------------------------------------
void TEditorTableSoundLogic::InitForms()
{
	//mDebugPanel = new TDebugPanel;
	//mDebugPanel->Show();
}
//----------------------------------------------------------
void TEditorTableSoundLogic::PhysicEndWork()
{

}
//---------------------------------------------------------------------------------------------
void TEditorTableSoundLogic::InitPhysic()
{

}
//---------------------------------------------------------------------------------------------
void TEditorTableSoundLogic::GraphicBeginWork()
{

}
//---------------------------------------------------------------------------------------------
void TEditorTableSoundLogic::PhysicBeginWork()
{

}
//---------------------------------------------------------------------------------------------
void TEditorTableSoundLogic::FreeGraphicResource()
{
	//delete mClientMain;
	//delete mDebugPanel;
}
//---------------------------------------------------------------------------------------------
