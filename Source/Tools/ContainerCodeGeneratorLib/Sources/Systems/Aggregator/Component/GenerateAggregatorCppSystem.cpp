/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorCppSystem.h"

#include <fmt/core.h>

#include <TextGenerator.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/ProjectConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsComponent
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "#include \"{{ JSON_FILE_NAME }}.h\""},
            {0, "#include \"{{ ENT_MNG_FILE_NAME }}.h\""},
            {0, "#include \"{{ TYPE_INFO_FILE_NAME }}.h\""},
            {0, "#include \"{{ DYNAMIC_CASTER_FILE_NAME }}.h\""},
            {0, "#include \"{{ TYPE_FACTORY_FILE_NAME }}.h\""},
            {0, ""},
            {0, "using namespace {{ PROJECT_NAMESPACE }};"},
            {0, ""},
            {0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {1, "mJson = new {{ JSON_TYPE_NAME }}();"},
            {0, "mEntMng = new {{ ENT_MNG_TYPE_NAME }}();"},
            {0, "mTypeInfo = new {{ TYPE_INFO_TYPE_NAME }}();"},
            {0, "mDynamicCaster = new {{ DYNAMIC_CASTER_TYPE_NAME }}();"},
            {0, "mTypeFactory = new {{ TYPE_FACTORY_TYPE_NAME }}();"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {1, "delete mJson;"},
            {0, "delete mEntMng;"},
            {0, "delete mTypeInfo;"},
            {0, "delete mDynamicCaster;"},
            {0, "delete mTypeFactory;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            projectConfigComponent->value.aggregator.componentImpl.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.impl.fileName;
        data["JSON_FILE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.jsonImpl.impl.fileName;
        data["DYNAMIC_CASTER_FILE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.dynamicCasterImpl.impl.fileName;
        data["TYPE_INFO_FILE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.typeInfoImpl.impl.fileName;
        data["ENT_MNG_FILE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.entMngImpl.impl.fileName;
        data["TYPE_FACTORY_FILE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.typeFactoryImpl.impl.fileName;
        
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;
        
        data["IMPL_TYPE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.impl.typeName;
        data["JSON_TYPE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.jsonImpl.impl.typeName;
        data["DYNAMIC_CASTER_TYPE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.dynamicCasterImpl.impl.typeName;
        data["TYPE_INFO_TYPE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.typeInfoImpl.impl.typeName;
        data["ENT_MNG_TYPE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.entMngImpl.impl.typeName;
        data["TYPE_FACTORY_TYPE_NAME"] = projectConfigComponent->value.aggregator.componentImpl.typeFactoryImpl.impl.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}