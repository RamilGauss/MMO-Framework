/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/Shader.h"

using namespace nsGraphicEngine;

TShader::TShader(unsigned int id)
{
    mId = id;
}
//------------------------------------------------------------------------
void TShader::MakeCurrentInConveyer()
{
    glUseProgram(mId);
}
//------------------------------------------------------------------------
void TShader::SetBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(mId, name.c_str()), (int)value);
}
//------------------------------------------------------------------------
void TShader::SetInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(mId, name.c_str()), value);
}
//------------------------------------------------------------------------
void TShader::SetFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(mId, name.c_str()), value);
}
//------------------------------------------------------------------------
void TShader::SetMat4(const std::string& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(mId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
//------------------------------------------------------------------------
void TShader::SetFloat2(const std::string& name, float value0, float value1) const
{
    glUniform2f(glGetUniformLocation(mId, name.c_str()), value0, value1);
}
//------------------------------------------------------------------------
void TShader::SetFloat3(const std::string& name, float value0, float value1, float value2) const
{
    glUniform3f(glGetUniformLocation(mId, name.c_str()), value0, value1, value2);
}
//------------------------------------------------------------------------
void TShader::SetFloat4(const std::string& name, float value0, float value1, float value2, float value3) const
{
    glUniform4f(glGetUniformLocation(mId, name.c_str()), value0, value1, value2, value3);
}
//------------------------------------------------------------------------
