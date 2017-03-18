/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderTerrain_BulletH
#define BuilderTerrain_BulletH

#include "TypeDef.h"
#include "HeightMapFromOgre.h"
#include <map>
#include "BuilderShapeBase_Bullet.h"

struct TTerrainItem;
struct TMapItem;
class btHeightfieldTerrainShape;

class DllExport TBuilderTerrain_Bullet : public TBuilderShapeBase_Bullet
{
	TMapItem*     mMapItem;
	TTerrainItem* mTerrainItem;
	THeightMapFromOgre mLoader;

	struct TResult
	{
		THeightMapFromOgre::TDataOut* pData;
		btRigidBody* pRB;
		TResult()
		{
			pData = NULL;
			pRB   = NULL;
		}
	};

	typedef std::map<int,TResult> TMapIntPtrData;
	typedef TMapIntPtrData::iterator   TMapIntPtrDataIt;
	typedef TMapIntPtrData::value_type TMapIntPtrDataVT;
	
	typedef std::map<int,TMapIntPtrData> TMapIntMap;
	typedef TMapIntMap::iterator   TMapIntMapIt;
	typedef TMapIntMap::value_type TMapIntMapVT;
	TMapIntMap mX_Y_Data;

	std::string mPathTerrain;
public:
	TBuilderTerrain_Bullet();
	~TBuilderTerrain_Bullet();

	void Begin(TMapItem* pMapItem, TTerrainItem* pTerrainItem);
	void Load( int x, int y );
	void End();

	virtual btRigidBody* CreateRigidBody();
protected:

	bool LoadData( int x, int y, TResult& result );
	void FindMinMax(THeightMapFromOgre::TDataOut* pData, 
		float& m_minHeight, float& m_maxHeight);

};

#endif
