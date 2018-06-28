/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TestClass.h"

#include "PushMaster.h"
#include "PopMaster.h"
#include "SerializableUniqueIdentity.h"

void TTestClass::Serialize( TPushMaster* pPushMaster )const
{
  pPushMaster->PushArraySer<TParamClass>( vParam );
}
//--------------------------------------------------------------------
void TTestClass::Deserialize( TPopMaster* pPopMaster )
{
  pPopMaster->PopVectorSer<TParamClass>( vParam );
}
//--------------------------------------------------------------------
short TTestClass::GetSerializableUniqueID()
{
  return nsSerializableUniqueIdentity::eTestClass; 
}
//--------------------------------------------------------------------
