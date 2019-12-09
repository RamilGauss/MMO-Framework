/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GameParam.h"

namespace nsGameParam
{
  const char* g_NameGame = "Evolution of war machines";
}

using namespace nsGameParam;

TGameParam::TGameParam()
{

}
//------------------------------------------------------------------------
TGameParam::~TGameParam()
{

}
//------------------------------------------------------------------------
std::string TGameParam::GetNameGame()
{
  return g_NameGame;
}
//------------------------------------------------------------------------
