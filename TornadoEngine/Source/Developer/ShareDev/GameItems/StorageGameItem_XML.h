/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef StorageGameItem_XMLH
#define StorageGameItem_XMLH

#include "TypeDef.h"
#include <string>
#include <boost/smart_ptr/scoped_ptr.hpp>

struct TBaseItem;
class IXML;

class TManagerSerializerItem_XML;
class TManagerCacheItem_XML;

class DllExport TStorageGameItem_XML
{
  IXML* mXML;

  boost::scoped_ptr<TManagerSerializerItem_XML> mMngSerializer;
  boost::scoped_ptr<TManagerCacheItem_XML>   mMngCache;
public:
  TStorageGameItem_XML();
  virtual ~TStorageGameItem_XML();
  
  bool Init(std::string& name_file_xml);
  
  // Save == Add, что добавить, что сохранить - это то же самое
  bool Save(TBaseItem* pItem);
  bool Delete(int type, std::string& name);
  bool Delete(TBaseItem* pItem);
  bool IsExist(int type, std::string& name);
  bool Load(TBaseItem* pItem);

  int GetCountByType( int type );
  bool GetNameByType( int type, int index, std::string& name );
private:

};

#endif
