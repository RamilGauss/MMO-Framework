/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#ifndef FactoryBuilderTool_Shape_OgreH
#define FactoryBuilderTool_Shape_OgreH

#include "TypeDef.h"

#include <OgrePrerequisites.h>
#include <OgreMesh.h>
#include <map>
#include "ParamBuilderShape.h"

struct TShapeItem;
struct TMaterialItem;
class TBuilderTool_ShapeBase_Ogre;

class DllExport TFactoryBuilderTool_Shape_Ogre
{
  TShapeItem*    mShape;
  TMaterialItem* mMaterial;
  
  Ogre::Entity* mPtrEntity;

  std::string mNameEntity;

  int mCntShape;

  typedef std::map<nsParamBuilderShape::eType,TBuilderTool_ShapeBase_Ogre*> TMapTypePtr;
  typedef TMapTypePtr::iterator              TMapTypePtrIt;
  typedef TMapTypePtr::value_type            TMapTypePtrVT;

  TMapTypePtr mMapTypeBuilder;

protected:
  TFactoryBuilderTool_Shape_Ogre();
  virtual ~TFactoryBuilderTool_Shape_Ogre();
public:
  static TFactoryBuilderTool_Shape_Ogre* Get();

  Ogre::Entity* Build(TShapeItem* pShape);
protected:
  void FindMaterialByShape();
  void SetupBuilderMap();
};

#endif
