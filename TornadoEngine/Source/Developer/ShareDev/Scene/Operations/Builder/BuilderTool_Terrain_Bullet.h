/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderTool_Terrain_BulletH
#define BuilderTool_Terrain_BulletH

#include "TypeDef.h"
#include "BuilderTool_Bullet.h"
#include "HeightMapTerrainFromOgre.h"

#include <map>
#include "StructPattern_Terrain.h"

struct TTerrainItem;
class btHeightfieldTerrainShape;

class DllExport TBuilderTool_Terrain_Bullet : public TBuilderTool_Bullet
{
	TTerrainItem* mTerrainItem;
	THeightMapTerrainFromOgre mLoader;

	std::string mPathTerrain;
public:
	TBuilderTool_Terrain_Bullet();
	~TBuilderTool_Terrain_Bullet();

	void Begin(TTerrainItem* pTerrainItem);
	void Load( int x, int y, nsStructPattern_Terrain::TTerrainPart_Physic* pPartPhysic);
	void End();
protected:

	bool LoadData( int x, int y, nsStructPattern_Terrain::THeightMapTerrain* pHMT );
	void FindMinMax(nsStructPattern_Terrain::THeightMapTerrain* pHMT, 
		float& m_minHeight, float& m_maxHeight);

};

#endif
