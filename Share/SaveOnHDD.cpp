/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SaveOnHDD.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
#include <sys/timeb.h>
#include <algorithm>
#include <boost/foreach.hpp>

#include "BL_Debug.h"
#include "HiTimer.h"

#define CHECK_LEN(buffer) \
{ \
  int len = _vscprintf( format, list )+ 1; \
  BL_ASSERT(len<sizeof(buffer)); \
}

using namespace std;

TSaveOnHDD::TSaveOnHDD(char* path)
{
  pFile = NULL;

	ReOpen(path);
  
  flgPrintf = false;
  flgEnable = true;
  flgBuffer = true;
}
//---------------------------------------------------------------
TSaveOnHDD::~TSaveOnHDD()
{
	Close();
  ClearBuffer();
}
//---------------------------------------------------------------
bool TSaveOnHDD::ReOpen(char* path, bool append )
{
	Close();

	if(path!=NULL)
		sPath = path;

	if(sPath.length()==0) return false;

  const char* sMode = (append)?"ba":"wb";
  pFile = fopen(sPath.data(),sMode);
	if(pFile!=NULL) 
  {
    FlushBuffer();
    return true;
  }

	char sErr[1000];
	sprintf(sErr,"fopen Error: %s path=\"%s\"",strerror(errno),path);
	BL_MessageBug(sErr);

	return false;
}
//---------------------------------------------------------------
bool TSaveOnHDD::IsOpen()
{
	return (pFile!=NULL);
}
//---------------------------------------------------------------
void TSaveOnHDD::Write(void* buffer, int size)
{
  if(flgEnable==false) return;

	if(pFile)
  {
    fwrite(buffer, size,1,pFile);
    fflush(pFile);
  }
  else
  {
    if(flgBuffer)
      FlushInBuffer((char*)buffer,size);
  }
}
//---------------------------------------------------------------
void TSaveOnHDD::Close()
{
	if(pFile==NULL) return;
	fclose(pFile);
	pFile = NULL;
}
//---------------------------------------------------------------
void TSaveOnHDD::WriteF(const char* format, ... )
{
  if(flgEnable==false) return;

	va_list list;
	va_start(list,format);

  char s[10000]; 
  CHECK_LEN(s);
	int res = vsprintf(s,format,list); 
	
  va_end(list);
  if(res==-1)
  {
    BL_MessageBug("WriteF Error!");
    return;
  }
  // делаем то что хотели, будь то запись в файл или в консоль
  if(flgPrintf)
    printf("%s",s);   
  Write(s,strlen(s));
}
//---------------------------------------------------------------
void TSaveOnHDD::WriteF_time(const char* format, ... )
{
  if(flgEnable==false) return;

  Write_Time();

  va_list list;
  va_start(list,format);

  char s[10000]; 
  CHECK_LEN(s);
  int res = vsprintf(s,format,list); 

  va_end(list);
  if(res==-1)  
  {
    BL_MessageBug("WriteF_time Error!");
    return;
  }

  // делаем то что хотели, будь то запись в файл или в консоль
  if(flgPrintf)
    printf("%s",s);   
  Write(s,strlen(s));
}
//---------------------------------------------------------------
void TSaveOnHDD::Write_Time()
{
#ifdef WIN32
  struct _timeb timebuffer;
  _ftime( &timebuffer );
#else
  struct timeb timebuffer;
  ftime( &timebuffer );
#endif

  time_t time1;
  unsigned short millitm1;

  time1 = timebuffer.time;
  millitm1 = timebuffer.millitm;

  char str_time[1000];
  // формируем время в строку
  struct tm * my_time = localtime(&time1);

  sprintf(str_time,"%04d_%02d_%02d %02d:%02d:%02d.%03d\n\t",
    my_time->tm_year+1900,my_time->tm_mon+1,my_time->tm_mday,
    my_time->tm_hour,my_time->tm_min,my_time->tm_sec,millitm1);

  Write(str_time,strlen(str_time));
}
//---------------------------------------------------------------
void TSaveOnHDD::FlushBuffer()
{
  TListContainer::T::iterator bit = mListBuffer->begin();
  TListContainer::T::iterator eit = mListBuffer->end();
  while(bit!=eit)
  {
    TContainer* v = *bit;
    Write(v->GetPtr(),v->GetSize());
    delete v;
    bit++;
  }
  mListBuffer->clear();
}
//---------------------------------------------------------------
void TSaveOnHDD::ClearBuffer()
{
  mListBuffer.Clear();
}
//---------------------------------------------------------------
void TSaveOnHDD::FlushInBuffer(char* buffer, int size)
{
  TContainer* v = new TContainer;
  v->SetData(buffer,size);

  mListBuffer->push_back(v);

  BL_ASSERT(mListBuffer->size()<=eMaxNumberForBufferization);

}
//---------------------------------------------------------------
