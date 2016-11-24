/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BaseSerializerItem_BinaryH
#define BaseSerializerItem_BinaryH

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "BreakPacket.h"

struct TBaseItem;

class DllExport TBaseSerializerItem_Binary
{
  char* mUnpackData;
  int   mUnpackSize;

protected:
  typedef unsigned char TypeType;
  TypeType mType;

  TBreakPacket mCollect;
public:
  TBaseSerializerItem_Binary(int type);
  virtual ~TBaseSerializerItem_Binary();

  int Type();

  // упаковать итэм в контейнер
  virtual void PackItem(TBaseItem* pItem, TContainer& cBinOut)    = 0;
  // распаковать упакованный в итэм
  virtual bool UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn) = 0;

  static bool ResolveType(void* pIn, int sizeIn, int& type);
protected:
  // базовые операции
  void UnlinkCollect();

  template <typename T>
  void Push(T v);
  template <typename T>
  void Push(T* pT, bool copyData = false);

  template <typename T>
  bool Pop(T& t);

  void BeginUnpack(char* pIn, int sizeIn);

  void Collect(TContainer& cOut);
protected:
  // производные
  void PushType();
  void PushStr(std::string& s);

  bool PopType();
  bool PopStr(std::string& s);
};
//------------------------------------------------------------------------------
template <typename T>
void TBaseSerializerItem_Binary::Push(T t)
{
  mCollect.PushBack((char*)&t, sizeof(T), true);
}
//------------------------------------------------------------------------------
template <typename T>
void TBaseSerializerItem_Binary::Push(T* pT, bool copyData)
{
  mCollect.PushBack((char*)pT, sizeof(T), copyData);
}
//------------------------------------------------------------------------------
template <typename T>
bool TBaseSerializerItem_Binary::Pop(T& t)
{
  int sizeT = sizeof(T);
  if( mUnpackSize < sizeT )
    return false;
  memcpy(&t, mUnpackData, sizeT);
  mUnpackData += sizeT;
  mUnpackSize -= sizeT;
  return true;
}
//------------------------------------------------------------------------------
#endif
