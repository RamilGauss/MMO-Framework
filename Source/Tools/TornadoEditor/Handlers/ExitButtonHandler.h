/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IButtonClickHandler.h"

#include "Modules.h"
#include "StopAccessor.h"
#include "SceneManager.h"

namespace nsTornadoEditor
{
    class DllExport TExitButtonClickHandler : public nsGuiWrapper::IButtonClickHandler
    {
    public:
        void Handle() override 
        {
            nsTornadoEngine::Modules()->SceneMng()->Unload("first scene");
            //nsTornadoEngine::Modules()->StopAccessor()->SetStop();
        }
    };
}