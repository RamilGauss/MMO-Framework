
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

//https://github.com/tbhaxor/WinAPI-RedBlue/tree/main

/// <summary>
/// Print the human-readable error message cause while execution of the function and exit if TRUE
/// </summary>
/// <param name="lpFunction">Function name caused error</param>
/// <param name="bExit">Whether to exit after printing error or not (TRUE/FALSE)</param>
VOID PrintError(LPCSTR lpFunction, BOOL bExit = FALSE)
{
    DWORD dwErrorCode = GetLastError();

    std::cout << "[" << dwErrorCode << "] " << lpFunction << ": ";
    if (dwErrorCode == 0x0) {
        std::cout << "Undefined error\n";
    } else {
        std::cout << std::system_category().message(dwErrorCode) << std::endl;
    }

    if (bExit) {
        ExitProcess(1);
    }
}

//BOOL ReadProcessMemory(
//    [in]  HANDLE  hProcess,
//    [in]  LPCVOID lpBaseAddress,
//    [out] LPVOID  lpBuffer,
//    [in]  SIZE_T  nSize,
//    [out] SIZE_T* lpNumberOfBytesRead
//);

//DWORD procid = GetProcId("ac_client.exe");
//
//unsigned char* addr = 0;
//
//HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procid);
//
//MEMORY_BASIC_INFORMATION mbi;
//
//while (VirtualQueryEx(hProc, addr, &mbi, sizeof(mbi))) {
//    if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS && mbi.Protect != PAGE_GUARD) {
//        std::cout << "base : 0x" << std::hex << mbi.BaseAddress << " end : 0x" << std::hex << (uintptr_t)mbi.BaseAddress + mbi.RegionSize << "\n";
//    }
//    addr += mbi.RegionSize;
//}

#include <cstdio>
#include <windows.h>
#include <tlhelp32.h>

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

int main(int, char* [])
{
    EnableDebugPriv();

    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry) == TRUE) {
        while (Process32Next(snapshot, &entry) == TRUE) {
            if (stricmp(entry.szExeFile, "target.exe") == 0) {
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);

                // Do stuff..

                CloseHandle(hProcess);
            }
        }
    }

    CloseHandle(snapshot);

    return 0;
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " PID /path/to/dll\n";
        return 0x1;
    }

    DWORD dwPID = GetProcId(argv[1]);

    // Permission PROCESS_VM_WRITE | PROCESS_VM_OPERATION are specifically for VirtualAlloc and WriteProcessMemory for the DLL Path
    // PROCESS_CREATE_THREAD is used for CreateRemoteThread function to work.
    HANDLE hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, FALSE, dwPID);
    if (hProcess == NULL) {
        PrintError("OpenProcess()", TRUE);
        return 0x1;
    }

    LPVOID lpBaseAddress = VirtualAllocEx(hProcess, nullptr, 1 << 12, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (lpBaseAddress == nullptr) {
        PrintError("VirtualAllocEx()", TRUE);
        return 0x0;
    }

    if (!WriteProcessMemory(hProcess, lpBaseAddress, (LPCVOID)argv[2], strlen(argv[2]), nullptr)) {
        PrintError("WriteProcessMemory()", TRUE);
    }

    // Kernel32 is ASLRed while booting and is then address is shared by all the processes
    HMODULE hKernel32 = GetModuleHandleA("Kernel32");
    if (hKernel32 == NULL) {
        VirtualFreeEx(hProcess, lpBaseAddress, 0x0, MEM_RELEASE);
        lpBaseAddress = nullptr;

        CloseHandle(hProcess);
        hProcess = NULL;

        PrintError("GetModuleHandleA()", TRUE);
        return 0x0;
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

        PrintError("CreateRemoteThread()", TRUE);
        return 0x0;
    }

    std::cout << "Injected DLL\n";


    CloseHandle(hProcess);
    CloseHandle(hThread);
    hProcess = hThread = nullptr;

    return 0;
}
