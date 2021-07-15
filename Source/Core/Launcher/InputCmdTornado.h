/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "InputByCmd.h"

class TInputCmdTornado : public TInputByCmd
{
public:

    struct TInput
    {
        std::string              libName;
        std::vector<std::string> param;
        bool                     useConsole = false;
    };

    TInput mInput;

    void Init() override;
};
