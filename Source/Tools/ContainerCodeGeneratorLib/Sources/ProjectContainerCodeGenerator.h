/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ContainerCodeGenerator.h"

#include "Systems/SetupConfig/Project/ConfigFeature.h"
#include "Systems/Aggregator/GeneratorFeature.h"
#include "Systems/Project/GeneratorFeature.h"

// Автоматизация
// Управляющий над кодогенератором для нужд ядра и проекта в редакторе.
// Настраивает задания для генератора, хранит изначальные настройки.
// В итоге утилита должна сгенерировать агрегатор для ядра.

namespace nsContainerCodeGenerator
{
    class DllExport TProjectContainerCodeGenerator : public TContainerCodeGenerator
    {
        nsSetupConfig::nsProject::TConfigFeature mSetupConfigFeature;
        nsProject::TGeneratorFeature         mProjectGeneratorFeature;
        nsAggregator::TGeneratorFeature      mAggregatorDumperFeature;

    public:
        [[nodiscard]]
        Result Generate(const std::string& filePath) override;
    };
}