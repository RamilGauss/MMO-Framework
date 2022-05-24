/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <algorithm>
#include <string>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#include "TextureFactory.h"
#include "Texture.h"

using namespace nsGraphicEngine;

TTexture* TTextureFactory::Load(const std::string& absPath)
{
    int width, height, bpp;
    unsigned char* data = stbi_load(absPath.c_str(), &width, &height, &bpp, STBI_rgb_alpha);
    if (!data) {
        return nullptr;
    }

    auto pTexture = new TTexture();

    pTexture->mWidth = width;
    pTexture->mHeight = height;
    pTexture->mBpp = bpp;

    pTexture->mData = new unsigned char[pTexture->GetSize()];
    memcpy(pTexture->mData, data, pTexture->GetSize());

    stbi_image_free(data);

    glGenTextures(1, &pTexture->mId);
    glBindTexture(GL_TEXTURE_2D, pTexture->mId); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // load image, create texture and generate mipmaps
    width = pTexture->mWidth;
    height = pTexture->mHeight;

    data = pTexture->mData;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    return pTexture;
}
//----------------------------------------------------------------------------------------------
bool TTextureFactory::Save(TTexture* pTexture, const std::string& absPath)
{
    return false;
}
//----------------------------------------------------------------------------------------------
void TTextureFactory::Unload(TTexture* pTexture)
{
    glDeleteTextures(1, &pTexture->mId);

    delete pTexture;
}
//----------------------------------------------------------------------------------------------
