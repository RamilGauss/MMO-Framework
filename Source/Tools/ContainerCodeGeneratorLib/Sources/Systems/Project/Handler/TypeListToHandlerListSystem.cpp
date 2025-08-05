/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include "Base/Common/TextFile.h"
#include "Base/Common/PathOperations.h"

#include "ECS/Include/Helper.h"

#include "Parser/Sources/Parser.h"

#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/HandlerListComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/TypeListComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Handler/TypeListToHandlerListSystem.h"

namespace nsContainerCodeGenerator::nsProject::nsHandler
{
    void TTypeListToHandlerListSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TProjectConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);
        auto typeListComponent = nsECSFramework::SingleComponent<TTypeListComponent>(mEntMng);

        THandlerListComponent handlerListComponent;

        auto baseHandlerTypeNames = configComponent->value.baseHandlerTypeNames;

        for (auto& type : typeListComponent->value) {

            auto fit = std::find_if(type.mInheritanceVec.begin(), type.mInheritanceVec.end(),
                [&baseHandlerTypeNames](const nsCppParser::TInheritanceInfo& inheritanceInfo) -> bool
            {
                return (baseHandlerTypeNames.contains(inheritanceInfo.mOriginalName));
            });

            if (fit == type.mInheritanceVec.end()) {
                continue;
            }

            handlerListComponent.value.insert(type.GetTypeNameWithNameSpace());
        }

        mEntMng->SetComponent(eid, handlerListComponent);
    }
}