/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <stddef.h>
#include <stdarg.h>

#include "TimeSliceEngine.h"
#include "BL_Debug.h"
#include "ShareMisc.h"
#include "HiTimer.h"
#include "Logger.h"
#include "IModule.h"
#include "FileOperation.h"
#include "IDevTool.h"
#include "ConveyerFileParser.h"
#include "MakerLoaderDLL.h"
#include "ILoaderDLL.h"

#include "fmt/core.h"

TTimeSliceEngine::TTimeSliceEngine()
{
    mSynchroPoint.reset(new TSynchroPoint);

    TMakerLoaderDLL maker;
    mLoaderDLL = maker.New();

    mGetDevTool = nullptr;
    mFreeDevTool = nullptr;
    mDevTool = nullptr;

    Init();
}
//----------------------------------------------------------------------
void TTimeSliceEngine::Done()
{
    if (mFreeDevTool) {
        mFreeDevTool(mDevTool);
    }

    mSynchroPoint.reset();

    TMakerLoaderDLL maker;
    maker.Delete(mLoaderDLL);

    GetLogger()->Done();
}
//----------------------------------------------------------------------
bool TTimeSliceEngine::LoadDLL(std::string& sNameDLL)
{
    if (mLoaderDLL->Init(sNameDLL.data()) == false) {
        GetLogger(sName)->WriteF_time("LoadDLL() FAIL init.\n");
        return false;
    }
    mFreeDevTool = (FuncFreeDevTool) mLoaderDLL->Get(StrFreeDevTool);
    if (mFreeDevTool == nullptr) {
        GetLogger(sName)->WriteF_time("LoadDLL() FAIL load FuncFree.\n");
        return false;
    }
    mGetDevTool = (FuncGetDevTool) mLoaderDLL->Get(StrGetDevTool);
    if (mGetDevTool == nullptr) {
        GetLogger(sName)->WriteF_time("LoadDLL() FAIL load FuncGetdevTool.\n");
        return false;
    }
    if (mDevTool != nullptr) {
        GetLogger(sName)->WriteF_time("LoadDLL() warning, object was loaded.\n");
        return true;
    }
    mDevTool = mGetDevTool();
    if (mDevTool == nullptr) {// нет DLL - нет движка.
        return false;
    }
    return true;
}
//----------------------------------------------------------------------
void TTimeSliceEngine::Init()
{
    GetLogger()->Done();
    GetLogger()->Register(sName);
}
//------------------------------------------------------------------------
void TTimeSliceEngine::Work(std::string& sNameDLL, std::vector<std::string>& vecParam)// начало работы
{
    if (LoadDLL(sNameDLL) == false) {
        return;
    }
    mDevTool->SetVectorParam(vecParam);
    // подготовка конвейера
    if (PrepareConveyer() == false) {
        return;
    }
    if (CreateModules() == false) {
        return;
    }

    Work();
    // чистка
    Done();
}
//------------------------------------------------------------------------
void TTimeSliceEngine::Work()
{
    for (auto& pModule : mModulePtrList) {
        pModule->StartEvent();
    }

    bool needStop = false;
    while (!needStop) {
        for (auto& pModule : mModulePtrList) {
            if (pModule->Work() == false) {
                needStop = true;
            }
        }
    }

    for (auto& pModule : mModulePtrList) {
        pModule->StopEvent();
    }
}
//------------------------------------------------------------------------
bool TTimeSliceEngine::PrepareConveyer()
{
    auto sFileDescConveyer = mDevTool->GetFileDescConveyer();
    TConveyerFileParser parser;
    if (parser.Parse(sFileDescConveyer)) {
        mModuleNameList = parser.GetResult();
    }
    if (mModuleNameList.size() > 0) {
        return true;
    }
    return false;
}
//------------------------------------------------------------------------
bool TTimeSliceEngine::CreateModules()
{
    for (auto& moduleName : mModuleNameList) {
        IModule* pModule = mDevTool->GetModuleByName(moduleName);
        if (pModule != nullptr) {
            mModulePtrList.push_back(pModule);
        } else {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------
