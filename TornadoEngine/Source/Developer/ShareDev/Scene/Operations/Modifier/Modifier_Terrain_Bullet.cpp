/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Modifier_Terrain_Bullet.h"

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

  for( auto& x_map : mPatternTerrain->mX_Y_PartPhysic )
  {
    for( auto& y_part : x_map.second )
    {
      nsStructPattern_Terrain::TTerrainPart_Physic* pPart = &(y_part.second);
      // уничтожить внутреннее состояние
      delete pPart->pRB->getMotionState();
      pPart->pRB->setMotionState(NULL);
      // удалить из Мира 
      pWorld->removeCollisionObject(pPart->pRB);
      // освободить память
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
  mBuilderTool_Bullet.SetID_PhysicWorld(mPatternTerrain->GetPhysicWorld());
  for( auto& x_map : mPatternTerrain->mX_Y_PartPhysic )
  {
    for( auto& y_part : x_map.second )
    {
      nsStructPattern_Terrain::TTerrainPart_Physic* pPart = &(y_part.second);
      pPart->pData = new nsStructPattern_Terrain::THeightMapTerrain;

      pPart->pData->size       = mDescTarget.sizePart;
      pPart->pData->worldSize  = mDescTarget.worldSizePart;
      pPart->pData->inputScale = mDescTarget.inputScale;
      pPart->pData->inputBias  = mDescTarget.inputBias;
      // расчет позиции
      // регулирование высоты
      float default_height = mDescTarget.height;// 39.5f;
      pPart->pData->pos.x = x_map.first*pPart->pData->worldSize;
      pPart->pData->pos.y = default_height;
      pPart->pData->pos.z = y_part.first*pPart->pData->worldSize;

      int cntPoint = pPart->pData->size*pPart->pData->size;
      pPart->pData->cHeight.SetData(NULL, sizeof(float)*cntPoint);
      // высота равна 0
      memset(pPart->pData->cHeight.GetPtr(),0,sizeof(float)*cntPoint);
      // make collision shape  
      int width  = pPart->pData->size;
      int lenght = pPart->pData->size;
      float s_gridHeightScale = 1.0f;
      int m_upAxis            = 1;
      PHY_ScalarType m_type   = PHY_FLOAT;
      bool flipQuadEdges      = false;
      float m_minHeight       = 0;
      float m_maxHeight       = 0;

      pPart->pHeightfieldShape = new btHeightfieldTerrainShape(width, lenght,
        pPart->pData->cHeight.GetPtr(),
        s_gridHeightScale,
        m_minHeight, m_maxHeight,
        m_upAxis, m_type, flipQuadEdges);

      pPart->pHeightfieldShape->setUseZigzagSubdivision(true);

      float scaleAxe = pPart->pData->worldSize/(pPart->pData->size-1);
      btVector3 scale;
      scale.setX(scaleAxe);
      scale.setY(1);
      scale.setZ(scaleAxe);
      pPart->pHeightfieldShape->setLocalScaling(scale);

      btTransform tr;
      tr.setIdentity();
      btVector3 pos;
      pos.setX(pPart->pData->pos.x);
      pos.setY(pPart->pData->pos.y);
      pos.setZ(pPart->pData->pos.z);
      tr.setOrigin(pos);

      // create ground object
      float mass = 0.0;
      pPart->pRB = mBuilderTool_Bullet.localCreateRigidBody(mass, tr, pPart->pHeightfieldShape,true);
    }
  }
}
//------------------------------------------------------------------------
