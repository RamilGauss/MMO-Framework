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

  typedef std::vector<TListContainer*> TVecPtr;
  typedef std::vector<TVecPtr> TVecVec;
  TVecVec mVec_Recv_Sender_ListEvent;

  typedef std::vector<int> TVectorInt;
  
  TVectorInt mVecIDAbonent;

public:
  TSynchroPoint();
  virtual ~TSynchroPoint();

  void SetupAfterRegister();
protected:
  friend class TSynchroAbonent;

  // регистрация абонента
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
  void Done();
};
//-----------------------------------------------------------------------------------------
template <typename T>
void TSynchroPoint::AddEventWithoutCopy(int id_sender, int id_recv, T* pObject)
{
  if(id_recv >= int(mVec_Recv_Sender_ListEvent.size()))
  {
    BL_FIX_BUG();
    return;
  }

  TVecPtr& vecList = mVec_Recv_Sender_ListEvent[id_recv];

  IContainer* pC = new TContainerArrObj<T>;
  pC->EntrustByCount((char*)pObject, 1);
  vecList[id_sender]->Add(pC);
}
//-----------------------------------------------------------------------------------------

#endif
