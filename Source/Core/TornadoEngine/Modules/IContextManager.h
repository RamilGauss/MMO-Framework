/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <string>
#include "TypeDef.h"

namespace nsTornadoEngine
{
    template <typename ContextType>
    class DllExport IContextManager
    {
        int mReferenceCount = 0;
        std::map<std::string, ContextType*> mGuidCtxMap;
    public:
        ContextType* GetContext(const std::string& guid)
        {
            auto fit = mGuidCtxMap.find(guid);
            if (fit == mGuidCtxMap.end()) {
                return nullptr;
            }
            return fit->second;
        }

        void OnAdd(const std::string& guid)
        {
            if (GetReferenceCount() == 0) {
                auto pCtx = CreateContext();
                mGuidCtxMap.insert({guid, pCtx});
            }
            IncrementReference();
        }

        void OnRemove(const std::string& guid)
        {
            DecrementReference();
            if (GetReferenceCount() == 0) {
                auto pCtx = GetContext(guid);
                DestroyContext(pCtx);
                mGuidCtxMap.erase(guid);
            }
        }
    protected:
        virtual ContextType* CreateContext() = 0;
        virtual void DestroyContext(ContextType* pCtx) = 0;

        void IncrementReference() { mReferenceCount++; }
        void DecrementReference() { mReferenceCount--; }
        int GetReferenceCount() const { return mReferenceCount; }
    };
}