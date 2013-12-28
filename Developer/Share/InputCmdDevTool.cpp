/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdDevTool.h"

#define KEY_IP   string("ip")
#define KEY_PORT string("port")

using namespace std;

TInputCmdDevTool::TInputCmdDevTool()
{
  mVecDefKey.push_back(KEY_IP);
	mVecDefKey.push_back(KEY_PORT);

	mCmdParam.SetDefKey(mVecDefKey);
}
//-------------------------------------------------------------------------------
TInputCmdDevTool::~TInputCmdDevTool()
{

}
//-------------------------------------------------------------------------------
void TInputCmdDevTool::SetDefParam(TInput& defInput)
{
  mInput = defInput;
}
//-------------------------------------------------------------------------------
bool TInputCmdDevTool::SetArg(vector<string>& vecArgv)
{
	mCmdParam.SetArg(vecArgv);

	int cIP = mCmdParam.GetCountValueByKey(KEY_IP);
	if(cIP)
  {
    string sIP;
    mCmdParam.GetByKey(KEY_IP, 0, sIP);
    mInput.ip = boost::asio::ip::address_v4::from_string(sIP.data()).to_ulong();
  }
	//-------------------------------------------------
	int cPort = mCmdParam.GetCountValueByKey(KEY_PORT);
	if(cPort)
  {
    string sPort;
    mCmdParam.GetByKey(KEY_PORT, 0, sPort);
    mInput.port = atoi(sPort.data());
  }
	//-------------------------------------------------
	return true;
}
//-------------------------------------------------------------------------------
void TInputCmdDevTool::Get(TInputCmdDevTool::TInput& v_out)
{
	v_out = mInput;
}
//-------------------------------------------------------------------------------
