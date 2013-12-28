/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BreakPacketH
#define BreakPacketH

#include <list>

#include "TypeDef.h"
#include "ContainerPtr.h"
#include "Container.h"

/*
  Разбитый на части пакет. Например, когда нужно добавлять на каждом уровне 
  иерархии новый заголовок, вместо выделения новой памяти (+ размер заголовка)и копирования
  туда данных, можно накапливать данные, а на последнем этапе агрегировать данные в пакет.
*/

class SHARE_EI TBreakPacket
{
protected:
  typedef std::list<TContainerPtr> TListC_Ptr;
  typedef TListC_Ptr::iterator TListC_PtrIt;

  TListC_Ptr mList;

  TContainer mCollect;

public:
  TBreakPacket();
  virtual ~TBreakPacket();

  // добавить кусок памяти
  void PushBack(char* p,int size);
  void PushFront(char* p,int size);
  // собрать кусочки в одно целое (копированием), 
  // теперь можно получить указатель на собранный пакет через GetPtr
  // если кол-во частей равно 1, то сборки не будет.
  void Collect();
  void* GetCollectPtr();
  int GetSize();
  // кол-во частей
  int GetCountPart();

  // освободить память, которая использовалась под собранный пакет
  void DeleteCollect();

  void UnlinkPart();

  void UnlinkCollect();

  const TBreakPacket& operator =( const TBreakPacket& b );

  std::list<TContainerPtr>* GetList(){return &mList;}
protected:
};


#endif

