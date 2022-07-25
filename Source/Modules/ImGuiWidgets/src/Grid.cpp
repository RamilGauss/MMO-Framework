/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Grid.h"

namespace nsImGuiWidgets
{
    void TGrid::Begin()
    {
        mCells.clear();
        mWidth = 0;
        mHeight = 0;
    }
    //-----------------------------------------------------------------------------------
    void TGrid::AddCell(const TCell& cell)
    {
        mCells.push_back(cell);
    }
    //-----------------------------------------------------------------------------------
    void TGrid::End()
    {
        for (auto& cell : mCells) {
            auto w = cell.pos.x + cell.size.width;
            mWidth = std::max(mWidth, w);

            auto h = cell.pos.y + cell.size.height;
            mHeight = std::max(mHeight, h);
        }
    }
    //-----------------------------------------------------------------------------------
}
