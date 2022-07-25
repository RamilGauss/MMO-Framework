/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "ProtoFrame.h"
#include "Events.h"
#include "CallbackPool.h"
#include "Padding.h"
#include "Grid.h"

namespace nsImGuiWidgets
{
    class DllExport TFrame : public TProtoFrame, public TPadding, public TGrid
    {
    public:
        TFrame();

        void SetUseGrid(bool value);
        bool GetUseGrid() const;

    protected:

        void BeforeBeginRender() override;

        ImVec2 GetChildMinSize() const override;
        ImVec2 GetChildMaxSize() const override;

    private:
        bool mIsUsedGrid = false;
    };
}
