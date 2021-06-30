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
    class TWindow : public TWidget
    {
    public:
        TWindow(const std::string& name) : TWidget(name) {}

        void PushWidget(TWidget* pWidget)
        {
            mChildList.push_back(pWidget);
        }

        void ClearWidgets()
        {
            mChildList.clear();
        }
    protected:
        std::list<TWidget*> mChildList;

        void RenderInheritance() override
        {
            ImGui::Begin(mName.c_str(), &mIsShown);

            for (auto& child : mChildList) {
                child->Render();
            }

            ImGui::End();
        }
    };
}
