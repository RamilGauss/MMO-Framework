/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DllExport.h"

int main(int argc, char** argv)
{
  char* p = "logName";
  InitLib( p );
  int id = MakeClient();
  Init( id );
  DoneLib();
  return 0;
}
//-----------------------------------------------------------------------
