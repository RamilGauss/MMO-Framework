/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <functional>

#include "Node.h"

namespace nsImGuiWidgets
{
    class DllExport TMenuNode : public TNode
    {
    public:
        using TCallback = std::function<void(TMenuNode*)>;

        void SetCallback(TCallback callback);
        void SetSelected(bool value);
    protected:
        TCallback mCallback;

        std::string mMenu;

        bool mSelected = false;
        bool mEnabled = true;

        void Render() override final;
    };
}
