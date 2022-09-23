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
    class DllExport TSystemViewer : public nsGraphicEngine::IRenderable
    {
        double mLastTimeUpdateModel = 0;
    public:
        void Render() override;
    protected:
        void UpdatelModel();
        void RenderModel();
        void RenderFilterSearching();

        bool mIsNeedInited = true;
        void Init();
    };
}