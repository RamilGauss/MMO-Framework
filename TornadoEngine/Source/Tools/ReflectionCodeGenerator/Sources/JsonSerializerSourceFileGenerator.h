/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "JsonSerializerFileGenerator.h"
#include <functional>

namespace nsReflectionCodeGenerator
{
  class TJsonSerializerSourceFileGenerator : public TJsonSerializerFileGenerator
  {
    const std::string s_Bool = "bool";

    const std::string s_CC = "::";
    const std::string s_STD = "std";
    const std::string s_STD_ = "std" + s_CC;

    const std::string s_POM = "POM";
    const std::string s_PUM = "PUM";

    const std::string s_Jobj = "Jobj";
    const std::string s_Obj = "obj";
    const std::string s_Json = "json";

    const std::string s_Push = "Push";
    const std::string s_PushMap = "PushMap";

    const std::string s_PushSerObjArray = "PushSerObjArray";
    const std::string s_PushSerPtrArray = "PushSerPtrArray";
    const std::string s_PushSerSmartPtrArray = "PushSerSmartPtrArray";

    const std::string s_PushSerObjMap = "PushSerObjMap";
    const std::string s_PushSerPtrMap = "PushSerPtrMap";
    const std::string s_PushSerSmartPtrMap = "PushSerSmartPtrMap";

    const std::string s_PopStr = "PopStr";
    const std::string s_PopBool = "PopBool";
    const std::string s_PopNum = "PopNum";

    const std::string s_PopStrArray = "PopStrArray";
    const std::string s_PopBoolArray = "PopBoolArray";
    const std::string s_PopNumArray = "PopNumArray";

    const std::string s_PopStrSet = "PopStrSet";
    const std::string s_PopBoolSet = "PopBoolSet";
    const std::string s_PopNumSet = "PopNumSet";

    const std::string s_PopStrNumMap = "PopStrNumMap";
    const std::string s_PopStrStrMap = "PopStrStrMap";
    const std::string s_PopStrBoolMap = "PopStrBoolMap";
    const std::string s_PopNumNumMap = "PopNumNumMap";
    const std::string s_PopNumStrMap = "PopNumStrMap";
    const std::string s_PopNumBoolMap = "PopNumBoolMap";

    const std::string s_PopSerObjArray = "PopSerObjArray";
    const std::string s_PopSerPtrArray = "PopSerPtrArray";
    const std::string s_PopSerSmartPtrArray = "PopSerSmartPtrArray";
    const std::string s_PopStrSerObjMap = "PopStrSerObjMap";
    const std::string s_PopStrSerPtrMap = "PopStrSerPtrMap";
    const std::string s_PopStrSerSmartPtrMap = "PopStrSerSmartPtrMap";
    const std::string s_PopNumSerObjMap = "PopNumSerObjMap";
    const std::string s_PopNumSerPtrMap = "PopNumSerPtrMap";
    const std::string s_PopNumSerSmartPtrMap = "PopNumSerSmartPtrMap";

  public:
    virtual void Work() override;

  private:
    void AddImplementations();

    void AddSerializeMethodImplementation( TTypeInfo* p );
    void AddDeserializeMethodImplementation( TTypeInfo* p );

    void AddCallingSerializeParent( const std::string& parentTypeName );
    void AddCallingDeserializeParent( const std::string& parentTypeName );

    void AddPushByMemberInfo( TMemberInfo* memberInfo );
    void AddPopByMemberInfo( TMemberInfo* memberInfo );

    void AddCallingMethod( TTypeInfo* p, std::function<void( TMemberInfo* )> func );
    void AddCallingMethodForParent( TTypeInfo* p, std::function<void( const std::string& )> func );

    void AddPush( const std::string& objectName );

    void AddPushSerObjArray( const std::string& type, const std::string& name );
    void AddPushSerPtrArray( const std::string& type, const std::string& name );
    void AddPushSerSmartPtrArray( const std::string& type, const std::string& smartPtrType, const std::string& name );

    void AddPushMap( const std::string& name );

    void AddPushSerObjMap( const std::string& type, const std::string& name );
    void AddPushSerPtrMap( const std::string& type, const std::string& name );
    void AddPushSerSmartPtrMap( const std::string& type, const std::string& smartPtrType, const std::string& name );

    void AddPopStr( const std::string& name );

    void AddPopBool( const std::string& name );
    void AddPopNum( const std::string& name );

    void AddPopBoolArray( const std::string& name );
    void AddPopNumArray( const std::string& name, const std::string& type );
    void AddPopStrArray( const std::string& name );

    void AddPopBoolSet( const std::string& name );
    void AddPopNumSet( const std::string& name, const std::string& type );
    void AddPopStrSet( const std::string& name );

    void AddPopNumBoolMap( const std::string& name );
    void AddPopNumNumMap( const std::string& name );
    void AddPopNumStrMap( const std::string& name );
    void AddPopStrBoolMap( const std::string& name );
    void AddPopStrNumMap( const std::string& name );
    void AddPopStrStrMap( const std::string& name );

    void AddPopMap( const std::string& methodName, const std::string& name );
  private:
    void HandleArrayForPush( TMemberInfo* pMemberInfo );
    void HandleMapForPush( TMemberInfo* pMemberInfo );
    void HandleReflectionForPush( TMemberInfo* pMemberInfo );

    void HandlePushBuiltInOrStringSerMap( TMemberInfo* pMemberInfo );

    void HandlePopBuiltIn( TMemberInfo* memberInfo );

    void HandlePopArray( TMemberInfo* pMemberInfo );
    void HandlePopSet( TMemberInfo* pMemberInfo );
    void HandlePopMap( TMemberInfo* pMemberInfo );
    void HandlePopReflection( TMemberInfo* pMemberInfo );

    void HandlePopReflectionArray( TMemberInfo* pMemberInfo );
    void HandlePopReflectionSet( TMemberInfo* pMemberInfo );

    void HandlePopBuiltInOrStringMap( TMemberInfo* pMemberInfo );
    void HandlePopBuiltInOrStringSerMap( TMemberInfo* pMemberInfo );
  private:

    void General_AddPushSerArrayOrMap( const std::string& type, const std::string& fullType, const std::string& name, const std::string& methodName );
    void General_AddPop( const std::string& name, const std::string& methodName );
    void General_AddPopArrayOrSet( const std::string& name, const std::string& type, const std::string& methodName );

    void General_AddPopSerArrayOrMap( const std::string& keyType, const std::string& valueType,
      const std::string& typeForLambda,
      const std::string& fullType, const std::string& name, const std::string& methodName, const std::string& retNewSmartPtrFunc );
  };
}
