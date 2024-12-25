/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2024_12_25 11:43:22.908
#pragma once

#include "IRunTimeTypeInformation.h"

namespace nsTornadoEditor
{
    struct DllExport TSystemRttiImpl : public nsTornadoEngine::IRunTimeTypeInformation
    {
        TSystemRttiImpl();
        virtual ~TSystemRttiImpl();
        
        const std::list<std::string>* GetTypeNameList() override;
        const std::list<int>* GetRunTimeTypeIndexList() override;
        
        void Init() override;
        bool ConvertTypeToName(int rtti, std::string& typeName) override;
        bool ConvertNameToType(const std::string& typeName, int& rtti) override;
        
    private:
        std::list<std::string> mTypeNameList;
        std::list<int> mRttiList;
    };
}
