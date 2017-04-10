/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerPatternConfigItem_XMLH
#define SerializerPatternConfigItem_XMLH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_XML.h"
#include "PatternConfigItem.h"

class DllExport TSerializerPatternConfigItem_XML : public TBaseSerializerItem_XML
{
  TPatternConfigItem* mPattern;

public:
  TSerializerPatternConfigItem_XML();
  virtual ~TSerializerPatternConfigItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:
  void LoadPropertyPattern();
  void SavePropertyPattern();

private:
	void LoadComment();
  void LoadVariant(TPatternConfigItem::TMapStrStr& mapStrStr, int iVariant );

	void SaveComment();
  void SaveVariant(TPatternConfigItem::TMapStrStr& mapStrStr );
};

#endif