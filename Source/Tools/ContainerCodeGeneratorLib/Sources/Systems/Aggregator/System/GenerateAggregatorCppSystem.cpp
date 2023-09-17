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
#include "MessageException.h"

#include "Components/ProjectConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsSystem
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            { 0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            { 0, "" },
            { 0, "#include \"{{ TYPE_FACTORY_FILE_NAME }}.h\"" },
            { 0, "#include \"{{ DYNAMIC_CASTER_FILE_NAME }}.h\"" },
            { 0, "#include \"{{ TYPE_INFO_FILE_NAME }}.h\"" },
            { 0, "" },
            { 0, "using namespace {{ PROJECT_NAMESPACE }};" },
            { 0, "" },
            { 0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()" },
            { 0, "{" },
            { 1, "mTypeFactory = new {{ TYPE_FACTORY_TYPE_NAME }}();" },
            { 0, "mDynamicCaster = new {{ DYNAMIC_CASTER_TYPE_NAME }}();" },
            { 0, "mTypeInfo = new {{ TYPE_INFO_TYPE_NAME }}();" },
            { -1,"}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()" },
            { 0, "{" },
            { 1, "delete mTypeFactory;" },
            { 0, "delete mDynamicCaster;" },
            { 0, "delete mTypeInfo;" },
            { -1,"}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "" },
        };

        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            projectConfigComponent->value.aggregator.systemImpl.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = projectConfigComponent->value.aggregator.systemImpl.impl.fileName;
        data["TYPE_FACTORY_FILE_NAME"] = projectConfigComponent->value.aggregator.systemImpl.typeFactoryImpl.impl.fileName;
        data["DYNAMIC_CASTER_FILE_NAME"] = projectConfigComponent->value.aggregator.systemImpl.dynamicCasterImpl.impl.fileName;
        data["TYPE_INFO_FILE_NAME"] = projectConfigComponent->value.aggregator.systemImpl.typeInfoImpl.impl.fileName;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;
        data["IMPL_TYPE_NAME"] = projectConfigComponent->value.aggregator.systemImpl.impl.typeName;
        data["TYPE_FACTORY_TYPE_NAME"] = projectConfigComponent->value.aggregator.systemImpl.typeFactoryImpl.impl.typeName;
        data["DYNAMIC_CASTER_TYPE_NAME"] = projectConfigComponent->value.aggregator.systemImpl.dynamicCasterImpl.impl.typeName;
        data["TYPE_INFO_TYPE_NAME"] = projectConfigComponent->value.aggregator.systemImpl.typeInfoImpl.impl.typeName;

        try {
            txtGen.Apply(data);
            generatedFile.content = txtGen.Render();
        } catch (...) {
            std::string msg = "Render error";
            throw MSG_EXCEPTION(msg);
        }

        generatedFilesComponent->value.push_back(generatedFile);
    }
}