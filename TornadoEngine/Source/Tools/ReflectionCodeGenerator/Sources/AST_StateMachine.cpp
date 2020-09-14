/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <boost/wave/token_ids.hpp>

#include "AST_StateMachine.h"
#include "SingletonManager.h"
#include "ConfigContainer.h"
#include <functional>

// Reference on IDs:
//https://www.boost.org/doc/libs/1_73_0/libs/wave/doc/token_ids.html

using namespace nsReflectionCodeGenerator;
using namespace boost::wave;

TAST_StateMachine::TAST_StateMachine(TTokenInfoManager::TTokenInfoList* tokenListPtr, const std::string& fileName) :
    mStateMachine(&mStateFunc)
{
    mTypeMng = SingletonManager()->Get<TTypeManager>();
    mConfig = SingletonManager()->Get<TConfigContainer>()->Config();

    mTypeInfo.mFileName = fileName;

    mTokenListPtr = tokenListPtr;
    mTokenInfoIt = mTokenListPtr->begin();

    mPrevBlock = BlockType::EMPTY;
}
//-------------------------------------------------------------------------------------------
void TAST_StateMachine::Work()
{
    mStateFunc = &TAST_StateMachine::SearchAttributeOrNamespace;

    auto beforeAction = &TAST_StateMachine::BeforeAction;
    auto afterAction = &TAST_StateMachine::AfterAction;
    mStateMachine.Work(this, beforeAction, afterAction);
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::BeforeAction()
{
    if ( mTokenInfoIt != mTokenListPtr->end() ) {
        if ( mTokenInfoIt->id == T_LEFTBRACE ) {
            mBlockList.push_back(mCurrentBlock);
            mCurrentBlock = BlockType::EMPTY;
        }
        if ( mTokenInfoIt->id == T_RIGHTBRACE ) {

            if ( mBlockList.size() > 0 ) {
                mPrevBlock = mBlockList.back();
                switch ( mPrevBlock ) {
                    case BlockType::EMPTY:
                        break;
                    case BlockType::CLASS_STRUCT:
                        break;
                    case BlockType::METHOD:
                        break;
                    case BlockType::NAMESPACE:
                        mTypeInfo.mNamespaceVec.pop_back();
                        break;
                }

                mBlockList.pop_back();
            }
        }
    }

    if ( IsTokensOut() ) {
        return false;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::AfterAction()
{
    mTokenInfoIt++;
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchAttributeOrNamespace()
{
    static auto applyClassOrStructPragmaFunc = [this] (auto& token) {
        auto fit = mClassOrStructPragmaTextSet.find(mConfig->filter.attribute);
        auto isFound = fit != mClassOrStructPragmaTextSet.end();

        if ( mConfig->filter.attribute.length() == 0 ) {
            isFound = true;
        }

        if ( isFound ) {
            mTypeInfo.mPragmaTextSet = mClassOrStructPragmaTextSet;
            if ( token == T_CLASS ) {
                mTypeInfo.mType = TTypeInfo::eType::Class;
                mMemberInfo.mAccessLevel = TMemberInfo::ePrivate;
            } else if ( token == T_STRUCT ) {
                mTypeInfo.mType = TTypeInfo::eType::Struct;
                mMemberInfo.mAccessLevel = TMemberInfo::ePublic;
            }
            mStateFunc = &TAST_StateMachine::SearchTypeName;
        }
        mClassOrStructPragmaTextSet.clear();
    };

    switch ( mTokenInfoIt->id ) {
        case T_PP_PRAGMA:
            mStateFunc = &TAST_StateMachine::SearchClassOrStructPragma;
            break;
        case T_NAMESPACE:
            mStateFunc = &TAST_StateMachine::SearchNamespaceName;
            mCurrentBlock = BlockType::NAMESPACE;
            break;
        case T_CLASS:
        case T_STRUCT:
            mCurrentBlock = BlockType::CLASS_STRUCT;

            applyClassOrStructPragmaFunc(mTokenInfoIt->id);
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchNamespaceAccept()
{
    switch ( mTokenInfoIt->id ) {
        case T_SPACE:
        case T_SPACE2:
            break;
        case T_LEFTBRACE:
            mTypeInfo.mNamespaceVec.push_back(mNamespaceNameForAdding);
            mStateFunc = &TAST_StateMachine::SearchAttributeOrNamespace;
            break;
        case T_SEMICOLON:
            mStateFunc = &TAST_StateMachine::SearchAttributeOrNamespace;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchNamespaceName()
{
    switch ( mTokenInfoIt->id ) {
        case T_SPACE:
        case T_SPACE2:
            break;
        case T_IDENTIFIER:
            mNamespaceNameForAdding = mTokenInfoIt->value;
            mStateFunc = &TAST_StateMachine::SearchNamespaceAccept;
            break;
        default:
            mStateFunc = &TAST_StateMachine::SearchAttributeOrNamespace;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchClassOrStruct()
{
    switch ( mTokenInfoIt->id ) {
        case T_CLASS:
            mTypeInfo.mType = TTypeInfo::eType::Class;
            mMemberInfo.mAccessLevel = TMemberInfo::ePrivate;
            mStateFunc = &TAST_StateMachine::SearchTypeName;
            break;
        case T_STRUCT:
            mTypeInfo.mType = TTypeInfo::eType::Struct;
            mMemberInfo.mAccessLevel = TMemberInfo::ePublic;
            mStateFunc = &TAST_StateMachine::SearchTypeName;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchInheritanceOrLeftBrace()
{
    switch ( mTokenInfoIt->id ) {
        case T_IDENTIFIER:
            mTypeInfo.mName = mTokenInfoIt->value;// новый идентификатор, может до этого мы встречали DllExport
            break;
        case T_LEFTBRACE:
            mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;

            mCurrentBlock = BlockType::METHOD;
            break;
        case T_COLON:
            mTypeInfo.mInheritanceVec.clear();
            mStateFunc = &TAST_StateMachine::SearchInheritance;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchInheritance()
{
    switch ( mTokenInfoIt->id ) {
        case T_PUBLIC:
            mTypeInfo.mInheritanceVec.push_back(TInheritanceInfo());
            mTypeInfo.mInheritanceVec.back().mInheritanceAccessLevel = TMemberInfo::ePublic;
            mStateFunc = &TAST_StateMachine::SearchBeginInheritanceType;
            break;
        case T_PROTECTED:
            mTypeInfo.mInheritanceVec.push_back(TInheritanceInfo());
            mTypeInfo.mInheritanceVec.back().mInheritanceAccessLevel = TMemberInfo::eProtected;
            mStateFunc = &TAST_StateMachine::SearchBeginInheritanceType;
            break;
        case T_PRIVATE:
            mTypeInfo.mInheritanceVec.push_back(TInheritanceInfo());
            mTypeInfo.mInheritanceVec.back().mInheritanceAccessLevel = TMemberInfo::ePrivate;
            mStateFunc = &TAST_StateMachine::SearchBeginInheritanceType;
            break;
        case T_IDENTIFIER:// namespace or type name, default type
        {
            mTypeInfo.mInheritanceVec.push_back(TInheritanceInfo());
            auto inheritanceAccessLevel = TMemberInfo::ePrivate;
            if ( mTypeInfo.mType == TTypeInfo::Struct )
                inheritanceAccessLevel = TMemberInfo::ePublic;
            auto& inheritanceInfo = mTypeInfo.mInheritanceVec.back();
            inheritanceInfo.mInheritanceAccessLevel = inheritanceAccessLevel;
            inheritanceInfo.mParentTypeName = mTokenInfoIt->value;
            mStateFunc = &TAST_StateMachine::SearchInheritanceEndOrContinueType;
        }
        break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchInheritanceEndOrContinueType()
{
    switch ( mTokenInfoIt->id ) {
        case T_IDENTIFIER:
        case T_COLON_COLON:
        case T_LESS:
        case T_GREATER:
        case T_SHIFTRIGHT:
        {
            auto& inheritanceInfo = mTypeInfo.mInheritanceVec.back();
            inheritanceInfo.mParentTypeName += mTokenInfoIt->value;
        }
        break;
        case T_LEFTBRACE:
            mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;
            break;
        case T_COMMA:
            mStateFunc = &TAST_StateMachine::SearchInheritance;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchBeginInheritanceType()
{
    switch ( mTokenInfoIt->id ) {
        case T_IDENTIFIER:
            auto& inheritanceInfo = mTypeInfo.mInheritanceVec.back();
            inheritanceInfo.mParentTypeName = mTokenInfoIt->value;
            mStateFunc = &TAST_StateMachine::SearchInheritanceEndOrContinueType;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchTypeName()
{
    switch ( mTokenInfoIt->id ) {
        case T_IDENTIFIER:
            mTypeInfo.mName = mTokenInfoIt->value;
            mStateFunc = &TAST_StateMachine::SearchInheritanceOrLeftBrace;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod()
{
    switch ( mTokenInfoIt->id ) {
        case T_PP_PRAGMA:
            mStateFunc = &TAST_StateMachine::SearchMemberPragma;
            break;
        case T_COMPL:// destructor
        case T_TEMPLATE:
        case T_VIRTUAL:
        case T_STATIC:
        case T_VOID:
            mStateFunc = &TAST_StateMachine::SearchDeclarationMethodHandler;
            break;
        case T_PRIVATE:
            mMemberInfo.mAccessLevel = TMemberInfo::ePrivate;
            mStateFunc = &TAST_StateMachine::SearchColonAfterSection;
            break;
        case T_PROTECTED:
            mMemberInfo.mAccessLevel = TMemberInfo::eProtected;
            mStateFunc = &TAST_StateMachine::SearchColonAfterSection;
            break;
        case T_PUBLIC:
            mMemberInfo.mAccessLevel = TMemberInfo::ePublic;
            mStateFunc = &TAST_StateMachine::SearchColonAfterSection;
            break;
        case T_RIGHTBRACE:
            mStateFunc = &TAST_StateMachine::SearchEndClassOrStruct;
            break;
        case T_IDENTIFIER:
            if ( mTokenInfoIt->value == mTypeInfo.mName ) {// constructor
                mStateFunc = &TAST_StateMachine::SearchDeclarationMethodHandler;
                break;
            }
            mMemberInfo.mTypeName = mTokenInfoIt->value;
            mStateFunc = &TAST_StateMachine::SearchFullTypeName;
            break;
        default:
            if ( IsBuiltInType(mTokenInfoIt->id) ) {
                mMemberInfo.mTypeName = mTokenInfoIt->value;
                mStateFunc = &TAST_StateMachine::SearchFullTypeName;
            }
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchFullTypeName()
{
    switch ( mTokenInfoIt->id ) {
        case T_COMMA:
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_SPACE:
        case T_SPACE2:
            if ( mCornerBalance == 0 )
                mStateFunc = &TAST_StateMachine::WaitVariableNameOrTypeContinuous;
            break;
        case T_COLON_COLON:
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_LESS:
            mCornerBalance++;
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_GREATER:
            mCornerBalance--;
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_SHIFTRIGHT:
            mCornerBalance--;
            mCornerBalance--;
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_AND:// &
        case T_STAR:// *
        case T_IDENTIFIER:
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        default:
            if ( IsType(mTokenInfoIt->id) )// vector, list, etc.
                mMemberInfo.mTypeName += mTokenInfoIt->value;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::WaitVariableNameOrTypeContinuous()
{
    switch ( mTokenInfoIt->id ) {
        case T_OPERATOR:
            mStateFunc = &TAST_StateMachine::SearchDeclarationMethodHandler;
            break;
        case T_ASSIGN:
            mTypeInfo.AddMember(mMemberInfo);
            mMemberInfo.mPragmaTextSet.clear();
            mStateFunc = &TAST_StateMachine::SearchWaitSemiColonAfterAssign;
            break;
        case T_COMMA:
            mTypeInfo.AddMember(mMemberInfo);
            break;
        case T_SPACE:
        case T_SPACE2:
            break;
        case T_IDENTIFIER:
            if ( mCornerBalance == 0 )
                mMemberInfo.mName = mTokenInfoIt->value;
            else
                mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_LESS:
            mCornerBalance++;
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_GREATER:
            mCornerBalance--;
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_SHIFTRIGHT:
            mCornerBalance--;
            mCornerBalance--;
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_COLON_COLON:
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            mStateFunc = &TAST_StateMachine::SearchAfterColonColonIdentifier;
            break;
        case T_AND:// &
        case T_STAR:// *
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            break;
        case T_LEFTPAREN:
            // method
            //mParenBalance++;
            mStateFunc = &TAST_StateMachine::SearchDeclarationMethodHandler;
            break;
        case T_SEMICOLON:// end member
            mTypeInfo.AddMember(mMemberInfo);
            mMemberInfo.mPragmaTextSet.clear();
            mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;
            break;
        case T_VIRTUAL:
            mStateFunc = &TAST_StateMachine::SearchDeclarationMethodHandler;
            break;
        default:
            if ( IsBuiltInType(mTokenInfoIt->id) )
                mMemberInfo.mTypeName += " " + mTokenInfoIt->value;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchColonAfterSection()
{
    switch ( mTokenInfoIt->id ) {
        case T_COLON:
            mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchEndClassOrStruct()
{
    switch ( mTokenInfoIt->id ) {
        case T_SEMICOLON:
        {
            // сброс информации о типе
            auto nameSpaces = mTypeInfo.GetNameSpace();
            mTypeMng->Add(nameSpaces, mTypeInfo);

            mTypeInfo.ClearMember();
            mTypeInfo.mInheritanceVec.clear();
            mStateFunc = &TAST_StateMachine::SearchAttributeOrNamespace;// конец класса или структуры
        }
        break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchDeclarationMethodHandler()
{
    switch ( mTokenInfoIt->id ) {
        case T_LEFTBRACE:
            mBraceBalance++;
            mStateFunc = &TAST_StateMachine::SearchMethodBodyHandler;
            break;
        case T_SEMICOLON:
            if ( mBlockList.size() > 0 ) {
                if ( mBlockList.back() == BlockType::CLASS_STRUCT ) {
                    mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;
                }
            }
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchMethodBodyHandler()
{
    switch ( mTokenInfoIt->id ) {
        case T_RIGHTBRACE:
            mBraceBalance--;
            if ( mBraceBalance == 0 )// check balance
                mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;
            break;
        case T_SEMICOLON:// end of declaration
            if ( mBraceBalance == 0 )
                mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchAfterColonColonIdentifier()
{
    switch ( mTokenInfoIt->id ) {
        case T_IDENTIFIER:
            mMemberInfo.mTypeName += mTokenInfoIt->value;
            mStateFunc = &TAST_StateMachine::SearchFullTypeName;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchWaitSemiColonAfterAssign()
{
    switch ( mTokenInfoIt->id ) {
        case T_SEMICOLON:
            mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchMemberPragma()
{
    switch ( mTokenInfoIt->id ) {
        case T_SPACE:
        case T_SPACE2:
            if ( mPragmaText.size() > 0 )
                mPragmaSpaces = mTokenInfoIt->value;
            else
                mPragmaSpaces = "";
            break;
        case T_IDENTIFIER:
            mPragmaText += mPragmaSpaces + mTokenInfoIt->value;
            break;
        case T_NEWLINE:
            mMemberInfo.mPragmaTextSet.insert(mPragmaText);
            mPragmaText = "";
            mStateFunc = &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchClassOrStructPragma()
{
    switch ( mTokenInfoIt->id ) {
        case T_SPACE:
        case T_SPACE2:
            if ( mPragmaText.size() > 0 )
                mPragmaSpaces = mTokenInfoIt->value;
            else
                mPragmaSpaces = "";
            break;
        case T_IDENTIFIER:
            mPragmaText += mPragmaSpaces + mTokenInfoIt->value;
            break;
        case T_NEWLINE:
            mClassOrStructPragmaTextSet.insert(mPragmaText);
            mPragmaText = "";
            mStateFunc = &TAST_StateMachine::SearchAttributeOrNamespace;
            break;
    }
    return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::IsTokensOut()
{
    auto eit = mTokenListPtr->end();
    if ( mTokenInfoIt == eit ) {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::IsBuiltInType(boost::wave::token_id id)
{
    switch ( id ) {
        case T_VOID:
        case T_UNSIGNED:
        case T_SIGNED:
        case T_BOOL:
        case T_CHAR:
        case T_SHORT:
        case T_INT:
        case T_LONG:
        case T_FLOAT:
        case T_DOUBLE:
            return true;
    }
    return false;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::IsType(boost::wave::token_id id)
{
    switch ( id ) {
        case T_IDENTIFIER:
            return true;
        default:
            if ( IsBuiltInType(id) )
                return true;
    }
    return false;
}
//---------------------------------------------------------------------------------------
