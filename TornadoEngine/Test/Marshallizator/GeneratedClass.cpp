/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GeneratedClass.h"

#include "PushMaster.h"
#include "PopMaster.h"
#include "SerializableUniqueIdentity.h"

void GeneratedClass::Serialize( TPushMaster* pPushMaster )
{
  pPushMaster->Push( mID );
}
//--------------------------------------------------------------------
void GeneratedClass::Deserialize( TPopMaster* pPopMaster )
{
  pPopMaster->Pop( mID );
}
//--------------------------------------------------------------------
short GeneratedClass::GetSerializableUniqueID()
{
  return nsSerializableUniqueIdentity::eGeneratedClass; 
}
//--------------------------------------------------------------------