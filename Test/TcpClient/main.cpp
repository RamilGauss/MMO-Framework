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

#include <string>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

#include "SHA256.h"
#include "CryptoAES_Impl.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

#include "HiTimer.h"

//https://github.com/TsudaKageyu/minhook/wiki - оригинальная идея

using boost::asio::ip::tcp;

enum { max_length = 1024 };

int Custom_WSASend(
    SOCKET s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesSent,
    DWORD dwFlags,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
)
{
    return 0;
}

//00007FF9278F1F60 48 89 5C 24 08       mov         qword ptr[rsp + 8], rbx
//00007FF9278F1F65 48 89 6C 24 10       mov         qword ptr[rsp + 10h], rbp
//00007FF9278F1F6A 48 89 74 24 18       mov         qword ptr[rsp + 18h], rsi
//00007FF9278F1F6F 48 89 7C 24 20       mov         qword ptr[rsp + 20h], rdi
//00007FF9278F1F74 41 56                push        r14
//00007FF9278F1F76 48 83 EC 70          sub         rsp, 70h
//00007FF9278F1F7A 48 8B 05 7F 00 05 00 mov         rax, qword ptr[7FF927942000h]
//00007FF9278F1F81 48 8B F9             mov         rdi, rcx
//00007FF9278F1F84 48 8D 0D 85 CF 00 00 lea         rcx, [7FF9278FEF10h]
//00007FF9278F1F8B 49 8B F1             mov         rsi, r9
//00007FF9278F1F8E 41 8B E8             mov         ebp, r8d
//00007FF9278F1F91 4C 8B F2             mov         r14, rdx
//00007FF9278F1F94 48 3B C1             cmp         rax, rcx


//00007FF72910D380 4C 89 4C 24 20       mov         qword ptr[rsp + 20h], r9
//00007FF72910D385 44 89 44 24 18       mov         dword ptr[rsp + 18h], r8d
//00007FF72910D38A 48 89 54 24 10       mov         qword ptr[rsp + 10h], rdx
//00007FF72910D38F 48 89 4C 24 08       mov         qword ptr[rsp + 8], rcx
//00007FF72910D394 55                   push        rbp
//00007FF72910D395 57                   push        rdi
//00007FF72910D396 48 81 EC E8 00 00 00 sub         rsp, 0E8h
//00007FF72910D39D 48 8D 6C 24 20       lea         rbp, [rsp + 20h]
//00007FF72910D3A2 48 8D 0D 14 81 04 00 lea         rcx, [__161E9A2B_main@cpp(07FF7291554BDh)]
//00007FF72910D3A9 E8 E3 6A FD FF       call        __CheckForDebuggerJustMyCode(07FF7290E3E91h)
int _WSASend(
    _In_ SOCKET s,
    _In_reads_(dwBufferCount) LPWSABUF lpBuffers,
    _In_ DWORD dwBufferCount,
    _Out_opt_ LPDWORD lpNumberOfBytesSent,
    _In_ DWORD dwFlags,
    _Inout_opt_ LPWSAOVERLAPPED lpOverlapped,
    _In_opt_ LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
)
{
    return 0;
}


int main(int argc, char* argv[])
{
    _WSASend(0, 0, 0, 0, 0, 0, 0);

    Custom_WSASend(0, 0, 0, 0, 0, 0, 0);

    WSASend(0, 0, 0, 0, 0, 0, 0);


    DWORD id = GetCurrentProcessId();
    auto handle = OpenProcess(PROCESS_ALL_ACCESS, TRUE, id);

    auto pFunc = (uint8_t*)WSASend;

    SIZE_T d = 0;
    BYTE p[] = { 0xcc }; //0xcc=int 3            
    //BYTE* p = (BYTE*)Custom_WSASend;

    ::WriteProcessMemory(handle, (void*)pFunc, p, sizeof(p), &d);


    TCryptoAES_Impl sendCrypter;
    TCryptoAES_Impl recvCrypter;

    std::string key = "12345678";

    TContainer keyHash;
    TSHA256 hasher;
    hasher.FastCalc((void*)key.c_str(), key.size(), keyHash);

    sendCrypter.SetKey(keyHash.GetPtr(), keyHash.GetSize());
    recvCrypter.SetKey(keyHash.GetPtr(), keyHash.GetSize());

    try {
        boost::asio::io_context io_context;

        tcp::socket s(io_context);
        tcp::resolver resolver(io_context);
        boost::asio::connect(s, resolver.resolve("localhost", "12345"));

        while (true) {

            std::cout << "Enter message: ";
            char request[max_length];
            std::cin.getline(request, max_length);
            size_t request_length = std::strlen(request);

            TContainer encrypted;
            sendCrypter.Encrypt((void*)request, request_length, encrypted);

            boost::asio::write(s, boost::asio::buffer(encrypted.GetPtr(), encrypted.GetSize()));

            char reply[max_length];
            boost::system::error_code error;
            size_t length = s.read_some(boost::asio::buffer(reply), error);
            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw boost::system::system_error(error); // Some other error.

            TContainer decrypted;
            recvCrypter.Decrypt((void*)reply, length, decrypted);

            std::string recvMsg(decrypted.GetPtr(), decrypted.GetSize());

            std::cout << "Reply is: ";
            std::cout << recvMsg;
            std::cout << "\n";
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}