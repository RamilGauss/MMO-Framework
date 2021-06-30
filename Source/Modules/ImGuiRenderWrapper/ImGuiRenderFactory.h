/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsImGuiRenderWrapper
{
    class IImGuiRender;

    enum class Implementation
    {
        DIRECTX_9,
        DIRECTX_10,
        DIRECTX_11,
        DIRECTX_12,
        OPEN_GL_2,
        OPEN_GL_3,
    };
    class DllExport TImGuiRenderFactory
    {
    public:
        static IImGuiRender* Make(Implementation implementaion);
        static void Done(IImGuiRender* render);
    };
}