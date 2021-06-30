#include <iostream>

#include "CryptoAES_Impl.h"

int main(int argc, char** argv)
{
    TCryptoAES_Impl src;
    src.GenerateKey();
    TContainerRise key;
    src.GetKey(key);

    TContainer encrypted;

    std::string str = "1234567890";

    auto resEncrypt = src.Encrypt((void*) str.data(), str.length(), encrypted);

    TCryptoAES_Impl dst;
    dst.SetKey(key.GetPtr(), key.GetSize());

    TContainerRise decrypted;
    auto resDecrypt = dst.Decrypt(encrypted.GetPtr(), encrypted.GetSize(), decrypted);

    return 0;
}

