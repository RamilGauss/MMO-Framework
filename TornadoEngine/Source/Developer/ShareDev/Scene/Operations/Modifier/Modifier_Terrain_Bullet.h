/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Modifier_Terrain_BulletH
#define Modifier_Terrain_BulletH

#include "TypeDef.h"

#include "Modifier_Terrain.h"

class DllExport TModifier_Terrain_Bullet : public TModifier_Terrain
{
	TDescTarget mDescTarget;

public:
	TModifier_Terrain_Bullet();

	virtual void SetFormat(TDescTarget& descTarget);
protected:
	void Clear();

	void ModifyExtent();
	
	void InitGrid();
	void SetupContentParts();
};

#endif
