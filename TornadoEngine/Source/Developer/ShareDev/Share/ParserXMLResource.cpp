/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ParserXMLResource.h"
#include "MakerXML.h"
#include "ShareMisc.h"
#include "IXML.h"

using namespace std;

namespace nsParserXMLResource
{
  const char* sResources     = "Resources";

  const char* sGraphicEngine = "GraphicEngine";
  const char* sGameEngine    = "GameEngine";
  const char* sGUI           = "GUI";
  const char* sGame          = "Game";
}

using namespace nsParserXMLResource;

TParserXMLResource::TParserXMLResource()
{
  TMakerXML maker;
  mXML = maker.New();
}
//---------------------------------------------------------------------------------------
TParserXMLResource::~TParserXMLResource()
{
  TMakerXML maker;
  maker.Delete(mXML);
  mXML = NULL;
}
//---------------------------------------------------------------------------------------
bool TParserXMLResource::Work(string& file)
{
  strError = "";

  if(mXML->Load(file.data())==false)
  {
    strError = "Нет такого файла";
    return false;
  }

  if(mXML->EnterSection(sResources, 0)==false)
  {
    strError = "Файл некорректен";
    return false;
  }

  if(LoadGraphicEngine()==false)
  {
    strError = "GraphicEngine";
    return false;
  }
  if(LoadGameEngine()==false)
  {
    strError = "GameEngine";
    return false;
  }
  if(LoadGame()==false)
  {
    strError = "Game";
    return false;
  }
  if(LoadGUI()==false)
  {
    strError = "GUI";
    return false;
  }
  return true;
}
//---------------------------------------------------------------------------------------
string TParserXMLResource::GetStrError()
{
  return strError;
}
//---------------------------------------------------------------------------------------
void TParserXMLResource::ErrorNoSection(const char* section)
{
  strError = "Нет секции ";
  strError += section;
}
//---------------------------------------------------------------------------------------
bool TParserXMLResource::LoadGraphicEngine()
{
  if(mXML->EnterSection(sGraphicEngine,0))
  {
    if(mRGrE.Work(mXML)==false)
    {
      strError = mRGrE.GetStrError();
      return false;
    }
    mXML->LeaveSection();
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TParserXMLResource::LoadGameEngine()
{
  if(mXML->EnterSection(sGameEngine,0))
  {
    if(mRGaE.Work(mXML)==false)
    {
      strError = mRGrE.GetStrError();
      return false;
    }
    mXML->LeaveSection();
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TParserXMLResource::LoadGame()
{
  if(mXML->EnterSection(sGame,0))
  {
    if(mRG.Work(mXML)==false)
    {
      strError = mRG.GetStrError();
      return false;
    }
    mXML->LeaveSection();
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TParserXMLResource::LoadGUI()
{
  if(mXML->EnterSection(sGUI,0))
  {
    if(mRGUI.Work(mXML)==false)
    {
      strError = mRGUI.GetStrError();
      return false;
    }
    mXML->LeaveSection();
  }
  return true;
}
//---------------------------------------------------------------------------------------
void TParserXMLResource::GetResultGame(TResources& g)
{
  g = mRG;
}
//---------------------------------------------------------------------------------------
void TParserXMLResource::GetResultGraphicEngine(TResourcesGraphicEngine& ge)
{
  ge = mRGrE;
}
//---------------------------------------------------------------------------------------
void TParserXMLResource::GetResultGUI(TResources& g)
{
  g = mRGUI;
}
//---------------------------------------------------------------------------------------
void TParserXMLResource::GetResultGameEngine(TResources& ge)
{
  ge = mRGaE;
}
//---------------------------------------------------------------------------------------
