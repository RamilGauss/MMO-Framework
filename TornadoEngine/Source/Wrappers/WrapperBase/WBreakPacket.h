/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WBreakPacketH
#define WBreakPacketH

class TBreakPacket;

public ref class WBreakPacket
{
  TBreakPacket* mBP;
public:
  WBreakPacket();
  //WBreakPacket(const WBreakPacket& bp);
  ~WBreakPacket();

  void PushBack(char* p,int size);
  void PushFront(char* p,int size);
  void Collect();
  void* GetCollectPtr();
  int GetSize();

  void UnlinkCollect();
  void Reset();



  //WBreakPacket& operator =( const WBreakPacket& b );
};

#endif

