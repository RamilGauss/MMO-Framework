/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_BuilderH
#define GP_Scenario_BuilderH

#include "IGP_Scenario_Builder.h"
#include "GP_Scenario_Block.h"

class DllExport TGP_Scenario_Builder : 
  public IGP_Scenario_Builder, public TGP_Scenario_Block
{
public:
  TGP_Scenario_Builder();
  virtual ~TGP_Scenario_Builder();

  virtual void LoadMap(std::string nameMap);

  virtual bool AddGameObject(TAddGameObject&    desc);
  virtual bool AddGameObject(TMapItem::TObject& desc);

  virtual int Progress();
};

#endif
