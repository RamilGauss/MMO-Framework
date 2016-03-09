#include "BasePacket.h"
#include "MarkUpContainer.h"
#include "BL_QConv.h"
#include "BL_Debug.h"
#include <time.h>

TBasePacket::TBasePacket()
{
  mMarkUp = new TMarkUpContainer;
  mRootDesc = new IMarkUpContainer::TDesc;
}
//--------------------------------------------------------------------------------
TBasePacket::~TBasePacket()
{
  delete mMarkUp;
  delete mRootDesc;
}
//--------------------------------------------------------------------------------
int TBasePacket::Set(char* p, int size)
{
  return mMarkUp->Set(p, size);
}
//--------------------------------------------------------------------------------
TContainer TBasePacket::GetData()
{
  TContainer c;
  mMarkUp->Collect();
  c.SetData((char*)mMarkUp->GetPtr(), mMarkUp->GetSize());
  return c;
}
//--------------------------------------------------------------------------------
void TBasePacket::GetStrContent(std::vector<std::string>& vecStr)
{
  vecStr.clear();
  mMarkUp->EnterRoot();
  GetStrDescItem(vecStr, 0);
}
//--------------------------------------------------------------------------------
void TBasePacket::GetStrDescItem(std::vector<std::string>& vecStr, int sizeStack)
{
  std::string tabs = "";
  for(int i = 0 ; i < sizeStack ; i++)
    tabs += "\t\t";

  int cntDesc = mMarkUp->GetCountDesc();
  for( int iDesc = 0 ; iDesc < cntDesc ; iDesc++ )
  {
    std::string name = mMarkUp->GetNameDesc(iDesc);
    QByteArray ba = WinToKoi8(name.data());
    std::string nameKOI8 = ba.data();// название секции берется из xml, там кодировка CP1251.

    int cntElem = 0;
    if(mMarkUp->GetTypeDesc(iDesc)==IMarkUpContainer::eArr)
    {
      // войти в какой-нибудь элемент и проверить что он константный
      cntElem = mMarkUp->GetCount(name.data());
      if(cntElem!=0)
      {
        bool resConst = false;
        if(mMarkUp->Enter(name.data(), 0))
        {
          resConst = ((mMarkUp->GetCountDesc()==1) && (mMarkUp->GetTypeDesc(0)==IMarkUpContainer::eConst));
          mMarkUp->Leave();
        }
        if(resConst)
        {
          std::string sConst = ": ";
          for( int iElem = 0 ; iElem < cntElem ; iElem++ )
          {
            if(mMarkUp->Enter(name.data(), iElem))
            {
              // не учел (пока намеренно) вариант когда str_const == "" т.е. когда не нужно отображать
              sConst += GetStrDescConstItem(mMarkUp->GetNameDesc(0));
              mMarkUp->Leave();
            }
          }
          vecStr.push_back(tabs + nameKOI8 + sConst);
          continue;
        }
      }
      char s[100];
      sprintf(s, "(%d):\n", cntElem);
      vecStr.push_back(tabs + nameKOI8 + s);
    }
    else
    {
      std::string str_const = GetStrDescConstItem(name);
      if(str_const.length())
      {
        std::string sConst = ": ";
        sConst += str_const;
        sConst += "\n";

        vecStr.push_back(tabs + nameKOI8 + sConst);
      }
    }
    
    for( int iElem = 0 ; iElem < cntElem ; iElem++ )
    {
      if(mMarkUp->Enter(name.data(), iElem))
      {
        GetStrDescItem(vecStr, sizeStack + 1);
        mMarkUp->Leave();
      }
    }
  }
}
//--------------------------------------------------------------------------------
