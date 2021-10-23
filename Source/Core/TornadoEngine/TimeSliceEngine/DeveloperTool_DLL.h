/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ScenePartContainer.h"

#define StrGetScenePartContainer  "GetScenePartContainer"
#define StrFreeScenePartContainer "FreeScenePartContainer"

typedef nsTornadoEngine::TScenePartContainer* (*FuncGetScenePartContainer)();
typedef void (*FuncFreeScenePartContainer)(nsTornadoEngine::TScenePartContainer*);

DllExport_C nsTornadoEngine::TScenePartContainer* GetScenePartContainer();
DllExport_C void FreeScenePartContainer(nsTornadoEngine::TScenePartContainer* p);
