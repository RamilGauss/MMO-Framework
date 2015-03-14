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
  int mCountCore;

  IXML* mXML;

  std::string strError;

  typedef std::vector<std::string> TVecStr;
  typedef std::vector< TVecStr > TVecVecStr;

  TVecVecStr mVecVecStrModule;

  typedef std::map<std::string,TVecStr> TMapStrVecStr;
  typedef TMapStrVecStr::value_type TMapStrVecStrVT;
  typedef TMapStrVecStr::iterator TMapStrVecStrIt;
  TMapStrVecStr mMapDst_SrcModule;

public:
  TParserXMLConveyer();
  ~TParserXMLConveyer();

  bool Work(std::string& fileDescConveyer, std::string& variantConveyer);
  std::string GetStrError();
  void GetResult(std::vector< std::vector<std::string > >&         vecVecStrModule, 
                 std::map<std::string, std::vector<std::string> >& mapDst_SrcModule);
protected:
  bool SearchVariant();
  bool SearchCountCore();
  bool MakeMapDstSrcModule();
  bool MakeStrModule();

  void ErrorNoSection(const char* section);

  TVecStr* FindVecStrByName(std::string name);
};

#endif
