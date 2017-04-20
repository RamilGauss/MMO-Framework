/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerMapItem_XMLH
#define SerializerMapItem_XMLH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_XML.h"
#include "MapItem.h"

struct TMapItem;

class DllExport TSerializerMapItem_XML : public TBaseSerializerItem_XML
{
  TMapItem* mMapItem;
public:
  TSerializerMapItem_XML();
  virtual ~TSerializerMapItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:

	//void LoadTableSound();
 // void LoadGravity();
 // void LoadFog();
 // void LoadBackgroundColour();
	//void LoadAmbientLight();
	void LoadSet();
	void LoadScenario();

	void LoadObject(TMapItem::TObject& object);

	//void SaveTableSound();
 // void SaveGravity();
	//void SaveFog();
 // void SaveBackgroundColour();
	//void SaveAmbientLight();
	void SaveSet();
	void SaveScenario();
	
  void SaveObject(TMapItem::TObject& object);
};

#endif