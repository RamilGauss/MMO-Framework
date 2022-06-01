/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <vector>
#include <map>
#include <string>

#include "GraphicEngine/IRenderable.h"

#include "ECS/include/Config.h"
#include "GraphicEngine/imgui/imgui.h"


namespace nsTornadoEngine
{
    class DllExport TComponentViewer : public nsGraphicEngine::IRenderable
    {
        int mCurrentEntityManagerIndex = 0;

        nsECSFramework::TEntityID mSelectedEid = nsECSFramework::NONE;

        ImVec2 mSize = {300, 600};
    public:
        void Render() override;
    private:

        struct TEntity
        {
            std::string name;
            nsECSFramework::TEntityID eid;
        };

        struct TModel
        {
            std::list<TEntity> nameEntities;
            std::map<std::string, std::list<std::string>> nsSelectedEntityComponents;

            void Clear() 
            {
                nameEntities.clear(); 
                nsSelectedEntityComponents.clear();
            }
        };
        
        TModel mModel;

        int mEntMngCount = 0;

        void FillModel();
        void RenderModel();
    };
}