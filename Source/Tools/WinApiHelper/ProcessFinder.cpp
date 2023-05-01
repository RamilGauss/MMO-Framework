/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProcessFinder.h"

#include <cstdio>
#include <windows.h>
#include <tlhelp32.h>

namespace nsWinApiHelper
{
    void EnableDebugPriv()
    {
        HANDLE hToken;
        LUID luid;
        TOKEN_PRIVILEGES tkp;

        OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);

        LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid);

        tkp.PrivilegeCount = 1;
        tkp.Privileges[0].Luid = luid;
        tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

        AdjustTokenPrivileges(hToken, false, &tkp, sizeof(tkp), NULL, NULL);

        CloseHandle(hToken);
    }
    //--------------------------------------------------------------------------------------------
    unsigned long TProcessFinder::GetProcessIdByName(const std::wstring& processName)
    {
        EnableDebugPriv();

        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(PROCESSENTRY32);

        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

        if (Process32First(snapshot, &entry) == TRUE) {
            while (Process32Next(snapshot, &entry) == TRUE) {

                auto cmpResult = (entry.szExeFile == processName);
                if (cmpResult) {
                    return entry.th32ProcessID;
                }
            }
        }

        CloseHandle(snapshot);

        return -1;
    }
}