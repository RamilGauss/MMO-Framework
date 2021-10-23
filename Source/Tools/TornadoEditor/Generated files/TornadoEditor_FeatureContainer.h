/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "FeatureContainer.h"

namespace nsTornadoEditor
{
    struct DllExport TTornadoEditor_FeatureContainer : public nsTornadoEngine::TFeatureContainer
    {
        TTornadoEditor_FeatureContainer();
        virtual ~TTornadoEditor_FeatureContainer();
    };
}