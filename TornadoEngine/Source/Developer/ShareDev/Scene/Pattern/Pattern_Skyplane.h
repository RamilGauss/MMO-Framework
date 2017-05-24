/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_SkyplaneH
#define Pattern_SkyplaneH

#include "TypeDef.h"
#include "BehaviourPattern.h"

class DllExport TPattern_Skyplane : public TBehaviourPattern
{
public:
	TPattern_Skyplane();
	virtual ~TPattern_Skyplane();

	virtual bool BuildByModule_Graphic(bool fast = false);

	virtual TManagerNamePattern::eBaseType GetBaseType();

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
