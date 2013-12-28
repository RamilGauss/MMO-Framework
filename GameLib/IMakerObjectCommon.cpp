/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IMakerObjectCommon.h"
#include <stddef.h>

#include "LoaderListPathID.h"
#include "GlobalParams.h"
#include "file_operation.h"
#include "BL_Debug.h"
#include "IBaseObjectCommon.h"
#include "MapXML_Field.h"
#include "StorePathResources.h"

using namespace std;

IMakerObjectCommon::IMakerObjectCommon()
{
  flgNeedInit = true;
}
//------------------------------------------------------------------------
IMakerObjectCommon::~IMakerObjectCommon()
{

}
//------------------------------------------------------------------------
IBaseObjectCommon* IMakerObjectCommon::New(unsigned int id_model)
{
  if(flgNeedInit) Init();

  unsigned int id_behavior = GetID_ModelByID_Behavior(id_model);
  IBaseObjectCommon* pObject = NewByID_Behavior(id_behavior);
  pObject->SetID_Model(id_model);
  return pObject;
}
//------------------------------------------------------------------------
unsigned int IMakerObjectCommon::GetID_ModelByID_Behavior(unsigned int id_model)
{
  TMapUintUint::iterator fit = mMapID.find(id_model);
  if(fit == mMapID.end())
  {
    BL_FIX_BUG();
    return 0;
  }
  return fit->second;
}
//------------------------------------------------------------------------
void IMakerObjectCommon::Init()
{
  TLoaderListPathID loader;
  char sAbsPath[300];
  FindAbsPath((char*)GetStorePathResources()->GetSecond("model"),sAbsPath,sizeof(sAbsPath));
  if(loader.LoadBehavior(sAbsPath,&mMapID)==false)
    BL_FIX_BUG();

  flgNeedInit = false;
}
//------------------------------------------------------------------------
