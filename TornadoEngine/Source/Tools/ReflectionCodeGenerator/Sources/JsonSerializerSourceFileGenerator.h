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

    void AddPushMap( const std::string& objectName );

  private:
    void HandleArrayForPush( TMemberInfo* pMemberInfo );
    void HandleMapForPush( TMemberInfo* pMemberInfo );
    void HandleReflectionForPush( TMemberInfo* pMemberInfo );

    void HandleSerMap( TMemberInfo* pMemberInfo );
  };
}
