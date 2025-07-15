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
#include "Base/Common/TypeDef.h"

#include "ImGuiWidgets/Include/Node.h"

namespace nsImGuiWidgets
{
    class DllExport TPopupNode : public TNode
    {
    public:
        void Render() override final;
    };
}
