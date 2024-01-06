/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputCmdClientTransport.h"

#include <stdlib.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>

using namespace std;

string KEY_SUB_NET("sub_net");
string CLIENT_COUNT("client_count");
string SERVER_IP("server_ip");
string SERVER_PORT("server_port");

TInputCmdClientTransport::TInputCmdClientTransport()
{
    mVecDefKey.push_back(KEY_SUB_NET);
    mVecDefKey.push_back(CLIENT_COUNT);
    mVecDefKey.push_back(SERVER_IP);
    mVecDefKey.push_back(SERVER_PORT);

    mCmdParam.SetDefKey(mVecDefKey);
}
//-------------------------------------------------------------------------------
TInputCmdClientTransport::~TInputCmdClientTransport()
{

}
//-------------------------------------------------------------------------------
bool TInputCmdClientTransport::SetArg(int argc, char** argv)
{
    vector<string> vecArgv;
    for (int i = 1; i < argc; i++)
        vecArgv.push_back(argv[i]);
    return SetArg(vecArgv);
}
//-------------------------------------------------------------------------------
bool TInputCmdClientTransport::SetArg(vector<string>& vecArgv)
{
    mCmdParam.SetArg(vecArgv);

    if (mCmdParam.GetCountValueByKey(KEY_SUB_NET) == 1) {
        string sSubNet;
        mCmdParam.GetByKey(KEY_SUB_NET, 0, sSubNet);
        mInput.sub_net = boost::lexical_cast<int>(sSubNet.data());
    }
    if (mCmdParam.GetCountValueByKey(CLIENT_COUNT) == 1) {
        string sClientCount;
        mCmdParam.GetByKey(CLIENT_COUNT, 0, sClientCount);
        mInput.client_count = boost::lexical_cast<int>(sClientCount.data());
    }
    if (mCmdParam.GetCountValueByKey(SERVER_IP) == 1) {
        string sServerIp;
        mCmdParam.GetByKey(SERVER_IP, 0, sServerIp);
        mInput.server_ip = sServerIp;
    }
    if (mCmdParam.GetCountValueByKey(SERVER_PORT) == 1) {
        string sServerPort;
        mCmdParam.GetByKey(SERVER_PORT, 0, sServerPort);
        mInput.server_port = boost::lexical_cast<int>(sServerPort.data());
    }
    return true;
}
//-------------------------------------------------------------------------------
void TInputCmdClientTransport::Get(TInputCmdClientTransport::TInput& v_out)
{
    v_out = mInput;
}
//-------------------------------------------------------------------------------
