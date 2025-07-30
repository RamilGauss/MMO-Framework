/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "fmt/core.h"
#include "Base/Common/BL_Debug.h"

#include "Parser/Sources/LexemaEngine.h"
#include "Parser/Sources/LexemaFactory.h"

using namespace nsCppParser;

TLexemaEngine::TLexemaEngine()
{
    constexpr auto& lexemas = magic_enum::enum_values<ILexema::LexemaType>();
    for (auto& lexema : lexemas) {
        auto newLexema = TLexemaFactory::New(lexema);

        BL_ASSERT(newLexema != nullptr);

        std::shared_ptr<ILexema> spLexema;
        spLexema.reset(newLexema);

        mLexemas[(int) lexema] = spLexema;
    }
}
//----------------------------------------------------------------------------------------------
ILexema* TLexemaEngine::Work(TLineTokenEntity* lineTokenEntity)
{
    ILexema* prevLexema = nullptr;

    ILexema* retLexema = nullptr;

    int canFillCounter = 0;

    for (auto& lexema : mLexemas) {
        if (lexema->CanFill(lineTokenEntity)) {

            if (canFillCounter > 0) {

                std::string tokens;
                for (auto& t : lineTokenEntity->mTokens) {
                    tokens += t.strId; 
                    tokens += ", ";
                    tokens += t.value;
                }

                fmt::print("TLexemaEngine: ambiguity of lexemas:\n  ret={},\n  found={},\n  tokens:\n{}\n", 
                    retLexema->ToString(), lexema->ToString(), tokens);
                BL_FIX_BUG();
            }
            prevLexema = lexema.get();

            canFillCounter++;

            retLexema = TLexemaFactory::New(lexema->GetType());
            retLexema->Fill(lineTokenEntity);
        }
    }

    return retLexema;
}
//----------------------------------------------------------------------------------------------
