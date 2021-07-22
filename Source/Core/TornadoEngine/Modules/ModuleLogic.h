/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>

#include "ModuleDev.h"
#include "Components.h"

class TSettings;

class DllExport TModuleLogic : public TModuleDev
{
    volatile bool flgNeedExit;

    std::string mTerrainPath;

    TSettings* mPtrSettings;
protected:
    TComponents      mComp;

    std::set<int> mSetUseID_Module;
public:
    TModuleLogic();
    virtual void ParseCmd(std::vector<std::string>& arg) = 0;
    virtual void InitLog();

    std::set<int> GetUseID_Module();

    void SetTerrainPath(std::string& path);
    std::string GetTerrainPath();

    void SetComponents(TComponents components);
    TComponents* GetC();

    // оставить, потому что не только GUI использует, но и другие объекты из ShareDev
    // которые не знают про GameImpl
    static TModuleLogic* Get();

    void Exit(int reason = 0);

    void SetSettings(TSettings* pSettings);
    TSettings* GetSettings();
protected:
    bool NeedExit();
};
