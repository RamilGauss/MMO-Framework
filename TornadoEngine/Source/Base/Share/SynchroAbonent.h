/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SynchroAbonentH
#define SynchroAbonentH

#include "TypeDef.h"
#include <map>
#include "ContainerTypes.h"
#include "GCS.h"

/*
  Связка пары TSynchroAbonent и TSynchroPoint
  работает по аналогии работы сайта youtube, когда один абонент
  закидывает видео на сервер (точка синхронизации) и остальные
  абоненты забирают события (копирование событий, удалять нельзя!).
	После того, как все зарегистрированные заберут событие,
	событие удаляется.
*/


class TSynchroPoint;

class DllExport TSynchroAbonent
{
  int mSelfID;

  TSynchroPoint* mSynchroPoint;

  // кэш данных от точки синхронизации
  typedef std::map<int,TContainer*> TMapIntPtr;
  typedef TMapIntPtr::iterator TMapIntPtrIt;
  typedef TMapIntPtr::value_type TMapIntPtrVT;

  TMapIntPtr mMapID_LastEvent;

  GCS mMutexAddGet;
public:
  TSynchroAbonent();
  virtual ~TSynchroAbonent();

  // 1. Первое что нужно сделать при работе абонента - задать точку синхронизации
  void SetSynchroPoint(TSynchroPoint* p);

  // 2. Задать свой собственный идентификатор
  void SetSelfID(int id);

  // 3. Регистрация (как подписка на получение событий)
  void Register(int id_sender);

  // Добавить событие с/без копирования
  void AddEventCopy(void* data, int size);
  void AddEventWithoutCopy(void* data, int size);
  
  // забрать событие от определенного абонента, удалять нельзя
  TContainer* GetEvent(int id_sender);

protected:
	TContainer* FindContainerByID(int id);

  void lock()  {mMutexAddGet.lock();}
  void unlock(){mMutexAddGet.unlock();}
};

#endif