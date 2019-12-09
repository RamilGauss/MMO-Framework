/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/
#ifndef FactoryBuilderTool_Shape_BulletH
#define FactoryBuilderTool_Shape_BulletH

#include "TypeDef.h"

#include <map>
#include "ParamBuilderShape.h"

struct TShapeItem;
struct TMaterialItem;
class TBuilderTool_ShapeBase_Bullet;
class btRigidBody;

class DllExport TFactoryBuilderTool_Shape_Bullet
{
  TShapeItem*    mShape;
  TMaterialItem* mMaterial;

  std::string mNameEntity;

  typedef std::map<nsParamBuilderShape::eType,TBuilderTool_ShapeBase_Bullet*> TMapTypePtr;
  typedef TMapTypePtr::iterator              TMapTypePtrIt;
  typedef TMapTypePtr::value_type            TMapTypePtrVT;

  TMapTypePtr mMapTypeBuilder;
protected:
  TFactoryBuilderTool_Shape_Bullet();
  virtual ~TFactoryBuilderTool_Shape_Bullet();
public:
  btRigidBody* Build(int id_world, TShapeItem* pShape);

  static TFactoryBuilderTool_Shape_Bullet* Get();
protected:
  void FindMaterialByShape();
  void SetupBuilderMap();
};

#endif
