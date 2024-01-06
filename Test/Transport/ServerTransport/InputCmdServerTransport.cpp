/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputCmdServerTransport.h"

#include <stdlib.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>

using namespace std;

string SUB_NET("sub_net");

TInputCmdServerTransport::TInputCmdServerTransport()
{
    mVecDefKey.push_back(SUB_NET);

    mCmdParam.SetDefKey(mVecDefKey);
}
//-------------------------------------------------------------------------------
TInputCmdServerTransport::~TInputCmdServerTransport()
{

}
//-------------------------------------------------------------------------------
bool TInputCmdServerTransport::SetArg(int argc, char** argv)
{
    vector<string> vecArgv;
    for (int i = 1; i < argc; i++)
        vecArgv.push_back(argv[i]);
    return SetArg(vecArgv);
}
//-------------------------------------------------------------------------------
bool TInputCmdServerTransport::SetArg(vector<string>& vecArgv)
{
    mCmdParam.SetArg(vecArgv);

    if (mCmdParam.GetCountValueByKey(SUB_NET) == 1) {
        string sSubNet;
        mCmdParam.GetByKey(SUB_NET, 0, sSubNet);
        mInput.sub_net = boost::lexical_cast<int>(sSubNet.data());
    }
    return true;
}
//-------------------------------------------------------------------------------
void TInputCmdServerTransport::Get(TInputCmdServerTransport::TInput& v_out)
{
    v_out = mInput;
}
//-------------------------------------------------------------------------------
