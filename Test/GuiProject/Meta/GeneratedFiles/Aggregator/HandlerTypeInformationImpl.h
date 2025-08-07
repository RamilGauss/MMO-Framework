/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#pragma once

#include "ITypeInformation.h"

namespace nsTornadoEditor
{
    struct DllExport THandlerTypeInformationImpl : public nsTornadoEngine::ITypeInformation
    {
        THandlerTypeInformationImpl();
        virtual ~THandlerTypeInformationImpl();
        
        void Init() override;
        const nsCppParser::TTypeInfo* Get(int rtti) override;
    };
}
