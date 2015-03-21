/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ResourcesH
#define ResourcesH

#include <list>
#include <string>
#include <utility>
#include "TypeDef.h"

class IXML;

class DllExport TResources
{
  std::string strError;

public:
  typedef std::pair<std::string,std::string> TPairStrStr;
  typedef std::list<TPairStrStr> TListPairNameType;

  TResources();
  virtual ~TResources();

  virtual bool Work(IXML* pXML);

  void GetResource(TListPairNameType& listPair);

  std::string GetStrError();
protected:
  void ErrorNoSection(const char* section);

  bool LoadResources();

private:
  TListPairNameType mListNameType;
protected:
  IXML* mXML;
};

#endif
