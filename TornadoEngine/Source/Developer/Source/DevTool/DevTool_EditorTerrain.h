/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_EditorTerrainH
#define DevTool_EditorTerrainH

#include "DevTool_Share.h"

class TDevTool_EditorTerrain : public TDevTool_Share
{
public:
  TDevTool_EditorTerrain();
  virtual ~TDevTool_EditorTerrain();
  
  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();

};

#endif
