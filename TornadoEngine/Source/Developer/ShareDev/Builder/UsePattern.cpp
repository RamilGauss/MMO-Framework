/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "UsePattern.h"
#include "ManagerNamePattern.h"

TUsePattern::TUsePattern()
{

}
//--------------------------------------------------------------------------
TUsePattern::~TUsePattern()
{

}
//--------------------------------------------------------------------------
bool TUsePattern::UseByBullet(std::string& namePattern)
{
  if(namePattern==TManagerNamePattern::Animated())
    return false;
  if(namePattern==TManagerNamePattern::Light())
    return false;
  if(namePattern==TManagerNamePattern::Model())
    return true;
  if(namePattern==TManagerNamePattern::Skybox())
    return false;
  if(namePattern==TManagerNamePattern::Sound())
    return false;
  if(namePattern==TManagerNamePattern::Terrain())
    return true;
  if(namePattern==TManagerNamePattern::Zone())
    return true;
  return true;
}
//--------------------------------------------------------------------------
bool TUsePattern::UseByOgre(std::string& namePattern)
{
  if(namePattern==TManagerNamePattern::Animated())
    return true;
  if(namePattern==TManagerNamePattern::Light())
    return true;
  if(namePattern==TManagerNamePattern::Model())
    return true;
  if(namePattern==TManagerNamePattern::Skybox())
    return true;
  if(namePattern==TManagerNamePattern::Sound())
    return false;
  if(namePattern==TManagerNamePattern::Terrain())
    return true;
  if(namePattern==TManagerNamePattern::Zone())
    return true;
  return true;
}
//--------------------------------------------------------------------------
bool TUsePattern::UseByOpenAL(std::string& namePattern)
{
  if(namePattern==TManagerNamePattern::Animated())
    return false;
  if(namePattern==TManagerNamePattern::Light())
    return false;
  if(namePattern==TManagerNamePattern::Model())
    return true;
  if(namePattern==TManagerNamePattern::Skybox())
    return false;
  if(namePattern==TManagerNamePattern::Sound())
    return true;
  if(namePattern==TManagerNamePattern::Terrain())
    return true;
  if(namePattern==TManagerNamePattern::Zone())
    return true;
  return true;
}
//--------------------------------------------------------------------------
