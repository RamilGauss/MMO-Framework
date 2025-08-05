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

#include "ContainerCodeGeneratorLib/Sources/Config.h"

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
        virtual Result Generate(const std::string& filePath) = 0;

    protected:
        void CreateSingleEntity(const std::string& filePath);

        Result Execute();
    };
}