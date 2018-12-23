/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/wave/token_ids.hpp>

#include "AST_StateMachine.h"
#include "SingletonManager.h"
#include "ConfigContainer.h"

using namespace nsReflectionCodeGenerator;
using namespace boost::wave;

TAST_StateMachine::TAST_StateMachine( TTokenInfoManager::TTokenInfoList* tokenListPtr, std::string fileName ) :
  mStateMachine( &mState )
{
  mTypeMng = SingletonManager()->Get<TTypeManager>();
  mConfig = SingletonManager()->Get<TConfigContainer>()->Config();

  mTypeInfo.mFileName = fileName;

  mTokenListPtr = tokenListPtr;
  mTokenInfoIt = mTokenListPtr->begin();
}
//-------------------------------------------------------------------------------------------
void TAST_StateMachine::Work()
{
  ConfigStateMachine();

  auto beforeAction = std::bind( &TAST_StateMachine::BeforeAction, this );
  auto afterAction = std::bind( &TAST_StateMachine::AfterAction, this );
  mStateMachine.Work( beforeAction, afterAction );
}
//-------------------------------------------------------------------------------------------
void TAST_StateMachine::ConfigStateMachine()
{
  mState = eSearchAttributeOrNamespace;

  AddAction( eSearchAttributeOrNamespace, &TAST_StateMachine::SearchAttributeOrNamespace );
  AddAction( eSearchNamespaceName, &TAST_StateMachine::SearchNamespaceName );
  AddAction( eSearchClassOrStruct, &TAST_StateMachine::SearchClassOrStruct );
  AddAction( eSearchInheritanceOrLeftBrace, &TAST_StateMachine::SearchInheritanceOrLeftBrace );
  AddAction( eSearchInheritance, &TAST_StateMachine::SearchInheritance );
  AddAction( eSearchNamespaceAccept, &TAST_StateMachine::SearchNamespaceAccept );
  AddAction( eSearchTypeName, &TAST_StateMachine::SearchTypeName );
  AddAction( eSearchBeginSectionOrTypeOrBeginMethod, &TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod );
  AddAction( eSearchFullTypeName, &TAST_StateMachine::SearchFullTypeName );
  AddAction( eWaitVariableNameOrTypeContinuous, &TAST_StateMachine::WaitVariableNameOrTypeContinuous );
  AddAction( eSearchColonAfterSection, &TAST_StateMachine::SearchColonAfterSection );
  AddAction( eSearchEndClassOrStruct, &TAST_StateMachine::SearchEndClassOrStruct );
  AddAction( eSearchBeginInheritanceType, &TAST_StateMachine::SearchBeginInheritanceType );
  AddAction( eSearchInheritanceEndOrContinueType, &TAST_StateMachine::SearchInheritanceEndOrContinueType );
  AddAction( eSearchDeclarationMethodHandler, &TAST_StateMachine::SearchDeclarationMethodHandler );
  AddAction( eSearchMethodBodyHandler, &TAST_StateMachine::SearchMethodBodyHandler );
  AddAction( eSearchAfterColonColonIdentifier, &TAST_StateMachine::SearchAfterColonColonIdentifier );
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::BeforeAction()
{
  if ( IsTokensOut() )
    return false;
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
  switch ( mTokenInfoIt->id )
  {
    case T_NAMESPACE:
      mState = eSearchNamespaceName;
      break;
    case T_IDENTIFIER:
      if ( mTokenInfoIt->value == mConfig->filter.attribute )
        mState = eSearchClassOrStruct;
      break;
    case T_RIGHTBRACE:// leave namespace
      if ( mTypeInfo.mNamespaceVec.size() > 0 )
        mTypeInfo.mNamespaceVec.pop_back();
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchNamespaceAccept()
{
  switch ( mTokenInfoIt->id )
  {
    case T_SPACE:
    case T_SPACE2:
      break;
    case T_LEFTBRACE:
      mTypeInfo.mNamespaceVec.push_back( mNamespaceNameForAdding );
      mState = eSearchAttributeOrNamespace;
      break;
    case T_SEMICOLON:
      mState = eSearchAttributeOrNamespace;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchNamespaceName()
{
  switch ( mTokenInfoIt->id )
  {
    case T_SPACE:
    case T_SPACE2:
      break;
    case T_IDENTIFIER:
      mNamespaceNameForAdding = mTokenInfoIt->value;
      mState = eSearchNamespaceAccept;
      break;
    default:
      mState = eSearchAttributeOrNamespace;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchClassOrStruct()
{
  switch ( mTokenInfoIt->id )
  {
    case T_CLASS:
      mTypeInfo.mType = TTypeInfo::eType::Class;
      mCurrentSection = TMemberInfo::ePrivate;
      mState = eSearchTypeName;
      break;
    case T_STRUCT:
      mTypeInfo.mType = TTypeInfo::eType::Struct;
      mCurrentSection = TMemberInfo::ePublic;
      mState = eSearchTypeName;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchInheritanceOrLeftBrace()
{
  switch ( mTokenInfoIt->id )
  {
    case T_LEFTBRACE:
      mState = eSearchBeginSectionOrTypeOrBeginMethod;
      break;
    case T_COLON:
      mTypeInfo.mInheritanceVec.clear();
      mState = eSearchInheritance;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchInheritance()
{
  switch ( mTokenInfoIt->id )
  {
    case T_PUBLIC:
      mTypeInfo.mInheritanceVec.push_back( TInheritanceInfo() );
      mTypeInfo.mInheritanceVec.back().mInheritanceAccessLevel = TMemberInfo::ePublic;
      mState = eSearchBeginInheritanceType;
      break;
    case T_PROTECTED:
      mTypeInfo.mInheritanceVec.push_back( TInheritanceInfo() );
      mTypeInfo.mInheritanceVec.back().mInheritanceAccessLevel = TMemberInfo::eProtected;
      mState = eSearchBeginInheritanceType;
      break;
    case T_PRIVATE:
      mTypeInfo.mInheritanceVec.push_back( TInheritanceInfo() );
      mTypeInfo.mInheritanceVec.back().mInheritanceAccessLevel = TMemberInfo::ePrivate;
      mState = eSearchBeginInheritanceType;
      break;
    case T_IDENTIFIER:// namespace or type name, default type
    {
      mTypeInfo.mInheritanceVec.push_back( TInheritanceInfo() );
      auto inheritanceAccessLevel = TMemberInfo::ePrivate;
      if ( mTypeInfo.mType == TTypeInfo::Struct )
        inheritanceAccessLevel = TMemberInfo::ePublic;
      auto& inheritanceInfo = mTypeInfo.mInheritanceVec.back();
      inheritanceInfo.mInheritanceAccessLevel = inheritanceAccessLevel;
      inheritanceInfo.mParentTypeName = mTokenInfoIt->value;
      mState = eSearchInheritanceEndOrContinueType;
    }
    break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchInheritanceEndOrContinueType()
{
  switch ( mTokenInfoIt->id )
  {
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
      mState = eSearchBeginSectionOrTypeOrBeginMethod;
      break;
    case T_COMMA:
      mState = eSearchInheritance;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchBeginInheritanceType()
{
  switch ( mTokenInfoIt->id )
  {
    case T_IDENTIFIER:
      auto& inheritanceInfo = mTypeInfo.mInheritanceVec.back();
      inheritanceInfo.mParentTypeName = mTokenInfoIt->value;
      mState = eSearchInheritanceEndOrContinueType;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchTypeName()
{
  switch ( mTokenInfoIt->id )
  {
    case T_IDENTIFIER:
      mTypeInfo.mName = mTokenInfoIt->value;
      mState = eSearchInheritanceOrLeftBrace;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchBeginSectionOrTypeOrBeginMethod()
{
  switch ( mTokenInfoIt->id )
  {
    case T_COMPL:// destructor
    case T_TEMPLATE:
    case T_VIRTUAL:
    case T_STATIC:
    case T_VOID:
      mState = eSearchDeclarationMethodHandler;
      break;
    case T_PRIVATE:
      mCurrentSection = TMemberInfo::ePrivate;
      mState = eSearchColonAfterSection;
      break;
    case T_PROTECTED:
      mCurrentSection = TMemberInfo::eProtected;
      mState = eSearchColonAfterSection;
      break;
    case T_PUBLIC:
      mCurrentSection = TMemberInfo::ePublic;
      mState = eSearchColonAfterSection;
      break;
    case T_RIGHTBRACE:
      mState = eSearchEndClassOrStruct;
      break;
    case T_IDENTIFIER:
      if ( mTokenInfoIt->value == mTypeInfo.mName )
      {// constructor
        mState = eSearchDeclarationMethodHandler;
        break;
      }
      mMemberInfo.mTypeName = mTokenInfoIt->value;
      mState = eSearchFullTypeName;
      break;
    default:
      if ( IsBuiltInType( mTokenInfoIt->id ) )
      {
        mMemberInfo.mTypeName = mTokenInfoIt->value;
        mState = eSearchFullTypeName;
      }
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchFullTypeName()
{
  switch ( mTokenInfoIt->id )
  {
    case T_COMMA:
      mMemberInfo.mTypeName += mTokenInfoIt->value;
      break;
    case T_SPACE:
    case T_SPACE2:
      if( mCornerBalance == 0 )
        mState = eWaitVariableNameOrTypeContinuous;
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
      if ( IsType( mTokenInfoIt->id ) )// vector, list, etc.
        mMemberInfo.mTypeName += mTokenInfoIt->value;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::WaitVariableNameOrTypeContinuous()
{
  switch ( mTokenInfoIt->id )
  {
    case T_COMMA:
      mMemberInfo.mTypeName += mTokenInfoIt->value;
      break;
    case T_SPACE:
    case T_SPACE2:
      break;
    case T_IDENTIFIER:
      if( mCornerBalance == 0 )
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
      mState = eSearchAfterColonColonIdentifier;
      break;
    case T_AND:// &
    case T_STAR:// *
      mMemberInfo.mTypeName += mTokenInfoIt->value;
      break;
    case T_LEFTBRACKET:// method
      mState = eSearchDeclarationMethodHandler;
      break;
    case T_SEMICOLON:// end member
      mTypeInfo.AddMember( mMemberInfo );
      mState = eSearchBeginSectionOrTypeOrBeginMethod;
      break;
    case T_VIRTUAL:
      mState = eSearchDeclarationMethodHandler;
      break;
    default:
      if ( IsBuiltInType( mTokenInfoIt->id ) )
        mMemberInfo.mTypeName += " " + mTokenInfoIt->value;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchColonAfterSection()
{
  switch ( mTokenInfoIt->id )
  {
    case T_COLON:
      mState = eSearchBeginSectionOrTypeOrBeginMethod;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchEndClassOrStruct()
{
  switch ( mTokenInfoIt->id )
  {
    case T_SEMICOLON:
    {
      // сброс информации о типе
      auto nameSpaces = mTypeInfo.GetNameSpace();
      mTypeMng->Add( nameSpaces, mTypeInfo );

      mTypeInfo.ClearMember();
      mTypeInfo.mInheritanceVec.clear();
      mState = eSearchAttributeOrNamespace;// конец класса или структуры
    }
    break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchDeclarationMethodHandler()
{
  switch ( mTokenInfoIt->id )
  {
    case T_LEFTPAREN:
      mParenBalance++;
      break;
    case T_RIGHTPAREN:// check balance
      mParenBalance--;
      if ( mParenBalance == 0 )
        mState = eSearchMethodBodyHandler;
      break;
    case T_SEMICOLON:
      if ( mParenBalance == 0 )
        mState = eSearchBeginSectionOrTypeOrBeginMethod;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchMethodBodyHandler()
{
  switch ( mTokenInfoIt->id )
  {
    case T_LEFTBRACE:
      mBraceBalance++;
      break;
    case T_RIGHTBRACE:
      mBraceBalance--;
      if ( mBraceBalance == 0 )// check balance
        mState = eSearchBeginSectionOrTypeOrBeginMethod;
      break;
    case T_SEMICOLON:// end of declaration
      if ( mBraceBalance == 0 )
        mState = eSearchBeginSectionOrTypeOrBeginMethod;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::SearchAfterColonColonIdentifier()
{
  switch ( mTokenInfoIt->id )
  {
    case T_IDENTIFIER:
      mMemberInfo.mTypeName += mTokenInfoIt->value;
      mState = eSearchFullTypeName;
      break;
  }
  return true;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::IsTokensOut()
{
  auto eit = mTokenListPtr->end();
  if ( mTokenInfoIt == eit )
  {
    return true;
  }
  return false;
}
//---------------------------------------------------------------------------------------
bool TAST_StateMachine::IsBuiltInType( boost::wave::token_id id )
{
  switch ( id )
  {
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
bool TAST_StateMachine::IsType( boost::wave::token_id id )
{
  switch ( id )
  {
    case T_IDENTIFIER:
      return true;
    default:
      if ( IsBuiltInType( id ) )
        return true;
  }
  return false;
}
//---------------------------------------------------------------------------------------