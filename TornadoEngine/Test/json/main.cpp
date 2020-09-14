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
void Save(const std::string& fileName, const std::string& content)
{
    std::ofstream out(fileName);
    out << content;
    out.close();
}
//------------------------------------------------------------------------------------
std::shared_ptr<TestClass> Create()
{
    std::shared_ptr<TestClass> p(new TestClass());

    p->i8 = 42;
    p->ui8 = 42;
    p->i16 = 42;
    p->ui16 = 42;
    p->i32 = 42;
    p->ui32 = 42;
    p->c = 42;
    p->uc = 42;
    p->s = 42;
    p->us = 42;
    p->i = 42;
    p->ui = 42;
    p->f = 42.0f;
    p->d = 42.0;

    p->myarray.push_back(0);
    p->myarray.push_back(1);
    p->myarray.push_back(2);
    p->myarray.push_back(3);
    return p;
}
//------------------------------------------------------------------------------------
void SaveTest(TestClass* pTestClass)
{
    std::string str;
    nsJson::TJsonSerializer::Serialize(pTestClass, str);

    Save(g_Path, str);
}
//------------------------------------------------------------------------------------
std::shared_ptr<TestClass> LoadTest()
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
    //std::string strA;
    //nsJson::TJsonSerializer::Serialize(pA, strA);

    //std::string strB;
    //nsJson::TJsonSerializer::Serialize(pB, strB);

    //return (strA == strB);

    return *pA == *pB;
}
//------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    auto pForSave = Create();
    SaveTest(pForSave.get());
    auto loaded = LoadTest();
    auto check = CheckSavedWithLoaded(pForSave.get(), loaded.get());
    std::string strResult = check ? "true" : "false";
    printf("Test pass %s\n", strResult.data());

    getchar();
    return 0;
}
//------------------------------------------------------------------------------------
