/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BootstrapperSystem.h"

#include "Modules.h"
#include "SceneManager.h"
#include "EditorInfoTagComponent.h"

using namespace nsTornadoEditor;

void TBootstrapperSystem::Init()
{
    nsTornadoEngine::Modules()->SceneMng()->InstantiateByGuid("Main.scene");

    auto editorEid = GetEntMng()->CreateEntity();

    TEditorInfoTagComponent editorInfoTagComponent;
    GetEntMng()->SetComponent(editorEid, editorInfoTagComponent);
}
