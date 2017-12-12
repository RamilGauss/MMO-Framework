/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ResourcesH
#define ResourcesH

#include <map>
#include <string>
#include "TypeDef.h"

class IXML;

class DllExport TResources
{
  std::string strError;

public:
  typedef std::multimap<std::string,std::string> TMMapStrStr;
  typedef TMMapStrStr::iterator   TMMapStrStrIt;
  typedef TMMapStrStr::value_type TMMapStrStrVT;

  TResources();
  virtual ~TResources();

  virtual bool Work(IXML* pXML);

  void GetResource(TMMapStrStr& mapTypePath);

  std::string GetStrError();
protected:
  void ErrorNoSection(const char* section);

  bool LoadResources();

private:
  TMMapStrStr mMapTypePath;
protected:
  IXML* mXML;
};

#endif
