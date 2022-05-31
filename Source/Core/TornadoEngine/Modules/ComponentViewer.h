/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "GraphicEngine/IRenderable.h"

namespace nsTornadoEngine
{
    class DllExport TComponentViewer : public nsGraphicEngine::IRenderable
    {
    public:
        void Render() override;
    };
}