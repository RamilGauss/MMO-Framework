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
#include <set>
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

        ImVec2 mSize = { 400, 600 };

        double mLastTimeUpdateModel = 0;

        char mInputFilterValue [200] = {0};
    public:
        TComponentViewer();
        void Render() override;
    private:

        struct TComponent
        {
            std::string typeName;
            std::string content;
        };

        struct TEntity
        {
            std::string name;
            int eid;
        };

        struct TModel
        {
            std::list<TEntity> nameEntities;
            std::map<std::string, std::list<TComponent>> nsSelectedEntityComponents;

            void Clear()
            {
                nameEntities.clear();
                nsSelectedEntityComponents.clear();
            }
        };

        TModel mModel;


        int mEntMngCount = 0;

        std::vector<ImVec4> mColors;

        struct TComponentType
        {
            std::string componentName;
            int rtti = 0;

            const std::string GetNs() const;
            const std::string GetTypeName() const;
        };

        std::map<std::string, TComponentType> mComponentFilter;

        std::map<std::string, std::list<TComponentType>> mNsComponentsMap;

        std::map<std::string, TComponentType> mComponentTypes;// Global, all components

        std::map<std::string, TComponentType> mComponentTypesMinusFilter;

        
        void UpdatelModel();
        void RenderModel();
        void RenderFilterSearching();

        void SeparateToLines(const std::string& content, std::list<std::string>& lines);
        bool IsPassedByFilter(nsECSFramework::TEntityID eid);

        void UpdateComponents();

        bool IsCanApplyComponentToFilter(const std::string& inputFilterValue);

        bool mIsNeedInited = true;
        void Init();
    };
}