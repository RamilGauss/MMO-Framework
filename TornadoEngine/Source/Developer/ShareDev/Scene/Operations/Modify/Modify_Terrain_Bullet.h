/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Modify_Terrain_BulletH
#define Modify_Terrain_BulletH

#include "TypeDef.h"

#include "Modify_Terrain.h"

class DllExport TModify_Terrain_Bullet : public TModify_Terrain
{
public:
	TModify_Terrain_Bullet();

	virtual void SetFormat(TDescTarget& descTarget);
protected:
	void setupContent();

};

#endif
