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
#include "EnumValuesLexema.h"
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
    mBlockStack.push_back(mCurrentBlock);
    mCurrentBlock.Reset();
    mCurrentBlock.blockLexemaEntity = blockLexemaEntity;

    for (auto& lexema : blockLexemaEntity->mTokens) {
        switch (lexema->GetType()) {
            case ILexemaEntity::Type::BLOCK:
                CollectLexemasToInfoByBlock((TBlockLexemaEntity*) lexema.get());
                break;
            case ILexemaEntity::Type::LINE:
                CollectLexemasToInfoByLine((TLineLexemaEntity*) lexema.get());
                break;
        }

        mCurrentBlock.lexemaIndex++;
    }

    HandleBlockEnd();
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
            case ILexema::LexemaType::ENUM_VALUES:
                HandleEnumValues((TEnumValuesLexema*) pLexema);
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
    mTypeResult.clear();
    mBlockStack.clear();
}
//----------------------------------------------------------------------------------------------------
std::string TTypeInfoCollector::GetCurrentSpace()
{
    std::string currentSpace;
    for (auto& block : mBlockStack) {
        if (block.type == BlockType::CLASS_STRUCT_OR_ENUM ||
            block.type == BlockType::NAMESPACE) {

            if (currentSpace.length() == 0) {
                currentSpace = block.space;
            } else {
                currentSpace += "::" + block.space;
            }
        }
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
    mCurrentBlock.space = (pLexema->mName);
    mCurrentBlock.type = BlockType::NAMESPACE;
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleAccess(TAccessLexema* pLexema)
{
    mCurrentBlock.accessLevel = pLexema->mAccessLevel;
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
    TTypeInfoShPtr typeInfo;
    typeInfo.reset(new TTypeInfo());

    typeInfo->mType = DeclarationType::ENUM;
    typeInfo->mName = pLexema->mName;

    for (auto& block : mBlockStack) {
        if (block.type == BlockType::CLASS_STRUCT_OR_ENUM ||
            block.type == BlockType::NAMESPACE) {
            typeInfo->mNamespaceVec.push_back(block.space);
        }
    }

    typeInfo->mFileName = mFileName;
    typeInfo->mAbsFileName = mAbsFileName;

    FillPragmaListUpper(typeInfo->mPragmaTextSet);

    mCurrentBlock.space = pLexema->mName;
    mCurrentBlock.type = BlockType::CLASS_STRUCT_OR_ENUM;
    mCurrentBlock.accessLevel = AccessLevel::PUBLIC;

    mCurrentBlock.typeInfo = typeInfo;

    mTypeResult.push_back(typeInfo);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleEnumValues(TEnumValuesLexema* pLexema)
{
    if (GetPrevBlock()->type != BlockType::CLASS_STRUCT_OR_ENUM) {
        return;
    }
    if (GetPrevBlock()->typeInfo->mType != DeclarationType::ENUM) {
        return;
    }

    for (auto& value : pLexema->mValuesMap) {
        GetPrevBlock()->typeInfo->mEnumKeys.insert(value.first);
    }
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleVariableDeclaration(TVariableDeclarationLexema* pLexema)
{
    if (GetPrevBlock()->type != BlockType::CLASS_STRUCT_OR_ENUM) {
        return;
    }
    if (GetPrevBlock()->typeInfo->mType == DeclarationType::ENUM)         {
        return;
    }

    TMemberInfo memberInfo;
    memberInfo.mAccessLevel = mCurrentBlock.accessLevel;
    memberInfo.mName = pLexema->mName;
    FillPragmaListUpper(memberInfo.mPragmaTextSet);
    memberInfo.mTypeName = pLexema->mType;
    memberInfo.mCategory = pLexema->mCategory;

    GetPrevBlock()->typeInfo->AddMember(memberInfo);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleFunctionDeclaration(TFunctionDeclarationLexema* pLexema)
{
    AddMethod(pLexema);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleFunctionDefinition(TFunctionDefinitionLexema* pLexema)
{
    AddMethod(pLexema);
    mCurrentBlock.type = BlockType::FUNCTION;
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleFriend(TFriendLexema* pLexema)
{

}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandlePragma(TPragmaLexema* pLexema)
{
    // See FillPragmaListUpper()
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

    typeInfo->mTemplateArgs = baseLexema->mTemplateInfo.args;

    for (auto& block : mBlockStack) {
        if (block.type == BlockType::CLASS_STRUCT_OR_ENUM ||
            block.type == BlockType::NAMESPACE) {
            typeInfo->mNamespaceVec.push_back(block.space);
        }
    }

    for (auto& inheritance : baseLexema->mInheritanceList) {

        TInheritanceInfo inheritanceInfo;
        ParseInheritanceInfo(inheritance, inheritanceInfo);
        typeInfo->mInheritanceVec.push_back(inheritanceInfo);
    }

    typeInfo->mFileName = mFileName;
    typeInfo->mAbsFileName = mAbsFileName;

    FillPragmaListUpper(typeInfo->mPragmaTextSet);

    mCurrentBlock.space = baseLexema->mName;
    mCurrentBlock.type = BlockType::CLASS_STRUCT_OR_ENUM;
    mCurrentBlock.accessLevel = baseLexema->mDeclType ==
        DeclarationType::CLASS ? AccessLevel::PRIVATE : AccessLevel::PUBLIC;

    mCurrentBlock.typeInfo = typeInfo;

    mTypeResult.push_back(typeInfo);
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::ParseInheritanceInfo(const TTypeDeclarationLexema::TInheritance& inheritance, 
    TInheritanceInfo& inheritanceInfo)
{
    const std::string COLON_COLON = "::";
    const std::string LESS = "<";

    // namespace bb {
    // class Foo : public aa::AA<xx::X, yy::Y>
    // }
    auto currentSpace = GetCurrentSpace();// bb

    inheritanceInfo.mOriginalName = inheritance.typeName;// aa::AA<xx::X, yy::Y>
    auto lessIndex = inheritance.typeName.find(LESS);
    if (lessIndex != std::string::npos) {
        inheritanceInfo.SetupTemplates();
        inheritanceInfo.mOriginalTypeName = inheritance.typeName.substr(0, lessIndex);
    } else {
        inheritanceInfo.mOriginalTypeName = inheritance.typeName;
    }

    auto ccIndex = inheritanceInfo.mOriginalTypeName.rfind(COLON_COLON);
    if (ccIndex != std::string::npos) {
        inheritanceInfo.mShortTypeName = inheritanceInfo.mOriginalTypeName.substr(ccIndex + COLON_COLON.length());
        inheritanceInfo.mOriginalNameSpace = inheritanceInfo.mOriginalTypeName.substr(0, ccIndex);
    } else {
        inheritanceInfo.mShortTypeName = inheritanceInfo.mOriginalTypeName;
    }

    if (currentSpace.length() > 0) {
        inheritanceInfo.mLongTypeName = currentSpace + "::" + inheritanceInfo.mOriginalTypeName;// ns::A::B
    } else {
        inheritanceInfo.mLongTypeName = inheritanceInfo.mOriginalTypeName;// ns::A::B
    }
    inheritanceInfo.mNameSpace = currentSpace;
    inheritanceInfo.mInheritanceAccessLevel = inheritance.accessLevel;
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::HandleBlockEnd()
{
    mCurrentBlock = mBlockStack.back();
    mBlockStack.pop_back();
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::FillPragmaListUpper(std::set<std::string>& pragmaList)
{
    pragmaList.clear();

    auto block = mCurrentBlock.blockLexemaEntity;
    auto lexemaIndex = mCurrentBlock.lexemaIndex;

    for (int i = lexemaIndex - 1; i >= 0; i--) {
        if (block->mTokens[i]->GetType() == ILexemaEntity::Type::LINE) {
            auto line = (TLineLexemaEntity*) (block->mTokens[i].get());
            auto lexemaCount = (int)(line->mLexemas.size());
            for (int j = lexemaCount - 1; j >= 0; j--) {
                if (line->mLexemas[j]->GetType() == ILexema::LexemaType::PRAGMA) {
                    auto pragma = (TPragmaLexema*) (line->mLexemas[j].get());
                    pragmaList.insert(pragma->mValue);
                } else {
                    return;
                }
            }
        } else {
            return;
        }
    }
}
//----------------------------------------------------------------------------------------------------
TTypeInfoCollector::TBlock* TTypeInfoCollector::GetPrevBlock()
{
    return &mBlockStack.back();
}
//----------------------------------------------------------------------------------------------------
void TTypeInfoCollector::AddMethod(TFunctionLexema* pLexema)
{
    if (GetPrevBlock()->type != BlockType::CLASS_STRUCT_OR_ENUM) {
        return;
    }
    if (GetPrevBlock()->typeInfo->mType == DeclarationType::ENUM) {
        return;
    }

    TMethodInfo methodInfo;
    methodInfo.mAccessLevel = mCurrentBlock.accessLevel;
    methodInfo.mName = pLexema->mName;
    FillPragmaListUpper(methodInfo.mPragmaTextSet);
    methodInfo.mCategory = pLexema->mCategory;

    GetPrevBlock()->typeInfo->AddMethod(methodInfo);
}
//----------------------------------------------------------------------------------------------------