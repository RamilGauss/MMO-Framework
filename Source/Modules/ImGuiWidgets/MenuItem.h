/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <functional>

#include "Widget.h"

namespace nsImGuiWidgets
{
    class DllExport TMenuItem : public TWidget
    {
    public:
        TMenuItem(const std::string& menu, const std::string& name);

        using TCallback = std::function<void(TMenuItem*)>;

        void SetCallback(TCallback callback);
        void SetSelected(bool value);
    protected:
        TCallback mCallback;

        std::string mMenu;

        bool mSelected = false;
        bool mEnabled = true;

        void RenderInheritance() override final;
    };
}
