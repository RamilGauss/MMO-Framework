/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "TypeDef.h"
#include "StatisticsValue.h"

#include "GraphicEngine/IRenderable.h"
#include "GraphicEngine/imgui/imgui.h"

#include "ImGuiWidgets/include/Window.h"
#include "ImGuiWidgets/include/TreeView.h"
#include "ImGuiWidgets/include/Label.h"
#include "ImGuiWidgets/include/TreeNode.h"
#include "ImGuiWidgets/include/Button.h"

#include "ECS/include/Feature.h"

namespace nsTornadoEngine
{
    class TLogicWrapperModule;
    class ILogicModule;
    class TFeatureManager;

    class DllExport TSystemViewer : public nsGraphicEngine::IRenderable
    {
        ImVec2 mSize = { 700, 700 };

        void* mSelectedPointer = nullptr;

        bool mIsNeedInited = true;

        nsImGuiWidgets::TWindow mWindow;
        nsImGuiWidgets::TTreeView mTreeView;
        nsImGuiWidgets::TLabel mStat;
        nsImGuiWidgets::TButton mRefresh;

        double mCommonSummaDt = 0;
    public:
        void Render() override;
    protected:
        void UpdateGui();
        
        void UpdateStat();
        void UpdateStat(TFeatureManager* pFeatureMng, double& summaDt);
        void UpdateStat(nsECSFramework::TFeature* pFeature);

        void AddNode(TFeatureManager* pFeatureMng, const std::string& name, const std::string& parentId);
        void AddNode(nsECSFramework::TFeature* pFeature, const std::string& parentId);

        nsImGuiWidgets::TTreeNode* AddNode(const std::string& title, const std::string& id, const std::string& parentId,
            const ImVec4* pColor = nullptr);

        void Init();

        void AddLogicWrapper(TLogicWrapperModule* pLogicWrapperModule, const std::string& name, const ImVec4& color);
        void AddLogicModule(ILogicModule* pLogicModule, const std::string& name, const ImVec4& color);

    private:

        struct TModuleNode
        {
            ImVec4 color;
            std::string name;

            TFeatureManager* beginFeatureMng = nullptr;
            TFeatureManager* logicFeatureMng = nullptr;
            TFeatureManager* endFeatureMng = nullptr;

            TLogicWrapperModule* pLogicWrapperModule = nullptr;

            TStatisticsValue stat;
        };

        std::list<TModuleNode> mModules;

        struct TStatistics
        {
            nsImGuiWidgets::TTreeNode* pNode = nullptr;
            std::string name;
            TStatisticsValue stat;
        };

        std::map<void*, TStatistics> mFeatureStatisticsMap;

        std::list<nsImGuiWidgets::TTreeNode*> mNodes;

        std::map<std::string, nsImGuiWidgets::TTreeNode*> mModuleNodeMap;
    };
}