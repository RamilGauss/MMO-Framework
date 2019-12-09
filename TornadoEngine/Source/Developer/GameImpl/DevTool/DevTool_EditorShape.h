/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef DevTool_EditorShapeH
#define DevTool_EditorShapeH

#include "DevTool_Share.h"

class TDevTool_EditorShape : public TDevTool_Share
{
public:
  TDevTool_EditorShape();
  virtual ~TDevTool_EditorShape();
  
  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();

};

#endif
