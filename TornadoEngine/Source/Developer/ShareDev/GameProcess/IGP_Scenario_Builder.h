/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_Scenario_BuilderH
#define IGP_Scenario_BuilderH

#include "IGP_Scenario_General.h"
#include <string>
#include "MathTools.h"
#include "ContainerTypes.h"
#include "MapItem.h"

class TFactoryBehaviourPatternModel;
class TUsePattern;

class DllExport IGP_Scenario_Builder : public virtual IGP_Scenario_General
{
public:
  IGP_Scenario_Builder();
  virtual ~IGP_Scenario_Builder();

  virtual void Setup(TUsePattern* pUsePattern, TFactoryBehaviourPatternModel* pFBP) = 0;
  virtual void LoadMap(std::string nameMap)  = 0;
  virtual bool AddGameObject(TMapItem::TObject& desc) = 0;
  virtual int GetPhysicWorldID() = 0;
};

#endif
