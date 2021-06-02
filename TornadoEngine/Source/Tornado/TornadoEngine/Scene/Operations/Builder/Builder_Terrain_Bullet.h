/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef Builder_Terrain_BulletH
#define Builder_Terrain_BulletH

#include "TypeDef.h"
#include "BuilderTool_Terrain_Bullet.h"
#include "Builder_Terrain.h"

class DllExport TBuilder_Terrain_Bullet : public TBuilder_Terrain
{
  TBuilderTool_Terrain_Bullet mBuilder;
public:
  TBuilder_Terrain_Bullet();
  virtual ~TBuilder_Terrain_Bullet();

  virtual void Begin();
  virtual void Load(int x, int y);
  virtual void End();
protected:
};

#endif
