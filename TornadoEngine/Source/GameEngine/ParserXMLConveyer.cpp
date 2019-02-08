/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ParserXMLConveyer.h"

#include "TextFile.h"
#include "JsonSerializer.h"

bool TParserXMLConveyer::Work( std::string& fileDescConveyer )
{
  std::string jsonContent;
  TTextFile::Load( fileDescConveyer, jsonContent );
  if ( jsonContent.length() == 0 )
  {
    strError = "No such file";
    return false;
  }
  nsGameEngine::TJsonSerializer::Fill( &mConveyerConfig, jsonContent );
  return true;
}
//---------------------------------------------------------------------------------------
std::string TParserXMLConveyer::GetStrError()
{
  return strError;
}
//---------------------------------------------------------------------------------------
std::vector<std::vector<std::string>> TParserXMLConveyer::GetResult( std::string& variantConveyer )
{
  auto fit = mConveyerConfig.appList.find( variantConveyer );
  if ( fit == mConveyerConfig.appList.end() )
    return std::vector<std::vector<std::string>>();
  return fit->second.modulesInThreads;
}
//---------------------------------------------------------------------------------------
