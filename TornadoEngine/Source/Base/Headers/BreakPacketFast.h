/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BreakPacketFastH
#define BreakPacketFastH

#include "TypeDef.h"
#include "ContainerTypes.h"

// Разбитый на части пакет. Например, когда нужно добавлять на каждом уровне иерархии новый заголовок.

class DllExport TBreakPacketFast
{
  int mSizeBuffer;

  TContainer mBackBuffer;
  int mBackOffset;

  TContainer mFrontBuffer;
  int mFrontOffset;

  TContainer mCollect;
public:
  TBreakPacketFast( int sizeBuffer = 0xFFFF );
  TBreakPacketFast(const TBreakPacketFast& bp);
  virtual ~TBreakPacketFast();

  // добавить кусок памяти
  // copyData=true - например если в цикле используется стековая переменная
  void PushBack(char* p,int size);
  void PushFront(char* p,int size);
  // собрать кусочки в одно целое (копированием), 
  // теперь можно получить указатель на собранный пакет через GetPtr
  // если кол-во частей равно 1, то сборки не будет.
  void Collect();
  void* GetCollectPtr();
  int GetSize();

  // освободить память, которая использовалась под собранный пакет
  void UnlinkCollect();
  void UnlinkPart();

  TBreakPacketFast& operator =( const TBreakPacketFast& b );
protected:
  void CopyFrom(const TBreakPacketFast& bp);
};


#endif

