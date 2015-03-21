/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleAloneGUISlave_DevH
#define ModuleAloneGUISlave_DevH

#include "ModuleAloneGUI.h"

class TModuleAloneGUISlave_Dev : public TModuleAloneGUI
{
protected:
  virtual void Input(int id, void* p, int size);
  virtual bool Output(void* p, int size);
};


#endif