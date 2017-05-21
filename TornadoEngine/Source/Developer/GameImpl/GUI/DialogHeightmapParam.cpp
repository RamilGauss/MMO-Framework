/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DialogHeightmapParam.h"
#include "EditorMapLogic.h"

#include <atlconv.h>
#include <boost/lexical_cast.hpp>

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
	assignWidget(ebHeight,    "ebHeight");

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
	USES_CONVERSION;
	std::string sWorldSize = W2A((LPCWSTR)ebWorldSize->getOnlyText().data());
	float worldSize = boost::lexical_cast<float>(sWorldSize.data());

	std::string sSize = W2A((LPCWSTR)ebSize->getOnlyText().data());
	int size = boost::lexical_cast<int>(sSize.data());

	std::string sHeight = W2A((LPCWSTR)ebHeight->getOnlyText().data());
	float height = boost::lexical_cast<float>(sHeight.data());

	//### берём простые входные данные
	TModifier_Terrain::TDescTarget descTarget;
	descTarget.diapX_Part.min = 0;
	descTarget.diapX_Part.max = 0;
	descTarget.diapY_Part.min = 0;
	descTarget.diapY_Part.max = 0;
	descTarget.worldSizePart  = worldSize;
	descTarget.sizePart       = size;
	descTarget.height         = height;

	TModifier_Terrain::TLayer layer;
	layer.worldSize           = 2;
	layer.textureNames_Color  = "grass_green-01_diffusespecular.dds";
	layer.textureNames_Normal = "grass_green-01_normalheight.dds";
	descTarget.listLayer.push_back(layer);
	descTarget.listLayer.push_back(layer);
	//###

	g_EditorMapLogic->ModifyTerrain_Extent(descTarget);
}
//---------------------------------------------------------------------------------------------
void TDialogHeightmapParam::sl_Close(MyGUI::Widget* _sender)
{
	//Hide();
}
//---------------------------------------------------------------------------------------------
