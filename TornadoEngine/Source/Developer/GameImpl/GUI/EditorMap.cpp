/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorMap.h"

#include <Precompiled.h>
#include <atlconv.h>
#include <OgreManualObject.h>

#include "ListModules.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "LogicEventCallBack.h"
#include "EditorMapLogic.h"
#include "ConverterLocale.h"

#include "StatusBar.h"
#include "DialogHeightmapParam.h"

TEditorMap::TEditorMap() 
{
  mBar                       = nullptr;
  mPopupMenu_File            = nullptr;
  mPopupMenu_Mode            = nullptr;
  miOpen                     = nullptr;
  miSave                     = nullptr;
  miExit                     = nullptr;
	miMode_Fly                 = nullptr;
	miMode_TerrainExtent			 = nullptr;
	miMode_TerrainHeight			 = nullptr;
	miMode_TerrainPainter      = nullptr;
	miMode_MapParameter        = nullptr;
	miMode_Objects             = nullptr;

	cbUsePhysic                = nullptr;

	mDialogHeightmapParam = new TDialogHeightmapParam;
}
//------------------------------------------------------
TEditorMap::~TEditorMap()
{
	delete mDialogHeightmapParam;
}
//-------------------------------------------------------------------------------------
void TEditorMap::Activate()
{
  // меню для виджетов
	assignWidget(mBar, "Menu");
	// file
	mPopupMenu_File = mBar->findItemById("File", true)->getItemChild();

  miOpen = mPopupMenu_File->findItemById("Command_FileOpen");
  miSave = mPopupMenu_File->findItemById("Command_FileSave");
  miExit = mPopupMenu_File->findItemById("Command_FileExit");

  miOpen->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Open);
	miSave->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Save);
  miExit->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Exit);
	
	mPopupMenu_Mode = mBar->findItemById("Mode", true)->getItemChild();

	miMode_Fly            = mPopupMenu_Mode->findItemById("Mode_Fly");
	miMode_TerrainExtent  = mPopupMenu_Mode->findItemById("Mode_TerrainExtent");
	miMode_TerrainHeight  = mPopupMenu_Mode->findItemById("Mode_TerrainHeight");
	miMode_TerrainPainter = mPopupMenu_Mode->findItemById("Mode_TerrainPainter");
	miMode_MapParameter   = mPopupMenu_Mode->findItemById("Mode_MapParameter");
	miMode_Objects        = mPopupMenu_Mode->findItemById("Mode_Objects");

	miMode_Fly           ->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_Fly);
	miMode_TerrainExtent ->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_TerrainExtent);
	miMode_TerrainHeight ->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_TerrainHeight);
	miMode_TerrainPainter->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_TerrainPainter);
	miMode_MapParameter  ->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_MapParameter);
	miMode_Objects       ->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Mode_Objects);

	assignWidget(cbUsePhysic, "cbUsePhysic");
	cbUsePhysic->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_ToggleUsePhysic);

	sl_Mode_Fly(miMode_Fly);
}
//-------------------------------------------------------------------------------------
const char* TEditorMap::GetNameLayout()
{
  return "EditorMap.layout";
}
//-------------------------------------------------------------------------------------
void* TEditorMap::GetParent()
{
  return nullptr;
}
//-------------------------------------------------------------------------------------
void TEditorMap::SetupTabChild()
{

}
//-------------------------------------------------------------------------------------
void TEditorMap::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  switch(_key.getValue())
  {
    case MyGUI::KeyCode::Return:
      //sl_Enter(_sender);
      break;
    default:;
  }
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Open(MyGUI::Widget* _sender)
{
	std::string nameMap = "Field";

	g_StatusBar->AddText("Открытие карты \"" + nameMap + "\"");

	g_EditorMapLogic->LoadGameMap(nameMap);
	// так можно скрывать мышку. Создатели MyGUI, не надо называть так мышиный курсор, я чтобы догадаться
	// до этого названия неделю потратил! PointerManager -> MouseCursorManager
	//MyGUI::PointerManager::getInstance().setVisible(false);
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Save(MyGUI::Widget* _sender)
{
	g_StatusBar->AddText("Сохранение карты...");
	//g_EditorMapLogic->Save();
	g_StatusBar->AddText("Сохранение карты завершено.");
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Exit(MyGUI::Widget* _sender)
{
  TModuleLogic::Get()->Exit();
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_ToggleUsePhysic(MyGUI::Widget* _sender)
{
	bool state = cbUsePhysic->getStateSelected();
	state = !state;
	cbUsePhysic->setStateSelected(state);

	TPhysicEngine_Bullet::eStateWorld stateWorld = 
	 state ? TPhysicEngine_Bullet::eStateRealTime : TPhysicEngine_Bullet::eStatePause;
	g_EditorMapLogic->TogglePhysicState(stateWorld);

	std::string sMsgUsePhysic = state ? "Физика вкл." : "Физика выкл.";
	g_StatusBar->AddText(sMsgUsePhysic);
}
//-------------------------------------------------------------------------------------
void TEditorMap::SetNameMode(std::string sMode)
{
	std::string newCaption = "Редактор карты [Режим работы - " + sMode + "]";
	std::wstring newCaptionW = TConverterLocale::ConvertUtf8ToUnicode(newCaption);
	TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->SetWindowCaption(newCaptionW);
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Mode_Fly(MyGUI::Widget* _sender)
{
	SetNameMode("Режим свободной камеры");
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Mode_TerrainExtent(MyGUI::Widget* _sender)
{
	SetNameMode("Переопределить параметры земли");
	mDialogHeightmapParam->Show();
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Mode_TerrainHeight(MyGUI::Widget* _sender)
{
	SetNameMode("Изменение высоты земли");
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Mode_TerrainPainter(MyGUI::Widget* _sender)
{
	SetNameMode("Изменение цвета земли");
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Mode_MapParameter(MyGUI::Widget* _sender)
{
	SetNameMode("Изменение параметров игровой карты");
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Mode_Objects(MyGUI::Widget* _sender)
{
	SetNameMode("Объекты");
}
//-------------------------------------------------------------------------------------
