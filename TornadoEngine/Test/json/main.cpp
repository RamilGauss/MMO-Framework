/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#include "TestClass.h"
#include "JsonSerializer.h"
#include "TextFile.h"

std::string g_Path = "data.json";

void TestSave()
{
  TTestClass testClass;
  testClass.str = "my str";  testClass.ts.s = "1234567890";
  testClass.ts.password = "12345678";
  testClass.ts.port = 1234;
  testClass.ts.flag = true;

  testClass.ts.numList = { 0, 1, 2 };
  testClass.ts.strSet = { "0", "1", "2" };

  testClass.ts.numVector = { 0, 1, 2 };
  testClass.ts.intSet = { 0, 1, 2 };

  testClass.ts.intStrMap = { { 0, "0" }, { 1, "1" }, { 2, "2" } };
  testClass.ts.strStrMap = { { "0", "0" }, { "1", "1" }, { "2", "2" } };
  testClass.ts.strIntMap = { { "0", 0 }, { "1", 1 }, { "2", 2 } };
  testClass.ts.strBoolMap = { { "0", false }, { "1", true }, { "2", true } };

  testClass.ts.baseVec.push_back( TBaseStruct() );
  testClass.ts.basePtrVec.push_back( nullptr );// new TBaseStruct() );
  testClass.ts.baseSPVec.push_back( std::shared_ptr<TBaseStruct>( new TBaseStruct() ) );

  testClass.ts.strBaseMap.insert( { "0", TBaseStruct() } );
  testClass.ts.strBasePtrMap.insert( {"0", nullptr} );// new TBaseStruct() } );
  testClass.ts.strBaseSPMap.insert( { "0", std::shared_ptr<TBaseStruct>( new TBaseStruct() ) } );

  testClass.ts.intBaseMap.insert( { 0, TBaseStruct() } );
  testClass.ts.intBasePtrMap.insert( { 0, nullptr} );//new TBaseStruct() } );
  testClass.ts.intBaseSPMap.insert( { 0, std::shared_ptr<TBaseStruct>( new TBaseStruct() ) } );

  std::string str;  TJsonSerializer::Serialize( &testClass, str );
  TTextFile::Save( g_Path, str );
}
//------------------------------------------------------------------------------------
void TestLoad()
{
  std::string str;
  TTextFile::Load( g_Path, str );

  TTestClass testClass;
  auto p = &testClass;
  TJsonSerializer::Deserialize( p, str );
}
//------------------------------------------------------------------------------------
int main( int argc, char **argv )
{
  //TestSave();
  TestLoad();
  return 0;
}

