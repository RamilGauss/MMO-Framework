/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/SystemTypeFactoryImpl.h"

#include "TornadoEditor/Meta/GeneratedFiles/Container/SystemTypeFactory.h"

using namespace nsTornadoEditor;

TSystemTypeFactoryImpl::TSystemTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
TSystemTypeFactoryImpl::~TSystemTypeFactoryImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TSystemTypeFactoryImpl::Init()
{
    TSystemTypeFactory::Init();
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
