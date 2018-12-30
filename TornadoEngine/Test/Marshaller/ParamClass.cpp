/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ParamClass.h"

#include "BinaryPushMaster.h"
#include "BinaryPopMaster.h"
#include "SerializableUniqueIdentity.h"

void TParamClass::Serialize( TBinaryPushMaster* pPushMaster ) const
{
  pPushMaster->Push( *this );
}
//--------------------------------------------------------------------
void TParamClass::Deserialize( TBinaryPopMaster* pPopMaster )
{
  pPopMaster->Pop( *this );
}
//--------------------------------------------------------------------
short TParamClass::GetSerializableUniqueID()
{
  return nsSerializableUniqueIdentity::eParamClass;
}
//--------------------------------------------------------------------
