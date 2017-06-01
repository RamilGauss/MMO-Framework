/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DialogHeightmapParamH
#define DialogHeightmapParamH

#include "BaseGUI.h"
#include <MyGUI.h>
#include <Ogre.h>

class TDialogHeightmapParam :  public TBaseGUI
{

public:
	TDialogHeightmapParam();
	virtual ~TDialogHeightmapParam();

protected:
	virtual void Activate();
	virtual void* GetParent();
	virtual const char* GetNameLayout();
	virtual void SetupTabChild();

	virtual void KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
protected:  
	void sl_Apply(MyGUI::Widget* _sender);
	void sl_Close(MyGUI::Widget* _sender);
protected:
	void LoadSetting();
	void SaveSetting();

	float GetWorldSize();
	int   GetSize();
	float GetHeight();

	void SetWorldSize(float v);
	void SetSize(int v);
	void SetHeight(float v);

	int GetMinX();
	int GetMaxX();
	int GetMinY();
	int GetMaxY();
	void SetMinX(int v);
	void SetMaxX(int v);
	void SetMinY(int v);
	void SetMaxY(int v);

protected:
	MyGUI::Button*  bApply;
	MyGUI::Button*  bClose;

	MyGUI::EditBox* ebWorldSize;
	MyGUI::EditBox* ebSize; 
	MyGUI::EditBox* ebX_min;
	MyGUI::EditBox* ebX_max;
	MyGUI::EditBox* ebY_min;
	MyGUI::EditBox* ebY_max;
	MyGUI::EditBox* ebHeight;

};
#endif 
