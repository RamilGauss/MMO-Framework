/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderGameMapH
#define BuilderGameMapH

#include "TypeDef.h"

#include "MapItem.h"
#include "DataExchange2Thread.h"
#include "GameObject.h"
#include "CallBackRegistrator.h"
#include "ListModules.h"

#include <string>
#include <vector>
#include <set>

class TFactoryGameItem;
class TUsePattern;
struct TTableSoundItem;

class TCacheTableSound;
class TApplySetup_GravityVector;
class TApplySetup_MapGraphicConfig;
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

  boost::scoped_ptr<TCacheTableSound>          		mCTableSound;
  boost::scoped_ptr<TApplySetup_GravityVector> 		mAS_GravityVector;
  boost::scoped_ptr<TApplySetup_MapGraphicConfig> mAS_CameraUp;

	std::set<int> mUseID_Module;

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

  void Init(std::set<int>& useID_Module, TFactoryBehaviourPatternModel* pFBP);
  bool BuildMap( TMapItem* pMI );// вызывать только если состояние eIdle

  typedef enum{eBuildMap,     // полностью требуется отдать квант
               eBuildComplete,// сборка завершена, можно забрать результат, фактически это eIdle
               eIdle,         // не требуется квант
  }State;
  State GetState();
  int GetProgress();
  void BuildByModule_Logic();
  void BuildByModule_Ogre();
  void BuildByModule_Bullet();
  void BuildByModule_OpenAL();

  typedef std::list<TGameObject*> TListPtrGameObject;
  typedef TListPtrGameObject::iterator TListPtrGameObjectIt;
  void GetResult(TListPtrGameObject& listPtrGameObject);
  int GetPhysicWorldID();
private:

  TListPtrGameObject mListGameObject;
  volatile State mState;
  
  void InitPhysic();

  typedef TDataExchange2Thread<TGameObject> TPipeToThreadFromLogic;
  struct TTaskForModule
  {
    volatile bool flgNeedInit;
    TPipeToThreadFromLogic pipe;
  };
  TTaskForModule mTask_Ogre;
  TTaskForModule mTask_Bullet;
  TTaskForModule mTask_OpenAL;

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

  void BuildByModule_XXX( 
    TTaskForModule& task, TCallBackRegistrator0& cbInit, 
		TProgressTask& progress, nsListModules::ID_Modules id_module);

  void CalcStatisticForProgress();

  TMapItem::TListObject::iterator mBeginIteratorMapObject;
};

#endif

