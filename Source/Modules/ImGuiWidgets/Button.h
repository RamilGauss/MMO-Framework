/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Widget.h"

#include <functional>

namespace nsImGuiWidgets
{
    class TButton : public TWidget
    {
    public:
        TButton(const std::string& name) : TWidget(name) {}

        using TCallback = std::function<void(TButton*)>;

        void SetCallback(TCallback cb)
        {
            mCallback = cb;
        }
    protected:
        void RenderInheritance() override final
        {
            if (ImGui::Button(GetName())) {
                if (mCallback) {
                    mCallback(this);
                }
            }
        }

        TCallback mCallback;
    };
}
