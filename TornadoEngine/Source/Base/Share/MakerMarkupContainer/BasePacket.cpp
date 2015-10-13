#include "BasePacket.h"
#include "MarkUpContainer.h"

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
void TBasePacket::GetStrDesc(std::vector<std::string>& vecStr)
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
    tabs += "\t";

  int cntDesc = mMarkUp->GetCountDesc();
  for( int iDesc = 0 ; iDesc < cntDesc ; iDesc++ )
  {
    std::string name = mMarkUp->GetNameDesc(iDesc);
    int cntElem = 0;
    if(mMarkUp->GetTypeDesc(iDesc)==IMarkUpContainer::eArr)
    {
      cntElem = mMarkUp->GetCount(name.data());
      char s[100];
      sprintf(s, "(%d):\n", cntElem);
      vecStr.push_back(tabs + name + s);
    }
    else
    {
      std::string sConst = ": ";
      int size     = mMarkUp->GetSizeConst(name.data());
      char* pConst = (char*)mMarkUp->GetPtrConst(name.data());
      for( int i = 0 ; i < size ; i++)
      {
        char s[100];
        sprintf(s, "0x%X ", pConst[i]);
        sConst += s;
      }
      sConst += "\n";
      vecStr.push_back(tabs + name + sConst);
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
