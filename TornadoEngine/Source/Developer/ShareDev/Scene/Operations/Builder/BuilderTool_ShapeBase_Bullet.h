/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef BuilderTool_ShapeBase_BulletH
#define BuilderTool_ShapeBase_BulletH

#include "TypeDef.h"
#include "BuilderTool_Bullet.h"

#include "ParamBuilderShape.h"

#include <CollisionDispatch/btCollisionObjectWrapper.h>

struct TShapeItem;
struct TMaterialItem;
class btRigidBody;

class DllExport TBuilderTool_ShapeBase_Bullet : public TBuilderTool_Bullet
{
protected:
  TShapeItem* mShape;
  TMaterialItem* mMaterial;
public:
  TBuilderTool_ShapeBase_Bullet();
  virtual ~TBuilderTool_ShapeBase_Bullet();

  virtual void SetShape(TShapeItem* pShape);
  virtual void SetMaterial(TMaterialItem* pMaterial);

  virtual btRigidBody* CreateRigidBody() = 0;
protected:
};

#endif
