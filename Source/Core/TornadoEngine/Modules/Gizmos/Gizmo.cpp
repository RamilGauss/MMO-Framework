/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Gizmos/Gizmo.h"

using namespace nsTornadoEngine;

nsGraphicEngine::IRenderable* TGizmo::GetComponentViewer()
{
    return &mComponentViewer;
}
//------------------------------------------------------------------------------------------------------
nsGraphicEngine::IRenderable* TGizmo::GetSystemViewer()
{
    return &mSystemViewer;
}
//------------------------------------------------------------------------------------------------------
