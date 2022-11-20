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
#include "ILexema.h"
#include "TypeDeclarationLexema.h"

namespace nsCppParser
{
    class TBlockLexemaEntity;
    class TLineLexemaEntity;

    class TEmptyLexema;
    class TNamespaceLexema;
    class TAccessLexema;
    class TClassLexema;
    class TStructLexema;
    class TEnumLexema;
    class TEnumValuesLexema;
    class TVariableDeclarationLexema;
    class TFunctionDeclarationLexema;
    class TFunctionDefinitionLexema;
    class TFunctionLexema;
    class TFriendLexema;
    class TPragmaLexema;
    class TIdentifierLexema;

    class TTypeInfoCollector
    {
        using TTypeInfoShPtr = std::shared_ptr<TTypeInfo>;

        enum class BlockType
        {
            EMPTY, CLASS_STRUCT_OR_ENUM, NAMESPACE, FUNCTION,
        };

        struct TBlock
        {
            BlockType type;
            std::string space;
            TTypeInfoShPtr typeInfo;
            AccessLevel accessLevel;

            int lexemaIndex;
            TBlockLexemaEntity* blockLexemaEntity;

            void Reset()
            {
                type = BlockType::EMPTY;
                space = "";
                typeInfo.reset();

                lexemaIndex = 0;
                blockLexemaEntity = nullptr;
            }
        };

        std::list<TBlock> mBlockStack;

        TBlock mCurrentBlock;

    public:
        using TTypeList = std::list<TTypeInfoShPtr>;
        TTypeList mTypeResult;

        mutable std::string mFileName;
        mutable std::string mAbsFileName;

        void CollectLexemasToInfoByBlock(TBlockLexemaEntity* blockLexemaEntity);
        void CollectLexemasToInfoByLine(TLineLexemaEntity* lineLexemaEntity);
    private:

        void Reset();

        void HandleBlockEnd();

        std::string GetCurrentSpace();

        TBlock* GetPrevBlock();

        void HandleEmpty(TEmptyLexema* pLexema);
        void HandleNamespace(TNamespaceLexema* pLexema);
        void HandleAccess(TAccessLexema* pLexema);
        void HandleClass(TClassLexema* pLexema);
        void HandleStruct(TStructLexema* pLexema);
        void HandleEnum(TEnumLexema* pLexema);
        void HandleEnumValues(TEnumValuesLexema* pLexema);
        void HandleVariableDeclaration(TVariableDeclarationLexema* pLexema);
        void HandleFunctionDeclaration(TFunctionDeclarationLexema* pLexema);
        void HandleFunctionDefinition(TFunctionDefinitionLexema* pLexema);
        void HandleFriend(TFriendLexema* pLexema);
        void HandlePragma(TPragmaLexema* pLexema);
        void HandleIdentifier(TIdentifierLexema* pLexema);


        void AddNewType(TTypeDeclarationLexema* baseLexema);

        void FillPragmaListUpper(std::set<std::string>& pragmaList);

        void AddMethod(TFunctionLexema* pLexema);
        void ParseInheritanceInfo(const TTypeDeclarationLexema::TInheritance& inheritance, TInheritanceInfo& inheritanceInfo);
    };
}