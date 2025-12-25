/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ContainerCodeGeneratorLib/Sources/ContainerCodeGenerator.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Core/GeneratorFeature.h"

// Автоматизация
// Управляющий над кодогенератором для нужд ядра и проекта в редакторе.
// Настраивает задания для генератора, хранит изначальные настройки.
// В итоге утилита должна сгенерировать агрегатор для ядра.

namespace nsContainerCodeGenerator
{
    class DllExport TCoreContainerCodeGenerator : public TContainerCodeGenerator
    {
        nsCore::TGeneratorFeature         mCoreGeneratorFeature;
    public:
        [[nodiscard]]
        Result Generate(const TPathSetting& pathSetting, 
            const TCoreConfig& coreConfig, const TProjectConfig& projectConfig);
    };
}