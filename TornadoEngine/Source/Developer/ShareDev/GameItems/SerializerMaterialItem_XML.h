/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef SerializerMaterialItem_XMLH
#define SerializerMaterialItem_XMLH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_XML.h"

struct TMaterialItem;

class DllExport TSerializerMaterialItem_XML : public TBaseSerializerItem_XML
{
  TMaterialItem* mMaterial;
public:
  TSerializerMaterialItem_XML();
  virtual ~TSerializerMaterialItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:

  void LoadGraphic();
  void LoadPhysic();

  void SaveGraphic();
  void SavePhysic();

  void FillPhysicParam();
private:
  TMapStrStr mMapNameValue_Physic;
};

#endif
