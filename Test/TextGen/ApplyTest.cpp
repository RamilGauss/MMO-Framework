/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include <fmt/core.h>

#include <inja/inja.hpp>

#include <TextGenerator.h>


TEST(TextGenerator, Apply_0)
{
    std::list<nsBase::TLine> lines =
    {
        {0, "for (int j = 0 ;j < 10 ;j++) {"},
        {1, "{{ Serialize(1) }}"},
        {-1, "}"},
    };

    nsBase::TTextGenerator textGenerator(lines);

    inja::json data;

    nsBase::TFormatFuncDeclaration func;
    func.name = "Serialize";
    func.argCount = 1;
    func.func = [](inja::Arguments& args)
    {
        int number = args.at(0)->get<int>(); // Adapt the index and type of the argument

        if (number == 0) {
            return std::string("Serialize();");
        }

        std::string ret =
            "for (int i = 0; i < 10; i++) {\n"
            "\tSerialize();\n"
            "}";

        return ret;
    };

    textGenerator.Apply(data, { func });
    auto renderedStr = textGenerator.Render();


    std::string ethalon = 
        "for (int j = 0 ;j < 10 ;j++) {\n"
        "    for (int i = 0; i < 10; i++) {\n"
        "        Serialize();\n"
        "    }\n"
        "}";

    ASSERT_TRUE(ethalon == renderedStr);
}
