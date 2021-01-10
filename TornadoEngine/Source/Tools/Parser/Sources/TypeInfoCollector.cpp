/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeInfoCollector.h"
#include "BlockLexemaEntity.h"
#include "LineLexemaEntity.h"
#include "BL_Debug.h"

#include "EmptyLexema.h"
#include "NamespaceLexema.h"
#include "ClassLexema.h"
#include "StructLexema.h"
#include "AccessLexema.h"
#include "EnumLexema.h"
#include "FriendLexema.h"
#include "FunctionDefinitionLexema.h"
#include "FunctionDeclarationLexema.h"
#include "VariableDeclarationLexema.h"
#include "PragmaLexema.h"
#include "IdentifierLexema.h"

using namespace nsCppParser;

void TTypeInfoCollector::CollectLexemasToInfoByBlock(TBlockLexemaEntity* blockLexemaEntity)
{
    if (blockLexemaEntity->mParentBlock == nullptr) {
        Reset();
    }

    for (auto& lexema : blockLexemaEntity->mTokens) {
        switch (lexema->GetType()) {
            case ILexemaEntity::Type::BLOCK:
                CollectLexemasToInfoByBlock((TBlockLexemaEntity*) lexema.get());
                break;
            case ILexemaEntity::Type::LINE:
                CollectLexemasToInfoByLine((TLineLexemaEntity*) lexema.get());
                break;
        }
    }

    PopSpace();
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::CollectLexemasToInfoByLine(TLineLexemaEntity* lineLexemaEntity)
{
    for (auto& lexema : lineLexemaEntity->mLexemas) {
        auto pLexema = lexema.get();
        auto type = lexema->GetType();
        switch (type) {
            case ILexema::LexemaType::EMPTY:
                HandleEmpty((TEmptyLexema*) pLexema);
                break;
            case ILexema::LexemaType::NAMESPACE:
                HandleNamespace((TNamespaceLexema*) pLexema);
                break;
            case ILexema::LexemaType::ACCESS:
                HandleAccess((TAccessLexema*) pLexema);
                break;
            case ILexema::LexemaType::CLASS:
                HandleClass((TClassLexema*) pLexema);
                break;
            case ILexema::LexemaType::STRUCT:
                HandleStruct((TStructLexema*) pLexema);
                break;
            case ILexema::LexemaType::ENUM:
                HandleEnum((TEnumLexema*) pLexema);
                break;
            case ILexema::LexemaType::VARIABLE_DECLARATION:
                HandleVariableDeclaration((TVariableDeclarationLexema*) pLexema);
                break;
            case ILexema::LexemaType::FUNCTION_DECLARATION:
                HandleFunctionDeclaration((TFunctionDeclarationLexema*) pLexema);
                break;
            case ILexema::LexemaType::FUNCTION_DEFINITION:
                HandleFunctionDefinition((TFunctionDefinitionLexema*) pLexema);
                break;
            case ILexema::LexemaType::FRIEND:
                HandleFriend((TFriendLexema*) pLexema);
                break;
            case ILexema::LexemaType::PRAGMA:
                HandlePragma((TPragmaLexema*) pLexema);
                break;
            case ILexema::LexemaType::IDENTIFIER:
                HandleIdentifier((TIdentifierLexema*) pLexema);
                break;
            default:
                BL_FIX_BUG();
                break;
        }
    }
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::Reset()
{
    mTypeStack.clear();
    mTypeResult.clear();
    mSpaceStack.clear();
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::PushSpace(std::string& space)
{
    mSpaceStack.push_back(space);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::PopSpace()
{
    mSpaceStack.pop_back();
    mTypeStack.pop_back();
}
//----------------------------------------------------------------------------------------------------
std::string TTypeInfoCollector::GetCurrentSpace()
{
    std::string currentSpace;
    for (auto& space : mSpaceStack) {
        currentSpace += "::" + space;
    }
    return currentSpace;
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleEmpty(TEmptyLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleNamespace(TNamespaceLexema* pLexema)
{
    PushSpace(pLexema->mName);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleAccess(TAccessLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleClass(TClassLexema* pLexema)
{
    AddNewType((TTypeDeclarationLexema*) pLexema);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleStruct(TStructLexema* pLexema)
{
    AddNewType((TTypeDeclarationLexema*) pLexema);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleEnum(TEnumLexema* pLexema)
{
    AddNewType((TTypeDeclarationLexema*) pLexema);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleVariableDeclaration(TVariableDeclarationLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleFunctionDeclaration(TFunctionDeclarationLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleFunctionDefinition(TFunctionDefinitionLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleFriend(TFriendLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandlePragma(TPragmaLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleIdentifier(TIdentifierLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::AddNewType(TTypeDeclarationLexema* baseLexema)
{
    TTypeInfoShPtr typeInfo;
    typeInfo.reset(new TTypeInfo());

    typeInfo->mType = baseLexema->mDeclType;
    typeInfo->mName = baseLexema->mName;

    for (auto& space : mSpaceStack) {
        typeInfo->mNamespaceVec.push_back(space);
    }

    auto currentSpace = GetCurrentSpace();

    for (auto& inheritance : baseLexema->mInheritanceList) {

        TInheritanceInfo inheritanceInfo;
        inheritanceInfo.mOriginalName = inheritance.typeName;

        auto ccIndex = inheritance.typeName.rfind("::");
        if (ccIndex != std::string::npos) {
            inheritanceInfo.mShortTypeName = inheritance.typeName.substr(ccIndex);
        } else {
            inheritanceInfo.mShortTypeName = inheritance.typeName;
        }

        if (currentSpace.length() > 0) {
            inheritanceInfo.mLongTypeName = currentSpace + "::" + inheritance.typeName;// ns::A::B
        } else {
            inheritanceInfo.mLongTypeName = inheritance.typeName;// ns::A::B
        }

        inheritanceInfo.mInheritanceAccessLevel = inheritance.accessLevel;
        typeInfo->mInheritanceVec.push_back(inheritanceInfo);
    }

    typeInfo->mFileName = mFileName;

    PushSpace(baseLexema->mName);
}
//----------------------------------------------------------------------------------------------------
