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
	TBehaviourPatternContext* mContext;// текущий контекст для работы
public:
  TBehaviourPatternModel();
  virtual ~TBehaviourPatternModel();

  void SetName(std::string v);
  std::string GetName();

  // при сохранении карты/объекта,
  // что бы знать какие ключи вообще возможны, проектирование новых карт
  virtual void GetDefaultParameterMap(TMapItem::TMapStrStr& m);

  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TContainer c);
  virtual TContainer GetParameterToPattern();// Slave

  // тип - подвижный, неподвижный - для оптимизации (в основном для моделей)
  // требуется ли каждый физ. кадр синхронизировать с графикой и звуком
  virtual bool GetNeedSynchro();// B

  //virtual bool LoadFromParameterMap();// L
  virtual bool UpdateFromGameItem(TBaseItem* pBI);// L

	// разделение по модулям нужно потому что у разных реализаций разное кол-во модулей

  // Правило(загрузка,синхронизация,выгрузка): 
  // сначала отрабатывает функция Логики, потом уже все остальные
  virtual void LoadByModule_Logic();// инициализация внутренней структуры
  virtual bool LoadByModule_Graphic(bool fast = false);
  virtual bool LoadByModule_Physic( bool fast = false);
  virtual bool LoadByModule_Sound(  bool fast = false);

  virtual void UnloadByModule_Logic();// подготовка к освобождению ресурсов
  virtual bool UnloadByModule_Graphic(bool fast = false);
  virtual bool UnloadByModule_Physic( bool fast = false);
  virtual bool UnloadByModule_Sound(  bool fast = false);

  virtual void SynchroByModule_Logic();  // внешняя синхронизация от сервера(например,MMO)
  virtual void SynchroByModule_Graphic();// графика от физики
  virtual void SynchroByModule_Physic(); // внутренняя синхронизация (физика влияет сама на себя)
  virtual void SynchroByModule_Sound();  // звук от физики

	virtual int GetBaseType();

	virtual void SetContext();
	virtual TBehaviourPatternContext* GetContext();
protected:
  virtual TBehaviourPatternContext* MakeNewConext();

  TBuilder_Ogre*   GetBuilderOgre();
  TBuilder_Bullet* GetBuilderBullet();
  TBuilder_OpenAL* GetBuilderOpenAL();

  TDestructor_Ogre*   GetDestructorOgre();
  TDestructor_Bullet* GetDestructorBullet();
  TDestructor_OpenAL* GetDestructorOpenAL();

};

#endif
