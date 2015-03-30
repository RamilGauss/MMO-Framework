/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleServerLogicSlave_Dev.h"
#include "ListModules.h"
#include "SlaveForm.h"

TModuleServerLogicSlave_Dev::TModuleServerLogicSlave_Dev()
{
  SetCycleTime(eCycleTime);

  mSlaveForm = NULL;
}
//------------------------------------------------------------------------------
bool TModuleServerLogicSlave_Dev::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::EndWork()
{

}
//------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::Input(int id, void* p, int size)
{
  switch(id)
  {
    case nsListModules::AloneGUI:
      break;
    case nsListModules::MMOEngineSlave:
      break;
    case nsListModules::PhysicEngine:
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
void TModuleServerLogicSlave_Dev::InitForms()
{
  mSlaveForm = new TSlaveForm;
  mSlaveForm->show();
}
//------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::StartEvent()
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSlave_Dev::InitForms);
}
//----------------------------------------------------------
void TModuleServerLogicSlave_Dev::StopEvent()
{

}
//----------------------------------------------------------
