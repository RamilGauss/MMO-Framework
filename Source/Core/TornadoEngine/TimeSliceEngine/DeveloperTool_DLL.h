/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ScenePartsContainer.h"

#define StrGetScenePartsContainer  "GetScenePartsContainer"
#define StrFreeScenePartsContainer "FreeScenePartsContainer"

typedef nsTornadoEngine::TScenePartsContainer* (*FuncGetScenePartsContainer)();
typedef void (*FuncFreeScenePartsContainer)(nsTornadoEngine::TScenePartsContainer*);

DllExport_C nsTornadoEngine::TScenePartsContainer* GetScenePartsContainer();
DllExport_C void FreeScenePartsContainer(nsTornadoEngine::TScenePartsContainer* p);
