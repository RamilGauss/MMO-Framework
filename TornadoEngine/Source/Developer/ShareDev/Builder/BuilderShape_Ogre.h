/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#ifndef BuilderShape_OgreH
#define BuilderShape_OgreH

#include "TypeDef.h"

#include <OgrePrerequisites.h>
#include <OgreMesh.h>

struct TShapeItem;

class DllExport TBuilderShape_Ogre
{
  TShapeItem* mShape;

  Ogre::MeshPtr mMeshPtr;
public:
  TBuilderShape_Ogre();
  ~TBuilderShape_Ogre();

  Ogre::MeshPtr Build(TShapeItem* pShape);
private:
  void BuildPlate();
  void BuildPlateVarGeom();
  void BuildSphere();
  void BuildCone();
  void BuildTrapezium();
  void BuildTriangularPyramid();
  void BuildQuadrangularPyramid();
  void BuildCylinder();
  void BuildTriangularPrism();

};

#endif
