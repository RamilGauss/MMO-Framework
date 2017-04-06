/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GameObjectH
#define GameObjectH

#include "TypeDef.h"
//#include <string>
//#include <boost/smart_ptr/scoped_ptr.hpp>

class TBehaviourPatternModel;
//class TBehaviourPatternContext;

/*
  Содержит данные, которые не зависят от типа Паттерна.
  Зависит только от Ogre, Bullet и OpenAL.
  Класс-контейнер для наследуемого контекста.
*/

class DllExport TGameObject
{
  int mID;

  // поведение - зависит от типа (Model, Terrain, Zone, Light, Sound, Animated, Sky)
  TBehaviourPatternModel* mPtrModel;
  //TBehaviourPatternContext* mPtrContext;

public:
  TGameObject();
  virtual ~TGameObject();

  int GetID() const;
  void SetID( int id );

  void SetModel(TBehaviourPatternModel* p);
	// нельзя хранить указатель на модель объекта, всегда делать запрос перед использованием 
  TBehaviourPatternModel* GetModel();

  //void SetContext(TBehaviourPatternContext* p);
  //TBehaviourPatternContext* GetContext();
};

#endif
