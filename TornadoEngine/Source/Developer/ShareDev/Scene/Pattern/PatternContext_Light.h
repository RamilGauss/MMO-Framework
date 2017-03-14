/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_LightH
#define PatternContext_LightH

#include "TypeDef.h"
#include "BehaviourPatternContext.h"

class DllExport TPatternContext_Light : public TBehaviourPatternContext
{
public:
  TPatternContext_Light(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Light();

	std::string GetNameLight();
	int GetType();
	bool GetIsCastShadow();
	bool GetIsVisible();
	nsMathTools::TVector3 GetDirVector();
	nsMathTools::TVector3 GetDiffuseColour();
	nsMathTools::TVector3 GetSpecularColour();
};

#endif
