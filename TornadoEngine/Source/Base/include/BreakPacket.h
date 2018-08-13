/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "ContainerRise.h"
#include "ReversedContainerRise.h"

// Разбитый на части пакет. Например, когда нужно добавлять на каждом уровне иерархии новый заголовок.
// РЕКОМЕНДАЦИИ по использованию:
// НЕ использовать на стеке, тяжелый конструктор.
// Лучше не копировать объект.
// После внесения внутрь, менять внесенные переменные снаружи бессмысленно, внутри буфера они не поменяются.

// PushBack, PushFront, ....
// Collect
// 

class DllExport TBreakPacket
{
  int mSizeBuffer;

  //TContainer mBackBuffer;
  TContainerRise mBackBuffer;
  //int mBackOffset;

  //TContainer mFrontBuffer;
  TReversedContainerRise mFrontBuffer;
  //int mFrontOffset;

  TContainerRise mCollect;
public:
  enum
  {
    DEFAULT_MEMORY_SIZE = 100
  };
  TBreakPacket( int sizeBuffer = DEFAULT_MEMORY_SIZE/*0xFFFF*/ );
  TBreakPacket( const TBreakPacket& bp );
  virtual ~TBreakPacket();

  // копировать кусок памяти
  void PushBack( char* p, int size );
  void PushFront( char* p, int size );

  void CopyInBuffer( TContainerRise& receiveBuffer, int offset = 0 );

  // собрать кусочки в одно целое
  // теперь можно получить указатель на собранный пакет через GetPtr
  void Collect();
  void* GetCollectPtr();
  int GetSize();

  void Reset();

  TBreakPacket& operator =( const TBreakPacket& b );
protected:
  void CopyFrom( const TBreakPacket& bp );
};
