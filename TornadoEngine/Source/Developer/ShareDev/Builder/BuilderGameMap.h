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

class TFactoryGameItem;
class TGameObject;
class TGameTableSound;
class TTaskForBuilder;
struct TTableSoundItem;

/*
  Алгоритм работы с классом:
    1. Настройка - Init(указать потоки).
    2. Проверка GetState.
    3. Дать квант времени по потокам - только если состояние eLoadMap (не давать физике квант),
    eObjectOperation - квант движкам, квант сборщику.
*/

class DllExport TBuilderGameMap
{
  TMapItem*        mMapItem;
  TTableSoundItem* mTableSound;

  TGameTableSound* mGameTableSound;

  volatile bool flgLoading;
  
  volatile int mCountTask_Ogre;
  volatile int mCurrentLoadTask_Ogre;
  
  volatile int mCountTask_Bullet;
  volatile int mCurrentLoadTask_Bullet;
  
  volatile int mCountTask_OpenAL;
  volatile int mCurrentLoadTask_OpenAL;
public:
  TBuilderGameMap();
  virtual ~TBuilderGameMap();

  typedef enum{eOgre, eBullet, eOpenAL} eTypeThread;
  void Init( std::vector<eTypeThread>& vec, TFactoryGameItem* pFactoryGameItem );
  // кэширование структуры карты и подготовка данных для загрузки из разных потоков
  // для каждого потока готовится список целей
  bool BuildMap( TMapItem* pMI );              // вызывать только если состояние eIdle
  bool AddObject( TMapItem::TObject* pObject );// вызывать только если состояние eIdle
  bool DeleteObject( TGameObject* pObject );   // вызывать только если состояние eIdle

  typedef enum{eBuildMap,       // полностью требуется отдать квант
               eObjectOperation,// сначало отдать квант движкам, потом загрузчику
               eEndBuildMap,    // сборка карты завершена, можно забрать результат, фактически это eIdle
               eEndBuildObject, // сборка объекта завершена, можно забрать результат, фактически это eIdle
               eIdle,           // не требуется квант
  }State;
  State GetState();
  int GetProgress();
  // дать квант в потоках - нет блокировки, вернет управление
  void BuildFromThread_Ogre();
  void BuildFromThread_Bullet();
  void BuildFromThread_OpenAL();

  // забрать результат сборки
  void Get(std::vector<TGameObject*>& vecPtrGameObject);
private:

  std::string              mNameMapItem;
  TFactoryGameItem*        mFactoryGameItem;
  std::vector<eTypeThread> mVecThread;

  typedef std::vector<TTaskForBuilder*> TVectorPtrTask;

  TVectorPtrTask mVecTask_OGRE;
  TVectorPtrTask mVecTask_Bullet;
  TVectorPtrTask mVecTask_OpenAL;

  volatile State mState;
private:
  bool CheckIdle();
};

#endif
