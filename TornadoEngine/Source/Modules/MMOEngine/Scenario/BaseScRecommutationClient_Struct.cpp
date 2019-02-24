/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MakerScenario.h"
#include "BaseScRecommutationClient_Struct.h"

using namespace nsMMOEngine;
using namespace nsRecommutationClientStruct;

THeader::THeader()
{
  type      = TMakerScenario::eRecommutationClient;
  clientKey = -1;
}
//---------------------------------------------------------------------------------------
THeaderBeginDonor::THeaderBeginDonor()
{
  subType = eBeginDonor;
}
//---------------------------------------------------------------------------------------
THeaderBeginClient::THeaderBeginClient()
{
  subType = eBeginClient;
}
//---------------------------------------------------------------------------------------
THeaderCheckBeginClient::THeaderCheckBeginClient()
{
  subType = eCheckBeginClient;
}
//---------------------------------------------------------------------------------------
THeaderCheckBeginDonor::THeaderCheckBeginDonor()
{
  subType = eCheckBeginDonor;
}
//---------------------------------------------------------------------------------------
THeaderBeginRecipient::THeaderBeginRecipient()
{
  subType = eBeginRecipient;
  random_num = 0;
}
//---------------------------------------------------------------------------------------
THeaderCheckBeginRecipient::THeaderCheckBeginRecipient()
{
  subType = eCheckBeginRecipient;
}
//---------------------------------------------------------------------------------------
THeaderInfoRecipientToDonor::THeaderInfoRecipientToDonor()
{
  subType = eInfoRecipientToDonor;
  random_num = 0;
}
//---------------------------------------------------------------------------------------
THeaderInfoRecipientToClient::THeaderInfoRecipientToClient()
{
  subType = eInfoRecipientToClient;
  random_num = 0;
}
//---------------------------------------------------------------------------------------
THeaderCheckInfoRecipient::THeaderCheckInfoRecipient()
{
  subType = eCheckInfoRecipient;
}
//---------------------------------------------------------------------------------------
THeaderRequestConnect::THeaderRequestConnect()
{
  subType = eRequestConnect;
  random_num = 0;
}
//---------------------------------------------------------------------------------------
THeaderCheckRequestConnect::THeaderCheckRequestConnect()
{
  subType = eCheckRequestConnect;
}
//---------------------------------------------------------------------------------------
THeaderClientConnect::THeaderClientConnect()
{
  subType = eClientConnect;
}
//---------------------------------------------------------------------------------------
THeaderDisconnectClient::THeaderDisconnectClient()
{
  subType = eDisconnectClient;
}
//---------------------------------------------------------------------------------------
