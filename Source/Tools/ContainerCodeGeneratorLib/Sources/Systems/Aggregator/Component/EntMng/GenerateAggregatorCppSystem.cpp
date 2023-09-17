/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorCppSystem.h"

#include <fmt/core.h>

#include <filesystem>

#include <TextGenerator.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsComponent::nsEntMng
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "#include \"{{ PROJECT_ENT_MNG_FILE_NAME }}.h\""},
            {0, "#include \"{{ CORE_ENT_MNG_FILE_NAME }}.h\""},
            {0, ""},
            {0, "using namespace {{ PROJECT_NAMESPACE }};"},
            {0, ""},
            {0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {0, ""},
            {0, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {0, ""},
            {0, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "void {{ IMPL_TYPE_NAME }}::Init()"},
            {0, "{"},
            {1, "{{ PROJECT_ENT_MNG_TYPE_NAME }}::Init();"},
            {0, "{{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::Init();"},
            {-1, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "void {{ IMPL_TYPE_NAME }}::SetComponent(nsECSFramework::TEntityID eid, int rtti, void* p)"},
            {0, "{"},
            {1, "if ({{ PROJECT_ENT_MNG_TYPE_NAME }}::Has(rtti)) {"},
            {1, "{{ PROJECT_ENT_MNG_TYPE_NAME }}::SetComponent(mEntMng, eid, rtti, p);"},
            {0, "return;"},
            {-1,"}"},
            {0, "if ({{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::Has(rtti)) {"},
            {1, "{{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::SetComponent(mEntMng, eid, rtti, p);"},
            {0, "return;"},
            {-1,"}"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "const void* {{ IMPL_TYPE_NAME }}::ViewComponent(nsECSFramework::TEntityID eid, int rtti)"},
            {0, "{"},
            {1, "if ({{ PROJECT_ENT_MNG_TYPE_NAME }}::Has(rtti)) {"},
            {1, "return {{ PROJECT_ENT_MNG_TYPE_NAME }}::ViewComponent(mEntMng, eid, rtti);"},
            {-1,"}"},
            {0, "if ({{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::Has(rtti)) {"},
            {1, "return {{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::ViewComponent(mEntMng, eid, rtti);"},
            {-1,"}"},
            {0, "return nullptr;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "bool {{ IMPL_TYPE_NAME }}::HasComponent(nsECSFramework::TEntityID eid, int rtti)"},
            {0, "{"},
            {1, "if ({{ PROJECT_ENT_MNG_TYPE_NAME }}::Has(rtti)) {"},
            {1, "return {{ PROJECT_ENT_MNG_TYPE_NAME }}::HasComponent(mEntMng, eid, rtti);"},
            {-1,"}"},
            {0, "if ({{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::Has(rtti)) {"},
            {1, "return {{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::HasComponent(mEntMng, eid, rtti);"},
            {-1,"}"},
            {0, "return false;"},
            {-1, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "void {{ IMPL_TYPE_NAME }}::RemoveComponent(nsECSFramework::TEntityID eid, int rtti)"},
            {0, "{"},
            {1, "if ({{ PROJECT_ENT_MNG_TYPE_NAME }}::Has(rtti)) {"},
            {1, "{{ PROJECT_ENT_MNG_TYPE_NAME }}::RemoveComponent(mEntMng, eid, rtti);"},
            {0, "return;"},
            {-1,"}"},
            {0, "if ({{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::Has(rtti)) {"},
            {1, "{{ CORE_NAMESPACE }}::{{ CORE_ENT_MNG_TYPE_NAME }}::RemoveComponent(mEntMng, eid, rtti);"},
            {0, "return;"},
            {-1,"}"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = projectConfigComponent->value.aggregator.componentImpl.entMngImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        auto absBase = projectConfigComponent->value.absCorePath;
        auto abs = coreConfigComponent->value.coreConfig.targetDirectory;

        std::string relToCoreSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToCoreSources);

        absBase = projectConfigComponent->value.projectConfig.relPathToSources;
        abs = projectConfigComponent->value.projectConfig.targetDirectory;

        std::string relToProjectSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToProjectSources);

        std::filesystem::path pathRelToProjectSources(relToProjectSources);
        pathRelToProjectSources /= projectConfigComponent->value.projectConfig.componentConfig.entMng.fileName;

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= coreConfigComponent->value.coreConfig.componentConfig.entMng.fileName;

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["CORE_NAMESPACE"] = coreConfigComponent->value.coreConfig.nameSpace;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;

        data["CORE_ENT_MNG_FILE_NAME"] = pathRelToCoreSources.string();
        data["PROJECT_ENT_MNG_FILE_NAME"] = pathRelToProjectSources.string();
        data["CORE_ENT_MNG_TYPE_NAME"] = coreConfigComponent->value.coreConfig.componentConfig.entMng.typeName;
        data["PROJECT_ENT_MNG_TYPE_NAME"] = projectConfigComponent->value.projectConfig.componentConfig.entMng.typeName;

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