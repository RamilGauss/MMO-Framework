/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextScDisconnectClient.h"

using namespace nsMMOEngine;

TContextScDisconnectClient::TContextScDisconnectClient()
{
  mIDClient = (unsigned int)-1;
}
//-----------------------------------------------------------------
TContextScDisconnectClient::~TContextScDisconnectClient()
{

}
//-----------------------------------------------------------------
unsigned int TContextScDisconnectClient::GetIDClient()
{
  return mIDClient;
}
//-----------------------------------------------------------------
void TContextScDisconnectClient::SetIDClient(unsigned int val)
{
  mIDClient = val;
}
//-----------------------------------------------------------------
