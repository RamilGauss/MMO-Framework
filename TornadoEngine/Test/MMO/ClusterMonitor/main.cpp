/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClusterMonitorClientHandler.h"
#include <iostream>

int main( int argc, char** argv )
{
  setlocale( LC_ALL, "Russian" );
  InitLogger( ClusterMonitorLog );

  TClusterMonitorClientHandler clientHandler( argc, argv );

  while( true )
    clientHandler.Work();
  return 0;
}

