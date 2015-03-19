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
    Undef         = 0,
    // visual
    GraphicEngine = 10,
    AloneGUI,
    // network
    MMOEngineClient,
    MMOEngineSlave,
    MMOEngineMaster,
    MMOEngineSuperServer,
    // auxiliary
    PhysicEngine,
    SoundEngine,
    DataBase,
    Timer,
    // server logic (add if need more logics)
    ServerLogicSlave,
    ServerLogicMaster,
    ServerLogicSuperServer,
  }ID_Modules;

// для именования модулей в конвейере для Ядра
// сделано так с целью присутствия в коде имени модуля единожды
#define NAME_MODULE(enumID) "Name"#enumID

}

#endif
