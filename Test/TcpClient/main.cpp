/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <string>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

#include "SHA256.h"
#include "CryptoAES_Impl.h"

//TCryptoAES_Impl crypter;

//std::string key = "12345678";

//TContainer keyHash;
//TSHA256 hasher;
//hasher.FastCalc((void*)key.c_str(), key.size(), keyHash);

//crypter.SetKey(keyHash.GetPtr(), keyHash.GetSize());
//TContainer encrypted;

//std::string msg = "1234567890abcdef";

//crypter.Encrypt((void*)msg.c_str(), msg.size(), encrypted);

//TContainer decrypted;
//crypter.Decrypt(encrypted.GetPtr(), encrypted.GetSize(), decrypted);



#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

enum { max_length = 1024 };

int main(int argc, char* argv[])
{
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