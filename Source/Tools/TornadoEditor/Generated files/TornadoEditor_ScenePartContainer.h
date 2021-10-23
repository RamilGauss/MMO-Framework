/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ScenePartContainer.h"

namespace nsTornadoEditor
{
    struct DllExport TTornadoEditor_ScenePartContainer : public nsTornadoEngine::TScenePartContainer
    {
        TTornadoEditor_ScenePartContainer();
        virtual ~TTornadoEditor_ScenePartContainer();
    };
}