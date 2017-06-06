/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerTerrainItem_XMLH
#define SerializerTerrainItem_XMLH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_XML.h"
#include "TerrainItem.h"

struct TTerrainItem;

class DllExport TSerializerTerrainItem_XML : public TBaseSerializerItem_XML
{
  TTerrainItem* mTerrain;
public:
  TSerializerTerrainItem_XML();
  virtual ~TSerializerTerrainItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:
 	void LoadNameHeightData();
  void LoadConvention();
	void LoadConventionArg(const char* sArg, TTerrainItem::TConvention& conv);
  void LoadGraphic();

 	void SaveNameHeightData();
  void SaveConvention();
	void SaveConventionArg(const char* sArg, TTerrainItem::TConvention& conv);
  void SaveGraphic();
};

#endif
