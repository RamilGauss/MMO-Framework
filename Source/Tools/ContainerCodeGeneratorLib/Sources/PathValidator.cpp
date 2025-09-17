/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include <fmt/core.h>

#include "ContainerCodeGeneratorLib/Sources/PathValidator.h"
#include "ContainerCodeGeneratorLib/Sources/MessageException.h"

namespace nsContainerCodeGenerator
{
    void TPathValidator::ValidateAndThrow(const std::string& tagName, const std::string& path)
    {
        auto isExist = std::filesystem::exists(path);

        if (!isExist) {
            auto msg = fmt::format("Not valid {}: \"{}\"\n", tagName, path);
            throw TMessageException(msg);
        }
    }
}