/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GlobalParams.h"

#include <stdio.h>

char strVerGameEngine[260];
char strVerGraphicEngine[260];
char strVerPhysicEngine[260];
char strVerNetEngine[260];

class TStrVersion
{
public:
  TStrVersion();
};


static TStrVersion strVersion;

//-------------------------------------------------------------------------------------
TStrVersion::TStrVersion()
{
  sprintf(strVerGameEngine,   "\"Tornado GameEngine\" v%0.3f, numComponents=%d",
    VER_GAME_ENGINE/1000.0f,COUNT_GAME_ENGINE_MODULES);
  sprintf(strVerGraphicEngine,"\"GraphicEngine\" v%0.3f DX9",VER_GRAPHIC_ENGINE/1000.0f);
  sprintf(strVerPhysicEngine, "\"PhysicEngine\" v%0.3f ",VER_PHYSIC_ENGINE/1000.0f);
  sprintf(strVerNetEngine,    "\"MMOEngine\" v%0.3f NET",VER_MMO_ENGINE/1000.0f);
}
//-------------------------------------------------------------------------------------
