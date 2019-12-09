/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef SerializerPatternConfigItem_BinaryH
#define SerializerPatternConfigItem_BinaryH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_Binary.h"

class DllExport TSerializerPatternConfigItem_Binary : public TBaseSerializerItem_Binary
{
public:
  TSerializerPatternConfigItem_Binary();
  virtual ~TSerializerPatternConfigItem_Binary();

  virtual void PackItem(TBaseItem* pItem, TContainerRise& cBinOut);
  virtual bool UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn);

protected:
};

#endif