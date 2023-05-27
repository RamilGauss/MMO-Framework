/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ParseFileListSystem.h"

#include <filesystem>

#include <TextFile.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include <Parser/Sources/Parser.h>

#include "Components/FileListComponent.h"
#include "Components/TypeListComponent.h"

namespace nsContainerCodeGenerator::nsCommon
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
            TTextFile::Load(absFilePath, content);

            parser.Parse(content, fileName, absFilePath);

            auto result = parser.GetResult();

            for (auto type : result->mTypeList) {
                typeListComponent.value.push_back(*type);
            }
        }

        mEntMng->SetComponent(eid, typeListComponent);
    }
}