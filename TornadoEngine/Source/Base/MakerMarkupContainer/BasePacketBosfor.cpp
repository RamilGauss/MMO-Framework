/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BasePacketBosfor.h"
#include "BL_Debug.h"

#include <time.h>

std::string TBasePacketBosfor::GetStrDescConstItem(std::string name)
{
  int size     = mMarkUp->GetSizeConst(name.data());
  char* pConst = (char*)mMarkUp->GetPtrConst(name.data());
  std::string type = mMarkUp->GetTypeConst(name.data());
  std::string sConst;
  if(type.length()==0)
  {
    for( int i = 0 ; i < size ; i++)
    {
      char s[100];
      sprintf(s, "0x%X ", ((unsigned char*)pConst)[i]);
      sConst += s;
    }
  }
  else if(type=="eSymbol")
  {
    sConst = pConst[0];
  }
  else if(type=="eInt")
  {
    BL_ASSERT(sizeof(int)==size);
    char s[100];
    sprintf(s, "%d", ((int*)pConst)[0]);
    sConst = s;
  }
  else if(type=="eFloat")
  {
    BL_ASSERT(sizeof(float)==size);
    char s[100];
    sprintf(s, "%f", ((float*)pConst)[0]);
    sConst = s;
  }
  else if(type=="eTime_Double")
  {
    BL_ASSERT(sizeof(double)==size);
    double cntSeconds = ((double*)pConst)[0];
    time_t time1 = (time_t)cntSeconds;
    struct tm * my_time = localtime(&time1);

    char s[1000];
    sprintf(s,"%04d_%02d_%02d %02d:%02d:%02d",
      my_time->tm_year+1900,my_time->tm_mon+1,my_time->tm_mday,
      my_time->tm_hour,my_time->tm_min,my_time->tm_sec);
    sConst = s;
  }
  else if(type=="eBool")
  {
    BL_ASSERT(sizeof(int)==size);
    if(((bool*)pConst)[0])
      sConst = "Да";
    else
      sConst = "Нет";
  }
  else if(type=="ePairInt")
  {
    BL_ASSERT(2*sizeof(int)==size);
    char s[100];
    sprintf(s, "(%d;%d)", ((int*)pConst)[0], ((int*)pConst)[1]);
    sConst += s;
  }
  return sConst;
}
//--------------------------------------------------------------------------------
