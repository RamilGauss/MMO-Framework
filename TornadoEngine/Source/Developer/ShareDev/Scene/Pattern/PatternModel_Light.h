/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternModel_LightH
#define PatternModel_LightH

#include "TypeDef.h"
#include "BehaviourPatternModel.h"

class DllExport TPatternModel_Light : public TBehaviourPatternModel
{
public:
  TPatternModel_Light();
  virtual ~TPatternModel_Light();

	//virtual TBehaviourPatternContext* MakeNewConext();

	virtual bool LoadByModule_Graphic(bool fast = false);

protected:

	std::string GetNameLight();
	int GetType();
	bool GetIsCastShadow();
	bool GetIsVisible();
	nsMathTools::TVector3 GetDirVector();
	nsMathTools::TVector3 GetDiffuseColour();
	nsMathTools::TVector3 GetSpecularColour();

};

#endif
