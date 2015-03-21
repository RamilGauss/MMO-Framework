/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ResourcesGraphicEngineH
#define ResourcesGraphicEngineH

#include "Resources.h"

class IXML;

class DllExport TResourcesGraphicEngine : public TResources
{
  std::string mPluginsCfg;

public:
  TResourcesGraphicEngine();
  virtual ~TResourcesGraphicEngine();

  virtual bool Work(IXML* pXML);
  
  std::string GetPluginsCfg();
protected:
  bool LoadPluginsCfg();
};

#endif
