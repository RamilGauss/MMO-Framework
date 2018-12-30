/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GeneratedClass.h"

#include "BinaryPushMaster.h"
#include "BinaryPopMaster.h"
#include "SerializableUniqueIdentity.h"

void TGeneratedClass::Serialize( TBinaryPushMaster* pPushMaster ) const
{
  pPushMaster->Push( mID );
}
//--------------------------------------------------------------------
void TGeneratedClass::Deserialize( TBinaryPopMaster* pPopMaster )
{
  pPopMaster->Pop( mID );
}
//--------------------------------------------------------------------
short TGeneratedClass::GetSerializableUniqueID()
{
  return nsSerializableUniqueIdentity::eGeneratedClass; 
}
//--------------------------------------------------------------------
