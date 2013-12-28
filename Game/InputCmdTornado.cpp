/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdTornado.h"

#define KEY_PARAM   string("-p")
#define KEY_LIB     string("-d")
#define KEY_VARIANT string("-v")
#define KEY_REALIZE string("-r")
#define KEY_CONSOLE string("-c")

using namespace std;

TInputCmdTornado::TInputCmdTornado()
{
	mVecDefKey.push_back(KEY_VARIANT);
	mVecDefKey.push_back(KEY_LIB    );
	mVecDefKey.push_back(KEY_REALIZE);
	mVecDefKey.push_back(KEY_PARAM  );
	mVecDefKey.push_back(KEY_CONSOLE);

	mCmdParam.SetDefKey(mVecDefKey);
}
//-------------------------------------------------------------------------------
TInputCmdTornado::~TInputCmdTornado()
{

}
//-------------------------------------------------------------------------------
bool TInputCmdTornado::SetArg(vector<string>& vecArgv)
{
	mCmdParam.SetArg(vecArgv);

	int cD = mCmdParam.GetCountValueByKey(KEY_LIB);
	if(cD==0) return false;
	mCmdParam.GetByKey(KEY_LIB, 0, mInput.libName);
	//-------------------------------------------------
	int cR = mCmdParam.GetCountValueByKey(KEY_REALIZE);
	if(cR==0) return false;
	mCmdParam.GetByKey(KEY_REALIZE, 0, mInput.type);
	//-------------------------------------------------
	int cV = mCmdParam.GetCountValueByKey(KEY_VARIANT);
	if(cV==1)
	{
		string sVariant;
		mCmdParam.GetByKey(KEY_VARIANT, 0, sVariant);
		mInput.variant_use = atoi(sVariant.data());
	}
	//-------------------------------------------------
	int cP = mCmdParam.GetCountValueByKey(KEY_PARAM);
	for(int i = 0 ; i < cP ; i++ )
  {
    string sParam;
    mCmdParam.GetByKey(KEY_PARAM, i, sParam);
    mInput.param.push_back(sParam);
  }
  //-------------------------------------------------
  if(mCmdParam.IsKey(KEY_CONSOLE))
    mInput.useConsole = true;
  //-------------------------------------------------
	return true;
}
//-------------------------------------------------------------------------------
void TInputCmdTornado::Get(TInputCmdTornado::TInput& v_out)
{
	v_out = mInput;
}
//-------------------------------------------------------------------------------
