/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_EditorMaterialH
#define DevTool_EditorMaterialH

#include "DevTool_Share.h"

class TDevTool_EditorMaterial : public TDevTool_Share
{
public:
  TDevTool_EditorMaterial();
  virtual ~TDevTool_EditorMaterial();
  
  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();

};

#endif
