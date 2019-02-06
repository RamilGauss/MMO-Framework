/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#include "TestClass.h"
#include "JsonSerializer.h"
#include "TextFile.h"
#include "fmt/core.h"
#include "BinaryMarshaller.h"

using namespace nsBS;

std::string g_Path = "testData.json";

std::shared_ptr<TTestClass> Create()
{
  std::shared_ptr<TTestClass> p( new TTestClass() );
  p->str = "my str ";
  p->ts.s = "1234567890";
  p->ts.password = "12345678";
  p->ts.port = 1234;
  p->ts.flag = true;

  p->ts.numList = {0, 1, 2};
  p->ts.strSet = {"0", "1", "2"};

  p->ts.numVector = {0, 1, 2};
  p->ts.intSet = {0, 1, 2};

  p->ts.intStrMap = {{ 0, "0" }, { 1, "1" }, { 2, "2" }};
  p->ts.strStrMap = {{ "0", "0" }, { "1", "1" }, { "2", "2" }};
  p->ts.strIntMap = {{ "0", 0 }, { "1", 1 }, { "2", 2 }};
  p->ts.strBoolMap = {{ "0", false }, { "1", true }, { "2", true }};

  p->ts.baseVec.push_back( TBaseStruct() );
  p->ts.basePtrVec.push_back( nullptr );// new TBaseStruct() );
  p->ts.baseSPVec.push_back( std::shared_ptr<TBaseStruct>( new TBaseStruct() ) );

  p->ts.strBaseMap.insert( {"0", TBaseStruct()} );
  p->ts.strBasePtrMap.insert( {"0", nullptr} );// new TBaseStruct() } );
  p->ts.strBaseSPMap.insert( {"0", std::shared_ptr<TBaseStruct>( new TBaseStruct() )} );

  p->ts.intBaseMap.insert( {0, TBaseStruct()} );
  p->ts.intBasePtrMap.insert( {0, nullptr} );//new TBaseStruct() } );
  p->ts.intBaseSPMap.insert( {0, std::shared_ptr<TBaseStruct>( new TBaseStruct() )} );

  p->ts.intArrArr = {{0,1,2,3},{0,1,2,3},{0,1,2,3}};
  p->ts.strMapMap =
  {
    { "0", {{"0", "0"}, {"1","1"}} },
  { "1", {{"1", "1"}, {"2","2"}} }
  };

  p->ts.strMapArr =
  {
    {{"0", "0"}, {"1","1"}},
  {{"1", "1"}, {"2","2"}}
  };

  p->ts.strArrMap =
  {
    {"0", {"0","1","2"}},
  {"1", {"10","11","12"}}
  };

  p->ts.spObjArrArr =
  {
    {std::shared_ptr<TBaseStruct>( new TBaseStruct() ),std::shared_ptr<TBaseStruct>()},
  {std::shared_ptr<TBaseStruct>( new TBaseStruct() ),std::shared_ptr<TBaseStruct>()},
  {std::shared_ptr<TBaseStruct>( new TBaseStruct() ),std::shared_ptr<TBaseStruct>()}
  };

  p->ts.spObjMapArr =
  {
    {{"0", std::shared_ptr<TBaseStruct>( new TBaseStruct() )}, {"1",std::shared_ptr<TBaseStruct>()}},
  {{"0", std::shared_ptr<TBaseStruct>( new TBaseStruct() )}, {"1",std::shared_ptr<TBaseStruct>()}},
  };

  p->ts.intSuperVec = {{{{0},{1}}}};
  return p;
}
//------------------------------------------------------------------------------------
void TestSave( TTestClass* pTestClass )
{
  std::string str;
  nsJson::TJsonSerializer::Serialize( pTestClass, str );

  TTextFile::Save( g_Path, str );
}
//------------------------------------------------------------------------------------
std::shared_ptr<TTestClass> TestLoad()
{
  std::string str;
  TTextFile::Load( g_Path, str );

  std::shared_ptr<TTestClass> p( new TTestClass() );
  nsJson::TJsonSerializer::Fill( p.get(), str );
  return p;
}
//------------------------------------------------------------------------------------
bool CheckSavedWithLoaded( TTestClass* pA, TTestClass* pB )
{
  nsBinary::TBinaryMarshaller marshaller;
  TContainerRise cA, cB;
  marshaller.Serialize( pA, cA );
  marshaller.Serialize( pB, cB );
  return ( cA == cB );
}
//------------------------------------------------------------------------------------
int main( int argc, char **argv )
{
  auto pForSave = Create();
  TestSave( pForSave.get() );
  auto loaded = TestLoad();
  auto check = CheckSavedWithLoaded( pForSave.get(), loaded.get() );
  fmt::print( "Test pass {}\n", check );

  getchar();
  return 0;
}
//------------------------------------------------------------------------------------
