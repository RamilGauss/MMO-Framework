/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CallFinder.h"

namespace nsWinApiHelper
{
    void SetupCallOperand(uint8_t* buffer, const int32_t value)
    {
        const uint8_t* pValue = (const uint8_t*)&value;

        std::memcpy(&buffer[0], &pValue[0], sizeof(int32_t));
    }
    //-----------------------------------------------------------------------------------------
    std::list<void*> TCallFinder::Find(const std::list<TPageInfo>& pages, void* pFunc)
    {
        // FF 15 xx xx xx xx
        // E8 xx xx xx xx

        const int OPERAND_CALL_SIZE = 5;

        std::list<void*> callPlaces;

        for (auto& page : pages) {

            const uint8_t* currentPtr = static_cast<const uint8_t*>(page.ptr);

            while (true) {

                auto isOutOfRange = currentPtr >= (uint8_t*)page.GetEnd() - OPERAND_CALL_SIZE + 1;
                if (isOutOfRange) {
                    break;
                }

                int32_t shift = (int32_t)((int64_t)pFunc - (int64_t)currentPtr) - 5;

                uint8_t operandCall[OPERAND_CALL_SIZE] = { 0xE8 };

                SetupCallOperand(&operandCall[1], shift);

                if (currentPtr[0] == 0xE8) {
                    auto cmpResult = std::memcmp(&operandCall[0], currentPtr, OPERAND_CALL_SIZE);
                    if (cmpResult == 0) {
                        callPlaces.push_back((void*)currentPtr);
                        currentPtr += OPERAND_CALL_SIZE;
                    } else {
                        currentPtr++;
                    }
                } else {
                    currentPtr++;
                }
            }
        }

        return callPlaces;
    }
}