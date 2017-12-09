/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

// Generated file!
// Изменения будут потеряны. Изменять бессмысленно!
// Дата создания: XXXXXXXXXXXX

#include "Marshallizator.h"
#include "SerializableUniqueIDType.h"

using namespace nsSerializableUniqueIDType;

TContainer TMarshallizator::Serialize( ISerializable* pSer )
{
	mPushMaster.Clear();
	short id = pSer->GetSerializableUniqueID();
	mPushMaster.Push( id, true );
	pSer->Serialize( &mPushMaster );
	return mPushMaster.GetBuffer();
}
//---------------------------------------------------------------------------------------
void TMarshallizator::Deserialize( TContainer* pContainer, bool newObject )
{
	mPopMaster.SetBuffer( pContainer, 0 );
	mPopMaster.Pop( mID );// calculate ID
	switch( mID )
	{
		case MyClass_SerializableUniqueID:
			CommonDeserialize( newObject, &mCBMyClass, &mMyClass );
			break;
		case GeneratedClass_SerializableUniqueID:
			CommonDeserialize( newObject, &mCBGeneratedClass, &mGeneratedClass );
			break;
    case TestClass_SerializableUniqueID:
      CommonDeserialize( newObject, &mCBTestClass, &mTestClass );
      break;
    case ParamClass_SerializableUniqueID:
      CommonDeserialize( newObject, &mCBParamClass, &mParamClass );
      break;
	}
}
//---------------------------------------------------------------------------------------
