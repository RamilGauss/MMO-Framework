/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerTableSoundItem_BinaryH
#define SerializerTableSoundItem_BinaryH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_Binary.h"

class DllExport TSerializerTableSoundItem_Binary : public TBaseSerializerItem_Binary
{
public:
  TSerializerTableSoundItem_Binary();
  virtual ~TSerializerTableSoundItem_Binary();

  virtual void PackItem(TBaseItem* pItem, TContainer& cBinOut);
  virtual bool UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn);

protected:
};

#endif