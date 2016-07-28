/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_BlockH
#define GP_Scenario_BlockH

#include "GP_Scenario.h"

class DllExport TGP_Scenario_Block : public TGP_Scenario
{
public:
  TGP_Scenario_Block();
  virtual ~TGP_Scenario_Block();

  virtual int Progress() = 0;
  virtual bool IsBlock();
};

#endif
