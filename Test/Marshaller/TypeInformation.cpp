#include "TypeInformation.h"

#include "IncludeList.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTypeInformation;

std::list<std::string> TTypeInformation::mTypeNameList;
std::list<int> TTypeInformation::mTypeIdentifierList;

std::map<int, std::string> TTypeInformation::mIdentifierNameMap;
std::map<std::string, int> TTypeInformation::mNameIdentifierMap;

void TTypeInformation::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;

    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();




    int _TFloat3Identifier = globalTypeIdentifier->type<TFloat3>();
    std::string _TFloat3Name = "TFloat3";

    mTypeIdentifierList.push_back(_TFloat3Identifier);
    mTypeNameList.push_back(_TFloat3Name);

    mIdentifierNameMap.insert({ _TFloat3Identifier, _TFloat3Name });
    mNameIdentifierMap.insert({ _TFloat3Name, _TFloat3Identifier });









}
//---------------------------------------------------------------------
const std::list<std::string>* TTypeInformation::GetTypeNameList()
{
    return &mTypeNameList;
}
//---------------------------------------------------------------------
const std::list<int>* TTypeInformation::GetTypeIdentifierList()
{
    return &mTypeIdentifierList;
}
//---------------------------------------------------------------------
bool TTypeInformation::ConvertTypeToName(int typeIdentifier, std::string& typeName)
{
    auto fit = mIdentifierNameMap.find(typeIdentifier);
    if ( fit == mIdentifierNameMap.end() ) {
        return false;
    }
    typeName = fit->second;
    return true;
}
//---------------------------------------------------------------------
bool TTypeInformation::ConvertNameToType(const std::string& typeName, int& typeIdentifier)
{
    auto fit = mNameIdentifierMap.find(typeName);
    if ( fit == mNameIdentifierMap.end() ) {
        return false;
    }
    typeIdentifier = fit->second;
    return true;
}
//---------------------------------------------------------------------