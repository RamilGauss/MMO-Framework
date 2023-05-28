/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_05_28 18:14:10.746
	
#include "SystemTypeFactoryImpl.h"

#include "Generated files\Container\SystemTypeFactory.h"

using namespace nsTornadoEditor;

TSystemTypeFactoryImpl::TSystemTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
TSystemTypeFactoryImpl::~TSystemTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
void* TSystemTypeFactoryImpl::New(int rtti)
{
    auto has = TSystemTypeFactory::Has(rtti);
    if (has) {
        return TSystemTypeFactory::New(rtti);
    }
    return nullptr;
}
//--------------------------------------------------------------------------------------------------
void TSystemTypeFactoryImpl::Delete(void* p, int rtti)
{
    auto has = TSystemTypeFactory::Has(rtti);
    if (has) {
        TSystemTypeFactory::Delete(p, rtti);
    }
}
//--------------------------------------------------------------------------------------------------
