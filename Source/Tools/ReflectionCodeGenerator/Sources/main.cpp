/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BL_Debug.h"

#include "ReflectionCodeGeneratorLib/Sources/ReflectionCodeGenerator.h"

#include "CodeGeneratorImplementation/GeneratorList.h"

#include "CodeGeneratorImplementation/IncludeList/IncludeListGenerator.h"

#include "CodeGeneratorImplementation/Json/JsonSerializerGenerator.h"
#include "CodeGeneratorImplementation/Binary/BinaryMarshallerGenerator.h"
#include "CodeGeneratorImplementation/DynamicCaster/DynamicCasterGenerator.h"
#include "CodeGeneratorImplementation/EcsComponentExtension/EcsComponentExtensionGenerator.h"
#include "CodeGeneratorImplementation/TypeFactory/TypeFactoryGenerator.h"
#include "CodeGeneratorImplementation/TypeInformation/TypeInformationGenerator.h"

using namespace nsReflectionCodeGenerator;
using namespace nsCodeGeneratorImplementation;

TReflectionCodeGenerator g_Rcg;

TIncludeListGenerator g_IncludeListGenerator;

TJsonSerializerGenerator g_JsonGenerator;
TBinaryMarshallerGenerator g_BinaryGenerator;
TTypeFactoryGenerator g_ReflectionGenerator;
TEcsComponentExtensionGenerator g_EcsComponentExtensionGenerator;
TDynamicCasterGenerator g_DynamicCasterGenerator;
TTypeInformationGenerator g_TypeInfoGenerator;

//---------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        BL_FIX_BUG();
        return 2;
    }

    g_Rcg.Init(argc, argv);

    //g_Rcg.AddGenerator(&g_MyGuiGenerator);
    g_Rcg.AddGenerator(&g_JsonGenerator);
    g_Rcg.AddGenerator(&g_BinaryGenerator);
    g_Rcg.AddGenerator(&g_ReflectionGenerator);
    g_Rcg.AddGenerator(&g_EcsComponentExtensionGenerator);
    g_Rcg.AddGenerator(&g_DynamicCasterGenerator);
    g_Rcg.AddGenerator(&g_TypeInfoGenerator);

    g_Rcg.SetIncludeListGenerator(&g_IncludeListGenerator);

    return (int) g_Rcg.Work();
}