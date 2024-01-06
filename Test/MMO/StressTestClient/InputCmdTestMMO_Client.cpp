/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputCmdTestMMO_Client.h"

#include <stdlib.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>

using namespace std;

string KEY_BEGIN_PORT("begin_port");
string KEY_COUNT("count");
string KEY_BEGIN_ID("begin_id");
string KEY_IP_SERVER("ip_server");

TInputCmdTestMMO_Client::TInputCmdTestMMO_Client()
{
}
//-------------------------------------------------------------------------------
void TInputCmdTestMMO_Client::Init()
{
    mVecDefKey.push_back(KEY_BEGIN_PORT);
    mVecDefKey.push_back(KEY_COUNT);
    mVecDefKey.push_back(KEY_BEGIN_ID);
    mVecDefKey.push_back(KEY_IP_SERVER);

    mCmdParam.SetDefKey(mVecDefKey);
}
//-------------------------------------------------------------------------------
TInputCmdTestMMO_Client::~TInputCmdTestMMO_Client()
{

}
//-------------------------------------------------------------------------------
bool TInputCmdTestMMO_Client::SetArg(int argc, char** argv)
{
    vector<string> vecArgv;
    for (int i = 1; i < argc; i++)
        vecArgv.push_back(argv[i]);
    return SetArg(vecArgv);
}
//-------------------------------------------------------------------------------
bool TInputCmdTestMMO_Client::SetArg(vector<string>& vecArgv)
{
    mCmdParam.SetArg(vecArgv);

    int cBP = mCmdParam.GetCountValueByKey(KEY_BEGIN_PORT);
    if (cBP) {
        string sBeginPort;
        mCmdParam.GetByKey(KEY_BEGIN_PORT, 0, sBeginPort);
        mInput.begin_port = boost::lexical_cast<int>(sBeginPort.data());
    }
    //-------------------------------------------------
    int cV = mCmdParam.GetCountValueByKey(KEY_COUNT);
    if (cV == 1) {
        string sCount;
        mCmdParam.GetByKey(KEY_COUNT, 0, sCount);
        mInput.count = boost::lexical_cast<int>(sCount.data());
    }
    int cL = mCmdParam.GetCountValueByKey(KEY_BEGIN_ID);
    if (cL == 1) {
        string sBeginID;
        mCmdParam.GetByKey(KEY_BEGIN_ID, 0, sBeginID);
        mInput.begin_id = boost::lexical_cast<int>(sBeginID.data());
    }
    int cIP_S = mCmdParam.GetCountValueByKey(KEY_IP_SERVER);
    if (cIP_S == 1)
        mCmdParam.GetByKey(KEY_IP_SERVER, 0, mInput.ip_server);
    return true;
}
//-------------------------------------------------------------------------------
void TInputCmdTestMMO_Client::Get(TInputCmdTestMMO_Client::TInput& v_out)
{
    v_out = mInput;
}
//-------------------------------------------------------------------------------
