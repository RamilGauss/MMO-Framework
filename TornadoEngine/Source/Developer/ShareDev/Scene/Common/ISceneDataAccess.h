/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ISceneDataAccessH
#define ISceneDataAccessH

class TGameObject;

class ISceneDataAccess
{
public:
  ISceneDataAccess();

  // выборка
  virtual int GetCountUsing() = 0;                    // mainly for debug
  virtual TGameObject* GetUsingByIndex(int index) = 0;// mainly for debug
  virtual TGameObject* GetUsingByID(int id) = 0;

  virtual int GetCountNotUsing() = 0;                    // mainly for debug
  virtual TGameObject* GetNotUsingByIndex(int index) = 0;// mainly for debug
  virtual TGameObject* GetNotUsingByID(int id) = 0;

  virtual int GetCount() = 0;
  virtual TGameObject* GetByIndex(int index) = 0;
  virtual TGameObject* GetByID(int id) = 0;

  // манипуляции
  virtual void Include(TGameObject* pGO) = 0;
  virtual void Exclude(int id) = 0;
  
  // набор методов, в основном, для системы коллизий,
  // используется ли в конвейере игрового процесса
  virtual void SetUsing(int id, bool v) = 0;
  virtual bool GetUsing(int id) = 0;
};

#endif
