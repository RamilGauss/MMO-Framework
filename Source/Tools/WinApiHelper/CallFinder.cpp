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


#include "CallFinder.h"

namespace nsWinApiHelper
{
    void SetupCallOpcode(uint8_t* buffer, const int32_t value)
    {
        const uint8_t* pValue = (const uint8_t*)&value;

        std::memcpy(&buffer[0], &pValue[0], sizeof(int32_t));
    }
    //-----------------------------------------------------------------------------------------
    std::list<void*> TCallFinder::Find(const std::list<TPageInfo>& pages, void* pFunc)
    {
        std::list<void*> callPlaces;

        FindAbsoluteCall(pages, pFunc, callPlaces);

        FindRelativeCall(pages, pFunc, callPlaces);

        return callPlaces;
    }
    //-----------------------------------------------------------------------------------------
    void TCallFinder::FindAbsoluteCall(const std::list<TPageInfo>& pages, void* pFunc, std::list<void*>& callPlaces)
    {
        uint32_t ADDRESS_SIZE = sizeof(void*);

        void* pAddressFunc = nullptr;

        for (auto& page : pages) {

            const uint8_t* currentPtr = static_cast<const uint8_t*>(page.ptr);

            for (size_t i = 0; i < page.size; i++, currentPtr++) {

                auto isOutOfRange = (currentPtr > (uint8_t*)page.GetEnd() - ADDRESS_SIZE);
                if (isOutOfRange) {
                    break;
                }

                auto cmpResult = std::memcmp((const uint8_t*)&pFunc, currentPtr, ADDRESS_SIZE);
                if (cmpResult == 0) {
                    pAddressFunc = (void*)currentPtr;
                    break;
                }
            }
            
            if (pAddressFunc != nullptr) {
                break;
            }
        }

        // FF 15 xx xx xx xx
        const int OPERAND_CALL_SIZE = 6;

        for (auto& page : pages) {

            const uint8_t* currentPtr = static_cast<const uint8_t*>(page.ptr);

            for (size_t i = 0; i < page.size; i++, currentPtr++) {

                auto isOutOfRange = (currentPtr > (uint8_t*)page.GetEnd() - OPERAND_CALL_SIZE);
                if (isOutOfRange) {
                    break;
                }

                int32_t shift = (int32_t)((int64_t)pAddressFunc - (int64_t)currentPtr) - OPERAND_CALL_SIZE;

                uint8_t operandCall[OPERAND_CALL_SIZE] = { 0xFF, 0x15 };

                SetupCallOpcode(&operandCall[2], shift);

                if (currentPtr[0] == 0xFF && currentPtr[1] == 0x15) {
                    auto cmpResult = std::memcmp(&operandCall[0], currentPtr, OPERAND_CALL_SIZE);
                    if (cmpResult == 0) {
                        callPlaces.push_back((void*)currentPtr);
                    }
                }
            }
        }
    }
    //-----------------------------------------------------------------------------------------
    void TCallFinder::FindRelativeCall(const std::list<TPageInfo>& pages, void* pFunc, std::list<void*>& callPlaces)
    {
        // E8 xx xx xx xx

        const int OPERAND_CALL_SIZE = 5;

        for (auto& page : pages) {

            const uint8_t* currentPtr = static_cast<const uint8_t*>(page.ptr);

            for (size_t i = 0; i < page.size; i++, currentPtr++) {

                auto isOutOfRange = (currentPtr > (uint8_t*)page.GetEnd() - OPERAND_CALL_SIZE);
                if (isOutOfRange) {
                    break;
                }

                int32_t shift = (int32_t)((int64_t)pFunc - (int64_t)currentPtr) - OPERAND_CALL_SIZE;

                uint8_t operandCall[OPERAND_CALL_SIZE] = { 0xE8 };

                SetupCallOpcode(&operandCall[1], shift);

                if (currentPtr[0] == 0xE8) {
                    auto cmpResult = std::memcmp(&operandCall[0], currentPtr, OPERAND_CALL_SIZE);
                    if (cmpResult == 0) {
                        callPlaces.push_back((void*)currentPtr);
                    }
                }
            }
        }
    }
    //-----------------------------------------------------------------------------------------
}