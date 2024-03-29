/*
	ReflectionCodeGenerator for Marshaller
*/
// File has been generated by ReflectionCodeGenerator version 1.18 build 46, at 2020_10_18 14:38:07.425
	
#include "Reflection.h"

using namespace nsReflection;

std::map<std::string, TReflection::Data> TReflection::mTypeNameMap;
void TReflection::Init(  )
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    Data TFloat3_Data;
    TFloat3_Data.typeName = "TFloat3";
    TFloat3_Data.newFunc = [](){ return new TFloat3(); };
    mTypeNameMap.insert({ TFloat3_Data.typeName, TFloat3_Data });
    
    Data TFloat4_Data;
    TFloat4_Data.typeName = "TFloat4";
    TFloat4_Data.newFunc = [](){ return new TFloat4(); };
    mTypeNameMap.insert({ TFloat4_Data.typeName, TFloat4_Data });
    
    Data TParamClass_Data;
    TParamClass_Data.typeName = "TParamClass";
    TParamClass_Data.newFunc = [](){ return new TParamClass(); };
    mTypeNameMap.insert({ TParamClass_Data.typeName, TParamClass_Data });
    
    Data TSimpleComponent_Data;
    TSimpleComponent_Data.typeName = "TSimpleComponent";
    TSimpleComponent_Data.newFunc = [](){ return new TSimpleComponent(); };
    mTypeNameMap.insert({ TSimpleComponent_Data.typeName, TSimpleComponent_Data });
    
    Data TTestClass_Data;
    TTestClass_Data.typeName = "TTestClass";
    TTestClass_Data.newFunc = [](){ return new TTestClass(); };
    mTypeNameMap.insert({ TTestClass_Data.typeName, TTestClass_Data });
    
    Data nsBS_TBaseStruct_Data;
    nsBS_TBaseStruct_Data.typeName = "nsBS::TBaseStruct";
    nsBS_TBaseStruct_Data.newFunc = [](){ return new nsBS::TBaseStruct(); };
    mTypeNameMap.insert({ nsBS_TBaseStruct_Data.typeName, nsBS_TBaseStruct_Data });
    
    Data nsBS_TTestStruct_Data;
    nsBS_TTestStruct_Data.typeName = "nsBS::TTestStruct";
    nsBS_TTestStruct_Data.newFunc = [](){ return new nsBS::TTestStruct(); };
    mTypeNameMap.insert({ nsBS_TTestStruct_Data.typeName, nsBS_TTestStruct_Data });
    
}
//---------------------------------------------------------------------------------------
void* TReflection::New( const std::string& typeName )
{
    Init();
    return mTypeNameMap[typeName].newFunc();
}
//---------------------------------------------------------------------------------------
