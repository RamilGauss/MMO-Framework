/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <map>
#include <array>
#include <list>

#include "TypeDef.h"

#include <functional>

namespace nsGraphicEngine
{
    class TMesh;

    class DllExport TMeshFactory
    {
    public:
        [[nodiscard]]
        static TMesh* CreateEmpty();
        [[nodiscard]]
        static TMesh* CreateCube(float size);
        [[nodiscard]]
        static TMesh* CreatePlate(float height, float width, float depth);
        [[nodiscard]]
        static TMesh* CreateSphere(float radius, int pointCount = 1000);
        [[nodiscard]]
        static TMesh* CreateCone(float height, float radius, int pointCount = 1000);
        [[nodiscard]]
        static TMesh* CreateCylinder(float height, float radius, int pointCount = 1000);
        
        static void Destroy(TMesh* pMesh);
    private:
    };
}
