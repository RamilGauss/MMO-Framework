/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ParserXMLConveyer.h"
#include "MakerXML.h"
#include "ShareMisc.h"
#include "IXML.h"

const char* sHeader = "Conveyer";

const char* sVariant     = "Variant";
const char* sDataflow    = "Dataflow";
const char* sDataflowDst = "Dst";
const char* sDataflowSrc = "Src";
const char* sCPU         = "CPU";
const char* sThread      = "Thread";
const char* sModule      = "Module";
const char* sCountCore   = "countCore";
const char* sName        = "name";

using namespace std;

TParserXMLConveyer::TParserXMLConveyer()
{
  TMakerXML maker;
  mXML = maker.New();
}
//---------------------------------------------------------------------------------------
TParserXMLConveyer::~TParserXMLConveyer()
{
  TMakerXML maker;
  maker.Delete(mXML);
  mXML = NULL;
}
//---------------------------------------------------------------------------------------
bool TParserXMLConveyer::Work(string& fileDescConveyer, string& variantConveyer)
{
  mVariantConveyer = variantConveyer;
  mCountCore = GetCountCoreCPU();
  strError = "";

  if(mXML->Load(fileDescConveyer.data())==false)
  {
    strError = "Нет такого файла";
    return false;
  }

  if(mXML->EnterSection(sHeader, 0)==false)
  {
    strError = "Файл некорректен";
    return false;
  }

  if(SearchVariant()==false)
  {
    strError = "Нет такого Варианта";
    return false;
  }
  // потоки данных
  if(MakeMapDstSrcModule()==false)
    return false;

  if(SearchCountCore()==false)
  {
    strError = "Нет такого количества ядер процессора";
    return false;
  }
  // потоки и модули
  if(MakeStrModule()==false)
    return false;

  return true;
}
//---------------------------------------------------------------------------------------
string TParserXMLConveyer::GetStrError()
{
  return strError;
}
//---------------------------------------------------------------------------------------
void TParserXMLConveyer::GetResult(vector< vector<string > >& vecVecStrModule, map<string, vector<string> >& mapDst_SrcModule)
{
  vecVecStrModule  = mVecVecStrModule;
  mapDst_SrcModule = mMapDst_SrcModule;
}
//---------------------------------------------------------------------------------------
bool TParserXMLConveyer::SearchVariant()
{
  // ищем вариант
  int cntVariant = mXML->GetCountSection(sVariant);
  for( int iVariant = 0; iVariant < cntVariant ; iVariant++ )
  {
    string nameVariant = mXML->ReadSectionAttr(sVariant, iVariant, sName);
    if(nameVariant==mVariantConveyer)
      return mXML->EnterSection(sVariant, iVariant);
  }

  return false;
}
//---------------------------------------------------------------------------------------
bool TParserXMLConveyer::MakeMapDstSrcModule()
{
  if(mXML->EnterSection(sDataflow, 0)==false)
  {
    ErrorNoSection(sDataflow);
    return false;
  }

  int cntDst = mXML->GetCountSection(sDataflowDst);
  if(cntDst==0)
  {
    ErrorNoSection(sDataflowDst);
    return false;
  }

  for( int iDst = 0 ; iDst < cntDst ; iDst++ )
  {
    string nameDst = mXML->ReadSectionAttr(sDataflowDst, iDst, sName);
    mMapDst_SrcModule.insert(TMapStrVecStrVT(nameDst,TVecStr()));
    TVecStr* pVecStr = FindVecStrByName(nameDst);
    if(mXML->EnterSection(sDataflowDst, iDst))
    {
      int cntSrc = mXML->GetCountSection(sDataflowSrc);
      for( int iSrc = 0 ; iSrc < cntSrc ; iSrc++ )
      {
        string nameSrc = mXML->ReadSectionAttr(sDataflowSrc, iSrc, sName);
        pVecStr->push_back(nameSrc);
      }
      mXML->LeaveSection();
    }
  }

  mXML->LeaveSection();
  return true;
}
//---------------------------------------------------------------------------------------
void TParserXMLConveyer::ErrorNoSection(const char* section)
{
  char s[200];
  sprintf(s, "Нет секции %s", section);
  strError = s;
}
//---------------------------------------------------------------------------------------
TParserXMLConveyer::TVecStr* TParserXMLConveyer::FindVecStrByName(string name)
{
  TMapStrVecStrIt fit = mMapDst_SrcModule.find(name);
  if(fit==mMapDst_SrcModule.end())
    return NULL;
  
  return &fit->second;
}
//---------------------------------------------------------------------------------------
bool TParserXMLConveyer::MakeStrModule()
{
  int cntThread = mXML->GetCountSection(sThread);
  if(cntThread==0)
  {
    ErrorNoSection(sThread);
    return false;
  }

  for( int iThread = 0 ; iThread < cntThread ; iThread++ )
  {
    if(mXML->EnterSection(sThread, iThread))
    {
      TVecStr vecStr;
      int cntModule = mXML->GetCountSection(sModule);
      for( int iModule = 0 ; iModule < cntModule ; iModule++ )
      {
        string nameModule = mXML->ReadSectionAttr(sModule, iModule, sName);
        vecStr.push_back(nameModule);
      }
      mVecVecStrModule.push_back(vecStr);
      mXML->LeaveSection();
    }
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TParserXMLConveyer::SearchCountCore()
{
  char arrSearchCount[100];
  sprintf(arrSearchCount, "%d", mCountCore);
  string sSearchCount = arrSearchCount;

  // ищем вариант
  int cntCPU = mXML->GetCountSection(sCPU);
  for( int iCPU = 0; iCPU < cntCPU ; iCPU++ )
  {
    string countCoreCPU = mXML->ReadSectionAttr(sCPU, iCPU, sCountCore);
    if(countCoreCPU==sSearchCount)
      return mXML->EnterSection(sCPU, iCPU);
  }

  return false;
}
//---------------------------------------------------------------------------------------
