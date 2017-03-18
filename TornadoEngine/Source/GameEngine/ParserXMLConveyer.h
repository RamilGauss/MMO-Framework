/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ParserXMLConveyerH
#define ParserXMLConveyerH

#include <vector>
#include <map>
#include <string>

class IXML;

class TParserXMLConveyer
{
  std::string mVariantConveyer;

  IXML* mXML;

  std::string strError;

  typedef std::vector<std::string> TVecStr;
  typedef std::vector<TVecStr> TVecVecStr;

  TVecVecStr mVecVecStrModule;

public:
  TParserXMLConveyer();
  ~TParserXMLConveyer();

  bool Work(std::string& fileDescConveyer, std::string& variantConveyer);
  std::string GetStrError();
  void GetResult(std::vector< std::vector<std::string > >& vecVecStrModule);
protected:
  bool SearchVariant();
  bool MakeStrModule();

  void ErrorNoSection(const char* section);
};

#endif
