/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"


#include "BL_Debug.h"
#include "CodeGeneratorImplementation/Sources/IncludeListGenerator.h"
#include "CodeGeneratorImplementation/Sources/JsonSerializerGenerator.h"

#include "ReflectionCodeGeneratorLib/Sources/ReflectionCodeGenerator.h"

#include "StringCollectorDumper.h"
#include "StringCollectorOutDumper.h"
#include "PrintableDumper.h"

using namespace nsReflectionCodeGenerator;

TReflectionCodeGenerator g_Rcg;

TIncludeListGenerator g_IncludeGenerator;

TJsonSerializerGenerator g_JsonGenerator;

TPrintableDumper g_Dumper;
TStringCollectorOutDumper g_OutDumper;

TEST(JsonDumperTest, _0)
{
    g_Rcg.Init(__argc, __argv);

    g_Rcg.AddGenerator(&g_JsonGenerator);
    g_Rcg.SetIncludeListGenerator(&g_IncludeGenerator);
    g_Rcg.SetDumper(&g_Dumper);
    g_Rcg.SetOutDumper(&g_OutDumper);
    auto result = g_Rcg.Work();

    ASSERT_TRUE(true);
}