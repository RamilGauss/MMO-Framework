/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BreakPacketOldH
#define BreakPacketOldH

#include <list>

#include "TypeDef.h"
#include "ContainerTypes.h"

/*
  Разбитый на части пакет. Например, когда нужно добавлять на каждом уровне 
  иерархии новый заголовок, вместо выделения новой памяти (+ размер заголовка)и копирования
  туда данных, можно накапливать данные, а на последнем этапе агрегировать данные в пакет.
*/

class DllExport TBreakPacketOld
{
protected:
  struct DllExport TDescContainer
  {
    typedef enum{eContainer, eContainerPtr}TypeContainer;
    TypeContainer type;
    IContainer* pC;
    TDescContainer(){pC=NULL;}
    void Init(TypeContainer t)
    {
      type = t;
      if(type==eContainer)
        pC = new TContainer;
      else
        pC = new TContainerPtr;
    }
  };
  typedef std::list<TDescContainer*> TListPtrDescContainer;
  typedef TListPtrDescContainer::iterator TListPtrDescContainerIt;

protected:
  TListPtrDescContainer mList;

  TListPtrDescContainer mCacheContainerList;
  TListPtrDescContainer mCacheContainerPtrList;

  TContainer mCollect;
public:
  TBreakPacketOld();
  TBreakPacketOld(const TBreakPacketOld& bp);
  virtual ~TBreakPacketOld();

  // добавить кусок памяти
  // copyData=true - например если в цикле используется стековая переменная
  void PushBack( char* p, int size );//, bool copyData = false);
  void PushFront( char* p, int size );//, bool copyData = false);
  // собрать кусочки в одно целое (копированием), 
  // теперь можно получить указатель на собранный пакет через GetPtr
  // если кол-во частей равно 1, то сборки не будет.
  void Collect();
  void* GetCollectPtr();
  int GetSize();

  void Reset();
  void UnlinkCollect();

  TBreakPacketOld& operator =( const TBreakPacketOld& b );
protected:
  TDescContainer* PushData(char* p,int size, bool copyData);
  void CopyFrom(const TBreakPacketOld& bp);

  TDescContainer* GetDescContainer( bool copyData );
  TDescContainer* FindInCache( bool copyData );
  void AddInCache( TDescContainer* pDesc );
  void DeleteCache();
};


#endif

