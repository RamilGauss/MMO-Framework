/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IBehaviourPatternH
#define IBehaviourPatternH

#include "TypeDef.h"
#include "ContainerTypes.h"

class DllExport IBehaviourPattern
{
public:
  IBehaviourPattern();
  virtual ~IBehaviourPattern();

  // Сериализация
  virtual bool SetInternalState(TContainer c) = 0;
  virtual TContainer GetInternalState() = 0;

  // Визуализация

  // тип - подвижный, неподвижный - для оптимизации (в основном для моделей)
  // требуется ли каждый физ. кадр синхронизировать с графикой и звуком
  virtual bool GetNeedSynchro() = 0;

  // Применить 

  // Модификация
  // Обновить от такого же Паттерна
  virtual bool SetDescUpdate(TContainer c) = 0;
  virtual TContainer GetDescUpdate() = 0;

  virtual void SetPosition(nsMathTools::TVector3& v) = 0;
  virtual void SetOrientation(nsMathTools::TVector3& v) = 0;

  // Обновить от FGIObject
  // ???
  //virtual bool SetDescFGIObject(TContainer c) = 0;
  //virtual TContainer GetDescFGIObject() = 0;

  virtual void ThreadLogica();
  virtual void ThreadOgre();
  virtual void ThreadBullet();
  virtual void ThreadOpenAL();
};

#endif
