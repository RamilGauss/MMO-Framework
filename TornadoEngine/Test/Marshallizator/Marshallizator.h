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

#include "IMarshallizator.h"
#include "CallBackRegistrator.h"
#include "PushMaster.h"
#include "PopMaster.h"
#include "MyClass.h"
#include "TestClass.h"
#include "ParamClass.h"

class TMarshallizator : public IMarshallizator
{
  MyClass        mMyClass;
  GeneratedClass mGeneratedClass;
  TestClass      mTestClass;
  ParamClass     mParamClass;
public:
  // регистрация на получения события десериализации соответсвующего типа (см. DeserializeCallback)
  // generated list of types
  TCallBackRegistrator1<MyClass*>        mCBMyClass;
  TCallBackRegistrator1<GeneratedClass*> mCBGeneratedClass;
  TCallBackRegistrator1<TestClass*>      mCBTestClass;
  TCallBackRegistrator1<ParamClass*>     mCBParamClass;
protected:
  virtual ISerializable* PrivateDeserialize( TContainer* pContainer, bool newObject, bool useCallback );
};

#endif
