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
#include "TornadoEngine/Generated files/EcsSystemExtension.h"

using namespace nsTornadoEditor;

TFeatureEcsSystemExtensionImpl::TFeatureEcsSystemExtensionImpl()
{

}
//--------------------------------------------------------------------------------------
TFeatureEcsSystemExtensionImpl::~TFeatureEcsSystemExtensionImpl()
{

}
//--------------------------------------------------------------------------------------
nsECSFramework::TSystem* TFeatureEcsSystemExtensionImpl::DynamicCast(void* p, int rtti)
{
    auto has = TFeatureTypeFactory::Has(rtti);
    if (has) {
        return TEcsSystemExtension::DynamicCast(p, rtti);
    }
    has = nsTornadoEngine::TFeatureTypeFactory::Has(rtti);
    if (has) {
        return nsTornadoEngine::TEcsSystemExtension::DynamicCast(p, rtti);
    }
    return nullptr;
}
//--------------------------------------------------------------------------------------
