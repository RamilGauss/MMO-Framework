/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <set>
#include <list>
#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/ColanderVector.h"

#include "TornadoEngine/Modules/Common/IContext.h"

namespace nsTornadoEngine
{
    class DllExport IContextManager
    {
        TColanderVector<IContext*> mCtxs;
    public:
        IContext* GetContext(int index);
        void TryAdd(int index);
        void OnRemove(int index);
        void CleanUp();
    protected:
        virtual IContext* CreateContext() = 0;
        virtual void DestroyContext(IContext* pCtx) = 0;
    private:
        TColanderVector<IContext*> mRemovedCtxs;

        std::list<int> mRemovedIndexes;
    };
}