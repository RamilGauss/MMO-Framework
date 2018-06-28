/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerMaterialItem_BinaryH
#define SerializerMaterialItem_BinaryH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_Binary.h"

class DllExport TSerializerMaterialItem_Binary : public TBaseSerializerItem_Binary
{
public:
  TSerializerMaterialItem_Binary();
  virtual ~TSerializerMaterialItem_Binary();

  virtual void PackItem(TBaseItem* pItem, TContainerRise& cBinOut);
  virtual bool UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn);

protected:
};

#endif