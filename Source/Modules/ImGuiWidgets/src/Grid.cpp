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
    void TGrid::AddCellInGrid(const TCell& cell)
    {
        const int id = cell.p->GetId();

        mCells.insert({ id, cell });

        InitCells();
    }
    //-----------------------------------------------------------------------------------
    void TGrid::RemoveCellInGrid(TUnit* p)
    {
        const int id = p->GetId();

        mCells.erase(id);

        InitCells();
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
    void TGrid::InitCells()
    {
        for (auto& it : mCells) {
            auto& cell = it.second;

            auto w = cell.pos.x + cell.size.width;
            mWidth = std::max(mWidth, w);

            auto h = cell.pos.y + cell.size.height;
            mHeight = std::max(mHeight, h);
        }
    }
}
