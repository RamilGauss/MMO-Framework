/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MyClassH
#define MyClassH

#include "ISerializable.h"
#include "OtherClass.h"

#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>


class MyClass : public ISerializable
{
public:// member region
		bool           b;
		unsigned char  uc;
		char           c;
		unsigned short us;
		short          s;
		unsigned int   ui;
		int            i;
		float          f;
		double         d;
		std::string    str;
		OtherClass     serializable;//ISerializable
		OtherClass*    pSerializable;//ISerializable*

		std::vector<unsigned char>  vUc;
		std::vector<char>           vC;
		std::vector<unsigned short> vUs;
		std::vector<short>          vS;
		std::vector<unsigned int>   vUi;
		std::vector<int>            vI;
		std::vector<float>          vF;
		std::vector<double>         vD;
		std::vector<std::string>    vStr;
		std::vector<OtherClass>     vSer;//std::vector<ISerializable>
		std::vector<OtherClass*>    vPtrSer;//std::vector<ISerializable*>

		std::list<unsigned char>  lUc;
		std::list<char>           lC;
		std::list<unsigned short> lUs;
		std::list<short>          lS;
		std::list<unsigned int>   lUi;
		std::list<int>   					lI;
		std::list<float> 					lF;
		std::list<double>         lD;
		std::list<std::string>    lStr;
		std::list<OtherClass>     lSer;//std::list<ISerializable>
		std::list<OtherClass*>    lPtrSer;//std::list<ISerializable*>

		std::set<unsigned char>  sUc;
		std::set<char>           sC;
		std::set<unsigned short> sUs;
		std::set<short>          sS;
		std::set<unsigned int>   sUi;
		std::set<int>   			   sI;
		std::set<float> 			   sF;
		std::set<double>         sD;
		std::set<std::string>    sStr;
		std::set<OtherClass>     sSer;

		std::map<unsigned char,bool>           mUcB;
		std::map<unsigned char,unsigned char>  mUcUc;
		std::map<unsigned char,char>           mUcC;
		std::map<unsigned char,unsigned short> mUcUs;
		std::map<unsigned char,short>          mUcS;
		std::map<unsigned char,unsigned int>	 mUcUi;
		std::map<unsigned char,int>            mUcI;
		std::map<unsigned char,float> 				 mUcF;
		std::map<unsigned char,double>				 mUcD;
		std::map<unsigned char,std::string>    mUcStr;
		std::map<unsigned char,OtherClass>     mUcSer;//std::map<unsigned char,ISerializable>
		std::map<unsigned char,OtherClass*>    mUcPtrSer;//std::map<unsigned char,ISerializable*>

		std::map<char,bool>           mCB;
		std::map<char,unsigned char>  mCUc;
		std::map<char,char>           mCC;
		std::map<char,unsigned short> mCUs;
		std::map<char,short>          mCS;
		std::map<char,unsigned int>   mCUi;
		std::map<char,int>            mCI;
		std::map<char,float>          mCF;
		std::map<char,double>         mCD;
		std::map<char,std::string>    mCStr;
		std::map<char,OtherClass>     mCSer;//std::map<char,ISerializable> 
		std::map<char,OtherClass*>    mCPtrSer;//std::map<char,ISerializable*>

		std::map<unsigned short,bool>           mUsB;
		std::map<unsigned short,unsigned char>  mUsUc;
		std::map<unsigned short,char>           mUsC;
		std::map<unsigned short,unsigned short> mUsUs;
		std::map<unsigned short,short>          mUsS;
		std::map<unsigned short,unsigned int>   mUsUi;
		std::map<unsigned short,int>            mUsI;
		std::map<unsigned short,float>          mUsF;
		std::map<unsigned short,double>         mUsD;
		std::map<unsigned short,std::string>    mUsStr;
		std::map<unsigned short,OtherClass>     mUsSer;  //std::map<unsigned short,ISerializable> 
		std::map<unsigned short,OtherClass*>    mUsPtrSer; //std::map<unsigned short,ISerializable*>

		std::map<short,bool>            mSB;
		std::map<short,unsigned char>   mSUc;
		std::map<short,char>            mSC;
		std::map<short,unsigned short>  mSUs;
		std::map<short,short>           mSS;
		std::map<short,unsigned int>    mSUi;
		std::map<short,int>             mSI;
		std::map<short,float>           mSF;
		std::map<short,double>          mSD;
		std::map<short,std::string>     mSStr;
		std::map<short,OtherClass>      mSSer; //std::map<short,ISerializable>
		std::map<short,OtherClass*>     mSPtrSer;//std::map<short,ISerializable*>

		std::map<unsigned int,bool>           mUiB;
		std::map<unsigned int,unsigned char>  mUiUc;
		std::map<unsigned int,char>           mUiC;
		std::map<unsigned int,unsigned short> mUiUs;
		std::map<unsigned int,short>          mUiS;
		std::map<unsigned int,unsigned int>   mUiUi;
		std::map<unsigned int,int>            mUiI;
		std::map<unsigned int,float>          mUiF;
		std::map<unsigned int,double>         mUiD;
		std::map<unsigned int,std::string>    mUiStr;
		std::map<unsigned int,OtherClass>     mUiSer;//std::map<unsigned int,ISerializable>
		std::map<unsigned int,OtherClass*>    mUiPtrSer;//std::map<unsigned int,ISerializable*>

		std::map<int,bool>           mIB;
		std::map<int,unsigned char>  mIUc;
		std::map<int,char>           mIC;
		std::map<int,unsigned short> mIUs;
		std::map<int,short>          mIS;
		std::map<int,unsigned int>   mIUi;
		std::map<int,int>            mII;
		std::map<int,float>          mIF;
		std::map<int,double>         mID;
		std::map<int,std::string>    mIStr;
		std::map<int,OtherClass>     mISer;//std::map<int,ISerializable>
		std::map<int,OtherClass*>    mIPtrSer;//std::map<int,ISerializable*>

		std::map<float,bool>           mFB;
		std::map<float,unsigned char>  mFUc;
		std::map<float,char>           mFC;
		std::map<float,unsigned short> mFUs;
		std::map<float,short>          mFS;
		std::map<float,unsigned int>   mFUi;
		std::map<float,int>            mFI;
		std::map<float,float>          mFF;
		std::map<float,double>         mFD;
		std::map<float,std::string>    mFStr;
		std::map<float,OtherClass>     mFSer;//std::map<float,ISerializable>
		std::map<float,OtherClass*>    mFPtrSer;//std::map<float,ISerializable*>

		std::map<double,bool>           mDB;
		std::map<double,unsigned char>  mDUc;
		std::map<double,char>           mDC;
		std::map<double,unsigned short> mDUs;
		std::map<double,short>          mDS;
		std::map<double,unsigned int>   mDUi;
		std::map<double,int>      			mDI;
		std::map<double,float>    			mDF;
		std::map<double,double>   			mDD;
		std::map<double,std::string> 		mDStr;
		std::map<double,OtherClass>  		mDSer;//std::map<double,ISerializable>
		std::map<double,OtherClass*> 		mDPtrSer;//std::map<double,ISerializable*>

		std::map<std::string,bool>           mStrB;
		std::map<std::string,unsigned char>  mStrUc;
		std::map<std::string,char>           mStrC;
		std::map<std::string,unsigned short> mStrUs;
		std::map<std::string,short>          mStrS;
		std::map<std::string,unsigned int> 	 mStrUi;
		std::map<std::string,int>            mStrI;
		std::map<std::string,float>  			 	 mStrF;
		std::map<std::string,double> 			 	 mStrD;
		std::map<std::string,std::string>  	 mStrStr;
		std::map<std::string,OtherClass>   	 mStrSer;//std::map<std::string,ISerializable>
		std::map<std::string,OtherClass*>  	 mStrPtrSer;//std::map<std::string,ISerializable*>

		std::map<OtherClass,bool>           mSerB;
		std::map<OtherClass,unsigned char>  mSerUc;
		std::map<OtherClass,char>           mSerC;
		std::map<OtherClass,unsigned short> mSerUs;
		std::map<OtherClass,short>          mSerS;
		std::map<OtherClass,unsigned int>   mSerUi;
		std::map<OtherClass,int>            mSerI;
		std::map<OtherClass,float>  				mSerF;
		std::map<OtherClass,double> 				mSerD;
		std::map<OtherClass,std::string> 		mSerStr;
		std::map<OtherClass,OtherClass>  		mSerSer;//std::map<std::string,ISerializable>
		std::map<OtherClass,OtherClass*> 		mSerPtrSer;//std::map<std::string,ISerializable*>
public:
	MyClass();
  virtual ~MyClass();

	virtual void Serialize( TPushMaster* pPushMaster );
	virtual void Deserialize( TPopMaster* pPopMaster );
	virtual short GetSerializableUniqueID();
};

#endif
