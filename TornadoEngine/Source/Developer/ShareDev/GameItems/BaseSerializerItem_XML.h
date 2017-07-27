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
	struct TIndex
	{
		int i;
		int j;
		TIndex(){i=0;j=0;}
		TIndex(int _i, int _j){i=_i;j=_j;}
	};
	typedef std::map<std::string,TIndex>  TMapStrIndex;
	typedef TMapStrIndex::iterator   TMapStrIndexIt;
	typedef TMapStrIndex::value_type TMapStrIndexVT;

	TMapStrIndex mMapNameIndex_m3x3;
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

	bool LoadVector4ByProperty(nsMathTools::TVector4& v4);
	bool SaveVector4ByProperty(nsMathTools::TVector4& v4);

	bool LoadOrientationByProperty(nsMathTools::TMatrix16& m4x4);
	bool SaveOrientationByProperty(nsMathTools::TMatrix16& m4x4);

	bool LoadColour(nsMathTools::TVector3& v3);
	bool SaveColour(nsMathTools::TVector3& v3);
private:
  bool EnterRoot();

	TIndex* FindIndex(std::string name);

protected:
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator              TMapStrStrIt;
  typedef TMapStrStr::value_type            TMapStrStrVT;
};

#endif
