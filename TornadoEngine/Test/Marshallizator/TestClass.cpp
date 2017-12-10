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

void TestClass::Serialize( TPushMaster* pPushMaster )
{
  pPushMaster->PushArraySer<ParamClass>( vParam );
}
//--------------------------------------------------------------------
void TestClass::Deserialize( TPopMaster* pPopMaster )
{
  pPopMaster->PopVectorSer<ParamClass>( vParam );
}
//--------------------------------------------------------------------
short TestClass::GetSerializableUniqueID()
{
  return nsSerializableUniqueIdentity::eTestClass; 
}
//--------------------------------------------------------------------