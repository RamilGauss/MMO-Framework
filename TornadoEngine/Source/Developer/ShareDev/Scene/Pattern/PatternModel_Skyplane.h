/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternModel_SkyplaneH
#define PatternModel_SkyplaneH

#include "TypeDef.h"
#include "BehaviourPatternModel.h"

class DllExport TPatternModel_Skyplane : public TBehaviourPatternModel
{
public:
	TPatternModel_Skyplane();
	virtual ~TPatternModel_Skyplane();

	virtual bool LoadByModule_Graphic(bool fast = false);

protected:
	float GetPlane_D();
	nsMathTools::TVector3 GetPlane_Normal();
	std::string GetNameMaterialOgre();
	float GetScale();
	float GetTiling();
	bool  GetDrawFirst();
	float GetBow();
	float GetXsegments();
	float GetYsegments();
};

#endif
