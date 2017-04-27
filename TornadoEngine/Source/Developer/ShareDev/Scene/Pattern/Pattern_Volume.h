/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_VolumeH
#define Pattern_VolumeH

#include "TypeDef.h"
#include "BehaviourPattern.h"

class DllExport TPattern_Volume : public TBehaviourPattern
{
public:
  TPattern_Volume();
  virtual ~TPattern_Volume();

	virtual TManagerNamePattern::eBaseType GetBaseType();
};

#endif
