/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_05_12 15:19:19.138
	
#include "DeveloperTool_DLL.h"
#include "ScenePartReflectionAggregatorImpl.h"

using namespace nsTornadoEngine;

DllExport_C TScenePartReflectionAggregator* GetScenePartReflectionAggregator()
{
    return new nsTornadoEditor::TScenePartReflectionAggregatorImpl();
}
//--------------------------------------------------------------------------------------------------
DllExport_C void FreeScenePartReflectionAggregator(TScenePartReflectionAggregator * p)
{
    delete p;
}
//--------------------------------------------------------------------------------------------------
