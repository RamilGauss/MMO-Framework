/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseSerializerItem_Binary.h"

TBaseSerializerItem_Binary::TBaseSerializerItem_Binary(int type)
{
  mUnpackData = NULL;
  mUnpackSize = 0;

  mType = type;
}
//------------------------------------------------------------------------------
TBaseSerializerItem_Binary::~TBaseSerializerItem_Binary()
{

}
//------------------------------------------------------------------------------
int TBaseSerializerItem_Binary::Type()
{
  return mType;
}
//------------------------------------------------------------------------------
bool TBaseSerializerItem_Binary::ResolveType(void* pIn, int sizeIn, int& type)
{
  if (sizeIn < sizeof(TypeType))
    return false;

  TypeType* pType = (TypeType*)pIn;
  type = *pType;
  return true;
}
//--------------------------------------------------------------------------------------
void TBaseSerializerItem_Binary::Reset()
{
  mCollect.Reset();
}
//--------------------------------------------------------------------------------------
void TBaseSerializerItem_Binary::Collect(TContainerRise& cOut)
{
  mCollect.CopyInBuffer(cOut);
}
//--------------------------------------------------------------------------------------
void TBaseSerializerItem_Binary::PushType()
{
  Push(mType);
}
//--------------------------------------------------------------------------------------
void TBaseSerializerItem_Binary::PushStr(std::string& s)
{
  Push(s.length());
  mCollect.PushBack((char*)s.data(), s.length());
}
//--------------------------------------------------------------------------------------
void TBaseSerializerItem_Binary::BeginUnpack(char* pIn, int sizeIn)
{
  mUnpackData = pIn;
  mUnpackSize = sizeIn;
}
//--------------------------------------------------------------------------------------
bool TBaseSerializerItem_Binary::PopType()
{
  return Pop(mType);
}
//--------------------------------------------------------------------------------------
bool TBaseSerializerItem_Binary::PopStr(std::string& s)
{
  std::string::size_type len;
  if (Pop(len) == false)
    return false;

  if (int(len) > mUnpackSize)
    return false;
  s.reserve(len);
  s.resize(len);
  memcpy((void*)s.data(), mUnpackData, len);

  mUnpackData += len;
  mUnpackSize -= len;
  return true;
}
//--------------------------------------------------------------------------------------
