/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2024_01_01 18:53:47.522
	
#include "HandlerTypeInformationImpl.h"

#include "Generated files\Container\HandlerTypeInfo.h"

using namespace nsTornadoEditor;

THandlerTypeInformationImpl::THandlerTypeInformationImpl()
{

}
//--------------------------------------------------------------------------------------------------
THandlerTypeInformationImpl::~THandlerTypeInformationImpl()
{

}
//--------------------------------------------------------------------------------------------------
void THandlerTypeInformationImpl::Init()
{
    THandlerTypeInfo::Init();
}
//--------------------------------------------------------------------------------------------------
const nsCppParser::TTypeInfo* THandlerTypeInformationImpl::Get(int rtti)
{
    return THandlerTypeInfo::Get(rtti);
}
//--------------------------------------------------------------------------------------------------
