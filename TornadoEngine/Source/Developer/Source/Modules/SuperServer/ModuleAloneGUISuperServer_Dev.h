/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleAloneGUISuperServer_DevH
#define ModuleAloneGUISuperServer_DevH

#include "ModuleAloneGUI.h"

class TModuleAloneGUISuperServer_Dev : public TModuleAloneGUI
{
protected:
  virtual void Input(int id, void* p, int size);
  virtual bool Output(void* p, int size);
};


#endif