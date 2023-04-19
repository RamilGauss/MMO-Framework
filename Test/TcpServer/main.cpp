/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <cstdlib>
#include <iostream>
#include <thread>
#include <utility>
#include <boost/asio.hpp>

#include "SHA256.h"
#include "CryptoAES_Impl.h"

using boost::asio::ip::tcp;

const int max_length = 1024;

void session(tcp::socket sock)
{
    int counter = 0;

    TCryptoAES_Impl sendCrypter;
    TCryptoAES_Impl recvCrypter;

    std::string key = "12345678";

    TContainer keyHash;
    TSHA256 hasher;
    hasher.FastCalc((void*)key.c_str(), key.size(), keyHash);

    sendCrypter.SetKey(keyHash.GetPtr(), keyHash.GetSize());
    recvCrypter.SetKey(keyHash.GetPtr(), keyHash.GetSize());

    try {
        for (;;) {
            char data[max_length];

            boost::system::error_code error;
            size_t length = sock.read_some(boost::asio::buffer(data), error);
            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw boost::system::system_error(error); // Some other error.

            TContainer decrypted;
            recvCrypter.Decrypt((void*)data, length, decrypted);

            std::string recvMsg(decrypted.GetPtr(), decrypted.GetSize());

            std::cout << recvMsg << std::endl;

            std::string sendMsg = std::to_string(counter) + ": " + recvMsg;

            TContainer encrypted;
            sendCrypter.Encrypt((void*)sendMsg.c_str(), sendMsg.size(), encrypted);

            boost::asio::write(sock, boost::asio::buffer(encrypted.GetPtr(), encrypted.GetSize()));

            counter++;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void server(boost::asio::io_context& io_context, unsigned short port)
{
    tcp::acceptor a(io_context, tcp::endpoint(tcp::v4(), port));
    for (;;) {
        std::thread(session, a.accept()).detach();
    }
}

int main(int argc, char* argv[])
{
    try {
        boost::asio::io_context io_context;

        server(io_context, 12345);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}