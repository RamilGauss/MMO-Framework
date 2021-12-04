/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FeatureTypeFactoryImpl.h"

#include "FeatureTypeFactory.h"
#include "TornadoEngine/Generated files/FeatureTypeFactory.h"

using namespace nsTornadoEditor;

TFeatureTypeFactoryImpl::TFeatureTypeFactoryImpl()
{

}
//------------------------------------------------------------------------------------
TFeatureTypeFactoryImpl::~TFeatureTypeFactoryImpl()
{

}
//------------------------------------------------------------------------------------
void* TFeatureTypeFactoryImpl::New(int rtti)
{
    auto has = TFeatureTypeFactory::Has(rtti);
    if (has) {
        return TFeatureTypeFactory::New(rtti);
    }
    has = nsTornadoEngine::TFeatureTypeFactory::Has(rtti);
    if (has) {
        return nsTornadoEngine::TFeatureTypeFactory::New(rtti);
    }
    return nullptr;
}
//------------------------------------------------------------------------------------
void TFeatureTypeFactoryImpl::Delete(void* p, int rtti)
{
    auto has = TFeatureTypeFactory::Has(rtti);
    if (has) {
        TFeatureTypeFactory::Delete(p, rtti);
        return;
    }
    has = nsTornadoEngine::TFeatureTypeFactory::Has(rtti);
    if (has) {
        nsTornadoEngine::TFeatureTypeFactory::Delete(p, rtti);
    }
}
//------------------------------------------------------------------------------------