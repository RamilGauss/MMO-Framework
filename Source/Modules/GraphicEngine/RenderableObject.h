
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "GraphicEngine/Shader.h"
#include "GraphicEngine/Mesh.h"
#include "GraphicEngine/Texture.h"

namespace nsGraphicEngine
{
    class DllExport TRenderableObject
    {
        TMesh* mMesh = nullptr;
        const TTexture* mTexture = nullptr;

        unsigned int mVBO = 0;
        unsigned int mVAO = 0;

        glm::vec3 mPosition = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 mRotation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 mScales = glm::vec3(1.0f, 1.0f, 1.0f);
    public:

        virtual ~TRenderableObject();

        void SetMesh(TMesh* pMesh);
        void SetTexture(const TTexture* pTexture);

        void Draw();

        glm::mat4 GetMatrix() const;

        void SetPosition(const glm::vec3& pos);
        void SetRotation(const glm::vec3& angles);
        void SetScale(const glm::vec3& scales);

        void AddPosition(const glm::vec3& pos);
        void AddRotation(const glm::vec3& angles);
        void AddScale(const glm::vec3& scales);
    private:
    };
}