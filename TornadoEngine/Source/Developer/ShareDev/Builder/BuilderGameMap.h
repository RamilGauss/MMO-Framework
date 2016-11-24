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
#include "DataExchange2Thread.h"
#include "GameObject.h"
#include "CallBackRegistrator.h"

class TFactoryGameItem;
class TUsePattern;
struct TTableSoundItem;

class TCacheTableSound;
class TApplySetup_GravityVector;
class TApplySetup_CameraUp;
class TFactoryBehaviourPatternModel;


/*
  Алгоритм работы с классом:
    Настройка - Init.
    
    1. Дать задание
    2. Дать квант через потоки
    3. Проверка GetState.

    N. Логике вывести физический мир из паузы.
*/

class DllExport TBuilderGameMap
{
  TFactoryBehaviourPatternModel* mFactoryBehaviourPattern;
  TFactoryGameItem*         mFactoryGameItem;
  TUsePattern*              mUsePattern;
  int                       mPhysicWorldID;
  TMapItem*                 mMapItem;
  TTableSoundItem*          mTableSound;

  boost::scoped_ptr<TCacheTableSound>          mCTableSound;
  boost::scoped_ptr<TApplySetup_GravityVector> mAS_GravityVector;
  boost::scoped_ptr<TApplySetup_CameraUp>      mAS_CameraUp;

  bool flgNeedInitPhysic;

  enum
  {
    eMaxCountBuildObject = 10,
    eTimeWaitObject = 1,
  };
  typedef enum
  {
    eBulletThread, 
    eOgreThread, 
    eOpenALThread
  }TypeThread;
public:
  TBuilderGameMap();
  virtual ~TBuilderGameMap();

  void Init(TUsePattern* pUsePattern, TFactoryBehaviourPatternModel* pFBP);
  bool BuildMap( TMapItem* pMI );// вызывать только если состояние eIdle
  bool BuildObject( std::list<TMapItem::TObject>& listObject, 
    bool fast = false );// вызывать только если состояние eIdle

  typedef enum{eBuildMap,     // полностью требуется отдать квант
               eBuildObject,  // сначало отдать квант движкам, потом загрузчику
               eBuildComplete,// сборка завершена, можно забрать результат, фактически это eIdle
               eIdle,         // не требуется квант
  }State;
  State GetState();
  int GetProgress();
  void BuildFromThread_Logic();
  void BuildFromThread_Ogre();
  void BuildFromThread_Bullet();
  void BuildFromThread_OpenAL();

  typedef std::list<TGameObject*> TListPtrGameObject;
  typedef TListPtrGameObject::iterator TListPtrGameObjectIt;
  void GetResult(TListPtrGameObject& listPtrGameObject);
  int GetPhysicWorldID();
private:

  TListPtrGameObject mListGameObject;
  volatile State mState;
  
  void InitPhysic();

  typedef TDataExchange2Thread<TGameObject> TPipeToThreadFromLogic;
  struct TTaskForThread
  {
    volatile bool flgNeedInit;
    TPipeToThreadFromLogic pipe;
  };
  TTaskForThread mTask_Ogre;
  TTaskForThread mTask_Bullet;
  TTaskForThread mTask_OpenAL;

  void InitMapFrom_Bullet();
  void InitMapFrom_Ogre();
  void InitMapFrom_OpenAL();

  struct TProgressTask
  {
    int mCurIndex;
    int mCount;
  };

  TProgressTask mProgressTask_Bullet;
  TProgressTask mProgressTask_Ogre;
  TProgressTask mProgressTask_OpenAL;

  volatile int mAllCount;

  void BuildFromThread_XXX( 
    TTaskForThread& task, TCallBackRegistrator0& cbInit, 
    TProgressTask& progress, TypeThread typeThread );

  void CalcStatisticForProgress();

  TMapItem::TListObject::iterator mBeginIteratorMapObject;
};

#endif
  //----------------------------------------
#if 0
  TBuilderGameMap builder;
  builder.Init(NULL,NULL,0);
  //----------------------------------------
  bool resBuildMap = builder.BuildMap(NULL);
  BL_ASSERT(resBuildMap);
  //----------------------------------------
  builder.BuildFromThread_Ogre();
  builder.BuildFromThread_Bullet();
  builder.BuildFromThread_OpenAL();

  if( builder.GetState()==eBuildComplete )//
  {
    // переход на другой сценарий
    builder.GetResult();// сбор данных
  }
#endif
