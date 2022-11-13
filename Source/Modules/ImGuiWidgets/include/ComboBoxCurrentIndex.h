/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TComboBoxCurrentIndex
    {
    public:
        virtual int GetCurrentIndex() const;
        virtual void SetCurrentIndex(int value);
    private:
        int mCurrentIndex = -1;
    };
}
