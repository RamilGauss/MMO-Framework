/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerSerializerItem_XMLH
#define ManagerSerializerItem_XMLH

#include "TypeDef.h"

#include <map>
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <boost/bimap/bimap.hpp>

#include "SerializerShapeItem_XML.h"
#include "SerializerModelItem_XML.h"
#include "SerializerMaterialItem_XML.h"
#include "SerializerTerrainItem_XML.h"
#include "SerializerMapItem_XML.h"
#include "SerializerTableSoundItem_XML.h"
#include "SerializerPatternConfigItem_XML.h"

class IXML;
struct TBaseItem;

class DllExport TManagerSerializerItem_XML
{
  IXML* mXML;

  // для поиска типа по имени и наоборот (по типу)
  typedef boost::bimaps::bimap<std::string,int> bmStrInt;
  typedef bmStrInt::left_const_iterator         bmStrIntLeftIt;
  typedef bmStrInt::right_const_iterator        bmStrIntRightIt;
  typedef bmStrInt::value_type                  bmStrIntVT;

  bmStrInt mMapStrType;

  // сериализаторы из/в формат XML
  typedef std::map<int,TBaseSerializerItem_XML*> TMapIntPtrSerilizer;
  typedef TMapIntPtrSerilizer::iterator          TMapIntPtrSerilizerIt;
  typedef TMapIntPtrSerilizer::value_type        TMapIntPtrSerilizerVT;

  boost::scoped_ptr<TSerializerPatternConfigItem_XML> mSerializerPatternConfig;
  boost::scoped_ptr<TSerializerShapeItem_XML>         mSerializerShape;
  boost::scoped_ptr<TSerializerModelItem_XML>         mSerializerModel;
  boost::scoped_ptr<TSerializerMaterialItem_XML>      mSerializerMaterial;
  boost::scoped_ptr<TSerializerTerrainItem_XML>       mSerializerTerrain;
  boost::scoped_ptr<TSerializerMapItem_XML>           mSerializerMap;
  boost::scoped_ptr<TSerializerTableSoundItem_XML>    mSerializerTableSound;

  TMapIntPtrSerilizer mMapTypeSerializer;// каждому типу итэма - свой сериализатор

public:
  TManagerSerializerItem_XML();

  void Init(IXML* xml);
  
  bool Str2Type(std::string& strType, int& type);
  bool Type2Str(int type, std::string& strType);

  bool Load(TBaseItem* pItem);
  bool Save(TBaseItem* pItem);
  bool Remove(int type, std::string& name);
  bool Remove(TBaseItem* pItem);
  bool Save();
protected:
  TBaseSerializerItem_XML* Find(int type);
};

#endif
