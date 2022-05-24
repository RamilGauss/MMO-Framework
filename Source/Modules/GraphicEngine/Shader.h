/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "TypeDef.h"

#include <glm/glm.hpp>

namespace nsGraphicEngine
{
    class DllExport TShader
    {
        unsigned int mId = 0;
    public:
        TShader(unsigned int id);

        void MakeCurrentInConveyer();
        void SetBool(const std::string& name, bool value) const;
        void SetInt(const std::string& name, int value) const;
        void SetFloat(const std::string& name, float value) const;

        void SetMat4(const std::string& name, const glm::mat4& mat) const;
    };
}