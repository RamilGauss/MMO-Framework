/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterPhysicEngineH
#define AdapterPhysicEngineH

#include "PrototypePhysicEngine.h"

class DllExport AdapterPhysicEngine : public PrototypePhysicEngine
{
public:
  AdapterPhysicEngine();
  virtual ~AdapterPhysicEngine();

  virtual void AddObject(IBaseObjectPE* pObject);
  virtual void Clear();
  virtual void InitState();
  virtual void Calc();

public:
  //std::list<IBaseObjectPE*> mListObject;
  //// список разрушенных или поврежденных объектов.
  //std::list<IBaseObjectPE*> mListDamageObject;

  //struct TEvent
  //{

  //};
  //std::list<TEvent*> mListFreshEvent;

public:
  virtual PrototypeBaseModule* NewExample();
  virtual void DeleteExample(PrototypeBaseModule* ptr);

  virtual int GetVersionAdapter();

  virtual bool Work();
};


#endif

