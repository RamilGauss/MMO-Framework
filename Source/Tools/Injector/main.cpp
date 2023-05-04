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

#include <winsock2.h>

#include <ws2tcpip.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <utility>

#include "ProcessFinder.h"
#include "MemoryInfo.h"

#include "MemoryDumper.h"
#include "CallFinder.h"

//https://github.com/tbhaxor/WinAPI-RedBlue/tree/main

void PrintError(LPCSTR lpFunction)
{
    DWORD dwErrorCode = GetLastError();

    std::cout << "[" << dwErrorCode << "] " << lpFunction << ": ";
    if (dwErrorCode == 0x0) {
        std::cout << "Undefined error\n";
    } else {
        std::cout << std::system_category().message(dwErrorCode) << std::endl;
    }
}

//BOOL ReadProcessMemory(
//    [in]  HANDLE  hProcess,
//    [in]  LPCVOID lpBaseAddress,
//    [out] LPVOID  lpBuffer,
//    [in]  SIZE_T  nSize,
//    [out] SIZE_T* lpNumberOfBytesRead
//);

int main(int argc, char* argv[])
{
    //if (argc < 3) {
    //    std::cerr << "Usage: " << argv[0] << " PID /path/to/dll\n";
    //    return 1;
    //}

    //### DLL begin
    std::wstring processName = L"Injector_d.exe";// argv[1];

    DWORD dwPID = nsWinApiHelper::TProcessFinder::GetProcessIdByName(processName);// argv[1]);

    auto pages = nsWinApiHelper::TMemoryInfo::GetExecutablePages(dwPID);

    size_t commonSize = 0;
    for (auto p : pages) {
        printf("base: 0x%p size: %llu\n", p.ptr, p.size);

        commonSize += p.size;
    }

    printf("common size = %llu\n", commonSize);

    void* pFunc = (void*)WSASend;
    printf("Enumerate calling of pFunc(0x%p):\n", pFunc);

    auto callPlaces = nsWinApiHelper::TCallFinder::Find(pages, pFunc);

    for (auto& callPlace : callPlaces) {
        auto placesStr = nsBase::TMemoryDumper::Dump(callPlace, 5, 5);
        for (auto& s : placesStr) {
            printf("%s\n", s.c_str());
        }
    }

    WSASend(0, 0, 0, 0, 0, 0, 0);
    //### DLL end


    // Permission PROCESS_VM_WRITE | PROCESS_VM_OPERATION are specifically for VirtualAlloc and WriteProcessMemory for the DLL Path
    // PROCESS_CREATE_THREAD is used for CreateRemoteThread function to work.
    HANDLE hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, FALSE, dwPID);
    if (hProcess == NULL) {
        PrintError("OpenProcess()");
        return 1;
    }

    LPVOID lpBaseAddress = VirtualAllocEx(hProcess, nullptr, 1 << 12, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (lpBaseAddress == nullptr) {
        PrintError("VirtualAllocEx()");
        return 0;
    }

    if (!WriteProcessMemory(hProcess, lpBaseAddress, (LPCVOID)argv[2], strlen(argv[2]), nullptr)) {
        PrintError("WriteProcessMemory()");
    }

    // Kernel32 is ASLRed while booting and is then address is shared by all the processes
    HMODULE hKernel32 = GetModuleHandleA("Kernel32");
    if (hKernel32 == NULL) {
        VirtualFreeEx(hProcess, lpBaseAddress, 0x0, MEM_RELEASE);
        lpBaseAddress = nullptr;

        CloseHandle(hProcess);
        hProcess = NULL;

        PrintError("GetModuleHandleA()");
        return 0;
    }
    FARPROC pLoadLibraryA = GetProcAddress(hKernel32, "LoadLibraryA");

    // Inherit the security attributes from the parent process (helps in getting privileges of that) with default stack size
    // Creation flag 0x0 means that thread will be started immediately and no thread ID is returned
    HANDLE hThread = CreateRemoteThread(hProcess, nullptr, NULL, (LPTHREAD_START_ROUTINE)pLoadLibraryA, lpBaseAddress, NULL, nullptr);
    if (hThread == NULL) {
        VirtualFreeEx(hProcess, lpBaseAddress, 0x0, MEM_RELEASE);
        lpBaseAddress = nullptr;

        CloseHandle(hProcess);
        hProcess = NULL;

        PrintError("CreateRemoteThread()");
        return 0;
    }

    std::cout << "Injected DLL\n";


    CloseHandle(hProcess);
    CloseHandle(hThread);
    hProcess = hThread = nullptr;

    return 0;
}
