/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ISceneDataAccess.h"
#include "ISceneSystemCollision.h"
#include <map>

class TGameObject;

class TScene : public ISceneDataAccess, public ISceneSystemCollision
{
  typedef std::map<int, TGameObject*> TMapIntPtr;
  typedef TMapIntPtr::iterator       TMapIntPtrIt;
  typedef TMapIntPtr::value_type     TMapIntPtrVT;

  TMapIntPtr mMapID_UsingGO;
  TMapIntPtr mMapID_NotUsingGO;

  // подвижные объекты - для внутренней синхронизации
  // для оптимизации процесса - создать список подвижных и включенных в конвейер
  //###
public:
  TScene();
  virtual ~TScene();

  // выборка
  virtual int GetCountUsing();
  virtual TGameObject* GetUsingByIndex( int index );
  virtual TGameObject* GetUsingByID( int id );

  virtual int GetCountNotUsing();
  virtual TGameObject* GetNotUsingByIndex( int index );
  virtual TGameObject* GetNotUsingByID( int id );

  // сначала using, потом notUsing
  virtual int GetCount();
  virtual TGameObject* GetByIndex( int index );
  virtual TGameObject* GetByID( int id );

  // манипуляции
  virtual void Include( TGameObject* pGO );
  virtual void Exclude( int id );

  // набор методов, в основном, для системы коллизий,
  // используется ли в конвейере игрового процесса
  virtual void SetUsing( int id, bool v );
  virtual bool GetUsing( int id );
  //---------------------------------------------------------------------------
  virtual void RefreshCollision();
  //---------------------------------------------------------------------------
private:
  bool Move( TMapIntPtr& fromMap, TMapIntPtr& toMap, int id );

  int GetCount( TMapIntPtr& m );
  TGameObject* GetByIndex( TMapIntPtr& m, int index );
  TGameObject* GetByID( TMapIntPtr& m, int id );

  void WorkByModule_Logic();
  void WorkByModule_Graphic();
  void WorkByModule_Physic();
  void WorkByModule_Sound();
};
