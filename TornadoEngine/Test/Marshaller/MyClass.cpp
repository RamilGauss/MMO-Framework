/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MyClass.h"

#include "BinaryPushMaster.h"
#include "BinaryPopMaster.h"
#include "SerializableUniqueIdentity.h"

TMyClass::TMyClass()
{
  // init all pointers
  pSerializable = nullptr;
}
//---------------------------------------------------------------------------
TMyClass::~TMyClass()
{
  delete pSerializable;
}
//---------------------------------------------------------------------------
void TMyClass::Serialize( TBinaryPushMaster* pPushMaster ) const
{
  pPushMaster->Push( b );
  pPushMaster->Push( uc );
  pPushMaster->Push( c );
  pPushMaster->Push( us );
  pPushMaster->Push( s );
  pPushMaster->Push( ui );
  pPushMaster->Push( i );
  pPushMaster->Push( f );
  pPushMaster->Push( d );
  pPushMaster->PushStr( str );
  pPushMaster->PushSer( serializable );
  pPushMaster->PushPtrSer( pSerializable );

  pPushMaster->PushArray<unsigned char>( vUc );
  pPushMaster->PushArray<char>( vC );
  pPushMaster->PushArray<unsigned short>( vUs );
  pPushMaster->PushArray<short>( vS );
  pPushMaster->PushArray<unsigned int>( vUi );
  pPushMaster->PushArray<int>( vI );
  pPushMaster->PushArray<float>( vF );
  pPushMaster->PushArray<double>( vD );
  pPushMaster->PushArrayStr( vStr );
  pPushMaster->PushArraySer<TOtherClass>( vSer );//std::vector<ISerializable>
  pPushMaster->PushArrayPtrSer( vPtrSer );      //std::vector<ISerializable*>

  pPushMaster->PushArray<unsigned char>( lUc ); //std::list<unsigned char> lUc;
  pPushMaster->PushArray<char>( lC );           //std::list<char> lC;
  pPushMaster->PushArray<unsigned short>( lUs );//std::list<unsigned short> lUs;
  pPushMaster->PushArray<short>( lS );          //std::list<short> lS;
  pPushMaster->PushArray<unsigned int>( lUi );  //std::list<unsigned int> lUi;
  pPushMaster->PushArray<int>( lI );            //std::list<int> lI;
  pPushMaster->PushArray<float>( lF );          //std::list<float> lF;
  pPushMaster->PushArray<double>( lD );         //std::list<double> lD;
  pPushMaster->PushArrayStr( lStr );            //std::list<std::string> lStr;
  pPushMaster->PushArraySer<TOtherClass>( lSer );//std::list<OtherClass> lSer;//std::list<ISerializable>
  pPushMaster->PushArrayPtrSer( lPtrSer );      //std::list<OtherClass*> lPtrSer;//std::list<ISerializable*>

  pPushMaster->PushSet<unsigned char>( sUc );  //std::set<unsigned char> sUc;
  pPushMaster->PushSet<char>( sC );            //std::set<char> s;
  pPushMaster->PushSet<unsigned short>( sUs ); //std::set<unsigned short> s;
  pPushMaster->PushSet<short>( sS );           //std::set<short> s;
  pPushMaster->PushSet<unsigned int>( sUi );   //std::set<unsigned int> sUi;
  pPushMaster->PushSet<int>( sI );             //std::set<int> sI;
  pPushMaster->PushSet<float>( sF );           //std::set<float> sF;
  pPushMaster->PushSet<double>( sD );          //std::set<double> sD;
  pPushMaster->PushSetStr( sStr );             //std::set<std::string> sStr;
  pPushMaster->PushSetSer<TOtherClass>( sSer );

  pPushMaster->PushMap__<unsigned char,bool>( mUcB );         //std::map<unsigned char,bool> mUcB;
  pPushMaster->PushMap__<unsigned char,unsigned char>(mUcUc); //std::map<unsigned char,unsigned char> mUcUc;
  pPushMaster->PushMap__<unsigned char,char>(mUcC);           //std::map<unsigned char,char> mUcC;
  pPushMaster->PushMap__<unsigned char,unsigned short>(mUcUs);//std::map<unsigned char,unsigned short> mUcUs;
  pPushMaster->PushMap__<unsigned char,short>(mUcS);          //std::map<unsigned char,short> mUcS;
  pPushMaster->PushMap__<unsigned char,unsigned int>(mUcUi);  //std::map<unsigned char,unsigned int> mUcUi;
  pPushMaster->PushMap__<unsigned char,int>(mUcI);             //std::map<unsigned char,int> mUcI;
  pPushMaster->PushMap__<unsigned char,float>(mUcF);           //std::map<unsigned char,float> mUcF;
  pPushMaster->PushMap__<unsigned char,double>(mUcD);          //std::map<unsigned char,double> mUcD;
  pPushMaster->PushMap_Str<unsigned char>(mUcStr);             //std::map<unsigned char,std::string> mUcStr;
  pPushMaster->PushMap_Ser<unsigned char,TOtherClass>(mUcSer); //std::map<unsigned char,OtherClass> mUcSer;//std::map<unsigned char,ISerializable>
  pPushMaster->PushMap_PtrSer<unsigned char>(mUcPtrSer);      //std::map<unsigned char,OtherClass*>mUcPtrSer;//std::map<unsigned char,ISerializable*>

  pPushMaster->PushMap__<char,bool>( mCB );         //std::map<char,bool> mCB;
  pPushMaster->PushMap__<char,unsigned char>(mCUc); //std::map<char,unsigned char> mCUc;
  pPushMaster->PushMap__<char,char>(mCC);           //std::map<char,char> mCC;
  pPushMaster->PushMap__<char,unsigned short>(mCUs);//std::map<char,unsigned short> mCUs;
  pPushMaster->PushMap__<char,short>(mCS);          //std::map<char,short> mCS;
  pPushMaster->PushMap__<char,unsigned int>(mCUi);  //std::map<char,unsigned int> mCUI;
  pPushMaster->PushMap__<char,int>(mCI);             //std::map<char,int> mCI;
  pPushMaster->PushMap__<char,float>(mCF);           //std::map<char,float> mCF;
  pPushMaster->PushMap__<char,double>(mCD);          //std::map<char,double> mCD;
  pPushMaster->PushMap_Str<char>(mCStr);             //std::map<char,std::string> mCStr;
  pPushMaster->PushMap_Ser<char,TOtherClass>(mCSer); //std::map<char,OtherClass> mSer;//std::map<char,ISerializable> 
  pPushMaster->PushMap_PtrSer<char>(mCPtrSer);      //std::map<char,OtherClass*> mCPtrSer;//std::map<char,ISerializable*>

  pPushMaster->PushMap__<unsigned short,bool>( mUsB );          //std::map<unsigned short,bool> mUsB;
  pPushMaster->PushMap__<unsigned short,unsigned char>(mUsUc);  //std::map<unsigned short,unsigned char> mUsUc;
  pPushMaster->PushMap__<unsigned short,char>(mUsC);            //std::map<unsigned short,char> mUsC;
  pPushMaster->PushMap__<unsigned short,unsigned short>(mUsUs); //std::map<unsigned short,unsigned short> mUsUs;
  pPushMaster->PushMap__<unsigned short,short>(mUsS);           //std::map<unsigned short,short> mUsS;
  pPushMaster->PushMap__<unsigned short,unsigned int>(mUsUi);   //std::map<unsigned short,unsigned int> mUsUi;
  pPushMaster->PushMap__<unsigned short,int>(mUsI);             //std::map<unsigned short,int> mUsI;
  pPushMaster->PushMap__<unsigned short,float>(mUsF);           //std::map<unsigned short,float> mUsF;
  pPushMaster->PushMap__<unsigned short,double>(mUsD);          //std::map<unsigned short,double> mUsD;
  pPushMaster->PushMap_Str<unsigned short>(mUsStr);             //std::map<unsigned short,std::string> mUsStr;
  pPushMaster->PushMap_Ser<unsigned short,TOtherClass>(mUsSer);  //std::map<unsigned short,OtherClass> mUsSer;  //std::map<unsigned short,ISerializable> 
  pPushMaster->PushMap_PtrSer<unsigned short>(mUsPtrSer);       //std::map<unsigned short,OtherClass*> mUsPtrSer; //std::map<unsigned short,ISerializable*>

  pPushMaster->PushMap__<short,bool>( mSB );          //std::map<short,bool> mSB;
  pPushMaster->PushMap__<short,unsigned char>(mSUc);  //std::map<short,unsigned char> mSUc;
  pPushMaster->PushMap__<short,char>(mSC);            //std::map<short,char> mSC;
  pPushMaster->PushMap__<short,unsigned short>(mSUs); //std::map<short,unsigned short> mSUs;
  pPushMaster->PushMap__<short,short>(mSS);           //std::map<short,short> mSS;
  pPushMaster->PushMap__<short,unsigned int>(mSUi);   //std::map<short,unsigned int> mSUi;
  pPushMaster->PushMap__<short,int>(mSI);             //std::map<short,int> mSI;
  pPushMaster->PushMap__<short,float>(mSF);           //std::map<short,float> mSF;
  pPushMaster->PushMap__<short,double>(mSD);          //std::map<short,double> mSD;
  pPushMaster->PushMap_Str<short>(mSStr);             //std::map<short,std::string> mSStr;
  pPushMaster->PushMap_Ser<short,TOtherClass>(mSSer);  //std::map<short,OtherClass> mSSer; //std::map<short,ISerializable>
  pPushMaster->PushMap_PtrSer<short>(mSPtrSer);       //std::map<short,OtherClass*> mSPtrSer;//std::map<short,ISerializable*>

  pPushMaster->PushMap__<unsigned int,bool>( mUiB );         //std::map<unsigned int,bool> mUiB;
  pPushMaster->PushMap__<unsigned int,unsigned char>(mUiUc); //std::map<unsigned int,unsigned char> mUiUc;
  pPushMaster->PushMap__<unsigned int,char>(mUiC);           //std::map<unsigned int,char> mUiC;
  pPushMaster->PushMap__<unsigned int,unsigned short>(mUiUs);//std::map<unsigned int,unsigned short> mUiUs;
  pPushMaster->PushMap__<unsigned int,short>(mUiS);          //std::map<unsigned int,short> mUiS;
  pPushMaster->PushMap__<unsigned int,unsigned int>(mUiUi);  //std::map<unsigned int,unsigned int> mUiUi;
  pPushMaster->PushMap__<unsigned int,int>(mUiI);            //std::map<unsigned int,int> mUiI;
  pPushMaster->PushMap__<unsigned int,float>(mUiF);          //std::map<unsigned int,float> mUiF;
  pPushMaster->PushMap__<unsigned int,double>(mUiD);         //std::map<unsigned int,double> mUiD;
  pPushMaster->PushMap_Str<unsigned int>(mUiStr);            //std::map<unsigned int,std::string> mUiStr;
  pPushMaster->PushMap_Ser<unsigned int,TOtherClass>(mUiSer); //std::map<unsigned int,OtherClass> mUiSer;//std::map<unsigned int,ISerializable>
  pPushMaster->PushMap_PtrSer<unsigned int>(mUiPtrSer);      //std::map<unsigned int,OtherClass*> mUiPtrSer;//std::map<unsigned int,ISerializable*>

  pPushMaster->PushMap__<int,bool>( mIB );          //std::map<int,bool> mIB;
  pPushMaster->PushMap__<int,unsigned char>(mIUc);  //std::map<int,unsigned char> mIUc;
  pPushMaster->PushMap__<int,char>(mIC);            //std::map<int,char> mIC;
  pPushMaster->PushMap__<int,unsigned short>(mIUs); //std::map<int,unsigned short> mIUs;
  pPushMaster->PushMap__<int,short>(mIS);           //std::map<int,short> mIS;
  pPushMaster->PushMap__<int,unsigned int>(mIUi);   //std::map<int,unsigned int> mIUi;
  pPushMaster->PushMap__<int,int>(mII);             //std::map<int,int> mII;
  pPushMaster->PushMap__<int,float>(mIF);           //std::map<int,float> mIF;
  pPushMaster->PushMap__<int,double>(mID);          //std::map<int,double> mID;
  pPushMaster->PushMap_Str<int>(mIStr);             //std::map<int,std::string> mIStr;
  pPushMaster->PushMap_Ser<int,TOtherClass>(mISer);  //std::map<int,ISerializable> mISer;//std::map<int,ISerializable>
  pPushMaster->PushMap_PtrSer<int>(mIPtrSer);       //std::map<int,ISerializable*> mIPtrSer;//std::map<int,ISerializable*>

  pPushMaster->PushMap__<float,bool>( mFB );          //std::map<float,bool> mFB;
  pPushMaster->PushMap__<float,unsigned char>(mFUc);  //std::map<float,unsigned char> mFUc;
  pPushMaster->PushMap__<float,char>(mFC);            //std::map<float,char> mFC;
  pPushMaster->PushMap__<float,unsigned short>(mFUs); //std::map<float,unsigned short> mFUs;
  pPushMaster->PushMap__<float,short>(mFS);           //std::map<float,short> mFS;
  pPushMaster->PushMap__<float,unsigned int>(mFUi);   //std::map<float,unsigned int> mFUi;
  pPushMaster->PushMap__<float,int>(mFI);             //std::map<float,int> mFI;
  pPushMaster->PushMap__<float,float>(mFF);           //std::map<float,float> mFF;
  pPushMaster->PushMap__<float,double>(mFD);          //std::map<float,double> mFD;
  pPushMaster->PushMap_Str<float>(mFStr);             //std::map<float,std::string> mFStr;
  pPushMaster->PushMap_Ser<float,TOtherClass>(mFSer);  //std::map<float,OtherClass> mFSer;//std::map<float,ISerializable>
  pPushMaster->PushMap_PtrSer<float>(mFPtrSer);       //std::map<float,OtherClass*> mFPtrSer;//std::map<float,ISerializable*>

  pPushMaster->PushMap__<double,bool>( mDB );         //std::map<double,bool> mDB;
  pPushMaster->PushMap__<double,unsigned char>(mDUc); //std::map<double,unsigned char> mDUc;
  pPushMaster->PushMap__<double,char>(mDC);           //std::map<double,char> mDC;
  pPushMaster->PushMap__<double,unsigned short>(mDUs);//std::map<double,unsigned short> mDUs;
  pPushMaster->PushMap__<double,short>(mDS);          //std::map<double,short> mDS;
  pPushMaster->PushMap__<double,unsigned int>(mDUi);  //std::map<double,unsigned int> mDUi;
  pPushMaster->PushMap__<double,int>(mDI);             //std::map<double,int> mDI;
  pPushMaster->PushMap__<double,float>(mDF);           //std::map<double,float> mDF;
  pPushMaster->PushMap__<double,double>(mDD);          //std::map<double,double> mDD;
  pPushMaster->PushMap_Str<double>(mDStr);             //std::map<double,std::string> mDStr;
  pPushMaster->PushMap_Ser<double,TOtherClass>(mDSer); //std::map<double,ISerializable> mDSer;//std::map<double,ISerializable>
  pPushMaster->PushMap_PtrSer<double>(mDPtrSer);      //std::map<double,ISerializable*> mDPtrSer;//std::map<double,ISerializable*>

  pPushMaster->PushMapStr_<bool>( mStrB );          //std::map<std::string,bool> mStrB;
  pPushMaster->PushMapStr_<unsigned char>(mStrUc);  //std::map<std::string,unsigned char> mStrUc;
  pPushMaster->PushMapStr_<char>(mStrC);            //std::map<std::string,char> mStrC;
  pPushMaster->PushMapStr_<unsigned short>(mStrUs); //std::map<std::string,unsigned short> mStrUS;
  pPushMaster->PushMapStr_<short>(mStrS);           //std::map<std::string,short> mStrS;
  pPushMaster->PushMapStr_<unsigned int>(mStrUi);   //std::map<std::string,unsigned int> mStrUi;
  pPushMaster->PushMapStr_<int>(mStrI);             //std::map<std::string,int> mStrI;
  pPushMaster->PushMapStr_<float>(mStrF);           //std::map<std::string,float> mStrF;
  pPushMaster->PushMapStr_<double>(mStrD);          //std::map<std::string,double> mStrD;
  pPushMaster->PushMapStrStr(mStrStr);               //std::map<std::string,std::string> mStrStr;
  pPushMaster->PushMapStrSer<TOtherClass>(mStrSer);  //std::map<std::string,ISerializable> mStrSer;//std::map<std::string,ISerializable>
  pPushMaster->PushMapStrPtrSer(mStrPtrSer);        //std::map<std::string,ISerializable*> mStrPtrSer;//std::map<std::string,ISerializable*>

  pPushMaster->PushMapSer_<TOtherClass,bool>( mSerB );         //std::map<int,bool> mIB;
  pPushMaster->PushMapSer_<TOtherClass,unsigned char>(mSerUc); //std::map<int,unsigned char> mIUc;
  pPushMaster->PushMapSer_<TOtherClass,char>(mSerC);           //std::map<int,char> mIC;
  pPushMaster->PushMapSer_<TOtherClass,unsigned short>(mSerUs);//std::map<int,unsigned short> mIUs;
  pPushMaster->PushMapSer_<TOtherClass,short>(mSerS);          //std::map<int,short> mIS;
  pPushMaster->PushMapSer_<TOtherClass,unsigned int>(mSerUi);  //std::map<int,unsigned int> mIUi;
  pPushMaster->PushMapSer_<TOtherClass,int>(mSerI);             //std::map<int,int> mII;
  pPushMaster->PushMapSer_<TOtherClass,float>(mSerF);           //std::map<int,float> mIF;
  pPushMaster->PushMapSer_<TOtherClass,double>(mSerD);          //std::map<int,double> mID;
  pPushMaster->PushMapSerStr<TOtherClass>(mSerStr);             //std::map<int,std::string> mIStr;
  pPushMaster->PushMapSerSer<TOtherClass,TOtherClass>(mSerSer); //std::map<int,ISerializable> mISer;//std::map<int,ISerializable>
  pPushMaster->PushMapSerPtrSer<TOtherClass>(mSerPtrSer);      //std::map<int,ISerializable*> mIPtrSer;//std::map<int,ISerializable*>
}
//----------------------------------------------------------------------
void TMyClass::Deserialize( TBinaryPopMaster* pPopMaster )
{
  pPopMaster->Pop( b );
  pPopMaster->Pop( uc );
  pPopMaster->Pop( c );
  pPopMaster->Pop( us );
  pPopMaster->Pop( s );
  pPopMaster->Pop( ui );
  pPopMaster->Pop( i );
  pPopMaster->Pop( f );
  pPopMaster->Pop( d );
  pPopMaster->PopStr( str );
  pPopMaster->PopSer( serializable );                //ISerializable
  pPopMaster->PopPtrSer<TOtherClass>( pSerializable );//ISerializable*

  pPopMaster->PopArray<unsigned char>( vUc );       //std::vector<unsigned char> vUc;
  pPopMaster->PopArray<char>( vC );                 //std::vector<char> vC;
  pPopMaster->PopArray<unsigned short>( vUs );      //std::vector<unsigned short> vUs;
  pPopMaster->PopArray<short>( vS );                //std::vector<short>  vS;
  pPopMaster->PopArray<unsigned int>( vUi );        //std::vector<unsigned int>  vUi;
  pPopMaster->PopArray<int>( vI );                   //std::vector<int>  vI;
  pPopMaster->PopArray<float>( vF );                 //std::vector<float> vF;
  pPopMaster->PopArray<double>( vD );                //std::vector<double> vD;
  pPopMaster->PopArrayStr( vStr );                  //std::vector<std::string> vStr;
  pPopMaster->PopVectorSer<TOtherClass>( vSer );      //std::vector<OtherClass> vSer;//std::vector<ISerializable>
  pPopMaster->PopArrayPtrSer<TOtherClass>( vPtrSer );//std::vector<OtherClass*> vPtrSer;//std::vector<ISerializable*>

  pPopMaster->PopArray<unsigned char>( lUc );       //std::list<unsigned char> lUc;
  pPopMaster->PopArray<char>( lC );                 //std::list<char> lC;
  pPopMaster->PopArray<unsigned short>( lUs );      //std::list<unsigned short> lUs;
  pPopMaster->PopArray<short>( lS );                //std::list<short> lS;
  pPopMaster->PopArray<unsigned int>( lUi );        //std::list<unsigned int> lUi;
  pPopMaster->PopArray<int>( lI );                   //std::list<int> lI;
  pPopMaster->PopArray<float>( lF );                 //std::list<float> lF;
  pPopMaster->PopArray<double>( lD );                //std::list<double> lD;
  pPopMaster->PopArrayStr( lStr );                  //std::list<std::string> lStr;
  pPopMaster->PopListSer<TOtherClass>( lSer );      //std::list<OtherClass> lSer;//std::list<ISerializable>
  pPopMaster->PopArrayPtrSer<TOtherClass>( lPtrSer );//std::list<OtherClass*> lPtrSer;//std::list<ISerializable*>

  pPopMaster->PopArray<unsigned char>( sUc );  //std::set<unsigned char> sUc;
  pPopMaster->PopArray<char>( sC );            //std::set<char> s;
  pPopMaster->PopArray<unsigned short>( sUs ); //std::set<unsigned short> s;
  pPopMaster->PopArray<short>( sS );           //std::set<short> s;
  pPopMaster->PopArray<unsigned int>( sUi );   //std::set<unsigned int> sUi;
  pPopMaster->PopArray<int>( sI );              //std::set<int> sI;
  pPopMaster->PopArray<float>( sF );            //std::set<float> sF;
  pPopMaster->PopArray<double>( sD );           //std::set<double> sD;
  pPopMaster->PopArrayStr( sStr );             //std::set<std::string> sStr;
  pPopMaster->PopSetSer<TOtherClass>( sSer ); //std::set<OtherClass> sSer;

  pPopMaster->PopMap__<unsigned char,bool>( mUcB );                //std::map<unsigned char,bool> mUcB;
  pPopMaster->PopMap__<unsigned char,unsigned char>( mUcUc );      //std::map<unsigned char,unsigned char> mUcUc;
  pPopMaster->PopMap__<unsigned char,char>( mUcC );                //std::map<unsigned char,char> mUcC;
  pPopMaster->PopMap__<unsigned char,unsigned short>( mUcUs );     //std::map<unsigned char,unsigned short> mUcUs;
  pPopMaster->PopMap__<unsigned char,short>( mUcS );               //std::map<unsigned char,short> mUcS;
  pPopMaster->PopMap__<unsigned char,unsigned int>( mUcUi );       //std::map<unsigned char,unsigned int> mUcUi;
  pPopMaster->PopMap__<unsigned char,int>( mUcI );                 //std::map<unsigned char,int> mUcI;
  pPopMaster->PopMap__<unsigned char,float>( mUcF );               //std::map<unsigned char,float> mUcF;
  pPopMaster->PopMap__<unsigned char,double>( mUcD );              //std::map<unsigned char,double> mUcD;
  pPopMaster->PopMap_Str<unsigned char>( mUcStr );                 //std::map<unsigned char,std::string> mUcStr;
  pPopMaster->PopMap_Ser<unsigned char,TOtherClass>( mUcSer );      //std::map<unsigned char,OtherClass> mUcSer;//std::map<unsigned char,ISerializable>
  pPopMaster->PopMap_PtrSer<unsigned char,TOtherClass>( mUcPtrSer );//std::map<unsigned char,OtherClass*>mUcPtrSer;//std::map<unsigned char,ISerializable*>

  pPopMaster->PopMap__<char,bool>( mCB );                 //std::map<char,bool> mCB;
  pPopMaster->PopMap__<char,unsigned char>( mCUc );      //std::map<char,unsigned char> mCUc;
  pPopMaster->PopMap__<char,char>( mCC );                //std::map<char,char> mCC;
  pPopMaster->PopMap__<char,unsigned short>( mCUs );     //std::map<char,unsigned short> mCUs;
  pPopMaster->PopMap__<char,short>( mCS );               //std::map<char,short> mCS;
  pPopMaster->PopMap__<char,unsigned int>( mCUi );       //std::map<char,unsigned int> mCUI;
  pPopMaster->PopMap__<char,int>( mCI );                 //std::map<char,int> mCI;
  pPopMaster->PopMap__<char,float>( mCF );               //std::map<char,float> mCF;
  pPopMaster->PopMap__<char,double>( mCD );              //std::map<char,double> mCD;
  pPopMaster->PopMap_Str<char>( mCStr );                 //std::map<char,std::string> mCStr;
  pPopMaster->PopMap_Ser<char,TOtherClass>( mCSer );      //std::map<char,OtherClass> mSer;//std::map<char,ISerializable> 
  pPopMaster->PopMap_PtrSer<char,TOtherClass>( mCPtrSer );//std::map<char,OtherClass*> mCPtrSer;//std::map<char,ISerializable*>

  pPopMaster->PopMap__<unsigned short,bool>( mUsB );                //std::map<unsigned short,bool> mUsB;
  pPopMaster->PopMap__<unsigned short,unsigned char>( mUsUc );      //std::map<unsigned short,unsigned char> mUsUc;
  pPopMaster->PopMap__<unsigned short,char>( mUsC );                //std::map<unsigned short,char> mUsC;
  pPopMaster->PopMap__<unsigned short,unsigned short>( mUsUs );     //std::map<unsigned short,unsigned short> mUsUs;
  pPopMaster->PopMap__<unsigned short,short>( mUsS );               //std::map<unsigned short,short> mUsS;
  pPopMaster->PopMap__<unsigned short,unsigned int>( mUsUi );       //std::map<unsigned short,unsigned int> mUsUi;
  pPopMaster->PopMap__<unsigned short,int>( mUsI );                  //std::map<unsigned short,int> mUsI;
  pPopMaster->PopMap__<unsigned short,float>( mUsF );                //std::map<unsigned short,float> mUsF;
  pPopMaster->PopMap__<unsigned short,double>( mUsD );               //std::map<unsigned short,double> mUsD;
  pPopMaster->PopMap_Str<unsigned short>( mUsStr );                 //std::map<unsigned short,std::string> mUsStr;
  pPopMaster->PopMap_Ser<unsigned short,TOtherClass>( mUsSer );      //std::map<unsigned short,OtherClass> mUsSer;  //std::map<unsigned short,ISerializable> 
  pPopMaster->PopMap_PtrSer<unsigned short,TOtherClass>( mUsPtrSer );//std::map<unsigned short,OtherClass*> mUsPtrSer; //std::map<unsigned short,ISerializable*>

  pPopMaster->PopMap__<short,bool>( mSB );                //std::map<short,bool> mSB;
  pPopMaster->PopMap__<short,unsigned char>( mSUc );      //std::map<short,unsigned char> mSUc;
  pPopMaster->PopMap__<short,char>( mSC );                //std::map<short,char> mSC;
  pPopMaster->PopMap__<short,unsigned short>( mSUs );     //std::map<short,unsigned short> mSUs;
  pPopMaster->PopMap__<short,short>( mSS );               //std::map<short,short> mSS;
  pPopMaster->PopMap__<short,unsigned int>( mSUi );       //std::map<short,unsigned int> mSUi;
  pPopMaster->PopMap__<short,int>( mSI );                  //std::map<short,int> mSI;
  pPopMaster->PopMap__<short,float>( mSF );                //std::map<short,float> mSF;
  pPopMaster->PopMap__<short,double>( mSD );               //std::map<short,double> mSD;
  pPopMaster->PopMap_Str<short>( mSStr );                 //std::map<short,std::string> mSStr;
  pPopMaster->PopMap_Ser<short,TOtherClass>( mSSer );      //std::map<short,OtherClass> mSSer; //std::map<short,ISerializable>
  pPopMaster->PopMap_PtrSer<short,TOtherClass>( mSPtrSer );//std::map<short,OtherClass*> mSPtrSer;//std::map<short,ISerializable*>

  pPopMaster->PopMap__<unsigned int,bool>( mUiB );                //std::map<unsigned int,bool> mUiB;
  pPopMaster->PopMap__<unsigned int,unsigned char>( mUiUc );      //std::map<unsigned int,unsigned char> mUiUc;
  pPopMaster->PopMap__<unsigned int,char>( mUiC );                //std::map<unsigned int,char> mUiC;
  pPopMaster->PopMap__<unsigned int,unsigned short>( mUiUs );     //std::map<unsigned int,unsigned short> mUiUs;
  pPopMaster->PopMap__<unsigned int,short>( mUiS );               //std::map<unsigned int,short> mUiS;
  pPopMaster->PopMap__<unsigned int,unsigned int>( mUiUi );       //std::map<unsigned int,unsigned int> mUiUi;
  pPopMaster->PopMap__<unsigned int,int>( mUiI );                  //std::map<unsigned int,int> mUiI;
  pPopMaster->PopMap__<unsigned int,float>( mUiF );                //std::map<unsigned int,float> mUiF;
  pPopMaster->PopMap__<unsigned int,double>( mUiD );               //std::map<unsigned int,double> mUiD;
  pPopMaster->PopMap_Str<unsigned int>( mUiStr );                 //std::map<unsigned int,std::string> mUiStr;
  pPopMaster->PopMap_Ser<unsigned int,TOtherClass>( mUiSer );      //std::map<unsigned int,OtherClass> mUiSer;//std::map<unsigned int,ISerializable>
  pPopMaster->PopMap_PtrSer<unsigned int,TOtherClass>( mUiPtrSer );//std::map<unsigned int,OtherClass*> mUiPtrSer;//std::map<unsigned int,ISerializable*>

  pPopMaster->PopMap__<int,bool>( mIB );                //std::map<int,bool> mIB;
  pPopMaster->PopMap__<int,unsigned char>( mIUc );      //std::map<int,unsigned char> mIUc;
  pPopMaster->PopMap__<int,char>( mIC );                //std::map<int,char> mIC;
  pPopMaster->PopMap__<int,unsigned short>( mIUs );     //std::map<int,unsigned short> mIUs;
  pPopMaster->PopMap__<int,short>( mIS );               //std::map<int,short> mIS;
  pPopMaster->PopMap__<int,unsigned int>( mIUi );       //std::map<int,unsigned int> mIUi;
  pPopMaster->PopMap__<int,int>( mII );                  //std::map<int,int> mII;
  pPopMaster->PopMap__<int,float>( mIF );                //std::map<int,float> mIF;
  pPopMaster->PopMap__<int,double>( mID );               //std::map<int,double> mID;
  pPopMaster->PopMap_Str<int>( mIStr );                 //std::map<int,std::string> mIStr;
  pPopMaster->PopMap_Ser<int,TOtherClass>( mISer );      //std::map<int,ISerializable> mISer;//std::map<int,ISerializable>
  pPopMaster->PopMap_PtrSer<int,TOtherClass>( mIPtrSer );//std::map<int,ISerializable*> mIPtrSer;//std::map<int,ISerializable*>

  pPopMaster->PopMap__<float,bool>( mFB );                //std::map<float,bool> mFB;
  pPopMaster->PopMap__<float,unsigned char>( mFUc );      //std::map<float,unsigned char> mFUc;
  pPopMaster->PopMap__<float,char>( mFC );                //std::map<float,char> mFC;
  pPopMaster->PopMap__<float,unsigned short>( mFUs );     //std::map<float,unsigned short> mFUs;
  pPopMaster->PopMap__<float,short>( mFS );               //std::map<float,short> mFS;
  pPopMaster->PopMap__<float,unsigned int>( mFUi );       //std::map<float,unsigned int> mFUi;
  pPopMaster->PopMap__<float,int>( mFI );                  //std::map<float,int> mFI;
  pPopMaster->PopMap__<float,float>( mFF );                //std::map<float,float> mFF;
  pPopMaster->PopMap__<float,double>( mFD );               //std::map<float,double> mFD;
  pPopMaster->PopMap_Str<float>( mFStr );                 //std::map<float,std::string> mFStr;
  pPopMaster->PopMap_Ser<float,TOtherClass>( mFSer );      //std::map<float,OtherClass> mFSer;//std::map<float,ISerializable>
  pPopMaster->PopMap_PtrSer<float,TOtherClass>( mFPtrSer );//std::map<float,OtherClass*> mFPtrSer;//std::map<float,ISerializable*>

  pPopMaster->PopMap__<double,bool>( mDB );                 //std::map<double,bool> mDB;
  pPopMaster->PopMap__<double,unsigned char>( mDUc );       //std::map<double,unsigned char> mDUc;
  pPopMaster->PopMap__<double,char>( mDC );                 //std::map<double,char> mDC;
  pPopMaster->PopMap__<double,unsigned short>( mDUs );      //std::map<double,unsigned short> mDUs;
  pPopMaster->PopMap__<double,short>( mDS );                //std::map<double,short> mDS;
  pPopMaster->PopMap__<double,unsigned int>( mDUi );        //std::map<double,unsigned int> mDUi;
  pPopMaster->PopMap__<double,int>( mDI );                 //std::map<double,int> mDI;
  pPopMaster->PopMap__<double,float>( mDF );               //std::map<double,float> mDF;
  pPopMaster->PopMap__<double,double>( mDD );              //std::map<double,double> mDD;
  pPopMaster->PopMap_Str<double>( mDStr );                 //std::map<double,std::string> mDStr;
  pPopMaster->PopMap_Ser<double,TOtherClass>( mDSer );      //std::map<double,ISerializable> mDSer;//std::map<double,ISerializable>
  pPopMaster->PopMap_PtrSer<double,TOtherClass>( mDPtrSer );//std::map<double,ISerializable*> mDPtrSer;//std::map<double,ISerializable*>

  pPopMaster->PopMapStr_<bool>( mStrB );                //std::map<std::string,bool> mStrB;
  pPopMaster->PopMapStr_<unsigned char>( mStrUc );      //std::map<std::string,unsigned char> mStrUc;
  pPopMaster->PopMapStr_<char>( mStrC );                //std::map<std::string,char> mStrC;
  pPopMaster->PopMapStr_<unsigned short>( mStrUs );     //std::map<std::string,unsigned short> mStrUS;
  pPopMaster->PopMapStr_<short>( mStrS );               //std::map<std::string,short> mStrS;
  pPopMaster->PopMapStr_<unsigned int>( mStrUi );       //std::map<std::string,unsigned int> mStrUi;
  pPopMaster->PopMapStr_<int>( mStrI );                  //std::map<std::string,int> mStrI;
  pPopMaster->PopMapStr_<float>( mStrF );                //std::map<std::string,float> mStrF;
  pPopMaster->PopMapStr_<double>( mStrD );               //std::map<std::string,double> mStrD;
  pPopMaster->PopMapStrStr( mStrStr );                  //std::map<std::string,std::string> mStrStr;
  pPopMaster->PopMapStrSer<TOtherClass>( mStrSer );      //std::map<std::string,ISerializable> mStrSer;//std::map<std::string,ISerializable>
  pPopMaster->PopMapStrPtrSer<TOtherClass>( mStrPtrSer );//std::map<std::string,ISerializable*> mStrPtrSer;//std::map<std::string,ISerializable*>

  pPopMaster->PopMapSer_<TOtherClass,bool>( mSerB );                 //std::map<std::string,bool> mStrB;
  pPopMaster->PopMapSer_<TOtherClass,unsigned char>( mSerUc );       //std::map<std::string,unsigned char> mStrUc;
  pPopMaster->PopMapSer_<TOtherClass,char>( mSerC );                 //std::map<std::string,char> mStrC;
  pPopMaster->PopMapSer_<TOtherClass,unsigned short>( mSerUs );      //std::map<std::string,unsigned short> mStrUS;
  pPopMaster->PopMapSer_<TOtherClass,short>( mSerS );                //std::map<std::string,short> mStrS;
  pPopMaster->PopMapSer_<TOtherClass,unsigned int>( mSerUi );        //std::map<std::string,unsigned int> mStrUi;
  pPopMaster->PopMapSer_<TOtherClass,int>( mSerI );                 //std::map<std::string,int> mStrI;
  pPopMaster->PopMapSer_<TOtherClass,float>( mSerF );               //std::map<std::string,float> mStrF;
  pPopMaster->PopMapSer_<TOtherClass,double>( mSerD );              //std::map<std::string,double> mStrD;
  pPopMaster->PopMapSerStr<TOtherClass>( mSerStr );                 //std::map<std::string,std::string> mStrStr;
  pPopMaster->PopMapSerSer<TOtherClass,TOtherClass>( mSerSer );      //std::map<std::string,ISerializable> mStrSer;//std::map<std::string,ISerializable>
  pPopMaster->PopMapSerPtrSer<TOtherClass,TOtherClass>( mSerPtrSer );//std::map<std::string,ISerializable*> mStrPtrSer;//std::map<std::string,ISerializable*>
}
//----------------------------------------------------------------------
short TMyClass::GetSerializableUniqueID()
{
  return nsSerializableUniqueIdentity::eMyClass;
}
//----------------------------------------------------------------------
