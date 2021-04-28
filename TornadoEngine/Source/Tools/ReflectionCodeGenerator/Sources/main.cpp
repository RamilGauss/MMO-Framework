/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BL_Debug.h"

#include "ReflectionCodeGeneratorLib/Sources/ReflectionCodeGenerator.h"

#include "CodeGeneratorImplementation/Sources/IncludeListGenerator.h"

#include "CodeGeneratorImplementation/Sources/JsonSerializerGenerator.h"
#include "CodeGeneratorImplementation/Sources/BinaryMarshallerGenerator.h"
#include "CodeGeneratorImplementation/Sources/ReflectionGenerator.h"
#include "CodeGeneratorImplementation/Sources/EntityManagerGenerator.h"
#include "CodeGeneratorImplementation/Sources/TypeInformationGenerator.h"

using namespace nsReflectionCodeGenerator;

TReflectionCodeGenerator g_Rcg;

TIncludeListGenerator g_IncludeListGenerator;

//TMyGuiSerializerGenerator g_MyGuiGenerator;
TJsonSerializerGenerator g_JsonGenerator;
TBinaryMarshallerGenerator g_BinaryGenerator;
TReflectionGenerator g_ReflectionGenerator;
TEntityManagerGenerator g_EntMngGenerator;
TTypeInformationGenerator g_TypeInfoGenerator;

//---------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        BL_FIX_BUG();
    }

    g_Rcg.Init(argc, argv);

    //g_Rcg.AddGenerator(&g_MyGuiGenerator);
    g_Rcg.AddGenerator(&g_JsonGenerator);
    g_Rcg.AddGenerator(&g_BinaryGenerator);
    g_Rcg.AddGenerator(&g_ReflectionGenerator);
    g_Rcg.AddGenerator(&g_EntMngGenerator);
    g_Rcg.AddGenerator(&g_TypeInfoGenerator);

    g_Rcg.SetIncludeListGenerator(&g_IncludeListGenerator);

    return (int) g_Rcg.Work();
}