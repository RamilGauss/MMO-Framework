/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <map>
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

  std::shared_ptr<TSerializerPatternConfigItem_XML> mSerializerPatternConfig;
  std::shared_ptr<TSerializerShapeItem_XML>         mSerializerShape;
  std::shared_ptr<TSerializerModelItem_XML>         mSerializerModel;
  std::shared_ptr<TSerializerMaterialItem_XML>      mSerializerMaterial;
  std::shared_ptr<TSerializerTerrainItem_XML>       mSerializerTerrain;
  std::shared_ptr<TSerializerMapItem_XML>           mSerializerMap;
  std::shared_ptr<TSerializerTableSoundItem_XML>    mSerializerTableSound;

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
