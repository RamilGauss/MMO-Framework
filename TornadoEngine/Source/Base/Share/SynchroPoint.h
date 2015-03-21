/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SynchroPointH
#define SynchroPointH

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "ListMultiThread.h"
#include <vector>

class DllExport TSynchroPoint
{
	typedef TListMultiThread<TContainer>  TListContainer;

  typedef std::map<int,TListContainer*> TMapIntPtr;
  typedef TMapIntPtr::iterator          TMapIntPtrIt;
  typedef TMapIntPtr::value_type        TMapIntPtrVT;

	typedef std::map<int,TMapIntPtr> TMapIntMap;
  typedef TMapIntMap::iterator     TMapIntMapIt;
  typedef TMapIntMap::value_type   TMapIntMapVT;

  TMapIntMap mMap_Sender_Recv_ListEvent;
public:
  TSynchroPoint();
  virtual ~TSynchroPoint();
protected:
  friend class TSynchroAbonent;

  // регистрация одного абонента на события другого
  void Register(int id_reciver, int id_sender);

  // Добавить событие с/без копирования
  void AddEventCopy(int id_sender, void* data, int size);
  void AddEventWithoutCopy(int id_sender, void* data, int size);

  void AddEventCopy(int id_sender, int id_recv, void* data, int size);
  void AddEventWithoutCopy(int id_sender, int id_recv, void* data, int size);

  // забрать событие от определенного абонента, удалять нельзя
  bool GetEvent(int id_reciver, int id_sender, TContainer* pC_out);// копия
private:
  void AddEvent(int id_sender, void* data, int size, bool copy);
  void AddEvent(int id_sender, int id_recv, void* data, int size, bool copy);

  void Done();
};

#endif
