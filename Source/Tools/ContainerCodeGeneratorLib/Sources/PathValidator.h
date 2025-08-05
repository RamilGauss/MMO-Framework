/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <string>

#include "Base/Common/TypeDef.h"

namespace nsContainerCodeGenerator
{
    class DllExport TPathValidator
    {
    public:
        static void ValidateAndThrow(const std::string& tagName, const std::string& path);
    };
}