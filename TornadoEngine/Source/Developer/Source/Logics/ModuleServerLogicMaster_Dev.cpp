/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleServerLogicMaster_Dev.h"
#include "MasterForm.h"
#include "ListModules.h"

TModuleServerLogicMaster_Dev::TModuleServerLogicMaster_Dev()
{
  mMasterForm = NULL;
}
//------------------------------------------------------------------------------
bool TModuleServerLogicMaster_Dev::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::EndWork()
{

}
//------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::Input(int id, void* p, int size)
{
  switch(id)
  {
    case nsListModules::AloneGUI:
      break;
    case nsListModules::MMOEngineMaster:
      break;
    case nsListModules::DataBase:
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
void TModuleServerLogicMaster_Dev::InitForms()
{
  mMasterForm = new TMasterForm;
  mMasterForm->show();
}
//------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::StartEvent()
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicMaster_Dev::InitForms);
}
//----------------------------------------------------------
void TModuleServerLogicMaster_Dev::StopEvent()
{

}
//----------------------------------------------------------
