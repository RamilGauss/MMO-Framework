/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_08_28 11:41:45.696
	
#include "HandlerTypeFactoryImpl.h"

#include "Generated files\Container\HandlerTypeFactory.h"

using namespace nsTornadoEditor;

THandlerTypeFactoryImpl::THandlerTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
THandlerTypeFactoryImpl::~THandlerTypeFactoryImpl()
{

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
