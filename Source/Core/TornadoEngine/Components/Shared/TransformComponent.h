/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ECS/include/IComponent.h>
#include <GraphicEngine/RenderableObject.h>

#include "MathStructs.h"
#include "PropertyOf.h"

namespace nsCommonWrapper
{
    struct DllExport TTransformComponent : nsTornadoEngine::TPropertyOf<nsGraphicEngine::TRenderableObject>, nsECSFramework::IComponent
    {
        nsMathTools::TMatrix16 value;
    };
}