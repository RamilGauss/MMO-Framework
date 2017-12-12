/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderTool_ShapePlate_BulletH
#define BuilderTool_ShapePlate_BulletH

#include "TypeDef.h"

#include "ParamBuilderShape.h"
#include "MaterialItem.h"
#include "BuilderTool_ShapeBase_Bullet.h"

struct TShapeItem;
class btRigidBody;

class DllExport TBuilderTool_ShapePlate_Bullet : public TBuilderTool_ShapeBase_Bullet
{
public:
  TBuilderTool_ShapePlate_Bullet();
  virtual ~TBuilderTool_ShapePlate_Bullet();

  // Bullet thread only
  virtual btRigidBody* CreateRigidBody();
protected:
};

#endif
