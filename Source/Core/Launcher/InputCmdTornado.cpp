/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputCmdTornado.h"
#include <boost/lexical_cast.hpp>

std::string KEY_LIB("-d");
std::string KEY_PARAM("-p");
std::string KEY_CONSOLE("-c");

void TInputCmdTornado::Init()
{
    Add(KEY_LIB, [&mInput = mInput](std::string& sValue)
    {
        mInput.libName = sValue.data();
    });

    Add(KEY_PARAM, [&mInput = mInput, &mCmdParam = mCmdParam](std::string& sValue)
    {
        int cP = mCmdParam.GetCountValueByKey(KEY_PARAM);
        for (int i = 0; i < cP; i++) {
            std::string sParam;
            mCmdParam.GetByKey(KEY_PARAM, i, sParam);
            mInput.param.push_back(sParam);
        }
    });

    Add(KEY_CONSOLE, [&mInput = mInput](std::string& sValue)
    {
        mInput.useConsole = true;
    });
}
//-------------------------------------------------------------------------------
