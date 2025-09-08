/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "GuiProject/Meta/GeneratedFiles/Aggregator/HandlerTypeFactoryImpl.h"

#include "GuiProject/Meta/GeneratedFiles/Container/HandlerTypeFactory.h"

using namespace nsGuiProject;

THandlerTypeFactoryImpl::THandlerTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
THandlerTypeFactoryImpl::~THandlerTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
void THandlerTypeFactoryImpl::Init()
{
    THandlerTypeFactory::Init();
}
//--------------------------------------------------------------------------------------------------
void* THandlerTypeFactoryImpl::New(int rtti)
{
    auto has = THandlerTypeFactory::Has(rtti);
    if (has) {
        return THandlerTypeFactory::New(rtti);
    }
    return nullptr;
}
//--------------------------------------------------------------------------------------------------
void THandlerTypeFactoryImpl::Delete(void* p, int rtti)
{
    auto has = THandlerTypeFactory::Has(rtti);
    if (has) {
        THandlerTypeFactory::Delete(p, rtti);
    }
}
//--------------------------------------------------------------------------------------------------
