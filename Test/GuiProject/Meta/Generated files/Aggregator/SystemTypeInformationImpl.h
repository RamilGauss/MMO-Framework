/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_05_28 17:59:43.232
	
#pragma once

#include "ITypeInformation.h"

namespace nsTornadoEditor
{
    struct DllExport TSystemTypeInformationImpl : public nsTornadoEngine::ITypeInformation
    {
        TSystemTypeInformationImpl();
        virtual ~TSystemTypeInformationImpl();
        
        const std::list<std::string>* GetTypeNameList() override;
        const std::list<int>* GetRunTimeTypeIndexList() override;
        
        bool ConvertTypeToName(int rtti, std::string& typeName) override;
        bool ConvertNameToType(const std::string& typeName, int& rtti) override;
        
    private:
        std::list<std::string> mTypeNameList;
        std::list<int> mRttiList;
    };
}
