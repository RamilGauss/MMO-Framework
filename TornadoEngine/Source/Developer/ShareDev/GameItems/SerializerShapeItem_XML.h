/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerShapeItem_XMLH
#define SerializerShapeItem_XMLH

#include <string>
#include <map>

#include "TypeDef.h"
#include "BaseSerializerItem_XML.h"

struct TShapeItem;

class DllExport TSerializerShapeItem_XML : public TBaseSerializerItem_XML
{
  TShapeItem* mShape;
public:
  TSerializerShapeItem_XML();
  virtual ~TSerializerShapeItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:
  void LoadGeometry();
  void LoadPaint();
  void LoadMaterial();

  void SaveGeometry();
  void SavePaint();
  void SaveMaterial();

  void MakeGeometry();

  typedef std::map<std::string,float> TMapStrFloat;
  typedef TMapStrFloat::iterator      TMapStrFloatIt;
  typedef TMapStrFloat::value_type    TMapStrFloatVT;

  std::string mNameShape;
  TMapStrFloat mMapNameValue;

};

#endif
