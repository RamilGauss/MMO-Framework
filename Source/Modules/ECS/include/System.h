/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "EntityManager.h"

namespace nsECSFramework
{
    class DllExport TSystem
    {
    protected:
        TEntityManager* mEntMng = nullptr;
    public:
        virtual ~TSystem();

        virtual void SetEntMng(TEntityManager* entMng);
        TEntityManager* GetEntMng();

        virtual bool IsInit()     const { return false; }
        virtual bool IsExecute()  const { return false; }
        virtual bool IsTearDown() const { return false; }
        virtual bool IsFeature()  const { return false; }

        const std::string& GetTypeName() const;
    };
}
