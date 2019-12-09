/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef SerializerMapItem_BinaryH
#define SerializerMapItem_BinaryH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_Binary.h"

class DllExport TSerializerMapItem_Binary : public TBaseSerializerItem_Binary
{
public:
  TSerializerMapItem_Binary();
  virtual ~TSerializerMapItem_Binary();

  virtual void PackItem(TBaseItem* pItem, TContainerRise& cBinOut);
  virtual bool UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn);

protected:
};

#endif