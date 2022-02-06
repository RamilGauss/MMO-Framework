/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IContextManager.h"
#include "BL_Debug.h"

using namespace nsTornadoEngine;

IContext* IContextManager::GetContext(int index)
{
    return mCtxs[index];
}
//-------------------------------------------------------------------------------------------
void IContextManager::TryAdd(int index)
{
    IContext* pCtx = GetContext(index);
    if (pCtx == nullptr) {
        pCtx = CreateContext();
        mCtxs[index] = pCtx;
    }
    pCtx->IncrementReference();
}
//-------------------------------------------------------------------------------------------
void IContextManager::OnRemove(int index)
{
    IContext* pCtx = GetContext(index);
    BL_ASSERT(pCtx != nullptr);
    pCtx->DecrementReference();


    if (mRemovedCtxs[index] == nullptr) {
        mRemovedCtxs[index] = pCtx;
        mRemovedIndexes.push_back(index);
    }
}
//-------------------------------------------------------------------------------------------
void IContextManager::CleanUp()
{
    for (auto& index : mRemovedIndexes) {
        mRemovedCtxs[index] = nullptr;// clear

        IContext* pCtx = GetContext(index);
        BL_ASSERT(pCtx != nullptr);
        if (pCtx->GetReferenceCount() == 0) {
            DestroyContext(pCtx);
            mCtxs[index] = nullptr;
        }
    }
    mRemovedIndexes.clear();
}
//-------------------------------------------------------------------------------------------
