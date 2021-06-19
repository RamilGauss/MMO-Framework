/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef BuilderTool_ShapeCylinder_BulletH
#define BuilderTool_ShapeCylinder_BulletH

#include "TypeDef.h"
#include "BuilderTool_ShapeBase_Bullet.h"

struct TShapeItem;

class DllExport TBuilderTool_ShapeCylinder_Bullet : public TBuilderTool_ShapeBase_Bullet
{
public:
  TBuilderTool_ShapeCylinder_Bullet();

  virtual btRigidBody* CreateRigidBody();
protected:

};

#endif
