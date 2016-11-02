/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryGameItemH
#define FactoryGameItemH

#include <map>
#include <list>
#include <boost/bimap/bimap.hpp>

#include "TypeDef.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

struct TBaseItem;
class IXML;

class TManagerSerializerItem;
class TManagerCacheItemXML;

class DllExport TFactoryGameItem
{
  IXML* mXML;

  std::list<TBaseItem*> mListItems;// удобно для освобождения ресурсов

  boost::scoped_ptr<TManagerSerializerItem> mMngSerializer;
  boost::scoped_ptr<TManagerCacheItemXML>   mMngCache;

  // для поиска типа по имени и наоборот
  typedef boost::bimaps::bimap<std::string,int> bmStrInt;
  typedef bmStrInt::value_type                  bmStrIntVT;

  bmStrInt mMapStrType;

  typedef std::map<std::string,TBaseItem*> TMapStrPtrItem;
  typedef TMapStrPtrItem::iterator         TMapStrPtrItemIt;
  typedef TMapStrPtrItem::value_type       TMapStrPtrItemVT;

  // карты итэмов по типам
  TMapStrPtrItem mMapNamePattern;
  TMapStrPtrItem mMapNameMaterial;
  TMapStrPtrItem mMapNameShape;
  TMapStrPtrItem mMapNameModel;
  TMapStrPtrItem mMapNameTerrain;
  TMapStrPtrItem mMapNameMap;
	TMapStrPtrItem mMapNameTableSound;

  typedef std::map<int,TMapStrPtrItem*>    TMapInt_PtrMapStrPtr;
  typedef TMapInt_PtrMapStrPtr::iterator   TMapInt_PtrMapStrPtrIt;
  typedef TMapInt_PtrMapStrPtr::value_type TMapInt_PtrMapStrPtrVT;

  TMapInt_PtrMapStrPtr mMapType_StrName_pItem;// по типу найти карту в которой хранятся
public:
  TFactoryGameItem();
  virtual ~TFactoryGameItem();
  
  bool Init(std::string& name_file);

  typedef enum{PatternConfig, Material, Shape, Model, Terrain, TableSound, Map, CountType}Type;

  TBaseItem* Add(Type type, std::string& name);
  bool Save(TBaseItem* pItem);

  int GetCount(Type type);
  bool GetName(Type type, int index, std::string& name);
  TBaseItem* Get(Type type, std::string& name);

  void FullLoad();
private:
  void AddItemInMap(TBaseItem* pItem, TMapStrPtrItem* pMap);
  TBaseItem* FindItemInMapByName(std::string& name, TMapStrPtrItem* pMap);

  TBaseItem* NewItem(Type type, std::string& name);
  TMapStrPtrItem* FindMap(Type type);

  void MakeStr_Map();
};

#endif
