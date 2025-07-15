/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/ShaderFactory.h"
#include "GraphicEngine/Shader.h"

using namespace nsGraphicEngine;

TShader* TShaderFactory::Create(const std::list<TParams>& params)
{
    std::list<unsigned int> shaderCompiledList;
    for (auto param : params) {

        auto shaderCompiled = glCreateShader(param.shaderType);
        for (auto& src : param.fileContent) {
            const char* srcCode = src.c_str();
            glShaderSource(shaderCompiled, 1, &srcCode, nullptr);
        }
        glCompileShader(shaderCompiled);

        CheckCompileErrors(shaderCompiled);

        shaderCompiledList.push_back(shaderCompiled);
    }

    unsigned int id = glCreateProgram();

    // shader Program
    for (auto& shaderCompiled : shaderCompiledList) {
        glAttachShader(id, shaderCompiled);
    }
    glLinkProgram(id);

    CheckLinkerErrors(id);

    for (auto& shaderCompiled : shaderCompiledList) {
        glDeleteShader(shaderCompiled);
    }

    return new TShader(id);
}
//---------------------------------------------------------------------------------------------
void TShaderFactory::Destroy(TShader* pShader)
{
    delete pShader;
}
//---------------------------------------------------------------------------------------------
bool TShaderFactory::CheckCompileErrors(unsigned int shader)
{
    int success;
    char infoLog[1024];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
    }

    return !success;
}
//------------------------------------------------------------------------
bool TShaderFactory::CheckLinkerErrors(unsigned int shader)
{
    int success;
    char infoLog[1024];
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader, 1024, NULL, infoLog);
        std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
    }

    return !success;
}
//------------------------------------------------------------------------