/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#pragma pack(push, 1)

struct TBasePacket
{
  enum PacketType
  {
    eStart, eStop, eGet, eInfo, eData
  };

  PacketType type;
};

struct TStartPacket : TBasePacket
{
  TStartPacket()
  {
    type = eStart;
  }
};

struct TStopPacket : TBasePacket
{
  TStopPacket()
  {
    type = eStop;
  }
};

struct TGetPacket : TBasePacket
{
  TGetPacket()
  {
    type = eGet;
  }
};

struct TInfoPacket : TBasePacket
{
  TInfoPacket()
  {
    type = eInfo;
  }
  float timerPerSend = 0;// us
};

struct TDataPacket : TBasePacket
{
  TDataPacket()
  {
    type = eData;
  }
  char data[10];
};

#pragma pack(pop)