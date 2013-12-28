/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "LoaderListPathID.h"
#include "BL_Debug.h"
#include "MakerXML.h"

using namespace std;

const char* Section_ID          = "id";
const char* Section_path        = "path";
const char* Section_ID_behavior = "id_behavior";

TLoaderListPathID::TLoaderListPathID()
{
  sCurrentPath[0] = '\0';
  TMakerXML makerXML;
  mXML = makerXML.New();
}
//--------------------------------------------------------------------------------------
TLoaderListPathID::~TLoaderListPathID()
{
	TMakerXML makerXML;
	makerXML.Delete(mXML);
}
//--------------------------------------------------------------------------------------
bool TLoaderListPathID::Load(char* sAbsPath, map<unsigned int,string>* pMap)
{
  bool res = true;
  RET_FALSE(mXML->Load(sAbsPath))
  if(!FindCurrentPath(sAbsPath))
    res = false;
  else
  {
    pMap->clear();
    // кол-во записей
    string sRoot = mXML->GetNameSection(0);
    if(sRoot.length()==0) return false;
    RET_FALSE(mXML->EnterSection(sRoot.data(),0))
    //--------------------------------------
    int cnt = mXML->GetCountSection();
    if(cnt==0)
      res = false;
    else
    {
      for(int i = 0 ; i < cnt ; i++ )
      {
        if(LoadPartPath(i,pMap)==false)
        {
          res = false;
          break;
        }
      }
    }
    //--------------------------------------
    mXML->LeaveSection();
  }

  return res;
}
//--------------------------------------------------------------------------------------
bool TLoaderListPathID::LoadPartPath(int i, map<unsigned int,string>* pMap)
{
  string sPart = mXML->GetNameSection(i);
  RET_FALSE(mXML->EnterSection(sPart.data(),i))
  //------------------------------------------------
  unsigned int id;
  RET_FALSE(mXML->ReadUint(Section_ID,0,id))
  string sPath = mXML->ReadSection(Section_path,0);
  if(sPath.length()==0) return false;
  //----------------------------------
  char buffer[400];
  strcpy(buffer,sCurrentPath);
  strcat(buffer,sPath.data());
  strcat(buffer,"\\");
  pMap->insert(map<unsigned int,string>::value_type(id,string(buffer)));
  //------------------------------------------------
  mXML->LeaveSection();

  return true;
}
//--------------------------------------------------------------------------------------
bool TLoaderListPathID::FindCurrentPath(char* sPath)
{
  int len = strlen(sPath);
  for(int i = len-1 ; i > 0 ; i--)
  {
    if((sPath[i]=='\\')||(sPath[i]=='/'))
    {
      strncpy(sCurrentPath,sPath,i+1);
      sCurrentPath[i+1] = '\0';
      return true;
    }
  }
  return false;
}
//--------------------------------------------------------------------------------------
bool TLoaderListPathID::LoadBehavior(char* sAbsPath, std::map<unsigned int,unsigned int>* pMapID_model_ID_Behavior)
{
  bool res = true;
  RET_FALSE(mXML->Load(sAbsPath))
  if(!FindCurrentPath(sAbsPath))
    res = false;
  else
  {
    pMapID_model_ID_Behavior->clear();
    // кол-во записей
    string sRoot = mXML->GetNameSection(0);
    if(sRoot.length()==0) return false;
    RET_FALSE(mXML->EnterSection(sRoot.data(),0))
    //--------------------------------------
    int cnt = mXML->GetCountSection();
    if(cnt==0)
      res = false;
    else
    {
      for(int i = 0 ; i < cnt ; i++ )
      {
        if(LoadPartID_Behavior(i,pMapID_model_ID_Behavior)==false)
        {
          res = false;
          break;
        }
      }
    }
    //--------------------------------------
    mXML->LeaveSection();
  }

  return res;
}
//--------------------------------------------------------------------------------------
bool TLoaderListPathID::LoadPartID_Behavior(int i, map<unsigned int,unsigned int>* pMap)
{
  string sPart = mXML->GetNameSection(i);
  RET_FALSE(mXML->EnterSection(sPart.data(),i))
  //------------------------------------------------
  unsigned int id,id_behavior;
  RET_FALSE(mXML->ReadUint(Section_ID,0,id))
  RET_FALSE(mXML->ReadUint(Section_ID_behavior,0,id_behavior))
  pMap->insert(map<unsigned int,unsigned int>::value_type(id,id_behavior));
  //------------------------------------------------
  mXML->LeaveSection();

  return true;
}
//--------------------------------------------------------------------------------------
 