/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MY_GUI_MANAGER_H
#define MY_GUI_MANAGER_H

#include "Base/BaseDemoManager.h"

class TMyGUI_Manager :
	public base::BaseDemoManager
{
public:
	virtual void createScene();
	virtual void destroyScene();

private:
	virtual void setupResources();
};

#endif 
