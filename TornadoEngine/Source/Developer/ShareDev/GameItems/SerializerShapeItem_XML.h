/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerShapeItem_XMLH
#define SerializerShapeItem_XMLH

#include "BaseSerializerItem_XML.h"
#include "SerializerParamBuilderShape.h"

struct TShapeItem;

class DllExport TSerializerShapeItem_XML : public TBaseSerializerItem_XML
{
  TShapeItem* mShape;

  TSerializerParamBuilderShape mSerParamShape;
public:
  TSerializerShapeItem_XML();
  virtual ~TSerializerShapeItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:
  void LoadGeometry();
  void LoadJoining();
  void LoadPaint();
  void LoadMaterial();

  void SaveGeometry();
  void SaveJoining();
  void SavePaint();
  void SaveMaterial();

  void MakeGeometryByMap();
  void MakeMapByGeometry();
private:
  TMapStrStr mMapNameValue_Geometry;
};

#endif
