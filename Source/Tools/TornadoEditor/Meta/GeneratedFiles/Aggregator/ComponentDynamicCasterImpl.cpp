/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#include "ComponentDynamicCasterImpl.h"

#include "TornadoEngine\GeneratedFiles\Container\ComponentDynamicCaster.h"
#include "GeneratedFiles\Container\ComponentDynamicCaster.h"

using namespace nsTornadoEditor;

TComponentDynamicCasterImpl::TComponentDynamicCasterImpl()
{

}
//--------------------------------------------------------------------------------------------------
TComponentDynamicCasterImpl::~TComponentDynamicCasterImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TComponentDynamicCasterImpl::Init()
{
    TComponentDynamicCaster::Init();
    nsTornadoEngine::TComponentDynamicCaster::Init();
}
//--------------------------------------------------------------------------------------------------
void* TComponentDynamicCasterImpl::Cast(int srcRtti, void* srcPtr, int dstRtti)
{
    auto& m = TComponentDynamicCaster::GetRttiCombinations();
    
    auto fit = m.find(srcRtti);
    auto isFound = (fit != m.end());
    if (isFound) {
        isFound = (fit->second.find(dstRtti) != fit->second.end());
        if (isFound) {
            return TComponentDynamicCaster::Cast(srcRtti, srcPtr, dstRtti);
        }
    }
    
    auto& coreM = nsTornadoEngine::TComponentDynamicCaster::GetRttiCombinations();
    
    auto coreFit = coreM.find(srcRtti);
    isFound = (coreFit != coreM.end());
    if (isFound) {
        isFound = (coreFit->second.find(dstRtti) != coreFit->second.end());
        if (isFound) {
            return nsTornadoEngine::TComponentDynamicCaster::Cast(srcRtti, srcPtr, dstRtti);
        }
    }
    return nullptr;
    }
    //--------------------------------------------------------------------------------------------------
    