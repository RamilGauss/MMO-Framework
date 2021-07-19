/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef DevTool_EditorMapH
#define DevTool_EditorMapH

#include "DevTool_Share.h"

class TDevTool_EditorMap : public TDevTool_Share
{
public:
  TDevTool_EditorMap();
  virtual ~TDevTool_EditorMap();

protected:
  virtual TModuleDev* GetModuleLogic();
};

#endif
