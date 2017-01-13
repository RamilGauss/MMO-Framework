/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <boost/atomic/fences.hpp>

#include "DataExchange2Thread.h"
#include "ThreadBoost.h"
#include "BL_Debug.h"
#include "HiTimer.h"
#include "LoadFromFile.h"
#include "SaveToFile.h"

TDataExchange2Thread<unsigned short> g_List2Thread;
std::string                          g_PathFile;
char sErr[300];

#define CMD_STOP 0xff00
//---------------------------------------------------------------------------------------
class TTestProducer : public TThreadBoost
{
	TLoadFromFile mLoader;
	int mSizeSend;
	TContainer mBuffer;
	int mSizeSendFromBuffer;
public:
  TTestProducer()
  {
		if( mLoader.ReOpen((char*)g_PathFile.data())==false )
		{
			sprintf(sErr,"File open FAIL \"%s\".\n", g_PathFile.data());
			BL_MessageBug(sErr);
			_exit(2);
		}
		mSizeSend = 0;
		mSizeSendFromBuffer = -1;
		mBuffer.SetData(NULL, 10000000);
  }
protected:
  virtual void Work()
  {
		if( mSizeSend==mLoader.Size() )
		{
			unsigned short* pCmd = new unsigned short(0);
			*pCmd = CMD_STOP;
			g_List2Thread.Add(pCmd);
			Stop();
			return;
		}

		unsigned short* pData = new unsigned short(0);
		ReadFromFile(pData);
    g_List2Thread.Add(pData);
		mSizeSend++;
  }
	void ReadFromFile(unsigned short* pData)
	{
		if( mSizeSendFromBuffer==-1 ||
				mSizeSendFromBuffer==mBuffer.GetSize() )
		{
			int restSize = mLoader.Size() - mSizeSend;
			if( mBuffer.GetSize() > restSize )
				mBuffer.SetData(NULL, restSize);

			unsigned int resRead = mLoader.Read(mBuffer.GetPtr(), mBuffer.GetSize(), mSizeSend);
			if( resRead!=mBuffer.GetSize() )
			{
				sprintf(sErr,"File read FAIL \"%s\", offset=%d.\n", g_PathFile.data(), mSizeSend);
				BL_MessageBug(sErr);
				_exit(4);
			}
			mSizeSendFromBuffer = 0;
		}
		memcpy( pData, mBuffer.GetPtr() + mSizeSendFromBuffer, sizeof(char));
		mSizeSendFromBuffer++;
	}
};
//---------------------------------------------------------------------------------------
class TTestConsumer : public TThreadBoost
{
	TSaveToFile mSaver;
public:
  TTestConsumer()
  {
		std::string sDst = g_PathFile + "_";
		if( mSaver.ReOpen((char*)sDst.data())==false )
		{
			sprintf(sErr,"File open FAIL \"%s\".\n", sDst.data());
			BL_MessageBug(sErr);
			_exit(3);
		}
  }
protected:
  virtual void Work()
  {
    unsigned short** pp = g_List2Thread.GetFirst();
    if( pp )
		{
			char* pData = (char*)(*pp);
			char* pCmd  = pData + 1;
			if( *pCmd==CMD_STOP )
			{
				mSaver.Close();
				_exit(0);
			}
			mSaver.Write(pData, sizeof(char));
			g_List2Thread.RemoveFirst();
		}
		else
			ht_msleep(10);
  }
};
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	if( argc==1 )
	{
		sprintf(sErr,"Set path file via argument.\n");
		BL_MessageBug(sErr);
		return 1;
	}
	g_PathFile = argv[1];

  TTestProducer producer;
  TTestConsumer consumer;
  
  producer.Start();
  consumer.Start();

  _getch();
  return 0;
}
//---------------------------------------------------------------------------------------
