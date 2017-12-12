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
#include "SerializableUniqueIdentity.h"

using namespace nsSerializableUniqueIdentity;

ISerializable* TMarshallizator::PrivateDeserialize( TContainer* pContainer, bool newObject, bool useCallback )
{
  mPopMaster.SetBuffer( pContainer, 0 );
  mPopMaster.Pop( mID );// calculate ID
  ISerializable* pSer = NULL;
  switch( mID )
  {
    case eMyClass:
      pSer = CommonDeserialize( newObject, &mCBMyClass, &mMyClass, useCallback );
      break;
    case eGeneratedClass:
      pSer = CommonDeserialize( newObject, &mCBGeneratedClass, &mGeneratedClass, useCallback );
      break;
    case eTestClass:
      pSer = CommonDeserialize( newObject, &mCBTestClass, &mTestClass, useCallback );
      break;
    case eParamClass:
      pSer = CommonDeserialize( newObject, &mCBParamClass, &mParamClass, useCallback );
      break;
  }
  return pSer;
}
//---------------------------------------------------------------------------------------
