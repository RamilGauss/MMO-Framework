/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdDevTool.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include <boost/lexical_cast.hpp>

#define KEY_IP_SRC    string("ip_dst")
#define KEY_PORT_SRC  string("port_dst")
#define KEY_PORT_SELF string("port_self")

using namespace std;

TInputCmdDevTool::TInputCmdDevTool()
{
  mVecDefKey.push_back(KEY_IP_SRC);
	mVecDefKey.push_back(KEY_PORT_SRC);
  mVecDefKey.push_back(KEY_PORT_SELF);

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

	int cIP = mCmdParam.GetCountValueByKey(KEY_IP_SRC);
	if(cIP)
  {
    string sIP;
    mCmdParam.GetByKey(KEY_IP_SRC, 0, sIP);
    mInput.ip_dst = boost::asio::ip::address_v4::from_string(sIP.data()).to_ulong();
  }
	//-------------------------------------------------
	int cPort = mCmdParam.GetCountValueByKey(KEY_PORT_SRC);
	if(cPort)
  {
    string sPort;
    mCmdParam.GetByKey(KEY_PORT_SRC, 0, sPort);
    mInput.port_dst = boost::lexical_cast<int>(sPort.data());
  }
	//-------------------------------------------------
  cPort = mCmdParam.GetCountValueByKey(KEY_PORT_SELF);
  if(cPort)
  {
    string sPort;
    mCmdParam.GetByKey(KEY_PORT_SELF, 0, sPort);
    mInput.port_self = boost::lexical_cast<int>(sPort.data());
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
