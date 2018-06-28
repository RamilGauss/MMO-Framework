/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryGameItemH
#define FactoryGameItemH

#include <map>
#include <boost/smart_ptr/scoped_ptr.hpp>
#include "TypeDef.h"

#include "ContainerTypes.h"
#include "ContainerRise.h"

struct TBaseItem;
class TStorageGameItem_XML;
class TManagerSerializerItem_Binary;
/*
  ВАЖНО!
  Нельзя добавлять, менять и удалять итэмы, когда идет сценарий Построения или Разрушения карты.
  Во время Синхронизации игровых объектов можно добавлять, менять или удалять итэмы.

  P.S. я мало доволен этим классом, точнее интерфейсом. Не те фундаментальные методы.
*/
class DllExport TFactoryGameItem
{
  boost::scoped_ptr<TStorageGameItem_XML> mStorageGameItem_XML;

  boost::scoped_ptr<TManagerSerializerItem_Binary> mMngSerBin;// импорт/экспорт бинарных блоков

  typedef std::map<std::string,TBaseItem*> TMapStrPtrItem;
  typedef TMapStrPtrItem::iterator         TMapStrPtrItemIt;
  typedef TMapStrPtrItem::value_type       TMapStrPtrItemVT;

  // карты итэмов по типам
  TMapStrPtrItem mMapNamePatternConfig;
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

  typedef enum{FirstType,
               PatternConfig=FirstType, Material, Shape, Model, Terrain, TableSound, Map, 
               CountType}TypeGameItem;
  
  // для операций с XML (сохранение, удаление и т.д.)
  TStorageGameItem_XML* GetStorage_XML();
  bool Init_XML(std::string& name_file_xml);
  // загрузка из XML в кэш итэмов, при дублировании происходит замена на вариант из XML
  void ReloadFromStorageAll_XML();
  void ReloadFromStorageByType_XML( TypeGameItem type );

  // добавить в кэш с заменой, старый итэм уничтожается
  TBaseItem* Add(TypeGameItem type, std::string& name);
  // из упакованного описания добавить в кэш с заменой, старый итэм уничтожается
  TBaseItem* AddFromBinary(void* pIn, int sizeIn);
  // формирование блока памяти, содержащий упакованное описание итэма
  bool MakeBinary(TypeGameItem type, std::string& name, TContainerRise& cBinOut);
  bool MakeBinary(TBaseItem* pItem, TContainerRise& cBinOut);
  // удалить только из кэша
  bool Delete(TypeGameItem type, std::string& name);
  bool Delete(TBaseItem* pItem);
  // если нет в кэше, то ищет в XML (добавляя в кэш)
  TBaseItem* Get(TypeGameItem type, std::string& name);
  // сколько итэмов данного типа в кэше (не ищет в XML)
  int GetCountByType(TypeGameItem type);
  // по индексу и типу получить имя (не ищет в XML)
  bool GetNameByType(TypeGameItem type, int index, std::string& name);
  // очистка кэша
  void Clear();
private:
  bool AddItemInMap(TBaseItem* pItem);
  TBaseItem* FindItemByTypeByName(int type, std::string& name);
  TBaseItem* MakeNewItem(int type, std::string& name);
  TMapStrPtrItem* FindMap(int type);
  void MakeStr_Map();

  void Done();
};

#endif
