/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "GuiProject/Meta/GeneratedFiles/Aggregator/ComponentTypeFactoryImpl.h"

#include "TornadoEngine/GeneratedFiles/Container/ComponentTypeFactory.h"
#include "GuiProject/Meta/GeneratedFiles/Container/ComponentTypeFactory.h"

using namespace nsGuiProject;

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
        