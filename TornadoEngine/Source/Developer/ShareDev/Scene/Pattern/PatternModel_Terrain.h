/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternModel_TerrainH
#define PatternModel_TerrainH

#include "TypeDef.h"
#include "BehaviourPatternModel.h"

class TPatternContext_Terrain;

class DllExport TPatternModel_Terrain : public TBehaviourPatternModel
{
public:
  TPatternModel_Terrain();
  virtual ~TPatternModel_Terrain();

  virtual TBehaviourPatternContext* MakeNewConext();

	virtual bool LoadByModule_Graphic(bool fast = false);
  virtual bool LoadByModule_Physic(bool fast = false);

protected:
	void BeginLoad_Bullet();
	bool TryLoad_Bullet();

	void BeginLoad_Ogre();
	bool TryLoad_Ogre();
};

#endif
