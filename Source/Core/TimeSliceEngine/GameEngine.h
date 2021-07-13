/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <vector>
#include <memory>
#include <string>

#include "CallBackRegistrator.h"
#include "SynchroPoint.h"
#include "DeveloperTool_DLL.h"

class ILoaderDLL;
class IDevTool;
class TThreadModules;
class IModule;

class DllExport TGameEngine
{
    const std::string sName = "GameEngine";
    const int sVersion = 9;// надеюсь последняя версия :)
    const std::string sModeWork = "Single thread mode";

    ILoaderDLL* mLoaderDLL;

    FuncGetDevTool  mGetDevTool;
    FuncFreeDevTool mFreeDevTool;

    typedef std::vector<std::string> TVecStr;
    TVecStr mModuleNameList;

    typedef std::vector<IModule*> TVecPtrModule;
    TVecPtrModule mModulePtrList;

    IDevTool* mDevTool;

    std::shared_ptr<TSynchroPoint> mSynchroPoint;
public:
    TGameEngine();

    void Work(int variant_use, std::string& sNameDLL, std::vector<std::string>& vecParam);// начало работы
    std::string GetVersion();
private:
    void Init();
    bool LoadDLL(int variant_use, std::string& sNameDLL);

    bool CreateModules();
    bool PrepareConveyer();
    void LinkModulesToSynchroPoint();

    void Work();
private:
    void Done();
    void Event(int id, std::string param = "");
};
