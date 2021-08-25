/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>
#include <functional>

#include "imgui.h"
#include "Typedef.h"

#include "Node.h"

namespace nsImGuiWidgets
{
    class TTreeView;

    class DllExport TTreeNode : public TNode
    {
    public:
        void Render() override;

    private:
        void SearchEvents();
    };
}
