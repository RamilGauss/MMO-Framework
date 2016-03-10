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

class TFactoryGameItem;
class TGameObject;

class DllExport TBuilderGameMap
{
public:
  typedef enum{eOGRE, eBullet, eOpenAL} eTypeThread;
private:
  std::string              mNameMapItem;
  TFactoryGameItem*        mFactoryGameItem;
  std::vector<eTypeThread> mVecThread;

  struct TTask
  {
    TGameObject* pObject;
    TTask(){pObject=NULL;}
  };

  typedef std::vector<TTask> TVectorTask;

  TVectorTask mVecTask_OGRE;
  TVectorTask mVecTask_Bullet;
  TVectorTask mVecTask_OpenAL;
public:
  TBuilderGameMap();
  virtual ~TBuilderGameMap();

  // по-умолчанию используются все потоки
  void SetupListThread(std::vector<eTypeThread>& vec);
  // кэширование структуры карты и подготовка данных для загрузки из разных потоков
  // для каждого потока готовится список целей
  bool BeginLoad(std::string& nameMapItem, TFactoryGameItem* pFactoryGameItem);

  // если progress_procent равен 100, то загрузка завершена
  void BuildFromThread_OGRE(int& progress_procent);
  void BuildFromThread_Bullet(int& progress_procent);
  void BuildFromThread_OpenAL(int& progress_procent);

  // забрать результат сборки
  void Get(std::vector<TGameObject*>& vecPtrGameObject);
private:
  
  bool PrepareTask_OGRE();
  bool PrepareTask_Bullet();
  bool PrepareTask_OpenAL();
};

#endif
