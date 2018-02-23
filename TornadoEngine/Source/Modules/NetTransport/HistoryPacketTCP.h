/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HistoryPacketTCPH
#define HistoryPacketTCPH

#include <map>

#include "ContainerRise.h"
#include "ShareMisc.h"
#include "BreakPacket.h"

class THistoryPacketTCP
{
public:
  struct TResult
  {
    TResult()
    {
      complete=false;
      parse_error = false;
    }
    void Set( char* b, int s )
    {
      buffer      = b;
      size        = s;
      complete    = true;
    }
    bool complete;
    char* buffer;
    int size;

    bool parse_error;// обнаружена ошибка, при парсинге пакета
  };
protected:
  typedef enum
  {
    eSearchSize,
    eSearchData,
  }eStatePacket;

  int mSizePacket;// предполагаемый размер пакета
  TContainerRise mCollectorPacket;    
  eStatePacket   mState;
  bool flgNewPacket;// начало нового пакета
public:
  THistoryPacketTCP();
  void Clear();
  static void PackForSend( TBreakPacket& bp );

  void Analiz(int& beginPos, TResult& res, int readSize, char* buffer);
protected:

  int SearchSize( int readSize, char* buffer, TResult& res, int beginPos );
  
  int BeginSearchSize(int readSize, char* buffer, TResult& res, int beginPos);
  int ContinueSearchSize(int readSize, char* buffer, TResult& res, int beginPos);
  
  int SearchData( int readSize, char* buffer, TResult& res, int beginPos );

  void CheckSize( TResult& res );

  enum
  {
    eMaxSize = 0xFFFF, // пакета большего размера быть не может
  };
};


#endif