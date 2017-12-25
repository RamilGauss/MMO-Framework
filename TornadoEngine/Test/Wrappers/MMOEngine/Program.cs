/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

using System;
using System.Collections.Generic;

namespace TestWrapperMMOEngineDotNET
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine( "Hello, World!" );

            var simpleWrapper = new TSimpleWrapper();
            simpleWrapper.Work();

        }
    }
}
