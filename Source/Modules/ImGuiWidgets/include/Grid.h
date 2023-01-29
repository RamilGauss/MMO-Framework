/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <unordered_map>

#include "TypeDef.h"

#include "imgui.h"

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

        virtual void AddCellInGrid(const TCell& cell);
        virtual void RemoveCellInGrid(TUnit* p);

        virtual int GetHorizontalCellCount() const;
        virtual int GetVerticalCellCount() const;

    protected:

        int mWidth = 0;
        int mHeight = 0;

        std::unordered_map<int, TCell> mCells;
    private:

        void InitCells();
    };
}
