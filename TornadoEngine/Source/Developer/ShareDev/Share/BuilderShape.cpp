/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderShape.h"

#include <Ogre.h>
#include <OgreManualObject.h>

TBuilderShape::TBuilderShape()
{

}
//-----------------------------------------------------------------------------
TBuilderShape::~TBuilderShape()
{

}
//-----------------------------------------------------------------------------
Ogre::MeshPtr TBuilderShape::Build(nsParamBuilderShape::TBaseParam* pParam)
{
  // выбрать из списка шаблон
  const float size = 60;
  Ogre::ManualObject mo("Cube");

  mo.begin("Cube", Ogre::RenderOperation::OT_TRIANGLE_LIST);

  mo.position(-size, -size, -size);
  mo.textureCoord(0, 0);

  mo.position(-size, size, -size);
  mo.textureCoord(1, 0);

  mo.position(size, size, -size);
  mo.textureCoord(1, 1);

  mo.position(size, -size, -size);
  mo.textureCoord(0, 1);
  //-----------------------------------  
  mo.position(-size, -size, size);
  mo.textureCoord(1, 0);

  mo.position(-size, size, size);
  mo.textureCoord(0, 0);

  mo.position(size, size, size);
  mo.textureCoord(1, 1);

  mo.position(size, -size, size);
  mo.textureCoord(0, 1);

  mo.triangle(0,1,2);
  mo.triangle(0,2,3);

  mo.triangle(0,4,5);
  mo.triangle(0,5,1);

  mo.triangle(3,2,6);
  mo.triangle(3,6,7);

  mo.triangle(0,7,4);
  mo.triangle(0,3,7);

  mo.triangle(1,5,6);
  mo.triangle(1,6,2);

  mo.triangle(4,6,5);
  mo.triangle(4,7,6);
  mo.end();

  Ogre::MeshPtr ptr = mo.convertToMesh("GrassBladesMesh");

  return ptr;
}
//-----------------------------------------------------------------------------
