/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ResourcesGraphicEngine.h"
#include "IXML.h"

namespace nsResourcesGraphicEngine
{
  const char* sPluginsCfg = "PluginsCfg";
  const char* sName       = "Name";
  const char* sVariant    = "Variant";

  const char* sDebug   = "Debug";
  const char* sRelease = "Release";
}

using namespace nsResourcesGraphicEngine;

TResourcesGraphicEngine::TResourcesGraphicEngine()
{

}
//--------------------------------------------------------------------------
TResourcesGraphicEngine::~TResourcesGraphicEngine()
{

}
//--------------------------------------------------------------------------
bool TResourcesGraphicEngine::Work(IXML* pXML)
{
  mPluginsCfg = "";

  if(TResources::Work(pXML)==false)
    return false;

  if(LoadPluginsCfg()==false)
  {
    ErrorNoSection(sPluginsCfg);
    return false;
  }

  return true;
}
//--------------------------------------------------------------------------
bool TResourcesGraphicEngine::LoadPluginsCfg()
{
  int cntPluginsCfg = mXML->GetCountSection(sPluginsCfg);
  for( int iPluginsCfg = 0 ; iPluginsCfg < cntPluginsCfg ; iPluginsCfg++ )
  {
    std::string name    = mXML->ReadSectionAttr(sPluginsCfg, iPluginsCfg, sName);
    std::string variant = mXML->ReadSectionAttr(sPluginsCfg, iPluginsCfg, sVariant);
    
    std::string curVariant = 
#ifdef _DEBUG
    sDebug;
#else
    sRelease;
#endif
    if(variant==curVariant)
    {
      mPluginsCfg = name;
      return true;
    }
  }
  return false;
}
//--------------------------------------------------------------------------
std::string TResourcesGraphicEngine::GetPluginsCfg()
{
  return mPluginsCfg;
}
//--------------------------------------------------------------------------
