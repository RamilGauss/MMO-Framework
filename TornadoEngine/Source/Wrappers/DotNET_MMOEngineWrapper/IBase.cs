using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DotNET_MMOEngineWrapper
{
  unsafe interface IBase
  {
    void Init( string logName);
    bool Open( ushort port, byte subNet, int count );
    void DisconnectUp();
    void SendUp( byte* p, int size, bool check );
    void Work();
    bool IsConnectUp();
    bool IsConnect( uint id );
    void SetLoad( int procent );
    void SetTimeLiveSession( uint time_ms );
    bool GetInfoSession( uint id_session, uint ip, ushort port );
  }
}
