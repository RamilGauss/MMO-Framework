/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Grid.h"

#include "Unit.h"

namespace nsImGuiWidgets
{
    void TGrid::BeginAddingInGrid()
    {
        mCells.clear();
        mWidth = 0;
        mHeight = 0;
    }
    //-----------------------------------------------------------------------------------
    void TGrid::AddCellInGrid(const TCell& cell)
    {
        mCells.push_back(cell);
    }
    //-----------------------------------------------------------------------------------
    void TGrid::EndAddingInGrid()
    {
        for (auto& cell : mCells) {
            auto w = cell.pos.x + cell.size.width;
            mWidth = std::max(mWidth, w);

            auto h = cell.pos.y + cell.size.height;
            mHeight = std::max(mHeight, h);

            auto& addedCell = mCells.back();
        }
    }
    //-----------------------------------------------------------------------------------
    int TGrid::GetHorizontalCellCount() const
    {
        return mWidth;
    }
    //-----------------------------------------------------------------------------------
    int TGrid::GetVerticalCellCount() const
    {
        return mHeight;
    }
    //-----------------------------------------------------------------------------------
}
