/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerNamePattern.h"

namespace nsManagerNameTypeObjectMap
{
  const char* sAnimated = "Animated";
  const char* sLight    = "Light";
  const char* sModel    = "Model";
  const char* sSkybox   = "Skybox";
	const char* sSkydome  = "Skydome";
	const char* sSkyplane = "Skyplane";
  const char* sSound    = "Sound";
  const char* sTerrain  = "Terrain";
  const char* sZone     = "Zone";
}

using namespace nsManagerNameTypeObjectMap;

TManagerNamePattern::TManagerNamePattern()
{
  mVecNameType.push_back(sAnimated);
  mVecNameType.push_back(sLight);
  mVecNameType.push_back(sModel);
  mVecNameType.push_back(sSkybox);
	mVecNameType.push_back(sSkydome);
	mVecNameType.push_back(sSkyplane);
  mVecNameType.push_back(sSound);
  mVecNameType.push_back(sTerrain);
  mVecNameType.push_back(sZone);
}
//-----------------------------------------------------------------------
int TManagerNamePattern::GetCount()
{
  return mVecNameType.size();
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Get(int index)
{
  if( index < 0 || index >= GetCount() )
    return "";
  return mVecNameType[index];
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Animated()
{
  return sAnimated;
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Light()
{
  return sLight;
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Model()
{
  return sModel;
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Skybox()
{
  return sSkybox;
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Skydome()
{
	return sSkybox;
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Skyplane()
{
	return sSkybox;
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Sound()
{
  return sSound;
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Terrain()
{
  return sTerrain;
}
//-----------------------------------------------------------------------
std::string TManagerNamePattern::Zone()
{
  return sZone;
}
//-----------------------------------------------------------------------
