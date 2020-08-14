/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fstream>
#include <string>
#include <iostream>

#include "TestClass.h"
#include "JsonSerializer.h"

using namespace nsBS;

std::string g_Path = "testData.json";

void Load(const std::string& fileName, std::string& content)
{
    std::ifstream ifs(fileName);
    std::string c((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    content = c;
}
//------------------------------------------------------------------------------------
void Save(const std::string& content, const std::string& fileName)
{
    std::ofstream out(fileName);
    out << content;
    out.close();
}
//------------------------------------------------------------------------------------
std::shared_ptr<TestClass> Create()
{
    std::shared_ptr<TestClass> p(new TestClass());
    p->myarray.push_back(0);
    p->myarray.push_back(1);
    p->myarray.push_back(2);
    p->myarray.push_back(3);
    return p;
}
//------------------------------------------------------------------------------------
void TestSave(TestClass* pTestClass)
{
    std::string str;
    nsJson::TJsonSerializer::Serialize(pTestClass, str);

    Save(g_Path, str);
}
//------------------------------------------------------------------------------------
std::shared_ptr<TestClass> TestLoad()
{
    std::string str;
    Load(g_Path, str);

    std::shared_ptr<TestClass> p(new TestClass());
    nsJson::TJsonSerializer::Fill(p.get(), str);
    return p;
}
//------------------------------------------------------------------------------------
bool CheckSavedWithLoaded(TestClass* pA, TestClass* pB)
{
    std::string strA;
    nsJson::TJsonSerializer::Serialize(pA, strA);

    std::string strB;
    nsJson::TJsonSerializer::Serialize(pB, strB);

    return (strA == strB);
}
//------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    auto pForSave = Create();
    TestSave(pForSave.get());
    auto loaded = TestLoad();
    auto check = CheckSavedWithLoaded(pForSave.get(), loaded.get());
    std::string strResult = check ? "true" : "false";
    printf("Test pass %s\n", strResult.data());

    getchar();
    return 0;
}
//------------------------------------------------------------------------------------
