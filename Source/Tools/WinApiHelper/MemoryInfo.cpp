/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include "MemoryInfo.h"

#include <iostream>

namespace nsWinApiHelper
{
    std::list<std::pair<uint8_t*, size_t>> TMemoryInfo::GetExecutablePages(unsigned long processId)
    {
        unsigned char* addr = 0;

        HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

        MEMORY_BASIC_INFORMATION mbi;

        std::list<std::pair<uint8_t*, size_t>> pages;

        while (VirtualQueryEx(hProc, addr, &mbi, sizeof(mbi))) {

            bool isProtected = mbi.Protect & PAGE_NOACCESS;
            isProtected &= mbi.Protect & PAGE_GUARD;

            if (isProtected) {
                continue;
            }

            bool isExecutable = mbi.Protect & PAGE_EXECUTE;
            isExecutable |= mbi.Protect & PAGE_EXECUTE_READ;
            isExecutable |= mbi.Protect & PAGE_EXECUTE_READWRITE;
            isExecutable |= mbi.Protect & PAGE_EXECUTE_WRITECOPY;
            isExecutable |= mbi.Protect & PAGE_READONLY;

            if (isExecutable && mbi.State == MEM_COMMIT) {
                std::pair<uint8_t*, size_t> newPage;
                newPage.first = (uint8_t*)mbi.BaseAddress;
                newPage.second = mbi.RegionSize;
                pages.push_back(newPage);
            }
            addr += mbi.RegionSize;
        }

        if (pages.size() <= 1) {
            return pages;
        }

        auto it = pages.begin();

        std::pair<uint8_t*, size_t> collectedPage = *it;
        std::list<std::pair<uint8_t*, size_t>> collectedPages;

        it++;
        for (; it != pages.end(); it++) {
            if (collectedPage.first + collectedPage.second == it->first) {
                collectedPage.second += it->second;
            } else {
                collectedPages.push_back(collectedPage);
                collectedPage = *it;
            }
        }

        collectedPages.push_back(collectedPage);

        return collectedPages;
    }
}