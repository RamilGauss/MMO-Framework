/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeListToHandlerListSystem.h"

#include <filesystem>

#include <TextFile.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include <Parser/Sources/Parser.h>

#include "Components/ConfigComponent.h"
#include "Components/HandlerListComponent.h"
#include "Components/TypeListComponent.h"

namespace nsContainerCodeGenerator::nsProject::nsHandler
{
    void TTypeListToHandlerListSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto typeListComponent = nsECSFramework::SingleComponent<TTypeListComponent>(mEntMng);

        THandlerListComponent handlerListComponent;

        auto baseHandlerTypeName = configComponent->value.baseHandlerTypeName;

        for (auto& type : typeListComponent->value) {

            auto fit = std::find_if(type.mInheritanceVec.begin(), type.mInheritanceVec.end(),
                [&baseHandlerTypeName](const nsCppParser::TInheritanceInfo& inheritanceInfo)
            {
                return (inheritanceInfo.mOriginalName == baseHandlerTypeName);
            });

            if (fit == type.mInheritanceVec.end()) {
                continue;
            }

            handlerListComponent.value.insert(type.GetTypeNameWithNameSpace());
        }

        mEntMng->SetComponent(eid, handlerListComponent);
    }
}