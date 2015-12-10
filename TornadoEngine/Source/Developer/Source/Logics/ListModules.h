/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ListModulesH
#define ListModulesH

// List of all modules and their ID
namespace nsListModules
{
  typedef enum
  {
    Undef               = 0,
    // visual
    GraphicEngine,      // client
    AloneGUI,           // server
    // network
    MMOEngineClient,
    MMOEngineSlave,
    MMOEngineMaster,
    MMOEngineSuperServer,
    // logic
    Logic,
    //ClientLogic,
    //ServerLogicSlave,
    //ServerLogicMaster,
    //ServerLogicSuperServer,
    // auxiliary
    PhysicEngine, 
    SoundEngine,        // client
    DataBase,           // common
    Timer,              // common
  }ID_Modules;
}

#endif
