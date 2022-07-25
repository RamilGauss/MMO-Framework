/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    class TUnit;

    struct DllExport TGrid
    {
    public:

        struct TCellPosition
        {
            int x = 0;
            int y = 0;
        };

        struct TCellSize
        {
            int width = 0;
            int height = 0;
        };

        struct TCell
        {
            TUnit* p = nullptr;
            TCellPosition pos;
            TCellSize size;
        };

        virtual void Begin();
        virtual void AddCell(const TCell& cell);
        virtual void End();

    protected:

        std::list<TCell> mCells;

        int mWidth = 0;
        int mHeight = 0;
    };
}
