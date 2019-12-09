/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef DevTool_EditorModelH
#define DevTool_EditorModelH

#include "DevTool_Share.h"

class TDevTool_EditorModel : public TDevTool_Share
{
public:
  TDevTool_EditorModel();
  virtual ~TDevTool_EditorModel();
  
  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();
};

#endif
