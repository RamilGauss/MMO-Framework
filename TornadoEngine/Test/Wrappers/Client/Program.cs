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
    unsafe static extern void InitLib(byte* logName);

    [DllImport("NativeMMOEngineWrapper_d")]
    static extern void DoneLib();

    [DllImport("NativeMMOEngineWrapper_d")]
    static extern int MakeClient();

    [DllImport("NativeMMOEngineWrapper_d")]
    static extern int Init(int implID);

    [DllImport("NativeMMOEngineWrapper_d")]
    static extern bool Open(int implID, ushort port, byte subNet);

    [StructLayout(LayoutKind.Explicit, Size = 4, CharSet = CharSet.Ansi)]
    public class BaseStruct
    {
      [FieldOffset(0)]
      public uint type;
    }

    [StructLayout(LayoutKind.Explicit, Size = 4, CharSet = CharSet.Ansi)]
    public class SessionIdentity : BaseStruct
    {
      [FieldOffset(0)]
      public uint other;
    }

    [DllImport("NativeMMOEngineWrapper_d")]
    public static extern IntPtr GetSession( ref int type, ref int size );

    //[DllImport("NativeMMOEngineWrapper_d")]
    //public static extern void GetSession([MarshalAs(UnmanagedType.LPStruct)]SessionIdentity session);

    static void Main(string[] args)
    {
      int type = 0;
      int size = 0;
      var ptr = GetSession( ref type, ref size );
      SessionIdentity session = null;
      try
      {
        session = (SessionIdentity)Marshal.PtrToStructure(ptr, typeof(SessionIdentity));
      }
      finally
      {
        // Free the pointer here if it's allocated memory
      }

      string str = "my string";

      ASCIIEncoding encoding = new ASCIIEncoding();
      Byte[] bytes = encoding.GetBytes(str);

      unsafe
      {
        fixed (byte* p = &bytes[0])
          InitLib(p);

        int id = MakeClient();
        Init(id);
        Open(id, 7777, 0);

        DoneLib();
      }
    }
  }
}

//using System;
//using System.Runtime.InteropServices;

//namespace InteropSample
//{

//  [StructLayout(LayoutKind.Explicit, Size = 16, CharSet = CharSet.Ansi)]
//  public class MySystemTime
//  {
//    [FieldOffset(0)]
//    public ushort wYear;
//    [FieldOffset(2)]
//    public ushort wMonth;
//    [FieldOffset(4)]
//    public ushort wDayOfWeek;
//    [FieldOffset(6)]
//    public ushort wDay;
//    [FieldOffset(8)]
//    public ushort wHour;
//    [FieldOffset(10)]
//    public ushort wMinute;
//    [FieldOffset(12)]
//    public ushort wSecond;
//    [FieldOffset(14)]
//    public ushort wMilliseconds;
//  }

//  class LibWrapper
//  {
//    [DllImport("kernel32.dll")]
//    public static extern void GetSystemTime([MarshalAs(UnmanagedType.LPStruct)]MySystemTime st);
//  };

//  class TestApplication
//  {
//    public static void Main()
//    {
//      try
//      {
//        MySystemTime sysTime = new MySystemTime();
//        LibWrapper.GetSystemTime(sysTime);
//        Console.WriteLine("The System time is {0}/{1}/{2} {3}:{4}:{5}", sysTime.wDay,
//           sysTime.wMonth, sysTime.wYear, sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
//      }
//      catch (TypeLoadException e)
//      {
//        Console.WriteLine("TypeLoadException : " + e.Message);
//      }
//      catch (Exception e)
//      {
//        Console.WriteLine("Exception : " + e.Message);
//      }
//    }
//  }
//}
