/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Widget.h"
#include "WidgetContainer.h"

namespace nsImGuiWidgets
{
    class TPopupNode;
    class DllExport TPopupMenu : public nsGraphicEngine::IRenderable, public TWidgetContainer
    {
        static int mLastId;
        int mId;

        bool mIsOpen = false;
    public:
        TPopupMenu();
        void Open();
    protected:
        void Render() override final;
    };
}
