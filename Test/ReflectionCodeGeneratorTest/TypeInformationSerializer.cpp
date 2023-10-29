/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_29 16:17:58.476
	
#include "TypeInformationSerializer.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTypeInformation;

std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> TTypeInformationSerializer::mTypeInoVector;

void TTypeInformationSerializer::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
//}
}
//---------------------------------------------------------------------------------------
const nsCppParser::TTypeInfo* TTypeInformationSerializer::Get(int rtti)
{
Init();
return mTypeInoVector[rtti].get();
}
//---------------------------------------------------------------------------------------
