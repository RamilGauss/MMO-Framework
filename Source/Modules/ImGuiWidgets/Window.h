/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include "Widget.h"

namespace nsImGuiWidgets
{
    class DllExport TWindow : public TWidget
    {
    public:
        TWindow(const std::string& name);

        void PushWidget(TWidget* pWidget);

        void ClearWidgets();
    protected:
        std::list<TWidget*> mChildList;

        void RenderInheritance() override;
    };
}
