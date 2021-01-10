/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <memory>

#include "TypeInfo.h"


namespace nsCppParser
{
    class TBlockLexemaEntity;
    class TLineLexemaEntity;
    class ILexema;

    class TEmptyLexema;
    class TNamespaceLexema;
    class TAccessLexema;
    class TClassLexema;
    class TStructLexema;
    class TEnumLexema;
    class TVariableDeclarationLexema;
    class TFunctionDeclarationLexema;
    class TFunctionDefinitionLexema;
    class TFriendLexema;
    class TPragmaLexema;
    class TIdentifierLexema;

    class TTypeDeclarationLexema;

    class TTypeInfoCollector
    {
        using TTypeInfoShPtr = std::shared_ptr<TTypeInfo>;

        using TTypeList = std::list<std::shared_ptr<TTypeInfo>>;

        TTypeList mTypeStack;

        std::list<std::string> mSpaceStack;

    public:
        TTypeList mTypeResult;

        mutable std::string mFileName;

        void CollectLexemasToInfoByBlock(TBlockLexemaEntity* blockLexemaEntity);
        void CollectLexemasToInfoByLine(TLineLexemaEntity* lineLexemaEntity);
    private:

        void Reset();

        void PushSpace(std::string& space);
        void PopSpace();

        std::string GetCurrentSpace();

        void HandleEmpty(TEmptyLexema* pLexema);
        void HandleNamespace(TNamespaceLexema* pLexema);
        void HandleAccess(TAccessLexema* pLexema);
        void HandleClass(TClassLexema* pLexema);
        void HandleStruct(TStructLexema* pLexema);
        void HandleEnum(TEnumLexema* pLexema);
        void HandleVariableDeclaration(TVariableDeclarationLexema* pLexema);
        void HandleFunctionDeclaration(TFunctionDeclarationLexema* pLexema);
        void HandleFunctionDefinition(TFunctionDefinitionLexema* pLexema);
        void HandleFriend(TFriendLexema* pLexema);
        void HandlePragma(TPragmaLexema* pLexema);
        void HandleIdentifier(TIdentifierLexema* pLexema);


        void AddNewType(TTypeDeclarationLexema* baseLexema);
    };
}