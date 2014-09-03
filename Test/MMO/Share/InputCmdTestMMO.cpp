/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdTestMMO.h"

#define KEY_BEGIN_PORT string("begin_port")
#define KEY_COUNT      string("count")

using namespace std;

TInputCmdTestMMO::TInputCmdTestMMO()
{
	mVecDefKey.push_back(KEY_BEGIN_PORT);
	mVecDefKey.push_back(KEY_COUNT     );

	mCmdParam.SetDefKey(mVecDefKey);
}
//-------------------------------------------------------------------------------
TInputCmdTestMMO::~TInputCmdTestMMO()
{

}
//-------------------------------------------------------------------------------
bool TInputCmdTestMMO::SetArg(int argc, char** argv)
{
  vector<string> vecArgv;
  for( int i = 1 ; i < argc ; i++)
    vecArgv.push_back(argv[i]);
  return SetArg(vecArgv);
}
//-------------------------------------------------------------------------------
bool TInputCmdTestMMO::SetArg(vector<string>& vecArgv)
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
	return true;
}
//-------------------------------------------------------------------------------
void TInputCmdTestMMO::Get(TInputCmdTestMMO::TInput& v_out)
{
	v_out = mInput;
}
//-------------------------------------------------------------------------------
