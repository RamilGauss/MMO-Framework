#include "QtEngine.h"
#include "HiTimer.h"
#include "Logger.h"
#include "ShareMisc.h"

#ifdef WIN32
#include <windows.h>
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
{	
  char** argv = __argv;
  int argc = __argc;
#else
int main( int argc, char* argv)
{
#endif
  bool resSetPath = SetCurrentPathByFile(argv[0]);
  BL_ASSERT(resSetPath);

  GetLogger()->Init("testQt");

  TQtEngine qtEngine;
  qtEngine.Start(argc, argv);
  ht_msleep(1000);
  qtEngine.Stop();

  return 0;
}