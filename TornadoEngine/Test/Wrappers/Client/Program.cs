/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

using System;
using System.Collections.Generic;
using System.Text;
using System.Globalization;
using System.Runtime.InteropServices;

namespace TestClient
{
  public class Program
  {
    [DllImport("NativeMMOEngineWrapper_d")]
    unsafe static extern void InitLib( byte* logName );

    [DllImport("NativeMMOEngineWrapper_d")]
    static extern void DoneLib();

    [DllImport("NativeMMOEngineWrapper_d")]
    static extern int MakeClient();

    [DllImport("NativeMMOEngineWrapper_d")]
    static extern int Init( int implID );
    
    [DllImport("NativeMMOEngineWrapper_d")]
    static extern bool Open( int implID, ushort port, byte subNet );

    static void Main(string[] args)
    {
      string str = "my string";

      ASCIIEncoding encoding = new ASCIIEncoding();
      Byte[] bytes = encoding.GetBytes(str);

      unsafe 
      {
        fixed (byte* p = &bytes[0])
        {               
            // do some work
            InitLib( p );
        }

        int id = MakeClient();
        Init( id );
        Open( id, 7777, 0);

        DoneLib();
      }
    }
  }
}
