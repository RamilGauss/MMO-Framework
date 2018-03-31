/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MyClass.h"
#include "Marshallizator.h"
#include "HiTimer.h"
#include "TestClass.h"
#include <conio.h>

class TDeserializeHandler
{
public:
  // handle MyClass packet
  void MyClassHandler( MyClass* p )
  {
    delete p;
  }
  // handle MyClass packet
  void TestClassHandler( TestClass* p )
  {
    int a = 0;
  }
  // handle MyClass packet
  void ParamClassHandler( ParamClass* p )
  {
  }
};
TDeserializeHandler handler;
//-----------------------------------------------------------------------------------------
void FillMyClass( MyClass* p )
{
  p->b = true;
  p->uc = 1;
  p->c = 2;
  p->us = 3;
  p->s = 4;
  p->ui = 5;
  p->i = 6;
  p->f = 7;
  p->d = 8;
  p->str = "9";
  p->serializable.mID = 10;//ISerializable
  p->pSerializable = new OtherClass();//ISerializable*
  p->pSerializable->mID = 11;

  p->vUc.push_back( 12 );
  p->vC.push_back( 13 );
  p->vUs.push_back( 14 );
  p->vS.push_back( 15 );
  p->vUi.push_back( 16 );
  p->vI.push_back( 17 );
  p->vF.push_back( 18 );
  p->vD.push_back( 19 );
  p->vStr.push_back( "20" );
  OtherClass localOtherClass;
  localOtherClass.mID = 20;
  p->vSer.push_back( localOtherClass );//std::vector<ISerializable>
  OtherClass* pOtherClass = new OtherClass();
  pOtherClass->mID = 21;
  p->vPtrSer.push_back( pOtherClass );//std::vector<ISerializable*>

  p->lUc.push_back(22);
  p->lC.push_back(23);
  p->lUs.push_back(24);
  p->lS.push_back(25);
  p->lUi.push_back(26);
  p->lI.push_back(27);
  p->lF.push_back(28);
  p->lD.push_back(29);
  p->lStr.push_back("30");
  //std::list<OtherClass>     lSer;//std::list<ISerializable>
  //std::list<OtherClass*>    lPtrSer;//std::list<ISerializable*>

  p->sUc.insert(31);
  p->sC.insert(32);
  p->sUs.insert(33);
  p->sS.insert(34);
  p->sUi.insert(35);
  p->sI.insert(36);
  p->sF.insert(37);
  p->sD.insert(38);
  p->sStr.insert("39");
  //std::set<OtherClass>     sSer;

  OtherClass keySer;
  keySer.mID = 666;
  p->mSerStr.insert(std::map<OtherClass,std::string>::value_type(keySer,"666"));
}
//-----------------------------------------------------------------------------------------
void Benchmark()
{
  TContainer networkPacket;// transport simulation 

  ParamClass param;
  TestClass* objSer = new TestClass();
  objSer->vParam.push_back(param);
  objSer->vParam.push_back(param);
  objSer->vParam.push_back(param);
  objSer->vParam[0].id = 1;
  objSer->vParam[0].rw = 2;
  objSer->vParam[0].rx = 3;
  objSer->vParam[0].ry = 4;
  objSer->vParam[0].rz = 5;
  objSer->vParam[0].vx = 6;
  objSer->vParam[0].vy = 7;
  objSer->vParam[0].vz = 8;
  TMarshallizator marsh;
  int cnt = 1000000;
  printf("cnt=%d\n", cnt);
  unsigned int start = ht_GetMSCount();
  for( int i = 0 ; i < cnt ; i++ )
    networkPacket = marsh.Serialize( objSer );
  unsigned int end = ht_GetMSCount();
  float speed = (float)(end - start)/cnt;
  printf("ser speed = %f\n",speed);
  printf("size=%d\n", networkPacket.GetSize());

  marsh.mCBTestClass.Register( &TDeserializeHandler::TestClassHandler, &handler );

  start = ht_GetMSCount();
  for( int i = 0 ; i < cnt ; i++ )
    marsh.Deserialize( &networkPacket, false );
  end = ht_GetMSCount();
  speed = (float)(end - start)/cnt;
  printf("deser speed = %f\n",speed);
  _getch();
}
//-----------------------------------------------------------------------------------------
int main( int argc, char** argv)
{
  Benchmark();
  return 0;

  // Marshalling
  TContainer networkPacket;// transport simulation 
  {
    // side A
    ParamClass param;
    MyClass* objSer = new MyClass();
    FillMyClass( objSer );
    TMarshallizator marsh;
    networkPacket = marsh.Serialize( objSer );
    delete objSer;
  }

  {
    // side B
    TMarshallizator marsh;
    marsh.mCBMyClass.Register( &TDeserializeHandler::MyClassHandler, &handler );
    marsh.Deserialize( &networkPacket, true/*newObj*/ );// want new object
  }
  return 0;
}

// IMarshallizator
// compression -> bit compression


/*
Эксперименты с JSON boost
#include <sstream>
#include <map>
#include <set>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

void example()
{
  // Write json.
  ptree pt;
  ptree children;
  ptree child;

  child.put("1", 1);
  child.put("2", 2);
  child.put("3", 3);

  children.push_back(std::make_pair("1", child));
  children.push_back(std::make_pair("2", child));
  children.push_back(std::make_pair("3", child));

  pt.add_child("MyArray", children);

  std::ostringstream buf;
  write_json(buf, pt, false);
  std::string json = buf.str(); // {"foo":"bar"}

  // Read json.
  ptree pt2;
  std::istringstream is(json);
  read_json(is, pt2);
  std::string foo = pt2.get<std::string>("foo");
}

std::string map2json(const std::map<std::string, std::string>& map)
{
  ptree pt;
  for (auto& entry : map)
    pt.put(entry.first, entry.second);
  std::ostringstream buf;
  write_json(buf, pt, false);
  return buf.str();
}

int main(int argc, char** argv)
{
  typedef std::map<std::string, std::string> TMapStrStr;
  typedef TMapStrStr::value_type TMapStrStrVT;
  typedef TMapStrStr::iterator TMapStrStrIt;
  TMapStrStr map;
  map.insert(TMapStrStrVT("1", "1"));
  map2json(map);

  example();

  return 0;
}
*/