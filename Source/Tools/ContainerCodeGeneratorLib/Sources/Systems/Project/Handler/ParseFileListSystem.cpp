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

#include "ContainerCodeGeneratorLib/Sources/Components/FileListComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/TypeListComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Handler/ParseFileListSystem.h"

namespace nsContainerCodeGenerator::nsProject::nsHandler
{
    void TParseFileListSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TFileListComponent>(mEntMng);

        auto fileListComponent = nsECSFramework::SingleComponent<TFileListComponent>(mEntMng);

        TTypeListComponent typeListComponent;

        nsCppParser::TParser parser;

        for (auto& absFilePath : fileListComponent->value) {

            std::filesystem::path path(absFilePath);
            auto fileName = path.filename().string();

            std::string content;
            nsBase::nsCommon::TTextFile::Load(absFilePath, content);

            parser.Parse(content, fileName, absFilePath);

            auto result = parser.GetResult();

            for (auto type : result->mTypeList) {
                typeListComponent.value.push_back(*type);
            }
        }

        mEntMng->SetComponent(eid, typeListComponent);
    }
}