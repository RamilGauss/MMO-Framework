/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerSerializerItem_BinaryH
#define ManagerSerializerItem_BinaryH

#include "TypeDef.h"

#include <map>
#include <boost/smart_ptr/scoped_ptr.hpp>

#include "SerializerShapeItem_Binary.h"
#include "SerializerModelItem_Binary.h"
#include "SerializerMaterialItem_Binary.h"
#include "SerializerTerrainItem_Binary.h"
#include "SerializerMapItem_Binary.h"
#include "SerializerTableSoundItem_Binary.h"
#include "SerializerPatternConfigItem_Binary.h"

struct TBaseItem;

class DllExport TManagerSerializerItem_Binary
{
  // сериализаторы
  typedef std::map<int,TBaseSerializerItem_Binary*> TMapIntPtrSerilizer;
  typedef TMapIntPtrSerilizer::iterator             TMapIntPtrSerilizerIt;
  typedef TMapIntPtrSerilizer::value_type           TMapIntPtrSerilizerVT;

  boost::scoped_ptr<TSerializerPatternConfigItem_Binary> mSerializerPatternConfig;
  boost::scoped_ptr<TSerializerShapeItem_Binary>         mSerializerShape;
  boost::scoped_ptr<TSerializerModelItem_Binary>         mSerializerModel;
  boost::scoped_ptr<TSerializerMaterialItem_Binary>      mSerializerMaterial;
  boost::scoped_ptr<TSerializerTerrainItem_Binary>       mSerializerTerrain;
  boost::scoped_ptr<TSerializerMapItem_Binary>           mSerializerMap;
  boost::scoped_ptr<TSerializerTableSoundItem_Binary>    mSerializerTableSound;

  TMapIntPtrSerilizer mMapTypeSerializer;// каждому типу итэма - свой сериализатор

public:
  TManagerSerializerItem_Binary();

  void Pack(TBaseItem* pItem, TContainerRise& cBinOut);
  bool Unpack(TBaseItem* pItem, void* pIn, int sizeIn);

protected:
  TBaseSerializerItem_Binary* FindMap(int type);
};

#endif
