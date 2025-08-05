/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <fmt/color.h>
#include <fmt/core.h>

#include <magic_enum/magic_enum.hpp>

#include "Base/Common/LoadFromFile.h"

#include "ContainerCodeGeneratorLib/Sources/ContainerCodeGenerator.h"
#include "ContainerCodeGeneratorLib/Sources/MessageException.h"

#include "ContainerCodeGeneratorLib/Sources/Components/FilePathComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/PathsComponent.h"

#include "ContainerCodeGeneratorLib/Sources/GeneratedFiles/JsonSerializer.h"

namespace nsContainerCodeGenerator
{
    TContainerCodeGenerator::TContainerCodeGenerator() : 
        mEntMng("ContainerCodeGenerator", 100)
    {
        mEntMng.Setup();
    }
    //-------------------------------------------------------------------------------------------
    TContainerCodeGenerator::~TContainerCodeGenerator()
    {

    }
    //-------------------------------------------------------------------------------------------
    void TContainerCodeGenerator::CreateSingleEntity(const std::string& filePath)
    {
        auto singleEid = mEntMng.CreateEntity();

        // Input
        TFilePathComponent filePathComponent;
        filePathComponent.value = filePath;
        mEntMng.SetComponent(singleEid, filePathComponent);

        TPathsComponent pathsComponent;
        mEntMng.SetComponent(singleEid, pathsComponent);
    }
    //-------------------------------------------------------------------------------------------
    TContainerCodeGenerator::Result TContainerCodeGenerator::Execute()
    {
        TContainerCodeGenerator::Result result = Result::OK;
        std::string resultStr;

        try {
            mMainFeature.Execute();

            // Output result
            fmt::print(fg(fmt::color::blue),
                "ContainerCodeGenerator:[{}]\n", magic_enum::enum_name(result));
        } catch (const TMessageException& exception) {
            resultStr = exception.what();

            result = Result::DEVELOPER_ERROR;

            // Output result
            fmt::print(fg(fmt::color::red),
                "ContainerCodeGenerator:[{}] {}\n", magic_enum::enum_name(result), resultStr);

        } catch (...) {
            result = Result::INNER_ERROR;

            // Output result
            fmt::print(fg(fmt::color::red),
                "ContainerCodeGenerator:[{}]\n", magic_enum::enum_name(result));
        }

        return result;
    }
    //-------------------------------------------------------------------------------------------
}