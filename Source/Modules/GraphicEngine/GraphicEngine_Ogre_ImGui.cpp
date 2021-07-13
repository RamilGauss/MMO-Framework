/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine_Ogre_ImGui.h"
#include "GE_Impl.h"
#include "BL_Debug.h"
#include "SrcEvent_ex.h"
#include "Events.h"
#include "Logger.h"
#include "GE_Impl.h"

#include <boost/cstdint.hpp>

using namespace nsGraphicEngine;

TGraphicEngine_Ogre_ImGui::TGraphicEngine_Ogre_ImGui()
{

}
//---------------------------------------------------------------------
TGraphicEngine_Ogre_ImGui::~TGraphicEngine_Ogre_ImGui()
{

}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::InitOGRE(const std::string& pathPluginCfg, const std::string& pathOgreCfg)
{
    return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::AddResource(const std::string& name, const std::string& type)
{
    
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin)
{
    return false;
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::Work()
{
    return false;
}
//---------------------------------------------------------------------
Ogre::Root* TGraphicEngine_Ogre_ImGui::GetRoot()
{
    return false;
}
//---------------------------------------------------------------------
Ogre::SceneManager* TGraphicEngine_Ogre_ImGui::GetSceneManager()
{
    return nullptr;
}
//---------------------------------------------------------------------
Ogre::Camera* TGraphicEngine_Ogre_ImGui::GetCamera()
{
    return nullptr;
}
//---------------------------------------------------------------------
Ogre::RenderWindow* TGraphicEngine_Ogre_ImGui::GetWindow()
{
    return nullptr;
}
//---------------------------------------------------------------------
Ogre::TerrainGroup* TGraphicEngine_Ogre_ImGui::GetTerrainGroup()
{
    return nullptr;
}
//---------------------------------------------------------------------
Ogre::TerrainGlobalOptions* TGraphicEngine_Ogre_ImGui::GetTerrainGlobals()
{
    return nullptr;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetGUIEnableEvent(bool v)
{
    
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetGUIEnableEvent()
{
    return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetUseClipCursor(bool v)
{
    
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetUseClipCursor()
{
    return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::GetWindowCaption(std::wstring& _text)
{
    
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetWindowCaption(const std::wstring& _text)
{

}
//---------------------------------------------------------------------
size_t TGraphicEngine_Ogre_ImGui::GetWindowHandle()
{
    return 0;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetTimeoutDblClick(int t_ms)
{

}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetCenterClippingCursor(bool v)
{

}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetCenterClippingCursor()
{
    return false;
}
//---------------------------------------------------------------------
