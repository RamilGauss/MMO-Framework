/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

// List of all modules and their ID
namespace nsListModules
{
    enum ID_Modules
    {
        Undef = 0,
        // visual
        GraphicEngine,      // client
        //AloneGUI,         // server have not gui
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
    };
}
