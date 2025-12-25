/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ECS/Include/EntityManager.h"
#include "ECS/Include/Feature.h"
#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Configs/PathSetting.h"
#include "ContainerCodeGeneratorLib/Sources/Configs/CoreConfig.h"
#include "ContainerCodeGeneratorLib/Sources/Configs/ProjectConfig.h"

// Автоматизация
// Управляющий над кодогенератором для нужд ядра и проекта в редакторе.
// Настраивает задания для генератора, хранит изначальные настройки.
// В итоге утилита должна сгенерировать агрегатор для ядра.

namespace nsContainerCodeGenerator
{
    class DllExport TContainerCodeGenerator
    {
    protected:
        nsECSFramework::TEntityManager mEntMng;
        nsECSFramework::TFeature mMainFeature;
    public:
        enum Result : int
        {
            OK = 0,
            DEVELOPER_ERROR = 3,
            INNER_ERROR = 4,
        };

        TContainerCodeGenerator();
        virtual ~TContainerCodeGenerator();

        [[nodiscard]]
        virtual Result Generate(const TPathSetting& pathSetting, 
            const TCoreConfig& coreConfig, const TProjectConfig& projectConfig) = 0;

    protected:
        Result Execute();
    };
}