/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BehaviourPatternModelH
#define BehaviourPatternModelH

/*
  Базовый тип поведения игрового объекта.

  Идеология: модель-логика без данных.
  Контекст: данные для модели для текущего вызова функции.
  GameObject: данные только Ogre, Bullet, OpenAL.
  Контекст: надстройка данных над Ogre, Bullet, OpenAL.

  Реализация класса предполагает: данные, которые используются для загрузки объекта не меняются
  в процессе загрузки. В частности это FactoryGameItem.
*/

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "MathTools.h"
#include "MapItem.h"

#include "Builder_Ogre.h"
#include "Destructor_Ogre.h"

#include "Builder_Bullet.h"
#include "Destructor_Bullet.h"

#include "Builder_OpenAL.h"
#include "Destructor_OpenAL.h"

class TFactoryGameItem;
class TFactoryBehaviourPatternModel;
class TBehaviourPatternContext;

class DllExport TBehaviourPatternModel
{
  std::string mName;
protected:
	TBehaviourPatternContext* mCurCtx;// текущий контекст для работы
public:
  TBehaviourPatternModel();
  virtual ~TBehaviourPatternModel();

  void SetName(std::string v);
  std::string GetName();

  virtual TBehaviourPatternContext* MakeNewConext();
  // при сохранении карты/объекта,
  // что бы знать какие ключи вообще возможны, проектирование новых карт
  virtual void GetDefaultParameterMap(TMapItem::TMapStrStr& m);

  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TBehaviourPatternContext* pContext, TContainer c);
  virtual TContainer GetParameterToPattern(TBehaviourPatternContext* pContext);// Slave

  // тип - подвижный, неподвижный - для оптимизации (в основном для моделей)
  // требуется ли каждый физ. кадр синхронизировать с графикой и звуком
  virtual bool GetNeedSynchro(TBehaviourPatternContext* pContext);// B

  //virtual bool LoadFromParameterMap();// L
  virtual bool UpdateFromGameItem(TBehaviourPatternContext* pContext, TBaseItem* pBI);// L

	// разделение по модулям нужно потому что у разных реализаций разное кол-во модулей

	// Выполнить задания в каждом из потоков
  // Правило(загрузка,синхронизация,выгрузка): 
  // сначала отрабатывает поток Логики, потом уже все остальные потоки
  virtual void LoadFromThread_Logic(TBehaviourPatternContext* pContext);
  virtual bool LoadFromThread_Ogre(TBehaviourPatternContext* pContext,   bool fast = false);
  virtual bool LoadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast = false);
  virtual bool LoadFromThread_OpenAL(TBehaviourPatternContext* pContext, bool fast = false);

  virtual void UnloadFromThread_Logic(TBehaviourPatternContext* pContext);
  virtual bool UnloadFromThread_Ogre(TBehaviourPatternContext* pContext,   bool fast = false);
  virtual bool UnloadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast = false);
  virtual bool UnloadFromThread_OpenAL(TBehaviourPatternContext* pContext, bool fast = false);

  virtual void SynchroFromThread_Logic(TBehaviourPatternContext* pContext); // внешняя синхронизация от сервера(MMO)
  virtual void SynchroFromThread_Ogre(TBehaviourPatternContext* pContext);  // графика от физики
  virtual void SynchroFromThread_Bullet(TBehaviourPatternContext* pContext);// внутренняя синхронизация (коллизии, у клиента тут пусто)
  virtual void SynchroFromThread_OpenAL(TBehaviourPatternContext* pContext);// звук от физики

	virtual int GetBaseType();

	//###
	virtual void SetContext(TBehaviourPatternContext* pContext);
	//###
protected:
  TBuilder_Ogre*   GetBuilderOgre();
  TBuilder_Bullet* GetBuilderBullet();
  TBuilder_OpenAL* GetBuilderOpenAL();

  TDestructor_Ogre*   GetDestructorOgre();
  TDestructor_Bullet* GetDestructorBullet();
  TDestructor_OpenAL* GetDestructorOpenAL();

};

#endif
