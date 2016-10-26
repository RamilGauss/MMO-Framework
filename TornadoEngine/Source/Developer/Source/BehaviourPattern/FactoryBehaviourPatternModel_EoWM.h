/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryBehaviourPatternModel_EoWMH
#define FactoryBehaviourPatternModel_EoWMH

#include "FactoryBehaviourPatternModel.h"

class TFactoryBehaviourPatternModel_EoWM : public TFactoryBehaviourPatternModel
{
  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Tank;
  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Gear;
public:
  TFactoryBehaviourPatternModel_EoWM();
  virtual ~TFactoryBehaviourPatternModel_EoWM();
protected:
  void MakeTank(TBehaviourPatternModel*& p);
  void MakeGear(TBehaviourPatternModel*& p);
};

#endif
