#include <conio.h>
#include <stdio.h>
#include <map>
#include <string>

#include "MakerNetTransport.h"
#include "INetTransport.h"
#include "GlobalParams.h"
#include "HiTimer.h"
#include "NetSystem.h"
#include "share_test.h"

#include "SaveOnHDD.h"
#include "BL_Debug.h"
#include <boost/asio/ip/impl/address_v4.ipp>

#include <boost/smart_ptr/scoped_ptr.hpp>

using namespace std;
using namespace boost::asio::ip;
//-----------------------------------------------------------------------
int main(int argc, char** argv)
{
	//g_ShareTest->SetParam(TShareTest::eTimePerActiveConnection,50);
	g_ShareTest->SetParam(TShareTest::eCountActiveConnectionPerTime,12000);

  g_ShareTest->Init("Server");

  INetTransport* pNetTransport = g_ShareTest->GetTransport();

  bool res = pNetTransport->Open(TShareTest::ePortServer);
  g_ShareTest->Register();

  pNetTransport->Start();

  //pNetTransport->Close( address_v4::from_string(ns_getSelfIP(0)).to_ulong(), 9000);
  _getch();

  pNetTransport->Stop();
  g_ShareTest->Unregister();
  //------------------------------------------------
  printf("CommonCountRecv=%d\n",
    g_ShareTest->GetCountRecv() + g_ShareTest->GetCountStream());
  _getch();
  return 0;
}
