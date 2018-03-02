/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternNameManager.h"

namespace nsManagerNameTypeObjectMap
{
  const char* sMapParameter = "MapParameter";
  const char* sAnimated     = "Animated";
  const char* sLight        = "Light";
  const char* sModel        = "Model";
  const char* sSkybox       = "Skybox";
  const char* sSkydome      = "Skydome";
  const char* sSkyplane     = "Skyplane";
  const char* sSound        = "Sound";
  const char* sTerrain      = "Terrain";
  const char* sVolume       = "Volume";
}

using namespace nsManagerNameTypeObjectMap;

TPatternNameManager::TPatternNameManager()
{
  mVecNameType.push_back(sMapParameter);
  mVecNameType.push_back(sAnimated);
  mVecNameType.push_back(sLight);
  mVecNameType.push_back(sModel);
  mVecNameType.push_back(sSkybox);
  mVecNameType.push_back(sSkydome);
  mVecNameType.push_back(sSkyplane);
  mVecNameType.push_back(sSound);
  mVecNameType.push_back(sTerrain);
  mVecNameType.push_back(sVolume);
}
//-----------------------------------------------------------------------
int TPatternNameManager::GetCount()
{
  return mVecNameType.size();
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Get(int index)
{
  if( index < 0 || index >= GetCount() )
    return "";
  return mVecNameType[index];
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::MapParameter()
{
  return sMapParameter;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Animated()
{
  return sAnimated;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Light()
{
  return sLight;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Model()
{
  return sModel;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Skybox()
{
  return sSkybox;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Skydome()
{
  return sSkydome;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Skyplane()
{
  return sSkyplane;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Sound()
{
  return sSound;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Terrain()
{
  return sTerrain;
}
//-----------------------------------------------------------------------
std::string TPatternNameManager::Volume()
{
  return sVolume;
}
//-----------------------------------------------------------------------
