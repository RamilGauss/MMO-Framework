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
    const std::string s_POM = "POM";
    const std::string s_PUM = "PUM";

    const std::string s_POM_ = s_POM + "::";
    const std::string s_PUM_ = s_PUM + "::";

    const std::string s_Obj = "obj";
    const std::string s_Json = "json";
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

    void AddCallingMethod( TTypeInfo* p, std::function<void(TMemberInfo*)> func );
    void AddCallingMethodForParent( TTypeInfo* p, std::function<void( const std::string&)> func );

    void AddPush( const std::string& objectName );

    void AddPushSerObjArray( const std::string& type, const std::string& name );
    void AddPushSerPtrArray( const std::string& type, const std::string& name );
    void AddPushSerSmartPtrArray();

  private:
    void HandleArrayForPush( TMemberInfo* memberInfo );
  };
}
