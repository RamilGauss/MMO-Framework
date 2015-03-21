/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ParserXMLResourceH
#define ParserXMLResourceH

#include <vector>
#include <map>
#include <string>
#include "ResourcesGraphicEngine.h"
#include "TypeDef.h"

class IXML;

class DllExport TParserXMLResource
{
  IXML* mXML;
  std::string strError;

  TResources              mRG;
  TResources              mRGaE;
  TResources              mRGUI;
  TResourcesGraphicEngine mRGrE;

public:
  TParserXMLResource();
  ~TParserXMLResource();

  bool Work(std::string& file);

  void GetResultGame(TResources& g);
  void GetResultGraphicEngine(TResourcesGraphicEngine& ge);
  void GetResultGUI(TResources& g);
  void GetResultGameEngine(TResources& ge);

  std::string GetStrError();
protected:
  void ErrorNoSection(const char* section);

  bool LoadGraphicEngine();
  bool LoadGameEngine();
  bool LoadGame();
  bool LoadGUI();

};

#endif
