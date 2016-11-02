/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_HullH
#define PatternContext_HullH

#include "PatternContext_Model.h"

class DllExport TPatternContext_Hull : public TPatternContext_Model
{
public:
  TPatternContext_Hull(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Hull();
};

#endif
