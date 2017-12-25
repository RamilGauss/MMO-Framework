using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Base
{
    class Program
    {
        static void Main(string[] args)
        {
            sbyte [] buf = new sbyte[10];

            unsafe
            {
                var bp = new WBreakPacket();
                fixed ( sbyte* pBuf = &buf[0] )
                {
                    bp.PushBack(pBuf, buf.Length );
                }
                bp.Collect();
                void* collect = bp.GetCollectPtr();
                int size = bp.GetSize();
            }

            Console.WriteLine("asdasdas");
            Console.ReadKey();
        }
    }
}
