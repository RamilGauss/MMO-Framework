/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Builder_BulletH
#define Builder_BulletH

#include "TypeDef.h"
#include "BuilderShape_Bullet.h"

class DllExport TBuilder_Bullet 
{
  int mID_PhysicWorld;

  TBuilderShape_Bullet mBuilderShape_Bullet;
public:
  TBuilder_Bullet();
  virtual ~TBuilder_Bullet();

  void SetID_PhysicWorld( int id );

  TBuilderShape_Bullet* GetShapeMaker();
};

#endif
