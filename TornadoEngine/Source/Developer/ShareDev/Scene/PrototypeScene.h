/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeSceneH
#define PrototypeSceneH

#include "TypeEventScene.h"
#include <list>

class TGameObject;

class PrototypeScene
{
public:
  // 1. Добавление от класса Загрузчика, который загружал объект в нескольких потоках 
  typedef std::list<TGameObject*>& TListObject;

  virtual void Entrust(TListObject& listObject) = 0;
  virtual void Entrust(TGameObject* pObject) = 0;
  virtual void DeleteObject(unsigned int id) = 0;// ??? изъятие возможно ли?
  virtual void DeleteAllObject() = 0;            // ???
  
  // 2. Выборка
  virtual int  GetCount() = 0;
  virtual TGameObject* Get(int index) = 0;
  virtual TGameObject* Get(unsigned int id) = 0;

  // 3. Синхронизация
  virtual void UpdateFromPhysicThread() = 0;
  virtual void UpdateToGraphicThread() = 0;
  
  typedef std::list<nsTypeEventScene::TEvent*> TListEvent;

  virtual void UpdateFromOut(TListEvent& listEvent) = 0;
  virtual void UpdateToOut(TListEvent& listEvent)   = 0;// информация по всем подвижным объектам

  // 4. Выявление коллизий
    
};

#endif
