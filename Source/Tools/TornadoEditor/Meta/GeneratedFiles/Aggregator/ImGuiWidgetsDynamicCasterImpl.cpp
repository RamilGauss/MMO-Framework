/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/ImGuiWidgetsDynamicCasterImpl.h"

#include "TornadoEngine/GeneratedFiles/Container/ImGuiWidgetsDynamicCaster.h"

using namespace nsTornadoEditor;

TImGuiWidgetsDynamicCasterImpl::TImGuiWidgetsDynamicCasterImpl()
{

}
//--------------------------------------------------------------------------------------------------
TImGuiWidgetsDynamicCasterImpl::~TImGuiWidgetsDynamicCasterImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TImGuiWidgetsDynamicCasterImpl::Init()
{
    nsTornadoEngine::TImGuiWidgetsDynamicCaster::Init();
}
//--------------------------------------------------------------------------------------------------
void* TImGuiWidgetsDynamicCasterImpl::Cast(int srcRtti, void* srcPtr, int dstRtti)
{
    auto& coreM = nsTornadoEngine::TImGuiWidgetsDynamicCaster::GetRttiCombinations();
    
    auto coreFit = coreM.find(srcRtti);
    auto isFound = (coreFit != coreM.end());
    if (isFound) {
        isFound = (coreFit->second.find(dstRtti) != coreFit->second.end());
        if (isFound) {
            return nsTornadoEngine::TImGuiWidgetsDynamicCaster::Cast(srcRtti, srcPtr, dstRtti);
        }
    }
    return nullptr;
}
//--------------------------------------------------------------------------------------------------
