/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IRenderable.h"

#include "imgui.h"
#include <Texture.h>
#include <TextureFactory.h>

class TGuiDemo : public nsGraphicEngine::IRenderable
{
    const nsGraphicEngine::TTexture* mTexture = nullptr;

    int mCameraIndex = 0;
public:
    void Load(const std::string& path);

    void SetTexture(const nsGraphicEngine::TTexture* pTexture);

    void Render() override;

    void SetCameraIndex(int value);
};