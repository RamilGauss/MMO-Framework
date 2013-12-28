/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MakerObjectCommon.h"

#include "namespace_ID_BEHAVIOR.h"
#include "TankTower.h"
#include "ObjectScene.h"
#include "LoaderListPathID.h"
#include "GlobalParams.h"
#include "file_operation.h"
#include "BL_Debug.h"
#include "ObjectLight.h"

using namespace nsID_BEHAVIOR;
using namespace std;

TMakerObjectCommon::TMakerObjectCommon()
{
}
//------------------------------------------------------------------------
TMakerObjectCommon::~TMakerObjectCommon()
{

}
//------------------------------------------------------------------------
IBaseObjectCommon* TMakerObjectCommon::NewByID_Behavior(unsigned int id_behavior)
{
  IBaseObjectCommon* pObject = NULL;
  switch(id_behavior)
  {
    case ID_OBJECT_SCENE:
      pObject = new TObjectScene();
      break;
    case ID_TANK_TOWER:
      pObject = new TTankTower();
      break;
    case ID_LIGHT:
      pObject = new TObjectLight();
      break;
    default:BL_FIX_BUG();
  }
  return pObject;
}
//------------------------------------------------------------------------
void TMakerObjectCommon::Delete(IBaseObjectCommon* pObject)
{
  delete pObject;
}
//------------------------------------------------------------------------
