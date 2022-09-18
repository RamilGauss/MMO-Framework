/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ILexema.h"
#include "Types.h"

namespace nsCppParser
{
    class DllExport TTypeDeclarationLexema : public ILexema
    {
    protected:

        boost::wave::token_id mTypeDecl;

    public:
        DeclarationType mDeclType;

        std::string mName;

        struct TTemplateInfo
        {
            std::vector<std::string> args;

            bool HasSome() const;
        };

        TTemplateInfo mTemplateInfo;

        struct TInheritance
        {
            AccessLevel accessLevel;
            std::string typeName;

            bool HasSome() const;
        };

        std::list<TInheritance> mInheritanceList;

        TTypeDeclarationLexema(boost::wave::token_id id);

        bool CanFill(const TLineTokenEntity* line) const override;

        void Fill(const TLineTokenEntity* line) override;

        ~TTypeDeclarationLexema() {}

        std::string ToString() override;
    private:
        void SearchTemplateArgs(const TLineTokenEntity* line);
        void SearchName(const TLineTokenEntity* line);
        void SearchInheritances(const TLineTokenEntity* line);
    };
}