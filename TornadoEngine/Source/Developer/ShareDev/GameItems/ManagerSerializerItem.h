/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerSerializerItemH
#define ManagerSerializerItemH

#include "TypeDef.h"

#include <map>
#include <boost/smart_ptr/scoped_ptr.hpp>

class IXML;

#include "SerializerShapeItem_XML.h"
#include "SerializerModelItem_XML.h"
#include "SerializerMaterialItem_XML.h"
#include "SerializerTerrainItem_XML.h"
#include "SerializerMapItem_XML.h"

struct TBaseItem;

class DllExport TManagerSerializerItem
{
  IXML* mXML;

  // сериализаторы из/в формат XML
  typedef std::map<int,TBaseSerializerItem_XML*> TMapIntPtrSerilizer;
  typedef TMapIntPtrSerilizer::iterator          TMapIntPtrSerilizerIt;
  typedef TMapIntPtrSerilizer::value_type        TMapIntPtrSerilizerVT;

  boost::scoped_ptr<TSerializerShapeItem_XML>    mSerializerShape;
  boost::scoped_ptr<TSerializerModelItem_XML>    mSerializerModel;
  boost::scoped_ptr<TSerializerMaterialItem_XML> mSerializerMaterial;
  boost::scoped_ptr<TSerializerTerrainItem_XML>  mSerializerTerrain;
  boost::scoped_ptr<TSerializerMapItem_XML>      mSerializerMap;

  TMapIntPtrSerilizer mMapTypeSerializer;// каждому типу итэма - свой сериализатор

public:
  TManagerSerializerItem();

  void Init(IXML* xml);
  
  bool Load(int type, TBaseItem* pItem);
  bool Save(int type, TBaseItem* pItem);

  std::string StrByType(int type);
protected:
  TBaseSerializerItem_XML* Find(int type);
};

#endif
