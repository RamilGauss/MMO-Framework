/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Logger.h"
#include <boost/foreach.hpp>

using namespace std;

class TLoggerOneObject : public TLogger
{
};
//-----------------------------------------------------------------------
TLoggerOneObject g_Logger;
TLogger* GetLogger()
{
  return (TLogger*)&g_Logger;
}
//-----------------------------------------------------------------------
TSaveOnHDD* GetLogger(const char* nameLog)
{
  return g_Logger.Get(nameLog);
}
//-----------------------------------------------------------------------
void TLogger::InitLogger(TSaveOnHDD* saver, const char* sName)
{
  if(saver->IsOpen()) return;
  char nameLogFile[260];
  sprintf(nameLogFile,".\\%s%s.log",sName,sPrefix.data());
  saver->ReOpen(nameLogFile);
}
//-----------------------------------------------------------------------
void TLogger::Register(const char* nameLogger)
{
  TSaveOnHDD* pSoHDD = new TSaveOnHDD;
  pSoHDD->SetPrintf(flgPrintf);
  pSoHDD->SetEnable(flgEnable);
  pSoHDD->SetBufferization(flgBuffer);

  mMapNamePtr.insert(TMapStrPtr::value_type(nameLogger,pSoHDD));
  if(sPrefix.length())
  {
    InitLogger(pSoHDD,nameLogger);
  }
}
//-----------------------------------------------------------------------
void TLogger::Init(char* prefix)
{
  sPrefix = prefix;
  
  BOOST_FOREACH( TMapStrPtr::value_type& bit, mMapNamePtr )
    InitLogger(bit.second,bit.first.data());
}
//-----------------------------------------------------------------------
TSaveOnHDD* TLogger::Get(const char* nameLog)
{
  TMapStrPtr::iterator fit = mMapNamePtr.find(nameLog);
  if(mMapNamePtr.end()!=fit)
    return fit->second;

  return NULL;
}
//-----------------------------------------------------------------------
void TLogger::Done()
{
  BOOST_FOREACH(TMapStrPtr::value_type& bit,mMapNamePtr)
    delete bit.second;
  mMapNamePtr.clear();
}
//-----------------------------------------------------------------------
TLogger::~TLogger()
{
  Done();
}
//-----------------------------------------------------------------------
void TLogger::SetPrintf(bool val)
{
  if(flgPrintf==val)
    return;
  
  flgPrintf = val;
  BOOST_FOREACH(TMapStrPtr::value_type &bit,mMapNamePtr)
    bit.second->SetPrintf(flgPrintf);
}
//-----------------------------------------------------------------------
bool TLogger::GetPrintf()
{
  return flgPrintf;
}
//-----------------------------------------------------------------------
void TLogger::SetEnable(bool val)
{
  if(flgEnable==val)
    return;

  flgEnable = val;
  BOOST_FOREACH(TMapStrPtr::value_type &bit,mMapNamePtr)
    bit.second->SetEnable(flgEnable);
}
//-----------------------------------------------------------------------
bool TLogger::GetEnable()
{
  return flgEnable;
}
//-----------------------------------------------------------------------
void TLogger::SetBufferization(bool val)
{
  if(flgBuffer==val)
    return;
  
  flgBuffer = val;
  BOOST_FOREACH(TMapStrPtr::value_type &bit,mMapNamePtr)
    bit.second->SetBufferization(flgBuffer);
}
//-----------------------------------------------------------------------
bool TLogger::GetBufferization()
{
  return flgBuffer;
}
//-----------------------------------------------------------------------
