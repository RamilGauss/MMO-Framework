# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

class PropsTemplate:

    def GenerateForVS2022(conanIncludes: str, conanIncludesValue: str, 
                          conanLibs: str, conanLibsValue: str, 
                          conanPreprocessors: str, conanPreprocessorsValue: str) -> str:
        return \
        f"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
        f"<Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\n" \
        f"<ImportGroup Label=\"PropertySheets\" />\n" \
        f"<PropertyGroup Label=\"UserMacros\">\n" \
        f"    <{conanIncludes}>{conanIncludesValue}</{conanIncludes}>\n" \
        f"    <{conanLibs}>{conanLibsValue}</{conanLibs}>\n" \
        f"    <{conanPreprocessors}>{conanPreprocessorsValue}</{conanPreprocessors}>\n" \
        f"</PropertyGroup>\n" \
        f"<PropertyGroup />\n" \
        f"<ItemDefinitionGroup />\n" \
        f"<ItemGroup>\n" \
        f"    <BuildMacro Include=\"{conanIncludes}\">\n" \
        f"    <Value>$({conanIncludes})</Value>\n" \
        f"    </BuildMacro>\n" \
        f"    <BuildMacro Include=\"{conanLibs}\">\n" \
        f"    <Value>$({conanLibs})</Value>\n" \
        f"    </BuildMacro>\n" \
        f"    <BuildMacro Include=\"{conanPreprocessors}\">\n" \
        f"    <Value>$({conanPreprocessors})</Value>\n" \
        f"    </BuildMacro>\n" \
        f"</ItemGroup>\n" \
        f"</Project>"
