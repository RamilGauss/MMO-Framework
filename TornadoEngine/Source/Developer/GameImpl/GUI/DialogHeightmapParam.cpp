/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DialogHeightmapParam.h"
#include "EditorMapLogic.h"

TDialogHeightmapParam::TDialogHeightmapParam()
{

}
//---------------------------------------------------------------------------------------------
TDialogHeightmapParam::~TDialogHeightmapParam()
{

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

	bApply->eventMouseButtonClick += MyGUI::newDelegate(this, &TDialogHeightmapParam::sl_Apply);
	bClose->eventMouseButtonClick += MyGUI::newDelegate(this, &TDialogHeightmapParam::sl_Close);
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
	g_EditorMapLogic->ModifyTerrain_Extent();
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::sl_Close(MyGUI::Widget* _sender)
{
	//Hide();
}
//---------------------------------------------------------------------------------------------
