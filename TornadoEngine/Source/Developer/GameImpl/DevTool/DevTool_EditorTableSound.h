/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_EditorTableSoundH
#define DevTool_EditorTableSoundH

#include "DevTool_Share.h"

class TDevTool_EditorTableSound : public TDevTool_Share
{
public:
  TDevTool_EditorTableSound();
  virtual ~TDevTool_EditorTableSound();

  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();
};

#endif
