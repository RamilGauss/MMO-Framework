/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TypeDef.h"
#include "TestClass.h"
#include "JsonSerializer.h"
#include "TextFile.h"

std::string g_Path = "data.json";
TJsonSerializer g_JsonSerializer;

void TestSave()
{
  TTestClass testClass;
  testClass.str = "my str";  testClass.ts.password = "12345678";
  testClass.ts.port = 1234;
  testClass.ts.flag = true;

  testClass.ts.numList = { 0, 1, 2 };
  testClass.ts.strSet = { "0", "1", "2" };
  std::string str;  g_JsonSerializer.Serialize( &testClass, str );
  TTextFile::Save( g_Path, str );
}
//------------------------------------------------------------------------------------
void TestLoad()
{
  std::string str;
  TTextFile::Load( g_Path, str );

  TTestClass testClass;
  auto p = &testClass;
  g_JsonSerializer.Deserialize( p, str );
}
//------------------------------------------------------------------------------------
int main( int argc, char **argv )
{
  //TestSave();
  TestLoad();

  return 0;
}