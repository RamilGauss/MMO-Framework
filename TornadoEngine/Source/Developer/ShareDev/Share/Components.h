/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ComponentsH
#define ComponentsH

#include "TypeDef.h"
#include <vector>

class TModuleDataBase;
class TModuleGraphicEngine;
class TModuleMMOEngineClient;
class TModuleMMOEngineSlave;
class TModuleMMOEngineMaster;
class TModuleMMOEngineSuperServer;
class TModulePhysicEngine;
class TModuleSoundEngine;
class TModuleTimer;

class TModuleComponent;

class DllExport TComponents
{
  std::vector<TModuleComponent*> mVecComp;
public:
  TComponents();

  void SetLogicID(int id);

  TModuleDataBase*             pDataBase;
  TModuleGraphicEngine*        pGraphicEngine;
  TModuleMMOEngineClient*      pMMOEngineClient;
  TModuleMMOEngineSlave*       pMMOEngineSlave;
  TModuleMMOEngineMaster*      pMMOEngineMaster;
  TModuleMMOEngineSuperServer* pMMOEngineSuperServer;
  TModulePhysicEngine*         pPhysicEngine;
  TModuleSoundEngine*          pSoundEngine;
  TModuleTimer*                pTimer;
};

#endif
