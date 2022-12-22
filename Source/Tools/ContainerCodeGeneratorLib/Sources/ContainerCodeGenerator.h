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

#include "Systems/AggregatorDumper/AggregatorDumperFeature.h"
#include "Systems/Core/CoreGeneratorFeature.h"
#include "Systems/Project/ProjectGeneratorFeature.h"
#include "Systems/SetupConfig/SetupConfigFeature.h"

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

        TSetupConfigFeature      mSetupConfigFeature;
        TCoreGeneratorFeature    mCoreGeneratorFeature;
        TProjectGeneratorFeature mProjectGeneratorFeature;
        TAggregatorDumperFeature mAggregatorDumperFeature;

    public:
        enum Result : int
        {
            OK = 0,
            DEVELOPER_ERROR = 3,
            INNER_ERROR = 4,
        };

        TContainerCodeGenerator();

        [[nodiscard]]
        Result Generate(int argc, char** argv);

    private:
        void Init(int argc, char** argv);
    };
}