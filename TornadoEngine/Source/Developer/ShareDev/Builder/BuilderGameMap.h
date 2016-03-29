/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderGameMapH
#define BuilderGameMapH

#include "TypeDef.h"
#include <string>
#include <vector>
#include "MapItem.h"
#include "FactoryPreBuilderGameObject.h"
#include "PreBuilder.h"

class TBuilder_Ogre;
class TBuilder_Bullet;
class TBuilder_OpenAL;
class TGameObject;
class TTaskForBuilder;
struct TTableSoundItem;

/*
  Алгоритм работы с классом:
    1. Настройка - Init(указать потоки).
    2. Проверка GetState.
    3. Дать квант времени по потокам - только если состояние eLoadMap (не давать физике квант),
    eBuildObject - квант движкам, квант сборщику.
*/

class DllExport TBuilderGameMap
{
  TMapItem*        mMapItem;
  TTableSoundItem* mTableSound;

  TFactoryPreBuilderGameObject mFactoryPreBuilderObject;

  std::string                  mNameMapItem;
  TFactoryGameItem*            mFactoryGameItem;
  TPreBuilder::TVectorTypeTask mVecTask;

  TPreBuilder::TListTaskOgre   mListTask_Ogre;
  TPreBuilder::TListTaskBullet mListTask_Bullet;
  TPreBuilder::TListTaskOpenAL mListTask_OpenAL;

  TPreBuilder::TListTaskOgre::iterator   mLastTask_Ogre;
  TPreBuilder::TListTaskBullet::iterator mLastTask_Bullet;
  TPreBuilder::TListTaskOpenAL::iterator mLastTask_OpenAL;

  boost::scoped_ptr<TBuilder_Ogre>   mBuilderOgre;
  boost::scoped_ptr<TBuilder_Bullet> mBuilderBullet;
  boost::scoped_ptr<TBuilder_OpenAL> mBuilderOpenAL;

  struct TProgressTask
  {
    int mCurIndex;// следующий на выполнение или кол-во сделанных
    int mCount;
  };

  volatile TProgressTask mProgressTask_Ogre;
  volatile TProgressTask mProgressTask_Bullet;
  volatile TProgressTask mProgressTask_OpenAL;

  volatile int mAllCount;
public:
  enum{CountTaskPerQuant=10,};
  TBuilderGameMap();
  virtual ~TBuilderGameMap();

  void Init( TPreBuilder::TVectorTypeTask& vec, TFactoryGameItem* pFactoryGameItem );
  // кэширование структуры карты и подготовка данных для загрузки из разных потоков
  // для каждого потока готовится список целей
  void InitPhysic( int id_physic_world );
  bool BuildMap( TMapItem* pMI );// вызывать только если состояние eIdle
  bool BuildObject( TMapItem::TObject* pObject );// вызывать только если состояние eIdle

  typedef enum{eBuildMap,     // полностью требуется отдать квант
               eBuildObject,  // сначало отдать квант движкам, потом загрузчику
               eBuildComplete,// сборка завершена, можно забрать результат, фактически это eIdle
               eIdle,         // не требуется квант
  }State;
  State GetState();
  int GetProgress();
  // дать квант в потоках - нет блокировки, вернет управление
  void BuildFromThread_Ogre();
  void BuildFromThread_Bullet();
  void BuildFromThread_OpenAL();

  // забрать результат сборки
  typedef std::list<TGameObject*> TListPtrGameObject;
  typedef TListPtrGameObject::iterator TListPtrGameObjectIt;

  void GetResult(TListPtrGameObject& listPtrGameObject);
private:
  TListPtrGameObject mListGameObject;
  volatile State mState;
private:
  bool CheckIdle();

  bool AddObject_Private( TMapItem::TObject* pObject );

  bool PrepareCameraUp();
  bool PrepareGravity();
  bool PrepareTableSound();
  bool PrepareGameObject();

  void CollectTask(TPreBuilder* pPreBuilder);
  void CalcStatisticForProgress();
  void PrepareIterator();

  template<typename TypeBuilderPtr, typename ListTaskIterator>
  void BuildFromThread_XXX(TProgressTask& progress, TypeBuilderPtr pBuilder, ListTaskIterator& iter)
  {
    int maxCount = CountTaskPerQuant;
    int calcMaxCount = progress.mCount - progress.mCurIndex;
    int cnt = std::min( maxCount, calcMaxCount);
    for( int i = 0 ; i < cnt ; i++ )
    {
      pBuilder->Work(*iter);
      iter++;
      progress.mCurIndex++;
    }
  }
};

#endif
