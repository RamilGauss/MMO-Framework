/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

// Generated file!
// Изменения будут потеряны. Изменять бессмысленно!
// Дата создания: XXXXXXXXXXXX

#ifndef MarshallizatorH
#define MarshallizatorH

#include "CallBackRegistrator.h"
#include "PushMaster.h"
#include "PopMaster.h"
#include "MyClass.h"
#include "TestClass.h"
#include "ParamClass.h"

class TMarshallizator
{
	TPushMaster mPushMaster;
	TPopMaster mPopMaster;

	MyClass        mMyClass;
	GeneratedClass mGeneratedClass;
  TestClass      mTestClass;
  ParamClass     mParamClass;

	short mID;
public:
	TContainer Serialize( ISerializable* pSer );
	void Deserialize( TContainer* pContainer, bool newObject );

	// generated list of types
	TCallBackRegistrator1<MyClass*>        mCBMyClass;
	TCallBackRegistrator1<GeneratedClass*> mCBGeneratedClass;
  TCallBackRegistrator1<TestClass*>      mCBTestClass;
  TCallBackRegistrator1<ParamClass*>     mCBParamClass;

private:
	template<typename T>
	void CommonDeserialize( bool newObject, TCallBackRegistrator1<T*>* pCB, T* pObj );
};
//--------------------------------------------------------------------
template<typename T>
void TMarshallizator::CommonDeserialize( bool newObject, TCallBackRegistrator1<T*>* pCB, T* pObj )
{
	int regCount = pCB->RegisteredCount();
	if( regCount == 0 )
		return;
	if( newObject )
		pObj = new T();

	pObj->Deserialize( &mPopMaster );
	pCB->Notify( pObj );
}
//--------------------------------------------------------------------
#endif
