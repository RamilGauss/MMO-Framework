/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BreakPacketH
#define BreakPacketH

#include "TypeDef.h"
#include "ContainerTypes.h"

// Разбитый на части пакет. Например, когда нужно добавлять на каждом уровне иерархии новый заголовок.
// РЕКОМЕНДАЦИИ по использованию:
// НЕ использовать на стеке, тяжелый конструктор.
// Лучше не копировать объект.
// После внесения внутрь, менять внесенные переменные снаружи бессмысленно, внутри буфера они не поменяются.

class DllExport TBreakPacket
{
  int mSizeBuffer;

  TContainer mBackBuffer;
  int mBackOffset;

  TContainer mFrontBuffer;
  int mFrontOffset;

  TContainer mCollect;
public:
  TBreakPacket( int sizeBuffer = 0xFFFF );
  TBreakPacket(const TBreakPacket& bp);
  virtual ~TBreakPacket();

  // копировать кусок памяти
  void PushBack(char* p,int size);
  void PushFront(char* p,int size);
  // собрать кусочки в одно целое
  // теперь можно получить указатель на собранный пакет через GetPtr
  void Collect();
  void* GetCollectPtr();
  int GetSize();

  // отцепиться от памяти под собранный пакет
  void UnlinkCollect();
  void Reset();

  TBreakPacket& operator =( const TBreakPacket& b );
protected:
  void CopyFrom(const TBreakPacket& bp);
};


#endif

