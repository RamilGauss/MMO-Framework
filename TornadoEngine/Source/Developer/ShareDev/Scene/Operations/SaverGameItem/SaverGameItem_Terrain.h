/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SaverGameItem_TerrainH
#define SaverGameItem_TerrainH

#include "TypeDef.h"
#include "Operation_Terrain.h"

class DllExport TSaverGameItem_Terrain : public TOperation_Terrain
{
public:
	TSaverGameItem_Terrain();

	virtual void Save() = 0;

private:
};

#endif
