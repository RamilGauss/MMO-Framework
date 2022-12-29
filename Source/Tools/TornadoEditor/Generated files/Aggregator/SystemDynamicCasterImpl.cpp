/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// File has been generated at 2022_12_29 17:47:00.851
	
#include "SystemDynamicCasterImpl.h"

#include "Generated files\Container\EcsDynamicCaster.h"

using namespace nsTornadoEditor;

TSystemDynamicCasterImpl::TSystemDynamicCasterImpl()
{
    
}
//--------------------------------------------------------------------------------------------------
TSystemDynamicCasterImpl::~TSystemDynamicCasterImpl()
{
    
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
