/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SynchroPointH
#define SynchroPointH

#include "TypeDef.h"
#include <vector>
#include <list>

#include "IContainer.h"
#include "ListMultiThread.h"
#include "ContainerArrObj.h"

class DllExport TSynchroPoint
{
  typedef TListMultiThread<IContainer>  TListContainer;

  typedef std::map<int,TListContainer*> TMapIntPtr;
  typedef TMapIntPtr::iterator          TMapIntPtrIt;
  typedef TMapIntPtr::value_type        TMapIntPtrVT;

	typedef std::map<int,TMapIntPtr> TMapIntMap;
  typedef TMapIntMap::iterator     TMapIntMapIt;
  typedef TMapIntMap::value_type   TMapIntMapVT;

  TMapIntMap mMap_Recv_Sender_ListEvent;

  typedef std::list<int> TListInt;
  
  TListInt mListIDAbonent;

public:
  TSynchroPoint();
  virtual ~TSynchroPoint();

  void SetupAfterRegister();
protected:
  friend class TSynchroAbonent;

  // регистрация одного абонента на события другого
  void Register(int id_abonent);

  // Добавить событие с/без копирования
  void AddEventCopy(int id_sender, int id_recv, void* data, int size);
	template <typename T>
  void AddEventWithoutCopy(int id_sender, int id_recv, T* pObject);
  void AddEventWithoutCopy(int id_sender, int id_recv, IContainer* pC);

  // забрать событие от определенного абонента, удалять нельзя
  IContainer* GetEvent(int id_reciver, int& id_sender);
private:
  void AddEvent(int id_sender, int id_recv, void* data, int size, bool copy);
	bool FindListEvents(int id_sender, int id_recv, TMapIntPtrIt& fitSendList);
  void Done();
};
//-----------------------------------------------------------------------------------------
template <typename T>
void TSynchroPoint::AddEventWithoutCopy(int id_sender, int id_recv, T* pObject)
{
  TMapIntPtrIt fitSendList;
  if(FindListEvents(id_sender, id_recv, fitSendList)==false)
    return;

  IContainer* pC = new TContainerArrObj<T>;
  pC->EntrustByCount((char*)pObject, 1);
  fitSendList->second->Add(pC);
}
//-----------------------------------------------------------------------------------------

#endif
