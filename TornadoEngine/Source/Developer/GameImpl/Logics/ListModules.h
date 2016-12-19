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
    // auxiliary
    PhysicEngine, 
    SoundEngine,        // client
    DataBase,           // common
    Timer,              // common

    // сама логика себе ничего не присылает, значит другие модули (например, MyGUI из потока графики)
    // смогут отправить событие Логике только через этот идентификатор
    // для понимания этого - Логика дает квант другим модулям из своих функций, модули дают Логике пакеты-события.
    FromSomeToLogic = Logic,// if wants send event from unusual source, such as GUI etc.
  }ID_Modules;
}

#endif
