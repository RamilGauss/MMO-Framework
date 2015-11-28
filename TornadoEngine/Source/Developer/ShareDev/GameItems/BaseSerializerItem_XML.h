/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BaseSerializerItem_XMLH
#define BaseSerializerItem_XMLH

#include <string>
#include "TypeDef.h"

class IXML;
struct TBaseItem;

class DllExport TBaseSerializerItem_XML
{
protected:
  IXML* mXML;
  std::string mType;
public:
  TBaseSerializerItem_XML(std::string type);
  virtual ~TBaseSerializerItem_XML();

  void Init(IXML* xml);
  std::string Type();

  virtual bool Load(TBaseItem* pItem) = 0;
  virtual bool Save(TBaseItem* pItem) = 0;

  static std::string ReadName(int index, IXML* xml);
protected:
  bool EnterByType(std::string& name);

  int GetCountProperty();
  bool LoadProperty(int index, std::string& key, std::string& value);
  bool RemoveSection(std::string& name);
private:
  bool EnterRoot();
};

#endif
