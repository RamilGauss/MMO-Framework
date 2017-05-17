/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Modifier_Terrain_Bullet.h"

#include <boost/foreach.hpp>
#include <CollisionShapes/btHeightfieldTerrainShape.h>

#include "Pattern_Terrain.h"
#include "ModuleLogic.h"
#include "ModulePhysicEngine.h"

TModifier_Terrain_Bullet::TModifier_Terrain_Bullet()
{

}
//-------------------------------------------------------------------------
void TModifier_Terrain_Bullet::SetFormat(TDescTarget& descTarget)
{
	mDescTarget = descTarget;
	// грохнуть все старые данные
	Clear();
	// создать заново
	ModifyExtent();
}
//------------------------------------------------------------------------
void TModifier_Terrain_Bullet::Clear()
{
	int id_world = mPatternTerrain->GetPhysicWorld();
	btDiscreteDynamicsWorld* pWorld = 
		TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(id_world);
	if( pWorld==NULL )
		return;

	BOOST_FOREACH( TPattern_Terrain::TMapIntMapPartPhysicVT& x_map, mPatternTerrain->mX_Y_PartPhysic )
	{
		BOOST_FOREACH( TPattern_Terrain::TMapIntPartPhysicVT& y_part, x_map.second )
		{
		  nsStructPattern_Terrain::TTerrainPart_Physic* pPart = &(y_part.second);
			// уничтожить внутреннее состо€ние
			delete pPart->pRB->getMotionState();
			pPart->pRB->setMotionState(NULL);
			// удалить из ћира 
			pWorld->removeCollisionObject(pPart->pRB);
			// освободить пам€ть
			delete pPart->pRB;
			pPart->pRB = NULL;
			//delete collision shapes
			delete pPart->pHeightfieldShape;
			pPart->pHeightfieldShape = NULL;
		}
	}
	mPatternTerrain->mX_Y_PartPhysic.clear();
}
//------------------------------------------------------------------------
void TModifier_Terrain_Bullet::ModifyExtent()
{
	// создать сетку из частей
	InitGrid();
	// задать свойства каждой части из сетки
	SetupContentParts();
}
//------------------------------------------------------------------------
void TModifier_Terrain_Bullet::InitGrid()
{
	for( int iX = mDescTarget.diapX_Part.min ; iX <= mDescTarget.diapX_Part.max ; iX++ )
	{
		TPattern_Terrain::TMapIntPartPhysic mapY_Part;
		for( int iY = mDescTarget.diapY_Part.min ; iY <= mDescTarget.diapY_Part.max ; iY++ )
		{
			nsStructPattern_Terrain::TTerrainPart_Physic part;
			mapY_Part.insert(TPattern_Terrain::TMapIntPartPhysicVT(iY,part));
		}
		mPatternTerrain->mX_Y_PartPhysic.
			insert(TPattern_Terrain::TMapIntMapPartPhysicVT(iX,mapY_Part));
	}
}
//------------------------------------------------------------------------
void TModifier_Terrain_Bullet::SetupContentParts()
{
	BOOST_FOREACH( TPattern_Terrain::TMapIntMapPartPhysicVT& x_map, mPatternTerrain->mX_Y_PartPhysic )
	{
		BOOST_FOREACH( TPattern_Terrain::TMapIntPartPhysicVT& y_part, x_map.second )
		{
		  nsStructPattern_Terrain::TTerrainPart_Physic* pPart = &(y_part.second);
			
			//pPart->pData = new TTerrainPart_Physic;
			//pPart->pHeightfieldShape = new ;
			//pPart->pRB = new ;
		}
	}
}
//------------------------------------------------------------------------
// from TerrainDemo.cpp Bullet SDK 2.82
#if 0
void TerrainDemo::resetPhysics(void)
{
	// reset gravity to point in appropriate direction
	m_dynamicsWorld->setGravity(getUpVector(m_upAxis, 0.0, -s_gravity));
	// get new heightfield of appropriate type
	m_rawHeightfieldData =
		getRawHeightfieldData(m_model, m_type, m_minHeight, m_maxHeight);
	btAssert(m_rawHeightfieldData && "failed to create raw heightfield");

	bool flipQuadEdges = false;
	btHeightfieldTerrainShape * heightfieldShape =
		new btHeightfieldTerrainShape(s_gridSize, s_gridSize,	m_rawHeightfieldData,	s_gridHeightScale,
		m_minHeight, m_maxHeight,	m_upAxis, m_type, flipQuadEdges);
	btAssert(heightfieldShape && "null heightfield");
	// scale the shape
	btVector3 localScaling = getUpVector(m_upAxis, s_gridSpacing, 1.0);
	heightfieldShape->setLocalScaling(localScaling);

	// stash this shape away
	m_collisionShapes.push_back(heightfieldShape);
	// set origin to middle of heightfield
	btTransform tr;
	tr.setIdentity();
	tr.setOrigin(btVector3(0,-20,0));
	// create ground object
	float mass = 0.0;
	localCreateRigidBody(mass, tr, heightfieldShape);
}
#endif
