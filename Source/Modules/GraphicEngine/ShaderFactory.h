/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <map>
#include <array>
#include <list>

#include "TypeDef.h"

#include "Shader.h"

namespace nsGraphicEngine
{
    class TCustomShader;

    class DllExport TShaderFactory
    {
    public:
        struct TParams
        {
            int shaderType;
            std::list<std::string> fileContent;
        };

        [[nodiscard]]
        static TShader* Create(const std::list<TParams>& params);

        static void Destroy(TShader* pShader);
    private:

        static bool CheckCompileErrors(unsigned int shader);
        static bool CheckLinkerErrors(unsigned int shader);
    };
}
