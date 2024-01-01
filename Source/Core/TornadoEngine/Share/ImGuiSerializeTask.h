/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ImGuiWidgets/include/Frame.h"

namespace nsTornadoEngine
{
    class DllExport TImGuiSerializeTask
    {
    public:
        enum class Mode
        {
            READ,
            READ_WRITE,
            READ_DELETE,
            READ_WRITE_DELETE,
        };
        Mode GetMode() const;
        void SetMode(Mode mode);

        TCallbackPool<nsImGuiWidgets::TFrame*> writeEvent;
        TCallbackPool<nsImGuiWidgets::TFrame*> closeEvent;

        nsImGuiWidgets::TFrame* GetFrame();

        int GetRtti() const;
        void SetRtti(int rtti);
    private:
        nsImGuiWidgets::TFrame mFrame;
        Mode mMode = Mode::READ;
        int mRtti = -1;
    };
}