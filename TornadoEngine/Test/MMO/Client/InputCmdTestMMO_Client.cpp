/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdTestMMO_Client.h"

#include <stdlib.h>
#include <stdio.h>

using namespace std;

string KEY_BEGIN_PORT("begin_port");
string KEY_COUNT     ("count");
string KEY_BEGIN_ID  ("begin_id");

TInputCmdTestMMO_Client::TInputCmdTestMMO_Client()
{
	mVecDefKey.push_back(KEY_BEGIN_PORT);
	mVecDefKey.push_back(KEY_COUNT     );
  mVecDefKey.push_back(KEY_BEGIN_ID  );

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
  for( int i = 1 ; i < argc ; i++)
    vecArgv.push_back(argv[i]);
  return SetArg(vecArgv);
}
//-------------------------------------------------------------------------------
bool TInputCmdTestMMO_Client::SetArg(vector<string>& vecArgv)
{
	mCmdParam.SetArg(vecArgv);

	int cBP = mCmdParam.GetCountValueByKey(KEY_BEGIN_PORT);
	if(cBP)
  {
    string sBeginPort;
    mCmdParam.GetByKey(KEY_BEGIN_PORT, 0, sBeginPort);
    mInput.begin_port = atoi(sBeginPort.data());
  }
	//-------------------------------------------------
	int cV = mCmdParam.GetCountValueByKey(KEY_COUNT);
	if(cV==1)
	{
		string sCount;
		mCmdParam.GetByKey(KEY_COUNT, 0, sCount);
		mInput.count = atoi(sCount.data());
	}
  int cL = mCmdParam.GetCountValueByKey(KEY_BEGIN_ID);
  if(cL==1)
  {
    string sBeginID;
    mCmdParam.GetByKey(KEY_BEGIN_ID, 0, sBeginID);
		mInput.begin_id = atoi(sBeginID.data());
  }
	return true;
}
//-------------------------------------------------------------------------------
void TInputCmdTestMMO_Client::Get(TInputCmdTestMMO_Client::TInput& v_out)
{
	v_out = mInput;
}
//-------------------------------------------------------------------------------
