/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Builder_TerrainH
#define Builder_TerrainH

#include "TypeDef.h"

#include "Operation_Terrain.h"

class DllExport TBuilder_Terrain : public TOperation_Terrain
{
public:
	TBuilder_Terrain();

	virtual void Begin() = 0;
	virtual void Load(int x, int y) = 0;
	virtual void End() = 0;
private:
};

#endif
