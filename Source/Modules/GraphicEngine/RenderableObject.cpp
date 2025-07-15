
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/RenderableObject.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


using namespace nsGraphicEngine;

void TRenderableObject::SetMesh(TMesh* pMesh)
{
    mMesh = pMesh;

    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);

    glBindVertexArray(mVAO);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mMesh->GetDataSize(), mMesh->GetPointData(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::SetTexture(const TTexture* pTexture)
{
    mTexture = pTexture;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::Draw()
{
    glBindVertexArray(mVAO);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mTexture->mId);

    glDrawArrays(GL_TRIANGLES, 0, mMesh->GetPointCount());
}
//-------------------------------------------------------------------------------------------------------
TRenderableObject::~TRenderableObject()
{
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
}
//-------------------------------------------------------------------------------------------------------
glm::mat4 TRenderableObject::GetMatrix() const
{
    auto matrix = glm::mat4(1.0f);
    matrix = glm::translate(matrix, mPosition);
    matrix = glm::rotate(matrix, glm::radians(mRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(mRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(mRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    matrix = glm::scale(matrix, mScales);

    return matrix;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::SetPosition(const glm::vec3& pos)
{
    mPosition = pos;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::SetRotation(const glm::vec3& angles)
{
    mRotation = angles;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::SetScale(const glm::vec3& scales)
{
    mScales = scales;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::AddPosition(const glm::vec3& pos)
{
    mPosition += pos;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::AddRotation(const glm::vec3& angles)
{
    mRotation += angles;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::AddScale(const glm::vec3& scales)
{
    mScales += scales;
}
//-------------------------------------------------------------------------------------------------------

