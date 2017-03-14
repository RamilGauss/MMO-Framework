/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ApplySetup_MapGraphicConfigH
#define ApplySetup_MapGraphicConfigH

#include "TypeDef.h"
#include "MathTools.h"
#include "MapItem.h"

class DllExport TApplySetup_MapGraphicConfig
{
  nsMathTools::TVector3 mBackgroundColour;
	TMapItem::TFog        mFog;
  nsMathTools::TVector3 mAmbientLight;
public:
  TApplySetup_MapGraphicConfig();
  virtual ~TApplySetup_MapGraphicConfig();

	void Set(nsMathTools::TVector3& backgroundColour, 
		TMapItem::TFog& fog, nsMathTools::TVector3& ambientLight);
  
  void WorkFromThread_Ogre();
};

#endif
