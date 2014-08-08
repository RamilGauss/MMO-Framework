/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "file_operation.h"

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include <boost/filesystem.hpp>

using namespace boost::filesystem;
//--------------------------------------------------------------------------------
bool FindAbsPath(char* sRelativePath, char* sAbsPath, int lenAbs)
{
  bool res = false;
  try
  {
    path p = sRelativePath;
    path canonicalPath = canonical(p);

    if(lenAbs<=int(canonicalPath.string().size()))
      return false;
    strcpy(sAbsPath, canonicalPath.string().data());
    res = true;
  }
  catch(std::exception e)
  {}
  return res;
}
//--------------------------------------------------------------------------------
void UpPath(char* path)
{
  int cnt = strlen(path);
  for(int i = cnt-1 ; i > 0 ; i--)
    if(path[i]=='\\')
    {
      path[i]='\0';
      return;
    }
}
//--------------------------------------------------------------------------------
bool GetCurrentPath(std::string &sPath)
{
  boost::system::error_code ec;
  path p = current_path(ec);
  if(ec)
    return false;
  sPath = p.string();
  return true;
}
//--------------------------------------------------------------------------------
