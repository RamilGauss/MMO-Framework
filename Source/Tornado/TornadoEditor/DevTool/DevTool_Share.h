/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>

#include "IDevTool.h"
#include "CallBackRegistrator.h"
#include "Settings.h"
#include "FrameworkResources.h"

class TModuleLogic;
class TModuleDev;
class TModuleGraphicEngine;

class TDevTool_Share : public IDevTool
{
    typedef std::map<std::string, int> TMapStrInt;
    typedef TMapStrInt::value_type    TMapStrIntVT;
    typedef TMapStrInt::iterator      TMapStrIntIt;
    TMapStrInt mMapNameID_Modules;

    typedef std::map<int, TModuleDev*>    TMapIntPtrModule;
    typedef TMapIntPtrModule::value_type TMapIntPtrModuleVT;
    typedef TMapIntPtrModule::iterator   TMapIntPtrModuleIt;
    TMapIntPtrModule mMapID_PtrModules;

    std::string mTerrainPath;
    std::string mPluginsCfg;
    std::string mOgreCfg;
    std::string mPathItems;
    std::string mPathSettings;

    TStrStrListMap mMapRGame;
    TStrStrListMap mMapRGUI;
    TStrStrListMap mMapRGameEngine;
    TStrStrListMap mMapRGraphicEngine;

    std::vector<std::string> mVecArg;

    TSettings mSettings;

    TModuleGraphicEngine* mGE_ForSetup = nullptr;
public:
    TDevTool_Share();
    virtual ~TDevTool_Share();

    virtual void SetVectorParam(std::vector<std::string>& vecArg);
    virtual std::string GetFileDescConveyer();
    virtual IModule* GetModuleByName(const std::string& sName);
    virtual void EventGameEngine(int id, const std::string& sDesc);
protected:
    virtual TModuleDev* GetModuleByID(int id);
    virtual TModuleDev* GetModuleLogic() = 0;
protected:
    void InitMapModules();
    // навигация
    int FindIDByNameModule(std::string name);
    TModuleDev* FindPtrModuleByID(int id);

    void Add(int id, TModuleDev* pModule);
    void Add(std::string name, int id);
protected:
    int GetCountPathInMap(const char* path, TStrStrListMap& mapResource);
    bool FindPath(const char* path, TStrStrListMap& mapResource,
        int index, std::string& result);
private:
    // Resource map{Type,Path}
    int GetCountPathInMap_Game(const char* type);
    bool FindPath_Game(const char* type, int index, std::string& result);

    int GetCountPathInMap_GUI(const char* type);
    bool FindPath_GUI(const char* type, int index, std::string& result);

    int GetCountPathInMap_GameEngine(const char* type);
    bool FindPath_GameEngine(const char* type, int index, std::string& result);

    int GetCountPathInMap_GraphicEngine(const char* type);
    bool FindPath_GraphicEngine(const char* type, int index, std::string& result);
private:
    void SetupGraphicEngine();

private:
    // реакции на события
    void Init();
    void SetComponentsForLogic();
};
