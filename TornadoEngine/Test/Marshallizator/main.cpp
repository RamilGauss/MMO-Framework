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
  //objSer->vParam.push_back(param);
  //objSer->vParam.push_back(param);
  //objSer->vParam.push_back(param);
  TMarshallizator marsh;
  int cnt = 50000000;
  unsigned int start = ht_GetMSCount();
  for( int i = 0 ; i < cnt ; i++ )
    networkPacket = marsh.Serialize( objSer );
  unsigned int end = ht_GetMSCount();
  float speed = (float)(end - start)/cnt;
  printf("ser speed = %f\n",speed);

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