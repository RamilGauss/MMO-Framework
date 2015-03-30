/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleServerLogicSuperServer_Dev.h"
#include "SuperServerForm.h"
#include "ListModules.h"


TModuleServerLogicSuperServer_Dev::TModuleServerLogicSuperServer_Dev()
{
	mSuperServerForm = NULL;
}
//------------------------------------------------------------------------------
bool TModuleServerLogicSuperServer_Dev::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::EndWork()
{

}
//------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::Input(int id, void* p, int size)
{
	switch(id)
	{
		case nsListModules::AloneGUI:
			break;
		case nsListModules::MMOEngineSuperServer:
			break;
		case nsListModules::Timer:
		{
			// события от таймера
			int a = 0;
		}
		break;
	}
}
//------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::InitForms()
{
	mSuperServerForm = new TSuperServerForm;
	mSuperServerForm->show();
}
//------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::StartEvent()
{
	CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSuperServer_Dev::InitForms);
}
//----------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::StopEvent()
{

}
//----------------------------------------------------------
