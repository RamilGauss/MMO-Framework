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
  const char* sOgreCfg    = "OgreCfg";

  const char* sPath       = "Path";
  const char* sVariant    = "Variant";

	const char* sValueVariant = 
#ifdef _DEBUG
  "Debug";
#else
  "Release";
#endif
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
	mOgreCfg    = "";

  if(TResources::Work(pXML)==false)
    return false;

  if(LoadPluginsCfg()==false)
    return false;
	if(LoadOgreCfg()==false)
		return false;

  return true;
}
//--------------------------------------------------------------------------
bool TResourcesGraphicEngine::LoadPluginsCfg()
{
	return Load(sPluginsCfg, mPluginsCfg);
}
//--------------------------------------------------------------------------
bool TResourcesGraphicEngine::LoadOgreCfg()
{
	return Load(sOgreCfg, mOgreCfg);
}
//--------------------------------------------------------------------------
bool TResourcesGraphicEngine::Load(const char* section, std::string& result)
{
	int cntSection = mXML->GetCountSection(section);
	for( int iSection = 0 ; iSection < cntSection ; iSection++ )
	{
		std::string path    = mXML->ReadSectionAttr(section, iSection, sPath);
		std::string variant = mXML->ReadSectionAttr(section, iSection, sVariant);

		if(variant==sValueVariant)
		{
			result = path;
			return true;
		}
	}
	ErrorNoSection(section);
	return false;
}
//--------------------------------------------------------------------------
std::string TResourcesGraphicEngine::GetPluginsCfg()
{
  return mPluginsCfg;
}
//--------------------------------------------------------------------------
std::string TResourcesGraphicEngine::GetOgreCfg()
{
	return mOgreCfg;
}
//--------------------------------------------------------------------------
