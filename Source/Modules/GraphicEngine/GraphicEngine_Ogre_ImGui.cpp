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
    mTimeoutDblClick = eTimeoutDblClick;

    //mCBKeyBoard.Register(&TGraphicEngine_Ogre_ImGui::KeyBoardEvent, this);
    //mCBMouse.Register(&TGraphicEngine_Ogre_ImGui::MouseEvent, this);

    mGE.reset(new TGE_Impl);

    //mGE->SetCallBackKeyBoard(&mCBKeyBoard);
    //mGE->SetCallBackMouse(&mCBMouse);
}
//---------------------------------------------------------------------
TGraphicEngine_Ogre_ImGui::~TGraphicEngine_Ogre_ImGui()
{

}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::InitOGRE(const std::string& pathPluginCfg, const std::string& pathOgreCfg)
{
    //try {
        return mGE->InitOGRE(pathPluginCfg, pathOgreCfg);
    //} catch (MyGUI::Exception& _e) {
        //MsgException(_e);
        //throw;
    //}
    //return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::AddResource(const std::string& name, const std::string& type)
{
    mGE->AddResource(name, type);
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin)
{
    //try {
        return mGE->InitMyGUI(nameFileCore, nameFileSkin);
    //} catch (MyGUI::Exception& _e) {
        //MsgException(_e);
        //throw;
    //}
    //return false;
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::Work()
{
    //try {
        return mGE->Work();
    //} catch (MyGUI::Exception& _e) {
        //MsgException(_e);
        //throw;
    //}
    //return false;
}
//---------------------------------------------------------------------
Ogre::Root* TGraphicEngine_Ogre_ImGui::GetRoot()
{
    return mGE->GetRoot();
}
//---------------------------------------------------------------------
Ogre::SceneManager* TGraphicEngine_Ogre_ImGui::GetSceneManager()
{
    return mGE->GetSceneManager();
}
//---------------------------------------------------------------------
Ogre::Camera* TGraphicEngine_Ogre_ImGui::GetCamera()
{
    return mGE->GetCamera();
}
//---------------------------------------------------------------------
Ogre::RenderWindow* TGraphicEngine_Ogre_ImGui::GetWindow()
{
    return mGE->GetWindow();
}
//---------------------------------------------------------------------
Ogre::TerrainGroup* TGraphicEngine_Ogre_ImGui::GetTerrainGroup()
{
    return mGE->GetTerrainGroup();
}
//---------------------------------------------------------------------
Ogre::TerrainGlobalOptions* TGraphicEngine_Ogre_ImGui::GetTerrainGlobals()
{
    return mGE->GetTerrainGlobals();
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetGUIEnableEvent(bool v)
{
    mGE->SetGUIEnableEvent(v);
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetGUIEnableEvent()
{
    return mGE->GetGUIEnableEvent();
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetUseClipCursor(bool v)
{
    mGE->SetUseClipCursor(v);
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetUseClipCursor()
{
    return mGE->GetUseClipCursor();
}
//---------------------------------------------------------------------
//void TGraphicEngine_Ogre_ImGui::MsgException(MyGUI::Exception& _e)
//{
//#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
//    MessageBoxA(NULL, _e.getFullDescription().c_str(), "An exception has occured", MB_OK | MB_ICONERROR | MB_TASKMODAL);
//#else
//    std::cerr << "An exception has occured" << " : " << _e.getFullDescription().c_str();
//#endif
//}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::GetWindowCaption(std::wstring& _text)
{
    mGE->GetWindowCaption(_text);
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetWindowCaption(const std::wstring& _text)
{
    mGE->SetWindowCaption(_text);
}
//---------------------------------------------------------------------
size_t TGraphicEngine_Ogre_ImGui::GetWindowHandle()
{
    return mGE->GetWindowHandle();
}
//---------------------------------------------------------------------
//void TGraphicEngine_Ogre_ImGui::KeyBoardEvent(const OIS::KeyEvent& k, bool pressed)
//{
//    nsGraphicEngine::TKeyEvent* pKE = new nsGraphicEngine::TKeyEvent;
//
//    pKE->key = k.key;
//    pKE->pressed = pressed;
//    pKE->modifier = mGE->GetModifierKeyBoard();
//
//    AddEventWithoutCopy<nsGraphicEngine::TKeyEvent>(pKE);
//}
////---------------------------------------------------------------------
//void TGraphicEngine_Ogre_ImGui::MouseEvent(const OIS::MouseEvent& m, OIS::MouseButtonID id,
//    nsGraphicEngine::tTypeMouseEvent typeEvent)
//{
//    nsGraphicEngine::TMouseEvent* pME = new nsGraphicEngine::TMouseEvent;
//
//    pME->x = m.state.X.abs;
//    pME->y = m.state.Y.abs;
//    pME->dx = m.state.X.rel;
//    pME->dy = m.state.Y.rel;
//    pME->button = id;
//    pME->pressedButtons = m.state.buttons;
//    pME->typeEvent = typeEvent;
//
//    if (m.state.Z.rel != 0) {
//        pME->typeEvent = nsGraphicEngine::eWheel;
//        pME->delta_wheel = m.state.Z.rel;
//    }
//
//    AddEventWithoutCopy<nsGraphicEngine::TMouseEvent>(pME);
//
//    if (CheckDblClick(m, id, typeEvent)) {
//        pME = new nsGraphicEngine::TMouseEvent;
//
//        pME->x = m.state.X.abs;
//        pME->y = m.state.Y.abs;
//        pME->dx = m.state.X.rel;
//        pME->dy = m.state.Y.rel;
//        pME->button = id;
//        pME->pressedButtons = m.state.buttons;
//        pME->typeEvent = nsGraphicEngine::eButtonDblClick;
//
//        AddEventWithoutCopy<nsGraphicEngine::TMouseEvent>(pME);
//    }
//}
////---------------------------------------------------------------------
//bool TGraphicEngine_Ogre_ImGui::CheckDblClick(const OIS::MouseEvent& m, OIS::MouseButtonID id,
//    nsGraphicEngine::tTypeMouseEvent typeEvent)
//{
//    // проверка на двойной клик
//    if (typeEvent != nsGraphicEngine::eButtonDown &&
//        typeEvent != nsGraphicEngine::eButtonUp)
//        return false;
//
//    if (id != OIS::MB_Left && id != OIS::MB_Right)
//        return false;
//
//    TInfoClick* pClick = (id == OIS::MB_Left) ? &mLClick : &mRClick;
//
//    unsigned int now_ms = ht_GetMSCount();
//
//    if (typeEvent == nsGraphicEngine::eButtonDown) {
//        pClick->SetTime(now_ms);
//    } else {
//        if (pClick->IsSecondRelease()) {
//            if (now_ms < pClick->mTimePrevLastPress + mTimeoutDblClick) {
//                pClick->Init();
//                return true;
//            }
//        }
//    }
//    return false;
//}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetTimeoutDblClick(int t_ms)
{
    mTimeoutDblClick = t_ms;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetCenterClippingCursor(bool v)
{
    mGE->SetCenterClippingCursor(v);
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetCenterClippingCursor()
{
    return mGE->GetCenterClippingCursor();
}
//---------------------------------------------------------------------
