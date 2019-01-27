/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "StateMachine.h"
#include "TokenInfoManager.h"
#include "Config.h"
#include "TypeInfo.h"
#include "TypeManager.h"

class TAST_StateMachine
{
  TTypeManager* mTypeMng;
  nsReflectionCodeGenerator::TConfig* mConfig;

  TStateMachine mStateMachine;
  int mState;

  // Data
  TTokenInfoManager::TTokenInfoList* mTokenListPtr;

  TTokenInfoManager::TTokenInfoListIt mTokenInfoIt;

  std::string mNamespaceNameForAdding;

  TMemberInfo::AccessLevel mCurrentSection = TMemberInfo::ePrivate;

  TTypeInfo   mTypeInfo;
  TMemberInfo mMemberInfo;

  // for method analyze
  int mBraceBalance = 0;// ()
  int mParenBalance = 0;// {}
  int mCornerBalance = 0;// <>

  enum eStateType
  {
    eSearchAttributeOrNamespace,// ищем в файле токен с аттрибутом или начало пространства имён
    eSearchClassOrStruct,// ищем начало класса
    eSearchInheritanceOrLeftBrace,
    eSearchInheritance,
    eSearchNamespaceName,
    eSearchNamespaceAccept,// искать ; как конец имени namespace
    eSearchTypeName,// ищем имя класса
    eSearchBeginSectionOrTypeOrBeginMethod,
    eSearchFullTypeName,
    eSearchColonAfterSection,
    eWaitVariableNameOrTypeContinuous,
    eSearchEndClassOrStruct,
    eSearchBeginInheritanceType,
    eSearchInheritanceEndOrContinueType,
    eSearchDeclarationMethodHandler,
    eSearchMethodBodyHandler,
    eSearchAfterColonColonIdentifier,
    eSearchWaitSemiColonAfterAssign,
  };

public:
  TAST_StateMachine( TTokenInfoManager::TTokenInfoList* tokenListPtr, std::string fileName );

  void Work();
private:
  void ConfigStateMachine();

  bool BeforeAction();
  bool AfterAction();

  bool SearchAttributeOrNamespace();
  bool SearchNamespaceName();
  bool SearchClassOrStruct();
  bool SearchInheritanceOrLeftBrace();
  bool SearchInheritance();
  bool SearchInheritanceEndOrContinueType();
  bool SearchBeginInheritanceType();
  bool SearchTypeName();
  bool SearchBeginSectionOrTypeOrBeginMethod();
  bool SearchFullTypeName();
  bool WaitVariableNameOrTypeContinuous();
  bool SearchColonAfterSection();
  bool SearchEndClassOrStruct();
  bool SearchNamespaceAccept();
  bool SearchDeclarationMethodHandler();
  bool SearchMethodBodyHandler();
  bool SearchAfterColonColonIdentifier();
  bool SearchWaitSemiColonAfterAssign();

  bool IsTokensOut();

  bool IsBuiltInType( boost::wave::token_id id );
  bool IsType( boost::wave::token_id id );

  template<typename TFunc>
  void AddAction( eStateType state, TFunc pFunc );
};
//---------------------------------------------------------------------------------------
template<typename TFunc>
void TAST_StateMachine::AddAction( eStateType state, TFunc pFunc )
{
  mStateMachine.AddAction( state, pFunc, this );
}
//---------------------------------------------------------------------------------------
