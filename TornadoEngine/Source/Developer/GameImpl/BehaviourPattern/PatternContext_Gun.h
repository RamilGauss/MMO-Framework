/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_GunH
#define PatternContext_GunH

#include "PatternContext_Model.h"

class DllExport TPatternContext_Gun : public TPatternContext_Model
{
public:
  TPatternContext_Gun(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Gun();
};

#endif
