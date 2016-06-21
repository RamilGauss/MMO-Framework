/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerPatternItem_XMLH
#define SerializerPatternItem_XMLH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_XML.h"
#include "PatternItem.h"

class DllExport TSerializerPatternItem_XML : public TBaseSerializerItem_XML
{
  TPatternItem* mPattern;

public:
  TSerializerPatternItem_XML();
  virtual ~TSerializerPatternItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:
  void LoadPropertyPattern();
  void SavePropertyPattern();

private:
  void LoadVariant(TPatternItem::TMapStrStr& mapStrStr, int iVariant );
  void SaveVariant(TPatternItem::TMapStrStr& mapStrStr );
};

#endif