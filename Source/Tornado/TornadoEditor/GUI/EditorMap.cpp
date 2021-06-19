///*
//Author: Gudakov Ramil Sergeevich a.k.a. Gauss
//Гудаков Рамиль Сергеевич
//Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
//See for more information LICENSE.md.
//*/
//
//#include "EditorMap.h"
//
//#include <Precompiled.h>
//#include <atlconv.h>
//#include <OgreManualObject.h>
//
//#include "ListModules.h"
//#include "ModuleLogic.h"
//#include "ModuleGraphicEngine.h"
//#include "LogicEventCallBack.h"
//#include "EditorMapLogic.h"
//#include "ConverterLocale.h"
//
//#include "StatusBar.h"
//#include "DialogHeightmapParam.h"
//#include "DialogOpenSave.h"
//
//TEditorMap::TEditorMap()
//{
//    mBar = nullptr;
//    mPopupMenu_File = nullptr;
//    mPopupMenu_Mode = nullptr;
//    miOpen = nullptr;
//    miSave = nullptr;
//    miSaveAs = nullptr;
//    miExit = nullptr;
//    miMode_Fly = nullptr;
//    miMode_TerrainExtent = nullptr;
//    miMode_TerrainHeight = nullptr;
//    miMode_TerrainPainter = nullptr;
//    miMode_MapParameter = nullptr;
//    miMode_Objects = nullptr;
//
//    cbUsePhysic = nullptr;
//
//    mDialogHeightmapParam = new TDialogHeightmapParam;
//    mDialogOpen = new TDialogOpenSave;
//    mDialogSaveAs = new TDialogOpenSave;
//
//    mDialogOpen->GetCB_Hide()->Register(&TEditorMap::HideDialogOpen, this);
//    mDialogSaveAs->GetCB_Hide()->Register(&TEditorMap::HideDialogSaveAs, this);
//}
////------------------------------------------------------
//TEditorMap::~TEditorMap()
//{
//    delete mDialogHeightmapParam;
//    delete mDialogOpen;
//    delete mDialogSaveAs;
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::Activate()
//{
//    // меню для виджетов
//    assignWidget(mBar, "Menu");
//    // file
//    mPopupMenu_File = mBar->findItemById("File", true)->getItemChild();
//
//    miOpen = mPopupMenu_File->findItemById("Command_FileOpen");
//    miSave = mPopupMenu_File->findItemById("Command_FileSave");
//    miSaveAs = mPopupMenu_File->findItemById("Command_FileSaveAs");
//    miExit = mPopupMenu_File->findItemById("Command_FileExit");
//
//    miOpen->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Open);
//    miSave->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Save);
//    miSaveAs->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_SaveAs);
//    miExit->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Exit);
//
//    mPopupMenu_Mode = mBar->findItemById("Mode", true)->getItemChild();
//
//    miMode_Fly = mPopupMenu_Mode->findItemById("Mode_Fly");
//    miMode_TerrainExtent = mPopupMenu_Mode->findItemById("Mode_TerrainExtent");
//    miMode_TerrainHeight = mPopupMenu_Mode->findItemById("Mode_TerrainHeight");
//    miMode_TerrainPainter = mPopupMenu_Mode->findItemById("Mode_TerrainPainter");
//    miMode_MapParameter = mPopupMenu_Mode->findItemById("Mode_MapParameter");
//    miMode_Objects = mPopupMenu_Mode->findItemById("Mode_Objects");
//
//    miMode_Fly->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_Fly);
//    miMode_TerrainExtent->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_TerrainExtent);
//    miMode_TerrainHeight->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_TerrainHeight);
//    miMode_TerrainPainter->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_TerrainPainter);
//    miMode_MapParameter->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_MapParameter);
//    miMode_Objects->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_Objects);
//
//    assignWidget(cbUsePhysic, "cbUsePhysic");
//    cbUsePhysic->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_ToggleUsePhysic);
//
//    sl_Mode_Fly(miMode_Fly);
//}
////-------------------------------------------------------------------------------------
//const char* TEditorMap::GetNameLayout()
//{
//    return "EditorMap.layout";
//}
////-------------------------------------------------------------------------------------
//void* TEditorMap::GetParent()
//{
//    return nullptr;
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::SetupTabChild()
//{
//
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
//{
//    switch (_key.getValue())   {
//        case MyGUI::KeyCode::Return:
//            //sl_Enter(_sender);
//            break;
//        default:;
//    }
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Open(MyGUI::Widget* _sender)
//{
//    mDialogOpen->Show();
//    TDialogOpenSave::TInitStruct initStruct;
//    initStruct.caption = "Открытие карты";
//    initStruct.nameButton = "Открыть";
//    initStruct.readOnly_ebName = true;
//    initStruct.currentItem = 0;
//
//    int cntMap = TModuleLogic::Get()->GetFGI()->GetCountByType(TFactoryGameItem::Map);
//    for (int i = 0; i < cntMap; i++)   {
//        std::string name;
//        if (TModuleLogic::Get()->GetFGI()->GetNameByType(TFactoryGameItem::Map, i, name))
//            initStruct.vecItems.push_back(name);
//    }
//
//    mDialogOpen->Init(initStruct);
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::Open(std::string nameMap)
//{
//    if (nameMap.length() == 0)
//        return;
//
//    g_StatusBar->AddText("Открытие карты \"" + nameMap + "\"");
//    g_EditorMapLogic->LoadGameMap(nameMap);
//    // так можно скрывать мышку. Создатели MyGUI, не надо называть так мышиный курсор, я чтобы догадаться
//    // до этого названия неделю потратил! PointerManager -> MouseCursorManager
//    //MyGUI::PointerManager::getInstance().setVisible(false);
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::SaveAs(std::string nameMap)
//{
//    if (nameMap.length() == 0)
//        return;
//
//    g_StatusBar->AddText("Сохранение карты как \"" + nameMap + "\"...");
//    g_EditorMapLogic->SaveAsGameMap(nameMap);
//    g_StatusBar->AddText("Сохранение карты как завершено.");
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Save(MyGUI::Widget* _sender)
//{
//    g_StatusBar->AddText("Сохранение карты...");
//    g_EditorMapLogic->SaveGameMap();
//    g_StatusBar->AddText("Сохранение карты завершено.");
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_SaveAs(MyGUI::Widget* _sender)
//{
//    short rand_id_map = rand();
//
//    // диалог для выбора нового имени
//    mDialogSaveAs->Show();
//    TDialogOpenSave::TInitStruct initStruct;
//    initStruct.caption = "Сохранение карты как";
//    initStruct.nameButton = "Сохранить как";
//    initStruct.readOnly_ebName = false;
//    initStruct.currentItem = -1;
//    initStruct.nameCurrentItem = "newMap_" + boost::lexical_cast<std::string>(rand_id_map);
//
//    int cntMap = TModuleLogic::Get()->GetFGI()->GetCountByType(TFactoryGameItem::Map);
//    for (int i = 0; i < cntMap; i++)   {
//        std::string name;
//        if (TModuleLogic::Get()->GetFGI()->GetNameByType(TFactoryGameItem::Map, i, name))
//            initStruct.vecItems.push_back(name);
//    }
//
//    mDialogSaveAs->Init(initStruct);
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Exit(MyGUI::Widget* _sender)
//{
//    TModuleLogic::Get()->Exit();
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_ToggleUsePhysic(MyGUI::Widget* _sender)
//{
//    bool state = cbUsePhysic->getStateSelected();
//    state = !state;
//    cbUsePhysic->setStateSelected(state);
//
//    TPhysicEngine_Bullet::eStateWorld stateWorld =
//        state ? TPhysicEngine_Bullet::eStateRealTime : TPhysicEngine_Bullet::eStatePause;
//    g_EditorMapLogic->TogglePhysicState(stateWorld);
//
//    std::string sMsgUsePhysic = state ? "Физика вкл." : "Физика выкл.";
//    g_StatusBar->AddText(sMsgUsePhysic);
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::SetNameMode(std::string sMode)
//{
//    std::string newCaption = "MapEditor [Mode - " + sMode + "]";
//    std::wstring newCaptionW = TConverterLocale::ConvertUtf8ToCp1251(newCaption);
//    TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->SetWindowCaption(newCaptionW);
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Mode_Fly(MyGUI::Widget* _sender)
//{
//    SetNameMode("Free camera");
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Mode_TerrainExtent(MyGUI::Widget* _sender)
//{
//    SetNameMode("Define terrain parameters");
//    mDialogHeightmapParam->Show();
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Mode_TerrainHeight(MyGUI::Widget* _sender)
//{
//    SetNameMode("Change terrain hight");
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Mode_TerrainPainter(MyGUI::Widget* _sender)
//{
//    SetNameMode("Change terrain color");
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Mode_MapParameter(MyGUI::Widget* _sender)
//{
//    SetNameMode("Change map parameters");
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::sl_Mode_Objects(MyGUI::Widget* _sender)
//{
//    SetNameMode("Objects");
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::HideDialogOpen()
//{
//    if (mDialogOpen->GetResult() == TDialogOpenSave::eAccept)   {
//        std::string nameMap = mDialogOpen->GetResultName();
//        Open(nameMap);
//    }
//}
////-------------------------------------------------------------------------------------
//void TEditorMap::HideDialogSaveAs()
//{
//    if (mDialogSaveAs->GetResult() == TDialogOpenSave::eAccept)   {
//        std::string nameMap = mDialogSaveAs->GetResultName();
//        SaveAs(nameMap);
//    }
//}
////-------------------------------------------------------------------------------------
