#include <stdio.h>
#include <openssl/md5.h>
#include "ContainerTypes.h"
#include "LoadFromFile.h"
#include "MD5.h"
#include "SHA.h"
#include "openssl/sha.h"
#define BUFSIZE (1025*160)

int main(int argc, char **argv)
{
  // 3EB92D12773E8BF8061AFF68D5C187CEAA8DBFB7
  TLoadFromFile loader;
  bool res = loader.ReOpen("d:\\dbltj\\загадка.txt");
  //bool res = loader.ReOpen("d:\\dbltj\\Virtual Zeppelin-The Lemon Song.flv");
  if(res==false)
    return 1;
  unsigned char bufferFile[BUFSIZE];

  TSHA256 md5;
  md5.Begin();
  //------------------------------------------------
  unsigned int size = loader.Size();
  for( unsigned int i = 0 ; i < size ;  )
  {
    int sizeRead = loader.Read(bufferFile, BUFSIZE, i);
    i += sizeRead;
    md5.Calc(bufferFile, sizeRead);
  }
  // Помещаем вычисленный хэш в буфер md_buf
  TContainer result;
  md5.End(result);
  //------------------------------------------------
  // Отображаем результат
  for( int i = 0; i < result.GetSize(); i++) 
    printf("%02x", ((unsigned char*)result.GetPtr())[i]);
  return 0;
} 

//#include <stdio.h>
//#include <string>
//#include <conio.h>
//
//#include "HiTimer.h"
//#include "ContainerTypes.h"
//#include "ManagerContextCrypto.h"
//#include <boost/foreach.hpp>
//#include <list>
//#include "DescEvent.h"
//#include "SrcEvent.h"


//int main(int argc, char** argv)
//{
#if 0
  bool res = false;
  std::string msg = "Some cat smell like apple.Some cat smell like apple.Some cat smell like apple.Some cat smell like ap";
  TIP_Port ip_port_client(0,1), 
           ip_port_server(0,2);
  TContainer RSApublicKey, AESkey,
             c_msg_ecnrypt;
  TContainerPtr c_res_ptr;
  TManagerContextCrypto mngCtxClient, mngCtxServer;

  //{
  //  std::list<unsigned int> lDelta;

  //  int cnt = 100000;
  //  unsigned int start = ht_GetMSCount();
  //  //unsigned int max = 0, min = 200000;
  //  //unsigned int a0 = ht_GetMSCount();
  //  for( int i = 0 ; i < cnt ; i++ )
  //  {
  //    mngCtxClient.SendRSA_PublicKey(TIP_Port(0,i), RSApublicKey);
  //    mngCtxClient.Close(TIP_Port(0,i));
  //    
  //    //unsigned int a1 = ht_GetMSCount();
  //    //unsigned int d = a1 - a0;
  //    //max = std::max(d,max);
  //    //min = std::min(d,min);
  //    //lDelta.push_front(d);
  //    //a0 = a1;
  //  }
  //  unsigned int delta = ht_GetMSCount() - start;
  //  float speed = float(delta)/cnt;
  //  printf("Generate RSA key on client speed = %f\n", speed);
  //  //printf("max = %u, min = %u\n", max, min);
  //  //BOOST_FOREACH(unsigned int d, lDelta)
  //    //printf("delta=%u\n",d);
  //}
  //_getch();

  // на стороне Клиента
  mngCtxClient.SendRSA_PublicKey(ip_port_server, RSApublicKey);
  
  // отослали Серверу
  int cnt = 0;
  unsigned int start = ht_GetMSCount();
  for( int i = 0 ; i < cnt ; i++ )
  {
    res = mngCtxServer.RecvRSA_PublicKey(TIP_Port(0,i), (char*)RSApublicKey.GetPtr(), RSApublicKey.GetSize());
    mngCtxServer.SendAES_Key(TIP_Port(0,i), AESkey);
  }
  unsigned int delta = ht_GetMSCount() - start;
  float speed = float(delta)/cnt;
  printf("Recv RSA key on server and generate AES key speed = %f\n", speed);
  //_getch();

  res = mngCtxServer.RecvRSA_PublicKey(ip_port_client, (char*)RSApublicKey.GetPtr(), RSApublicKey.GetSize());
  mngCtxServer.SendAES_Key(ip_port_client, AESkey);

  // отослали Клиенту
  res = mngCtxClient.RecvAES_Key(ip_port_server, (char*)AESkey.GetPtr(), AESkey.GetSize());

  // обмен пакетами между Клиентом и Сервером
  TBreakPacket bp;
  bp.PushFront((char*)msg.data(), msg.length());
  mngCtxClient.Send(ip_port_server, bp, c_msg_ecnrypt);

  cnt = 1000000;
  start = ht_GetMSCount();
  for( int i = 0 ; i < cnt ; i++ )
  {
    res = mngCtxServer.Recv(ip_port_client, c_msg_ecnrypt.GetPtr(), c_msg_ecnrypt.GetSize(), c_res_ptr);
  }
  delta = ht_GetMSCount() - start;
  speed = float(delta)/cnt;
  printf("Recv on server and Decrypt speed = %f\n", speed);

  _getch();
#endif
//  return 0;
//} 