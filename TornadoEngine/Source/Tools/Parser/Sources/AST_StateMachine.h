/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "StateMachine.h"
#include "TokenInfoManager.h"
#include "TypeInfo.h"
#include "TypeManager.h"

namespace nsCppParser
{
    class TAST_StateMachine
    {
        TTypeManager* mTypeMng;
        //nsReflectionCodeGenerator::TConfig* mConfig;

        TStateMachine<TAST_StateMachine> mStateMachine;

        using StateFunc = std::function<bool(TAST_StateMachine&)>;
        StateFunc mStateFunc = nullptr;

        // Data
        TTokenInfoManager::TTokenInfoList* mTokenListPtr;

        TTokenInfoManager::TTokenInfoListIt mTokenInfoIt;

        std::string mNamespaceNameForAdding;

        TTypeInfo   mTypeInfo;
        TMemberInfo mMemberInfo;

        std::set<std::string> mClassOrStructPragmaTextSet;

        std::string mPragmaText;
        std::string mPragmaSpaces;

        // for method analyze
        int mBraceBalance = 0;// {}
        //int mParenBalance = 0;// ()
        int mCornerBalance = 0;// <>

        enum class BlockType
        {
            EMPTY,
            NAMESPACE,
            CLASS_STRUCT,
            METHOD,
        };

        BlockType mCurrentBlock;
        BlockType mPrevBlock;

        std::list<BlockType> mBlockList;

    public:
        TAST_StateMachine(TTokenInfoManager::TTokenInfoList* tokenListPtr, const std::string& fileName);

        void Work();
    private:

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
        bool SearchMemberPragma();
        bool SearchClassOrStructPragma();

        bool IsTokensOut();

        bool IsBuiltInType(boost::wave::token_id id);
        bool IsType(boost::wave::token_id id);
    };
}
