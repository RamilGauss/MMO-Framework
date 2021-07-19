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

class DllExport TTimeSliceEngine
{
    const std::string sName = "TimeSliceEngine";

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
    TTimeSliceEngine();

    void Work(std::string& sNameDLL, std::vector<std::string>& vecParam);// начало работы
private:
    void Init();
    bool LoadDLL(std::string& sNameDLL);

    bool CreateModules();
    bool PrepareConveyer();

    void Work();
private:
    void Done();
};
