/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Title.h"
#include "Visibility.h"
#include "IRenderable.h"

namespace nsImGuiWidgets
{
    class DllExport TToolTip : public nsGraphicEngine::IRenderable, public TTitle, public TVisibility
    {
    protected:
        void Render() override final;
    };
}
