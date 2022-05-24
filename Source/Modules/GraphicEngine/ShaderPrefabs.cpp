/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ShaderPrefabs.h"

using namespace nsGraphicEngine;

const std::list<std::string> TShaderPrefabs::GetRenderObjectVertex()
{
    std::string text = \
    "#version 330 core\n" \
    "layout(location = 0) in vec3 aPos;\n" \
    "layout(location = 1) in vec2 aTexCoord;\n" \
    "\n" \
    "out vec2 TexCoord;\n" \
    "\n" \
    "uniform mat4 model;\n" \
    "uniform mat4 view;\n" \
    "uniform mat4 projection;\n" \
    "\n" \
    "void main()\n" \
    "{\n" \
    "    gl_Position = projection * view * model * vec4(aPos, 1.0f);\n" \
    "    TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n" \
    "}";

    return { text };
}
//----------------------------------------------------------------------------------------------
const std::list<std::string> TShaderPrefabs::GetRenderObjectFragment()
{
    std::string text = \
    "#version 330 core\n" \
    "out vec4 FragColor;\n" \
    "\n" \
    "in vec3 ourColor;\n" \
    "in vec2 TexCoord;\n" \
    "\n" \
    "uniform sampler2D texture1;\n" \
    "\n" \
    "void main()\n" \
    "{\n" \
    "    FragColor = texture(texture1, TexCoord);\n" \
    "}";

    return { text };
}
//----------------------------------------------------------------------------------------------