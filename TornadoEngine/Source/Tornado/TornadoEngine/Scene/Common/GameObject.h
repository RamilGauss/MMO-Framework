/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef GameObjectH
#define GameObjectH

#include "TypeDef.h"

class TBehaviourPattern;

class DllExport TGameObject
{
  int mID;
  // поведение - зависит от типа (Model, Terrain, Volume, Light, Sound, Animated, Sky)
  TBehaviourPattern* mPtrPattern;

public:
  TGameObject();
  virtual ~TGameObject();

  int GetID() const;
  void SetID( int id );

  void SetPattern(TBehaviourPattern* p);
  TBehaviourPattern* GetPattern();
};

#endif
