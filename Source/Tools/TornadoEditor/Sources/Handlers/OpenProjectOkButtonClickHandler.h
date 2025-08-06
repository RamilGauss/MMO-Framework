/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/Handlers/Gui/IButtonClickHandler.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfig.h"

namespace nsTornadoEditor
{
    class DllExport TOpenProjectOkButtonClickHandler : public nsGuiWrapper::IButtonClickHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pC) override;

    private:
        bool LoadProjectConfig(const std::string& absPath, 
            nsTornadoEngine::TProjectConfig& projectConfig, std::string& err);
    };
}
