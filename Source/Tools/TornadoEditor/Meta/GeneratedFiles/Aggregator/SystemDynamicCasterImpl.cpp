/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#include "SystemDynamicCasterImpl.h"

#include "GeneratedFiles\Container\EcsDynamicCaster.h"

using namespace nsTornadoEditor;

TSystemDynamicCasterImpl::TSystemDynamicCasterImpl()
{

}
//--------------------------------------------------------------------------------------------------
TSystemDynamicCasterImpl::~TSystemDynamicCasterImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TSystemDynamicCasterImpl::Init()
{
    TEcsDynamicCaster::Init();
}
//--------------------------------------------------------------------------------------------------
void* TSystemDynamicCasterImpl::Cast(int srcRtti, void* srcPtr, int dstRtti)
{
    auto& m = TEcsDynamicCaster::GetRttiCombinations();
    
    auto fit = m.find(srcRtti);
    auto notFound = (fit == m.end());
    if (notFound) {
        return nullptr;
    }
    notFound = (fit->second.find(dstRtti) == fit->second.end());
    if (notFound) {
        return nullptr;
    }
    return TEcsDynamicCaster::Cast(srcRtti, srcPtr, dstRtti);
}
//--------------------------------------------------------------------------------------------------
