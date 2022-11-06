/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ImGuiSerializeTask.h"

namespace nsTornadoEngine
{
    class DllExport IImGuiSerializer
    {
    public:
        virtual ~IImGuiSerializer() {}

        virtual void Serialize(void* p, TImGuiSerializeTask*& pTask, int rtti) = 0;
        virtual void Deserialize(void* p, TImGuiSerializeTask* pTask, int rtti) = 0;
    };

    /*
    Example for generated code

    class DllExport TImGuiSerializer
    {
    public:
        template <typename Type>
        static void Serialize(const Type* p, TImGuiSerializeTask*& pTask);

        template <typename Type>
        static bool Deserialize(Type*& p, const TImGuiSerializeTask* pTask);

    private:
        static void Serialize(const TSomeType* p, TImGuiSerializeTask*& pTask, bool isRoot);
        static bool Deserialize(TSomeType*& p, const TImGuiSerializeTask* pTask, bool isRoot);
    };
    */
}