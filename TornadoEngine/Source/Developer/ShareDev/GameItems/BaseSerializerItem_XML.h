/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BaseSerializerItem_XMLH
#define BaseSerializerItem_XMLH

#include <string>
#include <map>

#include "TypeDef.h"
#include "MathTools.h"

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

  bool RemoveSection(std::string& name);
  static std::string ReadName(int index, IXML* xml);
protected:
  bool EnterByType(std::string& name);
  bool AddAndEnterByType(std::string& name);

  int GetCountProperty();
  bool LoadProperty(int index, std::string& key, std::string& value);
  bool SaveProperty(std::string& key, std::string& value);

  bool LoadVector3ByProperty(nsMathTools::TVector3& v3);
  bool SaveVector3ByProperty(nsMathTools::TVector3& v3);
private:
  bool EnterRoot();
protected:
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator              TMapStrStrIt;
  typedef TMapStrStr::value_type            TMapStrStrVT;
};

#endif
