/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_TankH
#define PatternContext_TankH

#include "PatternContext_Model.h"

class DllExport TPatternContext_Tank : public TPatternContext_Model
{
public:
  TPatternContext_Tank(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Tank();
};

#endif
