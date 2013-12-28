/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef RobertH
#define RobertH

#include "IPhysicEngine.h"

// предсказатель
// Robert - физический движок
class TPhysicEngine : public IPhysicEngine
{
public:

  TPhysicEngine();
  virtual ~TPhysicEngine();

  void AddObject(IBaseObjectPrediction* pObject);
  void Clear();


  void InitState();

  void Calc();


/*public:
  std::list<IBaseObjectPrediction*> mListObject;
  // список разрушенных или поврежденных объектов.
  std::list<IBaseObjectPrediction*> mListDamageObject;

  struct TEvent
  {

  };
  std::list<TEvent*> mListFreshEvent;
*/
};


#endif

