/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "LoadFromFile.h"

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <algorithm>

#include <boost/cstdint.hpp>

using namespace std;

TLoadFromFile::TLoadFromFile(char* path)
{
 	ReOpen(path);
}
//---------------------------------------------------------------
TLoadFromFile::~TLoadFromFile()
{

}
//---------------------------------------------------------------
bool TLoadFromFile::ReOpen(char* path, bool /*append*/)
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
unsigned int TLoadFromFile::Size()
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
int TLoadFromFile::ReadSmall(TContainer& c)
{
  c.SetDataByCount(NULL, Size());
  return Read( c.GetPtr(), c.GetSize(), 0);
}
//---------------------------------------------------------------
unsigned int TLoadFromFile::Read(void* buffer, unsigned int size, unsigned int offset)
{
#ifdef WIN32
  int res = _fseeki64( pFile, boost::int64_t(offset), SEEK_SET);
#else
  int res = fseeko( pFile, off_t(offset), SEEK_SET);
#endif

  if(res!=0) return 0;

  if(Size()<offset) return 0;
  unsigned int max_read = Size() - offset;

  fread(buffer, size, 1, pFile);
  return min(max_read, size);
}
//---------------------------------------------------------------
