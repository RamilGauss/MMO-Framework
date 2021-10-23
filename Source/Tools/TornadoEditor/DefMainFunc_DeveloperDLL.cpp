/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DeveloperTool_DLL.h"

#include "TornadoEditor_ScenePartContainer.h"

using namespace nsTornadoEngine;

DllExport_C TScenePartContainer* GetScenePartContainer()
{
    return new nsTornadoEditor::TTornadoEditor_ScenePartContainer();
}
//-------------------------------------------------------------------
DllExport_C void FreeScenePartContainer(TScenePartContainer* p)
{
    delete p;
}
//-------------------------------------------------------------------