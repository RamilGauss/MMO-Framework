/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerNameTypeObjectMap.h"

namespace nsManagerNameTypeObjectMap
{
  const char* sAnimated = "animated";
  const char* sLight    = "light";
  const char* sModel    = "model";
  const char* sSkybox   = "skybox";
  const char* sSound    = "sound";
  const char* sTerrain  = "terrain";
  const char* sZone     = "zone";
}

using namespace nsManagerNameTypeObjectMap;

TManagerNameTypeObjectMap::TManagerNameTypeObjectMap()
{
  mVecNameType.push_back(sAnimated);
  mVecNameType.push_back(sLight);
  mVecNameType.push_back(sModel);
  mVecNameType.push_back(sSkybox);
  mVecNameType.push_back(sSound);
  mVecNameType.push_back(sTerrain);
  mVecNameType.push_back(sZone);
}
//-----------------------------------------------------------------------
int TManagerNameTypeObjectMap::GetCount()
{
  return mVecNameType.size();
}
//-----------------------------------------------------------------------
std::string TManagerNameTypeObjectMap::Get(int index)
{
  if( index < 0 || index >= GetCount() )
    return "";
  return mVecNameType[index];
}
//-----------------------------------------------------------------------
std::string TManagerNameTypeObjectMap::Animated()
{
  return sAnimated;
}
//-----------------------------------------------------------------------
std::string TManagerNameTypeObjectMap::Light()
{
  return sLight;
}
//-----------------------------------------------------------------------
std::string TManagerNameTypeObjectMap::Model()
{
  return sModel;
}
//-----------------------------------------------------------------------
std::string TManagerNameTypeObjectMap::Skybox()
{
  return sSkybox;
}
//-----------------------------------------------------------------------
std::string TManagerNameTypeObjectMap::Sound()
{
  return sSound;
}
//-----------------------------------------------------------------------
std::string TManagerNameTypeObjectMap::Terrain()
{
  return sTerrain;
}
//-----------------------------------------------------------------------
std::string TManagerNameTypeObjectMap::Zone()
{
  return sZone;
}
//-----------------------------------------------------------------------
