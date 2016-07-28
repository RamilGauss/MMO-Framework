/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_ScenarioH
#define GP_ScenarioH

#include "TypeDef.h"

class TScene;

class DllExport TGP_Scenario
{
  int mType;
protected:
  TScene* mPtrScene;
public:
  TGP_Scenario();
  virtual ~TGP_Scenario();

  int  GetType();
  void SetType(int type);
  virtual bool IsBlock();
};

#endif
