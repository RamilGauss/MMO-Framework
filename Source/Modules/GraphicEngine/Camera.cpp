/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/Camera.h"

#include <glm/gtx/euler_angles.hpp>

using namespace nsGraphicEngine;

TCamera::TCamera()
{

}
//-------------------------------------------------------------------------------------------------------
bool TCamera::IsRenderOnDisplay() const
{
    return mIsRenderOnDisplay;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetRenderOnDisplay(bool value)
{
    mIsRenderOnDisplay = value;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetZoom(float value)
{
    mZoom = value;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetWindowSize(const glm::vec2& value)
{
    if (mWindowSize == value) {
        return;
    }

    mWindowSize = value;

    SetTextureSize(mWindowSize);
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetWindowPosition(const glm::vec2& value)
{
    mWindowPosition = value;
}
//-------------------------------------------------------------------------------------------------------
const float TCamera::GetZoom() const
{
    return mZoom;
}
//-------------------------------------------------------------------------------------------------------
const glm::vec2 TCamera::GetWindowSize() const
{
    return mWindowSize;
}
//-------------------------------------------------------------------------------------------------------
const glm::vec2 TCamera::GetWindowPosition() const
{
    return mWindowPosition;
}
//-------------------------------------------------------------------------------------------------------
glm::mat4 TCamera::GetViewMatrix() const
{
    return glm::lookAt(mPosition, mPosition + GetForward(), GetUp());
}
//-------------------------------------------------------------------------------------------------------
glm::mat4 TCamera::GetProjectionMatrix() const
{
    return glm::perspective(glm::radians(mZoom), mWindowSize.x / mWindowSize.y, mNear, mFar);
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetPosition(const glm::vec3& pos)
{
    mPosition = pos;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetRotation(const glm::vec3& angles)
{
    mRotation = angles;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::AddPosition(const glm::vec3& pos)
{
    mPosition += pos;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::AddRotation(const glm::vec3& angles)
{
    glm::mat4 m = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);
    glm::mat4 mR(1.0f);
    auto right = GetRight();
    mR = glm::rotate(mR, angles.x, right);
    m = mR * m;
    glm::extractEulerAngleXYZ(m, mRotation.x, mRotation.y, mRotation.z);

    m = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);
    glm::mat4 mU(1.0f);
    auto up = GetUp();
    mU = glm::rotate(mU, angles.y, up);
    m = mU * m;
    glm::extractEulerAngleXYZ(m, mRotation.x, mRotation.y, mRotation.z);

    m = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);
    glm::mat4 mF(1.0f);
    auto forward = GetForward();
    mF = glm::rotate(mF, angles.z, forward);
    m = mF * m;
    glm::extractEulerAngleXYZ(m, mRotation.x, mRotation.y, mRotation.z);
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetPosition() const
{
    return mPosition;
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetRotation() const
{
    return mRotation;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::MoveForward(float value)
{
    mPosition += GetForward() * value;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::MoveRight(float value)
{
    mPosition += GetRight() * value;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::MoveUp(float value)
{
    mPosition += GetUp() * value;
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetRight() const
{
    auto right = glm::cross(GetUp(), GetForward());

    return glm::normalize(right);
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetForward() const
{
    glm::mat4 rotMatrix = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);

    auto forward4 = rotMatrix * glm::vec4(glm::vec3(0.0f, 0.0f, 1.0f), 0.0f);
    auto forward = glm::vec3(forward4.x, forward4.y, forward4.z);

    return glm::normalize(forward);
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetUp() const
{
    glm::mat4 rotMatrix = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);

    auto up4 = rotMatrix * glm::vec4(glm::vec3(0.0f, 1.0f, 0.0f), 0.0f);
    auto up = glm::vec3(up4.x, up4.y, up4.z);

    return glm::normalize(up);
}
//-------------------------------------------------------------------------------------------------------
void TCamera::FreeResources()
{
    if (mHasResources) {
        glDeleteFramebuffers(1, &mFrameBuffer);
        glDeleteTextures(1, &mTexture.mId);
        glDeleteRenderbuffers(1, &mRenderBufferForDepthStensilTest);
        mHasResources = false;
    }
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetTextureSize(const glm::vec2& textureSize)
{
    FreeResources();

    mHasResources = true;

    mTexture.mWidth = textureSize.x;
    mTexture.mHeight = textureSize.y;

    // framebuffer configuration
    glGenFramebuffers(1, &mFrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);

    // create a color attachment texture
    glGenTextures(1, &mTexture.mId);
    glBindTexture(GL_TEXTURE_2D, mTexture.mId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mTexture.mWidth, mTexture.mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexture.mId, 0);

    // create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
    glGenRenderbuffers(1, &mRenderBufferForDepthStensilTest);
    glBindRenderbuffer(GL_RENDERBUFFER, mRenderBufferForDepthStensilTest);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, mTexture.mWidth, mTexture.mHeight); // use a single renderbuffer object for both a depth AND stencil buffer.
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, mRenderBufferForDepthStensilTest); // now actually attach it
    // now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        //cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << endl;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
//-------------------------------------------------------------------------------------------------------
void TCamera::Begin()
{
    glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);

    glEnable(GL_DEPTH_TEST); // enable depth testing (is disabled for rendering screen-space quad)
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
//-------------------------------------------------------------------------------------------------------
void TCamera::End()
{
    // now bind back to default framebuffer and draw a quad plane with the attached framebuffer color texture
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
//-------------------------------------------------------------------------------------------------------
const TTexture* TCamera::GetRenderedTexture() const
{
    return &mTexture;
}
//-------------------------------------------------------------------------------------------------------
TCamera::~TCamera()
{

}
//-------------------------------------------------------------------------------------------------------