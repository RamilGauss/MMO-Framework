/*
Project Handler
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_01_01 18:53:46.491
	
#include "HandlerTypeInfo.h"

#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"
#include "Parser/Sources/Generated files/JsonSerializer.h"

using namespace nsTornadoEditor;

std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> THandlerTypeInfo::mTypeInoVector;

void THandlerTypeInfo::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::shared_ptr<nsCppParser::TTypeInfo>> m;
    int max = 0;
    for (auto& rttiType : m) {
        max = std::max(max, rttiType.first);
    }
    mTypeInoVector.resize(max + 1);
    for (auto& rttiType : m) {
        mTypeInoVector[rttiType.first] = rttiType.second;
    }
}
//---------------------------------------------------------------------------------------
const nsCppParser::TTypeInfo* THandlerTypeInfo::Get(int rtti)
{
    Init();
    return mTypeInoVector[rtti].get();
}
//---------------------------------------------------------------------------------------
