/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_TurretH
#define PatternContext_TurretH

#include "PatternContext_Model.h"

class DllExport TPatternContext_Turret : public TPatternContext_Model
{
public:
  TPatternContext_Turret(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Turret();
};

#endif
