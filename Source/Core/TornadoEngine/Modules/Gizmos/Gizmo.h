/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <string>

#include "GraphicEngine/IRenderable.h"

#include "EntityViewer.h"
#include "SystemViewer.h"

namespace nsTornadoEngine
{
    class DllExport TGizmo
    {
        TEntityViewer mComponentViewer;
        TSystemViewer mSystemViewer;

    public:
        nsGraphicEngine::IRenderable* GetComponentViewer();
        nsGraphicEngine::IRenderable* GetSystemViewer();
    };
}