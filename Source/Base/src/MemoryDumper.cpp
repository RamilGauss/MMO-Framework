/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MemoryDumper.h"

namespace nsBase
{
    std::list<std::string> TMemoryDumper::Dump(void* p, size_t size, size_t lineSize)
    {
        std::list<std::string> lines;

        int lineCount = size / lineSize;
        if (size % lineSize > 0) {
            lineCount++;
        }

        void* currentPtr = p;
        
        for (int i = 0; i < lineCount; i++) {
            char buf[100];
            sprintf(buf, "0x%p ", currentPtr);
            std::string line = buf;
            for (int j = 0; j < lineSize; j++) {
                sprintf(buf, "%02X", ((uint8_t*)currentPtr)[j]);
                line += buf;
                if (j < lineSize - 1) {
                    line += " ";
                }
            }

            lines.push_back(line);

            currentPtr = (void*)((char*)currentPtr + lineSize);
        }

        return lines;
    }
}