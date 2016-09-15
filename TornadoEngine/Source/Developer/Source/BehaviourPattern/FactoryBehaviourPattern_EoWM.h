/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryBehaviourPattern_EoWMH
#define FactoryBehaviourPattern_EoWMH

#include "FactoryBehaviourPattern.h"

class TFactoryBehaviourPattern_EoWM : public TFactoryBehaviourPattern
{
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Tank;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Gear;
public:
  TFactoryBehaviourPattern_EoWM();
  virtual ~TFactoryBehaviourPattern_EoWM();
protected:
  void MakeTank(TBehaviourPattern*& p);
  void MakeGear(TBehaviourPattern*& p);
};

#endif
