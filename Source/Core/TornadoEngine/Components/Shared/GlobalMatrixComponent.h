/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"
#include "GraphicEngine/RenderableObject.h"

#include "TornadoEngine/Share/MathStructs.h"
#include "TornadoEngine/Share/PropertyOf.h"

namespace nsCommonWrapper
{
    struct DllExport TGlobalMatrixComponent : 
        nsTornadoEngine::TPropertyOf<nsGraphicEngine::TRenderableObject>, nsECSFramework::IComponent
    {
        nsMathTools::TMatrix16 value;
    };
}