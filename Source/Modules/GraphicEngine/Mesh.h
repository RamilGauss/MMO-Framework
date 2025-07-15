/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "Base/Common/TypeDef.h"

namespace nsGraphicEngine
{
    class DllExport TMesh
    {
        std::vector<float> mVertices;
    public:
        const float* GetPointData() const;
        int GetPointCount() const;
        int GetDataSize() const;

        struct TPoint
        {
            float x;
            float y;
            float z;

            float u;
            float v;
        };

        void AddPoint(const TPoint& point);
    };
}
