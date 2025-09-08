/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "GuiProject/Meta/GeneratedFiles/Aggregator/HandlerTypeInformationImpl.h"

#include "GuiProject/Meta/GeneratedFiles/Container/HandlerTypeInfo.h"

using namespace nsGuiProject;

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
