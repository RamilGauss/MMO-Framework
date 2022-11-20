/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FeatureEcsSystemExtensionImpl.h"

#include "EcsSystemExtension.h"
#include "FeatureTypeFactory.h"
#include "TornadoEngine/Generated files/FeatureTypeFactory.h"
#include "TornadoEngine/Generated files/DynamicCaster.h"

using namespace nsTornadoEditor;

TFeatureEcsSystemExtensionImpl::TFeatureEcsSystemExtensionImpl()
{

}
//--------------------------------------------------------------------------------------
TFeatureEcsSystemExtensionImpl::~TFeatureEcsSystemExtensionImpl()
{

}
//--------------------------------------------------------------------------------------
void* TFeatureEcsSystemExtensionImpl::Cast(int srcRtti, void* srcPtr, int dstRtti)
{
    auto has = TFeatureTypeFactory::Has(srcRtti);
    if (has) {
        return TDynamicCaster::Cast(srcRtti, srcPtr, dstRtti);
    }
    has = nsTornadoEngine::TFeatureTypeFactory::Has(srcRtti);
    if (has) {
        return nsTornadoEngine::TDynamicCaster::Cast(srcRtti, srcPtr, dstRtti);
    }
    return nullptr;
}
//--------------------------------------------------------------------------------------
