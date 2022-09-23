/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"

#include "IContext.h"

#include <ImGuiWidgets/include/DialogStack.h>
#include <GraphicEngine/GraphicEngineContext.h>

namespace nsTornadoEngine
{
    class DllExport TGraphicEngineContext : public IContext
    {
        nsImGuiWidgets::TDialogStack mDialogStack;

        nsGraphicEngine::TGraphicEngineContext* mGraphicEngineContext = nullptr;
    public:
        nsImGuiWidgets::TDialogStack* GetDialogStack();

        nsGraphicEngine::TGraphicEngineContext* GetGraphicEngineContext() const;
        void SetGraphicEngineContext(nsGraphicEngine::TGraphicEngineContext* pCtx);

    private:
    };
}