/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderTerrain_Bullet.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include "MapItem.h"
#include "TerrainItem.h"
#include <boost/lexical_cast.hpp>

#include <iomanip>
#include <ios>
#include <iostream>

#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>

TBuilderTerrain_Bullet::TBuilderTerrain_Bullet()
{
	mMapItem     = NULL;
	mTerrainItem = NULL;
}
//--------------------------------------------------------------------
TBuilderTerrain_Bullet::~TBuilderTerrain_Bullet()
{

}
//--------------------------------------------------------------------
void TBuilderTerrain_Bullet::Begin(TMapItem* pMapItem, TTerrainItem* pTerrainItem)
{
	mMapItem     = pMapItem;
	mTerrainItem = pTerrainItem;
	mPathTerrain = TModuleLogic::Get()->GetTerrainPath();

	for( int iX = mTerrainItem->mX.min ; iX <= mTerrainItem->mX.max ; iX++ )
	{
		TMapIntPtrData mapData;
		for( int iY = mTerrainItem->mY.min ; iY <= mTerrainItem->mY.max ; iY++ )
		{
			TResult result;
			result.pData = new THeightMapFromOgre::TDataOut;
			mapData.insert(TMapIntPtrDataVT(iY,result));
		}
		mX_Y_Data.insert(TMapIntMapVT(iX,mapData));
	}
}
//--------------------------------------------------------------------
void TBuilderTerrain_Bullet::Load( int x, int y )
{
	TResult result;
	if( LoadData( x, y, result)==false )
		return;

	float m_minHeight, m_maxHeight;
	FindMinMax(result.pData, m_minHeight, m_maxHeight);

  int width  = result.pData->size;
  int lenght = result.pData->size;
	float s_gridHeightScale = 1.0f;
	int m_upAxis            = 1;
	PHY_ScalarType m_type   = PHY_FLOAT;
	bool flipQuadEdges      = true;//true
	
	btHeightfieldTerrainShape* pHeightfieldShape = new btHeightfieldTerrainShape(
		width, lenght,
		result.pData->cHeight.GetPtr(),
		s_gridHeightScale,
		m_minHeight, m_maxHeight,
		m_upAxis, m_type, flipQuadEdges);

	pHeightfieldShape->setUseZigzagSubdivision(true);
	float scaleAxe = result.pData->worldSize/result.pData->size;
	btVector3 scale;
	scale.setX(scaleAxe);
	scale.setY(1);
	scale.setZ(scaleAxe);
	pHeightfieldShape->setLocalScaling(scale);

	btTransform tr;
	tr.setIdentity();
	btVector3 pos;
	pos.setX(0/*-result.pData->pos.x*/);//-result.pData->worldSize/2);
	pos.setY(result.pData->pos.y +(m_minHeight+m_maxHeight)/2.0);
	pos.setZ(0/*-result.pData->pos.z*/);//-result.pData->worldSize/2);
	tr.setOrigin(pos);

	// create ground object
	float mass = 0.0;
	result.pRB = localCreateRigidBody(mass, tr, pHeightfieldShape);
}
//--------------------------------------------------------------------
bool TBuilderTerrain_Bullet::LoadData( int x, int y, TResult& result )
{
	TMapIntMapIt fitByX = mX_Y_Data.find(x);
	if( fitByX==mX_Y_Data.end() )
	{
		BL_FIX_BUG();
		return false;
	}
	TMapIntPtrDataIt fitByY = fitByX->second.find(y);
	if( fitByY==fitByX->second.end() )
	{
		BL_FIX_BUG();
		return false;
	}
	result = fitByY->second;

	std::string path = mPathTerrain + "/" + mMapItem->mName + "_";
	// Convert to signed 16-bit so sign bit is in bit 15
	short xs16 = static_cast<short>(x);
	short ys16 = static_cast<short>(y);
	// convert to unsigned because we do not want to propagate sign bit to 32-bits
	unsigned short x16 = static_cast<unsigned short>(xs16);
	unsigned short y16 = static_cast<unsigned short>(ys16);

	unsigned int key = 0;
	key = (x16 << 16) | y16;
	typedef std::basic_stringstream<char,std::char_traits<char>,std::allocator<char> > StreamString;
	StreamString str;

	str << std::setw(8) << std::setfill('0') << std::hex << key;
	path += str.str();

	mLoader.Setup(path, *(result.pData) );
	return true;
}
//--------------------------------------------------------------------
void TBuilderTerrain_Bullet::End()
{
	
}
//--------------------------------------------------------------------
void TBuilderTerrain_Bullet::FindMinMax(THeightMapFromOgre::TDataOut* pData, 
																				float& m_minHeight, float& m_maxHeight)
{
	float* p = (float*)pData->cHeight.GetPtr();

	m_minHeight = p[0];
	m_maxHeight = p[0];
	int cnt = pData->cHeight.GetCount();
	for( int i = 0 ; i < cnt ; i++ )
	{
		if( p[i] > m_maxHeight )
			m_maxHeight = p[i];
		if( p[i] < m_minHeight )
			m_minHeight = p[i];
	}
}
//--------------------------------------------------------------------
btRigidBody* TBuilderTerrain_Bullet::CreateRigidBody()
{
	return NULL;
}
//--------------------------------------------------------------------
