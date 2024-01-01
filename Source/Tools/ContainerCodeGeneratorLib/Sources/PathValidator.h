/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/TypeDef.h"

#include <string>

namespace nsContainerCodeGenerator
{
    class DllExport TPathValidator
    {
    public:
        static void ValidateAndThrow(const std::string& tagName, const std::string& path);
    };
}