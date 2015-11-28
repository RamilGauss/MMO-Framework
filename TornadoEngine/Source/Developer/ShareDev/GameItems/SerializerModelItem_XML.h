/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerModelItem_XMLH
#define SerializerModelItem_XMLH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_XML.h"

struct TModelItem;

class DllExport TSerializerModelItem_XML : public TBaseSerializerItem_XML
{
  TModelItem* mModel;
public:
  TSerializerModelItem_XML();
  virtual ~TSerializerModelItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:
};

#endif