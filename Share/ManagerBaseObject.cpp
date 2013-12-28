/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerBaseObject.h"
#include "GlobalParams.h"
#include "file_operation.h"
#include "LoaderListPathID.h"
#include "IBaseObject.h"
#include "BL_Debug.h"
#include "StorePathResources.h"
#include "MapXML_Field.h"

#include <boost/foreach.hpp>

using namespace std;

const char* NameJointFile = "joint.xml";

TManagerBaseObject::TManagerBaseObject()
{
  LoadListPath();
}
//-------------------------------------------------------------------------------------------
TManagerBaseObject::~TManagerBaseObject()
{
  Done();
}
//-------------------------------------------------------------------------------------------
void TManagerBaseObject::AddObject(IBaseObject* pObject)
{
  SetTree(pObject);
}
//-------------------------------------------------------------------------------------------
void TManagerBaseObject::SetTree(IBaseObject* pObject)
{
  TTreeJoint::TLoadedJoint* pLoaded = NULL;
  unsigned int id = pObject->GetID_Model();
  TMapID_Tree::iterator fit = mMapID_Tree.find(id);
  TMapID_Tree::iterator eit = mMapID_Tree.end();
  if(fit!=eit)
    pLoaded = (TTreeJoint::TLoadedJoint*)fit->second;
  else
  {
    TMapID_Path::iterator it = mMapID_Path.find(id);
    if(mMapID_Path.end()==it) {BL_FIX_BUG();return;}
    if(mLoaderTree.Load((char*)it->second.data())==false) {BL_FIX_BUG();return;}
    pLoaded = mLoaderTree.TakeTree();

    TMapID_Tree::value_type val(id,pLoaded);
    mMapID_Tree.insert(val);
  }
  pObject->SetTree(pLoaded);
}
//-------------------------------------------------------------------------------------------
void TManagerBaseObject::Done()
{
	BOOST_FOREACH( TMapID_Tree::value_type &bit, mMapID_Tree )
    delete bit.second;

  mMapID_Tree.clear();
}
//-------------------------------------------------------------------------------------------
bool TManagerBaseObject::LoadListPath()
{
  TLoaderListPathID loader;
  char sAbsPath[300];
  FindAbsPath((char*)GetStorePathResources()->GetSecond("model"),
              sAbsPath,sizeof(sAbsPath));
  if(loader.Load(sAbsPath,&mMapID_Path)==false)
  {
    BL_FIX_BUG();
    return false;
  }

  PrepareForTreeJoint();

  return true;
}
//--------------------------------------------------------------------------------------
void TManagerBaseObject::PrepareForTreeJoint()
{
	BOOST_FOREACH(TMapID_Path::value_type &bit, mMapID_Path)
		bit.second += NameJointFile;
}
//--------------------------------------------------------------------------------------
