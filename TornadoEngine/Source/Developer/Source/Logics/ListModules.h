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
    ClientLogic,
    ServerLogicSlave,
    ServerLogicMaster,
    ServerLogicSuperServer,
    // auxiliary
    PhysicEngine, 
    SoundEngine,        // client
    DataBase,           // common
    Timer,              // common
  }ID_Modules;

// для именования модулей в конвейере для Ядра
// сделано так с целью присутствия в коде имени модуля единожды
#define NAME_MODULE(enumID) ""#enumID

}

#endif
