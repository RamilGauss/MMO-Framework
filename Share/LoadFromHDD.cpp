/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "LoadFromHDD.h"

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <algorithm>

using namespace std;

TLoadFromHDD::TLoadFromHDD(char* path)
{
  pFile = NULL;

	ReOpen(path);
}
//---------------------------------------------------------------
TLoadFromHDD::~TLoadFromHDD()
{
	Close();
}
//---------------------------------------------------------------
bool TLoadFromHDD::ReOpen(char* path)
{
  Close();

	if(path!=NULL)
    sPath = path;

	if(sPath.size()==0) 
    return false;

	pFile = fopen(sPath.data(), "rb");
	if(pFile!=NULL) return true;

	return false;
}
//---------------------------------------------------------------
bool TLoadFromHDD::IsOpen()
{
  return (pFile!=NULL);
}
//---------------------------------------------------------------
unsigned int TLoadFromHDD::Size()
{
#ifdef WIN32
	int fd = _fileno(pFile);

  if(fd<0) return 0;

  struct _stat buffer;
  int resstat = _fstat( fd,&buffer);
  if(resstat!=0) return 0;

  return buffer.st_size;
#else
  int fd = fileno(pFile);

  if(fd<0) return 0;

  struct stat buffer;
  int resstat = fstat( fd,&buffer);
  if(resstat!=0) return 0;

  return buffer.st_size;
#endif
}
//---------------------------------------------------------------
int TLoadFromHDD::ReadSmall(TContainer& c)
{
  c.SetData(NULL, Size());
  return Read( c.GetPtr(), c.GetSize(), 0);
}
//---------------------------------------------------------------
int TLoadFromHDD::Read(void* buffer, int size, int offset)
{
  int res = fseek(pFile, offset, SEEK_SET);
  if(res!=0) return 0;

  int max_read = Size() - offset;
  if(max_read<=0) return 0;

  fread(buffer, size, 1, pFile);
  return min(max_read, size);
}
//---------------------------------------------------------------
void TLoadFromHDD::Close()
{
	if(pFile==NULL) return;
  fclose(pFile);
	pFile = NULL;
}
//---------------------------------------------------------------
