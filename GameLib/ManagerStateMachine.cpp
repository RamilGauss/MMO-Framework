/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerStateMachine.h"
#include "MakerXML.h"
#include "IXML.h"
#include <string>

using namespace std;

const char* sState   = "state";
const char* sName    = "name";
const char* sDesc    = "desc";
const char* sKey     = "key";
const char* sValue   = "value";
const char* sComment = "comment";

TManagerStateMachine::TManagerStateMachine()
{
  TMakerXML maker;
  pXML = maker.New();
}
//---------------------------------------------------------------------------------
TManagerStateMachine::~TManagerStateMachine()
{
  Done();
}
//---------------------------------------------------------------------------------
/*
  Формат xml
  <state>
    <name>A</name>
    <desc>
      <key>0</key>
      <value>1</value>
      <comment>adasdad</comment>
    </desc>
    <desc>
      <key>0</key>
      <value>1</value>
      <comment>asdasdad</comment>
    </desc>
  </state>
*/
bool TManagerStateMachine::Load(const char* sPath,unsigned int& id)
{
  TSM_UintUint* pSM = new TSM_UintUint;
  mVecSM.push_back(pSM);

  RET_FALSE(pXML->Load(sPath))
  string sRoot = pXML->GetNameSection(0);
  RET_FALSE(pXML->EnterSection(sRoot.data(),0))
    
    int cntState = pXML->GetCountSection(sState);
    for(int i = 0 ; i < cntState ; i++)
    {
      string nameState;
      string sectionComment;
      unsigned int k, v;
      TMapUintPtr* m = new TMapUintPtr;
      RET_FALSE(pXML->EnterSection(sState,i))
        nameState = pXML->ReadSection(sName,0);// имя состояния
        int cntDesc = pXML->GetCountSection(sDesc);
        for(int j = 0 ; j < cntDesc ; j++)
        {
          RET_FALSE(pXML->EnterSection(sDesc,j))
            RET_FALSE(pXML->ReadUint(sKey,  0,k))
            RET_FALSE(pXML->ReadUint(sValue,0,v))
            sectionComment = pXML->ReadSection(sComment,0);
          RET_FALSE(pXML->LeaveSection())
          m->insert(TMapUintPtr::value_type(k,TDesc(v,sectionComment)));
        }
      RET_FALSE(pXML->LeaveSection())
      pSM->AddState(nameState,NULL,m);
      if(i==0)
        pSM->Init(nameState.data());
    }
  RET_FALSE(pXML->LeaveSection())
  //--------------------------------------------------
  id = mVecSM.size()-1;
  return true;
}
//---------------------------------------------------------------------------------
bool TManagerStateMachine::GetValue(unsigned int id, unsigned int k, unsigned int& v)
{
  if(mVecSM.size()<=id) return false;

  TMapUintPtr::iterator fit = mVecSM.at(id)->GetDataCurrent()->find(k);
  if(fit!=mVecSM.at(id)->GetDataCurrent()->end())
  {
    v = fit->second.v;
    return true; 
  }
  return false;
}
//---------------------------------------------------------------------------------
void TManagerStateMachine::Done()
{
  int cnt = mVecSM.size();
  for(int i = 0 ; i < cnt ; i++ )
  {
    delete mVecSM.at(i);
  }
  mVecSM.clear();

  TMakerXML maker;
  maker.Delete(pXML);
  pXML = NULL;
}
//---------------------------------------------------------------------------------
bool TManagerStateMachine::SetState(const char* sNewStateName, unsigned int id )
{
  if(id==eAll)
  {
    bool res = true;
    int cnt = mVecSM.size();
    for(int i = 0 ; i < cnt ; i++ )
    {
      res &= mVecSM.at(i)->Init(sNewStateName);
    }
    return res;
  }
  return mVecSM.at(id)->Init(sNewStateName);
}
//---------------------------------------------------------------------------------
bool TManagerStateMachine::GetComment(unsigned int id, unsigned int k, string& comment)
{
  TMapUintPtr::iterator fit = mVecSM.at(id)->GetDataCurrent()->find(k);
  if(fit!=mVecSM.at(id)->GetDataCurrent()->end())
  {
    comment = fit->second.comment;
    return true; 
  }
  return false;
}
//---------------------------------------------------------------------------------
