/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "LoaderTree.h"
#include "MakerXML.h"

namespace TreeSection
{
  const char* SectionMatrix = "matrix";
  const char* SectionRow    = "row";
  const char* SectionJoint  = "joint";
  const char* SectionName   = "name";
  const char* SectionNumUse = "numUse";
  const char* SectionChild  = "child";
}

using namespace std;
using namespace TreeSection;
using namespace nsStruct3D;

TLoaderTree::TLoaderTree()
{
  pLoadedTree = NULL;
  TMakerXML makerXML;
  mXML = makerXML.New();
}
//-----------------------------------------------------------------------------
TLoaderTree::~TLoaderTree()
{
  delete pLoadedTree;
	TMakerXML makerXML;
	makerXML.Delete(mXML);
}
//-----------------------------------------------------------------------------
bool TLoaderTree::Load(char* sPath)
{
  delete pLoadedTree;
  pLoadedTree = new TTreeJoint::TLoadedJoint;
  RET_FALSE(mXML->Load(sPath))
  string sRoot = mXML->GetNameSection(0);
  RET_FALSE(mXML->EnterSection(sRoot.data(),0))
  //--------------------------------------------
  LoadMatrix4x4(SectionMatrix,0,&(pLoadedTree->world));

  // загрузить Joint
  // имя корня
  string str = mXML->ReadSection(SectionName,0);
  if(str.length())
    pLoadedTree->root = str.data();
  else return false;
  //------------------------------------------------------------------
  // загрузить части
  int cntJoint = mXML->GetCountSection(SectionJoint);
  for(int i = 0 ; i < cntJoint ; i++)
    RET_FALSE(LoadJoint(i)) 

  mXML->ResetPos();
  return true;
}
//---------------------------------------------------------------------------------------
TTreeJoint::TLoadedJoint* TLoaderTree::TakeTree()
{
  TTreeJoint::TLoadedJoint* p = pLoadedTree;
  pLoadedTree = NULL;
  return p;
}
//--------------------------------------------------------------------------------
bool TLoaderTree::LoadMatrix4x4(const char* name,int num, TMatrix16* pM)
{
  RET_FALSE(mXML->EnterSection(name,num))
  for(int k = 0 ; k < 4 ; k++)
  {
    float v4[4];
    RET_FALSE(mXML->ReadFloat4(SectionRow,k,&v4[0]))
    for(int m = 0 ; m < 4 ; m++)
      pM->m[k][m] = v4[m];
  }
  mXML->LeaveSection();
  return true;
}
//--------------------------------------------------------------------------------
bool TLoaderTree::LoadJoint(int i)
{
  RET_FALSE(mXML->EnterSection(SectionJoint,i))

  TTreeJoint::TPart* pPart = new TTreeJoint::TPart;
  // name
  string str = mXML->ReadSection(SectionName,0);
  if(str.length())
    pPart->name = str;
  else return false;
  // numUse
  int numUse;
  RET_FALSE(mXML->ReadInt(SectionNumUse,0,numUse))
  pPart->numUse = numUse;
  // загрузить детей
  int cntChild = mXML->GetCountSection(SectionChild);
  // 05.03.2013 if(cntChild==0) return false;
  for(int j = 0 ; j < cntChild; j++)
  {
    RET_FALSE(mXML->EnterSection(SectionChild,j))
    //---------------------------------------------------------
    TTreeJoint::TChild* pChild = new TTreeJoint::TChild;
    str = mXML->ReadSection(SectionName,0);
    if(str.length())
      pChild->name = str.data();
    else return false;
    //----------------------------------------------    
    RET_FALSE(LoadMatrix4x4(SectionMatrix,0,&(pChild->matrix)))
    pPart->vectorChild.push_back(pChild);
    //--------------------------------------------------------
    mXML->LeaveSection();
  }

  pLoadedTree->vectorPart.push_back(pPart);
  
  mXML->LeaveSection();
  return true;
}
//--------------------------------------------------------------------------------
