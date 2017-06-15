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
#include "ModelItem.h"
#include "SerializerParamBuilderConstraint.h"

class DllExport TSerializerModelItem_XML : public TBaseSerializerItem_XML
{
  TModelItem* mModel;

  TSerializerParamBuilderConstraint mSerParamConstraint;
public:
  TSerializerModelItem_XML();
  virtual ~TSerializerModelItem_XML();

  virtual bool Load(TBaseItem* pItem);
  virtual bool Save(TBaseItem* pItem);
protected:
  void LoadPattern();
  void LoadHierarchy();
  void LoadCollection();
  void LoadExternalJoining();

  void LoadRoot();
  void LoadLocation(TModelItem::TLocation& location, int iLocation);
  void LoadLink(TModelItem::TLink& link, int iLink);
  void LoadPart(TModelItem::TPart& part, int iPart);
  void LoadVariant(TModelItem::TVariant& variant, int iVariant);

  void SavePattern();
  void SaveHierarchy();
  void SaveCollection();
  void SaveExternalJoining();

  void SaveRoot();
  void SaveLocation(TModelItem::TLocation& location);
  void SaveLink(TModelItem::TLink& link);
  void SavePart(TModelItem::TPart& part);
  void SaveVariant(TModelItem::TVariant& variant);
private:
  TMapStrStr mMapNameValue_Constraint;
  
  void MakeConstraintByMap(TModelItem::TLink& link);
  void MakeMapByConstraint(TModelItem::TLink& link);
};

#endif