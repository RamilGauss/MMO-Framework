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

class DllExport IGP_Scenario_Builder : public IGP_Scenario_General
{
public:
  IGP_Scenario_Builder();
  virtual ~IGP_Scenario_Builder();

  virtual void LoadMap(std::string nameMap)  = 0;

  struct TAddGameObject
  {
    int                   id;
    std::string           type;
    std::string           namePattern;
    nsMathTools::TVector3 pos;
    nsMathTools::TVector3 orient;
    TContainer            internalState;
  };

  virtual bool AddGameObject(TAddGameObject&    desc) = 0;
  virtual bool AddGameObject(TMapItem::TObject& desc) = 0;
};

#endif
