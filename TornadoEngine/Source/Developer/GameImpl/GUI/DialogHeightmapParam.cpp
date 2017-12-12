/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DialogHeightmapParam.h"
#include "EditorMapLogic.h"
#include "Settings.h"

TDialogHeightmapParam::TDialogHeightmapParam()
{

}
//---------------------------------------------------------------------------------------------
TDialogHeightmapParam::~TDialogHeightmapParam()
{
  if( IsVisible() )
    SaveSetting();
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::Activate()
{
  assignWidget(bApply,      "bApply");
  assignWidget(bClose,      "bClose");
  assignWidget(ebWorldSize, "ebWorldSize");
  assignWidget(ebSize,      "ebSize"); 
  assignWidget(ebX_min,     "ebX_min");
  assignWidget(ebX_max,     "ebX_max");
  assignWidget(ebY_min,     "ebY_min");
  assignWidget(ebY_max,     "ebY_max");
  assignWidget(ebHeight,    "ebHeight");

  bApply->eventMouseButtonClick += MyGUI::newDelegate(this, &TDialogHeightmapParam::sl_Apply);
  bClose->eventMouseButtonClick += MyGUI::newDelegate(this, &TDialogHeightmapParam::sl_Close);

  LoadSetting();
}
//---------------------------------------------------------------------------------------------
void* TDialogHeightmapParam::GetParent()
{
  return nullptr;
}
//---------------------------------------------------------------------------------------------
const char* TDialogHeightmapParam::GetNameLayout()
{
  return "DialogHeightmapParam.layout";
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SetupTabChild()
{
  mVectorChild_Tab.push_back(ebWorldSize);
  mVectorChild_Tab.push_back(ebSize);
  mVectorChild_Tab.push_back(ebX_min);
  mVectorChild_Tab.push_back(ebX_max);
  mVectorChild_Tab.push_back(ebY_min);
  mVectorChild_Tab.push_back(ebY_max);
  mVectorChild_Tab.push_back(ebHeight);
  mVectorChild_Tab.push_back(bApply);
  mVectorChild_Tab.push_back(bClose);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  switch(_key.getValue())
  {
  case MyGUI::KeyCode::Return:
    //sl_Enter(_sender);
    break;
  default:;
  }
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::sl_Apply(MyGUI::Widget* _sender)
{
  SaveSetting();

  TModifier_Terrain::TDescTarget descTarget;
  descTarget.diapX_Part.min = GetMinX();
  descTarget.diapX_Part.max = GetMaxX();
  descTarget.diapY_Part.min = GetMinY();
  descTarget.diapY_Part.max = GetMaxY();
  descTarget.worldSizePart  = GetWorldSize();
  descTarget.sizePart       = GetSize();
  descTarget.height         = GetHeight();

  TModifier_Terrain::TLayer layer;
  layer.worldSize           = 2;
  layer.textureNames_Color  = "grass_green-01_diffusespecular.dds";
  layer.textureNames_Normal = "grass_green-01_normalheight.dds";
  descTarget.listLayer.push_back(layer);
  descTarget.listLayer.push_back(layer);

  g_EditorMapLogic->ModifyTerrain_Extent(descTarget);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::sl_Close(MyGUI::Widget* _sender)
{
  //Hide();
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SaveSetting()
{
  float worldSize = GetWorldSize();
  int   size      = GetSize();
  float height    = GetHeight();

  int x_min = GetMinX();
  int x_max = GetMaxX();
  int y_min = GetMinY();
  int y_max = GetMaxY();

  // save settings
  g_EditorMapLogic->GetSettings()->BeginGroup("DialogHeightmapParam");

  g_EditorMapLogic->GetSettings()->WriteEntry("WorldSize", worldSize);
  g_EditorMapLogic->GetSettings()->WriteEntry("Size",      size);
  g_EditorMapLogic->GetSettings()->WriteEntry("Height",    height);

  g_EditorMapLogic->GetSettings()->WriteEntry("x_min", x_max);
  g_EditorMapLogic->GetSettings()->WriteEntry("x_max", x_max);
  g_EditorMapLogic->GetSettings()->WriteEntry("y_min", y_min);
  g_EditorMapLogic->GetSettings()->WriteEntry("y_max", y_max);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::LoadSetting()
{
  g_EditorMapLogic->GetSettings()->BeginGroup("DialogHeightmapParam");

  // set default
  float worldSize = 10.0f;
  int   size      = 33;
  float height    = 39.6f;

  int x_min = 0;
  int x_max = 0;
  int y_min = 0;
  int y_max = 0;

  worldSize = g_EditorMapLogic->GetSettings()->ReadEntry("WorldSize", &worldSize);
  size      = g_EditorMapLogic->GetSettings()->ReadEntry("Size",   &size);
  height    = g_EditorMapLogic->GetSettings()->ReadEntry("Height", &height);

  x_min = g_EditorMapLogic->GetSettings()->ReadEntry("x_min", &x_min);
  x_max = g_EditorMapLogic->GetSettings()->ReadEntry("x_max", &x_max);
  y_min = g_EditorMapLogic->GetSettings()->ReadEntry("y_min", &y_min);
  y_max = g_EditorMapLogic->GetSettings()->ReadEntry("y_max", &y_max);

  SetWorldSize(worldSize);
  SetSize(size);
  SetHeight(height);

  SetMinX(x_max);
  SetMaxX(x_max);
  SetMinY(y_min);
  SetMaxY(y_max);
}
//---------------------------------------------------------------------------------------------
float TDialogHeightmapParam::GetWorldSize()
{
  return GetValueFromEditBox<float>(ebWorldSize);
}
//---------------------------------------------------------------------------------------------
int TDialogHeightmapParam::GetSize()
{
  return GetValueFromEditBox<int>(ebSize);
}
//---------------------------------------------------------------------------------------------
float TDialogHeightmapParam::GetHeight()
{
  return GetValueFromEditBox<float>(ebHeight);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SetWorldSize(float v)
{
  SetValueFromEditBox(ebWorldSize, v);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SetSize(int v)
{
  SetValueFromEditBox(ebSize, v);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SetHeight(float v)
{
  SetValueFromEditBox(ebHeight, v);
}
//---------------------------------------------------------------------------------------------
int TDialogHeightmapParam::GetMinX()
{
  return GetValueFromEditBox<int>(ebX_min);
}
//---------------------------------------------------------------------------------------------
int TDialogHeightmapParam::GetMaxX()
{
  return GetValueFromEditBox<int>(ebX_max);
}
//---------------------------------------------------------------------------------------------
int TDialogHeightmapParam::GetMinY()
{
  return GetValueFromEditBox<int>(ebY_min);
}
//---------------------------------------------------------------------------------------------
int TDialogHeightmapParam::GetMaxY()
{
  return GetValueFromEditBox<int>(ebY_max);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SetMinX(int v)
{
  SetValueFromEditBox(ebX_min, v);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SetMaxX(int v)
{
  SetValueFromEditBox(ebX_max, v);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SetMinY(int v)
{
  SetValueFromEditBox(ebY_min, v);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::SetMaxY(int v)
{
  SetValueFromEditBox(ebY_max, v);
}
//---------------------------------------------------------------------------------------------
