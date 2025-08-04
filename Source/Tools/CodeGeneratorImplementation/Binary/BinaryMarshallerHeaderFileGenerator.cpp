/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BinaryMarshallerHeaderFileGenerator.h"
#include "fmt/core.h"
#include <set>

using namespace nsCodeGeneratorImplementation;

void TBinaryMarshallerHeaderFileGenerator::Work()
{
    AddHeader(mResolvedConfig->header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();

    AddStandartInclude("functional");
    AddInclude("Base/Common/ContainerRise.h");
    AddInclude("Base/Common/TypeDef.h");
    AddInclude("Base/Common/BinaryPushMaster.h");
    AddInclude("Base/Common/BinaryPopMaster.h");
    AddInclude("Base/Common/MemoryObjectPoolAllocator.h");
    AddInclude("Base/Common/BL_Debug.h");
    AddInclude("lz4.h");

    AddEmptyLine();
    AddInclude(mResolvedConfig->includeFileForInclude + ".h");
    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if (namespaceName.length()) {
        AddNamespaceBegin(namespaceName);
        IncrementTabs();
    }

    AddClassBegin(mSerializer->exportDeclaration, mSerializer->className);

    AddList(GetBinaryDeclBeforeEnum());

    AddEnums();

    AddList(GetBinaryDeclAfterEnum_BeforeTypesDecl());

    AddDeclarations();

    AddClassEnd();

    AddList(GetBinaryImpl());

    if (namespaceName.length()) {
        DecrementTabs();
        AddNamespaceEnd();
    }
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerHeaderFileGenerator::AddDeclarations()
{
    IncrementTabs();

    auto& forGenerate = mTypeNameDbPtr->GetForGenerate();
    for (auto& namespaceTypeInfo : forGenerate) {

        auto fullTypeName = namespaceTypeInfo.GetFullType();
        auto type = mTypeManager->Get(fullTypeName);

        auto namespaceWithType = type->GetTypeNameWithNameSpace();

        auto serMethod = fmt::format("{} {}( {}* p );", s_Void, s_Serialize, namespaceWithType);
        Add(serMethod);
        auto deserMethod = fmt::format("{} {}( {}* p );", s_Void, s_Deserialize, namespaceWithType);
        Add(deserMethod);
        auto deser = fmt::format("{} {}( {}* p );", s_TypeID, s_GetTypeID, namespaceWithType);
        Add(deser);
        std::list<std::string> paramList = {fmt::format("{}* p", namespaceWithType)};
        AddStaticMethodDeclaration(s_Void, s_Deallocate, paramList);
        AddEmptyLine();
    }

    DecrementTabs();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerHeaderFileGenerator::AddEnums()
{
    IncrementTabs();
    IncrementTabs();

    std::set<std::string> sortedTypeNameSet;

    auto& forGenerate = mTypeNameDbPtr->GetForGenerate();
    for (auto& namespaceTypeInfo : forGenerate) {

        auto fullTypeName = namespaceTypeInfo.GetFullType();
        auto type = mTypeManager->Get(fullTypeName);

        sortedTypeNameSet.insert(MakeEnumName(type));
    }

    int i = 0;
    std::string sEnum;
    for (auto& enumName : sortedTypeNameSet) {
        if (i != 0) {
            sEnum = fmt::format("{},", enumName);
        } else {
            auto beginIdFit = mSerializer->keyValueMap.find("beginId");
            if (beginIdFit != mSerializer->keyValueMap.end()) {
                auto beginId = atoi(beginIdFit->second.c_str());

                sEnum = fmt::format("{} = {},", enumName, beginId);
            }
        }
        Add(sEnum);
        i++;
    }
    DecrementTabs();
    DecrementTabs();
}
//-------------------------------------------------------------------------------------
const std::list<std::string> TBinaryMarshallerHeaderFileGenerator::GetBinaryDeclBeforeEnum()
{
    return 
    {
        "public:",
        fmt::format("    typedef unsigned short {};", s_TypeID),
        "private:",
        "#pragma pack(push, 1)",
        fmt::format("    struct {}", s_THeader),
        "    {",
        fmt::format("        {} type : 15;", s_TypeID),
        fmt::format("        {} useCompression : 1;", s_TypeID),
        "        unsigned char ratio = 0;",
        "    };",
        "#pragma pack(pop)",
        "    // upper use LZ4 for compression",
        "    int mSetLimitForCompression = 0x40;",
        "",
        "    TContainerRise mBuffer;",
        "    // collectors",
        fmt::format("    TBinaryPushMaster {};", s_PushMaster),
        fmt::format("    TBinaryPopMaster {};", s_PopMaster),
        "public:",
        fmt::format("    enum SerializableUniqueID : {}", s_TypeID),
        "    {",
    };
}
//-------------------------------------------------------------------------------------
const std::list<std::string> TBinaryMarshallerHeaderFileGenerator::GetBinaryDeclAfterEnum_BeforeTypesDecl()
{
    return
    {
        "    };",
            "",
            fmt::format("    void {}(int binarySize);", s_SetLimitForCompression),
            "",
            "    // serialize / deserialize",
            "    template <typename Type>",
            "    void Serialize(Type* p, TContainerRise& c);",
            "    template <typename Type>",
            "    void Deserialize(Type*& p, char* serData, int size);",
            "    template <typename Type>",
            "    void Fill(Type* p, char* serData, int size);",
            "",
            "    // pack / unpack",
            "    template <typename Type>",
            "    void Pack(Type* p, TContainerRise& c);",
            "    // WARNING! handle in {} определяется настройками генератора",
            "    void Unpack(char* packedData, int size);",
            "",
            "    TypeID GetID(char* packedData, int size);",
            "    template <typename Type>",
            "    Type* HandleUnpack(char* packedData, int size);",
            "    template <typename Type>",
            "    void FillUnpack(Type* p, char* packedData, int size, bool check = false);",
            "",
            "    template <typename Type>",
            fmt::format("  static void {}(Type* p);", s_GeneralDeallocate),
            "private:",
            "    void PushIsNotNullptr(void* p);",
            "    bool PopIsNotNullptr();",
            "",
            "    template <typename Type>",
            fmt::format("  static Type* {}();", s_GeneralAllocate),
            "    template <typename Type>",
            "    void _Deserialize(Type*& p, char* serData, int size, bool checkPtr);",
            fmt::format("  {} PrepareForUnpackPopMaster(char* packedData, int size);", s_TypeID),
            "private:",
    };
}
//-------------------------------------------------------------------------------------
const std::list<std::string> TBinaryMarshallerHeaderFileGenerator::GetBinaryImpl()
{
    return
    {
        "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("void {}::Serialize(Type* p, TContainerRise& c)", mSerializer->className),
            "{",
            fmt::format("    {}.Clear();", s_PushMaster),
            fmt::format("    {}(p);", s_Serialize),
            fmt::format("    {}.CopyInBuffer(c, 0);", s_PushMaster),
            "}",
            "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("void {}::Deserialize(Type*& p, char* serData, int size)", mSerializer->className),
            "{",
            "    _Deserialize(p, serData, size, true);",
            "}",
            "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("void {}::Fill(Type* p, char* serData, int size)", mSerializer->className),
            "{",
            "    _Deserialize(p, serData, size, false);",
            "}",
            "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("void {}::Pack(Type* p, TContainerRise& c)", mSerializer->className),
            "{",
            "    Serialize( p, c );",
            "",
            "    const int headerSize = sizeof(THeader);",
            "    THeader header;",
            "    header.type = _GetTypeID( p );",
            "    header.useCompression = 0;",
            "    header.ratio = 0;",
            "    if ( c.GetSize() - headerSize > mSetLimitForCompression )",
            "    {",
            "        header.useCompression = 1;",
            "        // compression",
            "        mBuffer.Clear();",
            "        mBuffer.Shift(LZ4_compressBound(c.GetSize()));",
            "        int compressedSize = LZ4_compress_default(c.GetPtr(), mBuffer.GetPtr(),",
            "          c.GetSize(), mBuffer.GetSize());",
            "        header.ratio = c.GetSize() / compressedSize + 1;",
            "",
            "        c.Clear();",
            "        c.Shift(headerSize + compressedSize);",
            "        memcpy(c.GetPtr() + headerSize, mBuffer.GetPtr(), compressedSize);",
            "    }",
            "    else",
            "    {",
            "        auto size = c.GetSize();",
            "        c.Shift(headerSize);",
            "        memmove(c.GetPtr() + headerSize, c.GetPtr(), size);",
            "    }",
            "    memcpy(c.GetPtr(), &header, headerSize);",
            "}",
            "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("Type* {}::HandleUnpack(char* packedData, int size)", mSerializer->className),
            "{",
            "    Type* p = nullptr;",
            "    auto typeFromBinary = PrepareForUnpackPopMaster(packedData, size);",
            "    auto typeByUserGuest = _GetTypeID(p);",
            "    BL_Assert(typeFromBinary == typeByUserGuest);",
            fmt::format("    p = {}<Type>();", s_GeneralAllocate),
            fmt::format("    {}(p);", s_Deserialize),
            "    return p;",
            "}",
            "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("void {}::FillUnpack(Type* p, char* packedData, int size, bool check)", mSerializer->className),
            "{",
            "    auto typeFromBinary = PrepareForUnpackPopMaster( packedData, size );",
            "    auto typeByUserGuest = _GetTypeID(p);",
            "    if ( check ) {",
            "        BL_Assert(typeFromBinary == typeByUserGuest);",
            "    }",
            fmt::format("    {}(p);", s_Deserialize),
            "}",
            "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("void {}::{}(Type* p)", mSerializer->className, s_GeneralDeallocate),
            "{",
            fmt::format("    {}(p);", s_Deallocate),
            fmt::format("    {}::DeallocateFunc(p);", s_MemoryObjectPoolAllocator),
            "}",
            "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("static Type* {}::{}()", mSerializer->className, s_GeneralAllocate),
            "{",
            fmt::format("    return {}::AllocateFunc<Type>();", s_MemoryObjectPoolAllocator),
            "}",
            "//-----------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("void {}::_Deserialize(Type*& p, char* serData, int size, bool checkPtr)", mSerializer->className),
            "{",
            "    if ( checkPtr ) {",
            "        p = p ? p : new Type();",
            "}",
            "",
            fmt::format("    {}.SetBuffer(serData, size, 0);", s_PopMaster),
            fmt::format("    {}( p );", s_Deserialize),
            "}",
    };
}