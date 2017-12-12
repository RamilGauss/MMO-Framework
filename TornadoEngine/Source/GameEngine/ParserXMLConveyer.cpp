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

const char* sConveyer = "Conveyer";

const char* sVariant     = "Variant";
const char* sThread      = "Thread";
const char* sModule      = "Module";
const char* sName        = "Name";

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
bool TParserXMLConveyer::Work(std::string& fileDescConveyer, std::string& variantConveyer)
{
  mVariantConveyer = variantConveyer;
  strError = "";

  if(mXML->Load(fileDescConveyer.data())==false)
  {
    strError = "Нет такого файла";
    return false;
  }

  if(mXML->EnterSection(sConveyer, 0)==false)
  {
    strError = "Файл некорректен";
    return false;
  }

  if(SearchVariant()==false)
  {
    strError = "Нет такого Варианта";
    return false;
  }
  // потоки и модули
  if(MakeStrModule()==false)
    return false;

  return true;
}
//---------------------------------------------------------------------------------------
std::string TParserXMLConveyer::GetStrError()
{
  return strError;
}
//---------------------------------------------------------------------------------------
void TParserXMLConveyer::GetResult(std::vector< std::vector<std::string > >& vecVecStrModule)
{
  vecVecStrModule  = mVecVecStrModule;
}
//---------------------------------------------------------------------------------------
bool TParserXMLConveyer::SearchVariant()
{
  // ищем вариант
  int cntVariant = mXML->GetCountSection(sVariant);
  for( int iVariant = 0; iVariant < cntVariant ; iVariant++ )
  {
    std::string nameVariant = mXML->ReadSectionAttr(sVariant, iVariant, sName);
    if( nameVariant==mVariantConveyer )
      return mXML->EnterSection(sVariant, iVariant);
  }

  return false;
}
//---------------------------------------------------------------------------------------
void TParserXMLConveyer::ErrorNoSection(const char* section)
{
  strError = "Нет секции ";
  strError += section;
}
//---------------------------------------------------------------------------------------
bool TParserXMLConveyer::MakeStrModule()
{
  int cntThread = mXML->GetCountSection(sThread);
  if( cntThread==0 )
  {
    ErrorNoSection(sThread);
    return false;
  }
  if( cntThread!=1 )
  {
    strError = "Количество потоков должно быть равно 1";
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
        std::string nameModule = mXML->ReadSectionAttr(sModule, iModule, sName);
        vecStr.push_back(nameModule);
      }
      mVecVecStrModule.push_back(vecStr);
      mXML->LeaveSection();
    }
  }
  return true;
}
//---------------------------------------------------------------------------------------
