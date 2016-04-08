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
#include "ContainerArrObj.h"
#include "DataExchange2Thread.h"

class DllExport TSynchroPoint
{
  typedef TDataExchange2Thread<IContainer>  TListContainer;

  struct TDescSender
  {
    int             id;
    TListContainer* pList;
  };
  typedef std::vector<TDescSender> TVectorDescSender;
  struct TDescRecv
  {
    int               id;
    TVectorDescSender vec;
  };
  typedef std::vector<TDescRecv> TVectorDescRecv;
  TVectorDescRecv mVecRecv;

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
  IContainer* GetEvent(int id_recv, int& id_sender);
private:
  void AddEvent(int id_sender, int id_recv, void* data, int size, bool copy);
  void Done();

  TDescSender* Find(int id_recv, int id_sender);
  TDescRecv* FindByRecv(int id_recv);
};
//-----------------------------------------------------------------------------------------
template <typename T>
void TSynchroPoint::AddEventWithoutCopy(int id_sender, int id_recv, T* pObject)
{
  TDescSender* pDescSender = NULL;
  pDescSender = Find(id_recv, id_sender);
  if(pDescSender)
  {
    IContainer* pC = new TContainerArrObj<T>;
    pC->EntrustByCount((char*)pObject, 1);
    pDescSender->pList->Add(pC);
  }
}
//-----------------------------------------------------------------------------------------

#endif
