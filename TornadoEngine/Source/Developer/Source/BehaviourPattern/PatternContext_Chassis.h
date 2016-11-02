/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_ChassisH
#define PatternContext_ChassisH

#include "PatternContext_Model.h"

class DllExport TPatternContext_Chassis : public TPatternContext_Model
{
public:
  TPatternContext_Chassis(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Chassis();
};

#endif
