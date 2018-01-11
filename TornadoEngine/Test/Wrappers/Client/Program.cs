using System;
using System.Collections.Generic;
using System.Text;
using ManagedMMOEngineWrapper;
using System.Globalization;

namespace Client
{
  class Program
  {
    static void Main(string[] args)
    {
      unsafe
      {
        var client = new WClient();
        string logName = "asdaa";
        client.Init( logName );
      }
    }
  }
}
