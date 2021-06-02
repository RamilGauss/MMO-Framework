/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef Pattern_SkyboxH
#define Pattern_SkyboxH

#include "TypeDef.h"
#include "BehaviourPattern.h"

class DllExport TPattern_Skybox : public TBehaviourPattern
{
public:
  TPattern_Skybox();
  virtual ~TPattern_Skybox();

  virtual bool BuildByModule_Graphic(bool fast = false);
  
  virtual TPatternNameManager::eBaseType GetBaseType();
};

#endif
