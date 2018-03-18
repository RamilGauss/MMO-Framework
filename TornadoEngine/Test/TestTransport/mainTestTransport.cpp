/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>
#include "BL_Debug.h"
#include <string.h>
#include "InputCmdTestTransport.h"
#include "HiTimer.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"
#include "ShareMisc.h"
#include "MakerNetTransport.h"
#include "INetTransport.h"
#include "DataExchange2Thread.h"

#include "CryptoAES_Impl.h"
#include "SHA256.h"

nsMMOEngine::INetTransport* g_pTransport = NULL;

class THandler
{
  int count_recv;
public:
  TDataExchange2Thread<TIP_Port> mListDisc;

  THandler()
  {
    count_recv = 0;
  }
  void Recv(nsMMOEngine::INetTransport::TDescRecv* p)
  {
    count_recv++;
    printf("Recv event from %u\n", p->ip_port.port);
    if (count_recv == 1)
      g_pTransport->Close(p->ip_port.ip, p->ip_port.port);
  }
  void Disconnect(TIP_Port* p)
  {
    printf("Disconnect event from %u\n", p->port);

    TIP_Port* pNew = new TIP_Port;
    *pNew = *p;
    mListDisc.Add(pNew);
  }
};

THandler g_Handler;

int CRC32( char* data, int size )
{
  int crc = 0;
  for (int i = 0; i < size; i++)
    crc += (unsigned char)data[i];
  return crc;
}

int main(int argc, char** argv)
{
  //###
  const char* password = "1234567890";
  TSHA256 sha256;
  TContainer hashKey;
  sha256.FastCalc( (void*)password, strlen(password), hashKey);
  char* key = hashKey.GetPtr();
  auto sizeKey = hashKey.GetSize();

  TCryptoAES_Impl aes0, aes1;
  aes0.SetPublicKey(key, sizeKey);
  aes1.SetPublicKey(key, sizeKey);
  char original[10];
  int sizeOriginal = sizeof(original);
  for (int i = 0; i < sizeOriginal; i++)
    original[i] = i;

  TContainer crypt0, crypt1, crypt2;
  aes0.Encrypt(original, sizeOriginal, crypt0);
  aes0.Encrypt(original, sizeOriginal, crypt1);
  aes0.Encrypt(original, sizeOriginal, crypt2);
  TContainer retOriginal0, retOriginal1;
  aes1.Decrypt(crypt0.GetPtr(), crypt0.GetSize(), retOriginal0);
  aes1.Decrypt(crypt1.GetPtr(), crypt1.GetSize(), retOriginal1);

  auto crcO = CRC32(original, sizeof(original));
  auto crcC0 = CRC32(crypt0.GetPtr(), crypt0.GetSize());
  auto crcC1 = CRC32(crypt1.GetPtr(), crypt1.GetSize());
  auto crcC2 = CRC32(crypt2.GetPtr(), crypt2.GetSize());
  auto crcRO0 = CRC32(retOriginal0.GetPtr(), retOriginal0.GetSize());
  auto crcRO1 = CRC32(retOriginal1.GetPtr(), retOriginal1.GetSize());
  //###

  TBreakPacket g_BP;

  SetCurrentPathByFile(argv[0]);

  TInputCmdTestTransport inputCmd;
  bool res = inputCmd.SetArg(argc, argv);
  BL_ASSERT(res);

  TInputCmdTestTransport::TInput inputArg;
  inputCmd.Get(inputArg);

  char sLog[100];
  sprintf(sLog, "TestTransport%d", inputArg.port_src);

  GetLogger()->Register("TestNetTransport");
  GetLogger()->Init(sLog);
  GetLogger()->SetPrintf(false);

  TMakerNetTransport makerTransport;
  g_pTransport = makerTransport.New();

  std::string sLocalHost;
  TResolverSelf_IP_v4 resolver;
  resolver.Get(sLocalHost, 0);

  unsigned int IP = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();

  g_pTransport->GetCallbackDisconnect()->Register(&THandler::Disconnect, &g_Handler);
  g_pTransport->GetCallbackRecv()->Register(&THandler::Recv, &g_Handler);

  g_pTransport->Open(inputArg.port_src);
  g_pTransport->Start();

  bool resConnect = g_pTransport->Connect(IP, inputArg.port_dst);

  unsigned int start = ht_GetMSCount();
  while (true)
  {
    ht_msleep(100);
    unsigned int now_ms = ht_GetMSCount();

    if (resConnect)
      if (now_ms > start + inputArg.timer_send)
      {
        inputArg.timer_send += 1000;
        char* msg = "1";
        g_BP.Reset();
        g_BP.PushBack(msg, strlen(msg));
        g_pTransport->Send(IP, inputArg.port_dst, g_BP);
      }

    TIP_Port** ppFisrt = g_Handler.mListDisc.GetFirst();
    while (ppFisrt)
    {
      TIP_Port* pIP_Port = *ppFisrt;
      if (pIP_Port->port == inputArg.port_dst)
        resConnect = g_pTransport->Connect(IP, inputArg.port_dst);

      g_Handler.mListDisc.RemoveFirst();
      ppFisrt = g_Handler.mListDisc.GetFirst();
    }
  }

  return 0;
}
//-----------------------------------------------------------------------
