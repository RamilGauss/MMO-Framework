/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdTestTransport.h"

#include <stdlib.h>
#include <stdio.h>

using namespace std;

string KEY_PORT_SRC  ("port_src");
string KEY_PORT_DST  ("port_dst");
string KEY_TIME_SEND ("time_send");

TInputCmdTestTransport::TInputCmdTestTransport()
{
	mVecDefKey.push_back(KEY_PORT_SRC);
	mVecDefKey.push_back(KEY_PORT_DST);
  mVecDefKey.push_back(KEY_TIME_SEND);

	mCmdParam.SetDefKey(mVecDefKey);
}
//-------------------------------------------------------------------------------
TInputCmdTestTransport::~TInputCmdTestTransport()
{

}
//-------------------------------------------------------------------------------
bool TInputCmdTestTransport::SetArg(int argc, char** argv)
{
  vector<string> vecArgv;
  for( int i = 1 ; i < argc ; i++)
    vecArgv.push_back(argv[i]);
  return SetArg(vecArgv);
}
//-------------------------------------------------------------------------------
bool TInputCmdTestTransport::SetArg(vector<string>& vecArgv)
{
	mCmdParam.SetArg(vecArgv);

	int cBP = mCmdParam.GetCountValueByKey(KEY_PORT_SRC);
	if(cBP)
  {
    string sPortSrc;
    mCmdParam.GetByKey(KEY_PORT_SRC, 0, sPortSrc);
    mInput.port_src = atoi(sPortSrc.data());
  }
	//-------------------------------------------------
	int cV = mCmdParam.GetCountValueByKey(KEY_PORT_DST);
	if(cV==1)
	{
		string sPortDst;
		mCmdParam.GetByKey(KEY_PORT_DST, 0, sPortDst);
		mInput.port_dst = atoi(sPortDst.data());
	}
  int cL = mCmdParam.GetCountValueByKey(KEY_TIME_SEND);
  if(cL==1)
  {
    string sTime;
    mCmdParam.GetByKey(KEY_TIME_SEND, 0, sTime);
		mInput.timer_send = atoi(sTime.data());
  }
	return true;
}
//-------------------------------------------------------------------------------
void TInputCmdTestTransport::Get(TInputCmdTestTransport::TInput& v_out)
{
	v_out = mInput;
}
//-------------------------------------------------------------------------------
