/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:55.071
#include "ComponentTypeFactoryImpl.h"

#include "TornadoEngine\GeneratedFiles\Container\ComponentTypeFactory.h"
#include "GeneratedFiles\Container\ComponentTypeFactory.h"

using namespace nsTornadoEditor;

TComponentTypeFactoryImpl::TComponentTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
TComponentTypeFactoryImpl::~TComponentTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TComponentTypeFactoryImpl::Init()
{
    TComponentTypeFactory::Init();
    nsTornadoEngine::TComponentTypeFactory::Init();
}
//--------------------------------------------------------------------------------------------------
void* TComponentTypeFactoryImpl::New(int rtti)
{
    auto has = nsTornadoEngine::TComponentTypeFactory::Has(rtti);
    if (has) {
        return nsTornadoEngine::TComponentTypeFactory::New(rtti);
    }
        has = TComponentTypeFactory::Has(rtti);
        if (has) {
            return TComponentTypeFactory::New(rtti);
        }
        return nullptr;
    }
    //--------------------------------------------------------------------------------------------------
    void TComponentTypeFactoryImpl::Delete(void* p, int rtti)
    {
        auto has = nsTornadoEngine::TComponentTypeFactory::Has(rtti);
        if (has) {
            nsTornadoEngine::TComponentTypeFactory::Delete(p, rtti);
            return;
        }
            has = TComponentTypeFactory::Has(rtti);
            if (has) {
                TComponentTypeFactory::Delete(p, rtti);
            }
        }
        //--------------------------------------------------------------------------------------------------
        