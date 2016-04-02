/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DestructorGameObjectH
#define DestructorGameObjectH

#include "TypeDef.h"
#include "PreDestructor.h"
#include <list>

class TGameObject;

class DllExport TDestructorGameObject
{
public:
  TDestructorGameObject();
  virtual ~TDestructorGameObject();

  void Init( TPreDestructor::TVectorTypeTask& vec );
  bool DesctructObject( std::list<TGameObject*>& pListObject );// вызывать только если состояние eIdle

  typedef enum{eDestruct, eIdle}State;
  State GetState();
  // дать квант в потоках - нет блокировки, вернет управление
  void DestructFromThread_Ogre();
  void DestructFromThread_Bullet();
private:
  State mState;
};

#endif
