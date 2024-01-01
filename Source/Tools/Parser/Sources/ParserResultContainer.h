/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <memory>

#include "Base/Common/TypeDef.h"
#include "TypeInfo.h"

namespace nsCppParser
{
    class DllExport TParserResultContainer
    {
    public:
        std::list<std::shared_ptr<TTypeInfo>> mTypeList;

        //std::list<std::shared_ptr<TFunctionInfo>> mFunctionList;


        void Clear()
        {
            mTypeList.clear();
        }
    };
}