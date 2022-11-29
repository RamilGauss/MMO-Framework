/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <ECS/include/EntityManager.h>
#include <ECS/include/Feature.h>
#include <ECS/include/Helper.h>

#include "Config.h"
#include "SetupConfig.h"

#include "Systems/ConfigLoaderSystem.h"
#include "Systems/CoreGeneratorFeature.h"
#include "Systems/ProjectGeneratorFeature.h"
#include "Systems/AggregatorDumperFeature.h"

// Автоматизация
// Управляющий над кодогенератором для нужд ядра и проекта в редакторе.
// Настраивает задания для генератора, хранит изначальные настройки.
// В итоге утилита должна сгенерировать агрегатор для ядра.

namespace nsContainerCodeGenerator
{
    class DllExport TContainerCodeGenerator
    {
        nsECSFramework::TEntityManager mEntMng;
        nsECSFramework::TFeature mMainFeature;

        TConfigLoaderSystem mConfigLoaderSystem;
        TCoreGeneratorFeature mCoreGeneratorFeature;
        TProjectGeneratorFeature mProjectGeneratorFeature;
        TAggregatorDumperFeature mAggregatorDumperFeature;

        TSetupConfig mSetupConfig;

    public:
        enum class Result
        {
            OK,
            NOT_FOUND_CONFIG,
            INNER_ERROR,
            PARSER_ERROR,
        };

        TContainerCodeGenerator();

        [[nodiscard]]
        bool Init(int argc, char** argv);

        [[nodiscard]]
        Result Generate();
    };
}