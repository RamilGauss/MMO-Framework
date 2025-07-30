/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include <string>

#include "Base/Common/TypeDef.h"
#include "GraphicEngine/IRenderable.h"

#include "TornadoEngine/Modules/Gizmos/EntityViewer.h"
#include "TornadoEngine/Modules/Gizmos/SystemViewer.h"

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