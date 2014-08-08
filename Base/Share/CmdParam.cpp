/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "CmdParam.h"

using namespace std;

TCmdParam::TCmdParam()
{

}
//-------------------------------------------------------------------------------
TCmdParam::~TCmdParam()
{

}
//-------------------------------------------------------------------------------
void TCmdParam::SetArg(vector<string>& vecArgv)
{
  mMapKey.clear();
  mSetFoundKey.clear();

  int cnt = vecArgv.size();
  for( int iKey = 0 ; iKey < cnt ; iKey++)
  {
    bool resFoundKey = FindInDefKey( vecArgv[iKey] );
    if(resFoundKey)
    {
      mSetFoundKey.insert(vecArgv[iKey]);
      // ищем значения после ключа
      int iValue = iKey + 1;
      while(iValue < cnt)
      {
        resFoundKey = FindInDefKey( vecArgv[iValue] );
        if(resFoundKey==false)
          mMapKey.insert(TMultiMapStrStr::value_type(vecArgv[iKey],vecArgv[iValue]));
        else
          break;
        iValue++;
      }
      iKey = iValue - 1;
    }
  }
}
//-------------------------------------------------------------------------------
int TCmdParam::GetCountValueByKey(string& sKey)
{
  return mMapKey.count(sKey);
}
//-------------------------------------------------------------------------------
bool TCmdParam::GetByKey(string& sKey, int index, string& sOut)
{
  TMultiMapStrStrIt fit = mMapKey.lower_bound(sKey);
  if(fit==mMapKey.end()) return false;
  for(int i = 0 ; i < index ; i++)
    fit++;
  sOut = fit->second;
  return true;
}
//-------------------------------------------------------------------------------
bool TCmdParam::IsKey(string& sKey)
{
  return (mSetFoundKey.find(sKey)!=mSetFoundKey.end());
}
//-------------------------------------------------------------------------------
void TCmdParam::SetDefKey(vector<string>& vecKey)
{
  mSetDefKey.clear();
  mSetDefKey.insert(vecKey.begin(),vecKey.end());
}
//-------------------------------------------------------------------------------
bool TCmdParam::FindInDefKey( string& sKey )
{
  return (mSetDefKey.find(sKey)!=mSetDefKey.end());
}
//-------------------------------------------------------------------------------

