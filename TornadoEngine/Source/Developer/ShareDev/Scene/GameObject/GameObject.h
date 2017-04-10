/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GameObjectH
#define GameObjectH

#include "TypeDef.h"

class TBehaviourPatternModel;

class DllExport TGameObject
{
  int mID;
  // поведение - зависит от типа (Model, Terrain, Zone, Light, Sound, Animated, Sky)
  TBehaviourPatternModel* mPtrModel;

public:
  TGameObject();
  virtual ~TGameObject();

  int GetID() const;
  void SetID( int id );

  void SetModel(TBehaviourPatternModel* p);
  TBehaviourPatternModel* GetModel();
};

#endif
