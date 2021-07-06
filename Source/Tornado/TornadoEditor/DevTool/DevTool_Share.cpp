/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DevTool_Share.h"
#include "ListModules.h"

#include "Components.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "ModuleMMOEngineClient.h"
#include "ModuleMMOEngineSlave.h"
#include "ModuleMMOEngineMaster.h"
#include "ModuleMMOEngineSuperServer.h"
#include "ModulePhysicEngine.h"
#include "ModuleSoundEngine.h"
#include "ModuleTimer.h"
#include "ModuleDatabase.h"

#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"
#include "EventGameEngine.h"

#include "MakerXML.h"
#include "IXML.h"
#include "TextFile.h"
#include "ShareDevJsonSerializer.h"

#ifndef WIN32
#include <unistd.h>
#endif

namespace nsDevTool_Share
{
    // для именования модулей в конвейере для Ядра
    // сделано так с целью присутствия в коде имени модуля единожды
#define NAME_MODULE(enumID) ""#enumID

#define NAME_ID(X) NAME_MODULE(X),X

    const char* sFileResources = "Resources.json";

    const char* sConveyer = "Conveyer";
    const char* sItems = "Items";
    const char* sSettings = "Settings";
}

using namespace nsListModules;

TDevTool_Share::TDevTool_Share()
{
    InitMapModules();
}
//-----------------------------------------------------------------------
TDevTool_Share::~TDevTool_Share()
{
    // уничтожить все модули
    for ( auto& vtID_Ptr : mMapID_PtrModules ) {
        delete vtID_Ptr.second;
    }
}
//-----------------------------------------------------------------------
void TDevTool_Share::Init()
{
    std::string file = nsDevTool_Share::sFileResources;

    std::string str;
    TTextFile::Load(file, str);
    if ( str.length() == 0 ) {
        return;
    }

    TFrameworkResources frameworkResources;
    std::string err;
    nsShareDev::TShareDevJsonSerializer::Deserialize(&frameworkResources, str, err);

    mTerrainPath = frameworkResources.graphicEngine.terrainPath;
    mPluginsCfg = frameworkResources.graphicEngine.pluginsCfg.Get();
    mOgreCfg = frameworkResources.graphicEngine.ogreCfg.Get();

    mMapRGame = frameworkResources.game.resources;
    mMapRGameEngine = frameworkResources.gameEngine.resources;
    mMapRGUI = frameworkResources.gui.resources;
    mMapRGraphicEngine = frameworkResources.graphicEngine.resources;

    FindPath_Game(nsDevTool_Share::sItems, 0, mPathItems);
    FindPath_Game(nsDevTool_Share::sSettings, 0, mPathSettings);
}
//-----------------------------------------------------------------------
IModule* TDevTool_Share::GetModuleByName(const std::string& sName)
{
    int id = FindIDByNameModule(sName);
    TModuleDev* pModule = FindPtrModuleByID(id);
    if ( pModule ) {
        return pModule;
    }

    pModule = GetModuleByID(id);
    pModule->SetID(id);
    pModule->SetName(sName);
    Add(id, pModule);
    return pModule;
}
//-----------------------------------------------------------------------
void TDevTool_Share::InitMapModules()
{
    Add(NAME_ID(GraphicEngine));
    Add(NAME_ID(MMOEngineClient));
    Add(NAME_ID(MMOEngineSlave));
    Add(NAME_ID(MMOEngineMaster));
    Add(NAME_ID(MMOEngineSuperServer));
    Add(NAME_ID(Logic));
    Add(NAME_ID(PhysicEngine));
    Add(NAME_ID(SoundEngine));
    Add(NAME_ID(DataBase));
    Add("Timer", ID_Modules::Timer);
}
//-----------------------------------------------------------------------
int TDevTool_Share::FindIDByNameModule(std::string name)
{
    TMapStrIntIt fit = mMapNameID_Modules.find(name);
    if ( fit == mMapNameID_Modules.end() ) {
        return ID_Modules::Undef;
    }
    return fit->second;
}
//-----------------------------------------------------------------------
TModuleDev* TDevTool_Share::FindPtrModuleByID(int id)
{
    TMapIntPtrModuleIt fit = mMapID_PtrModules.find(id);
    if ( fit == mMapID_PtrModules.end() ) {
        return nullptr;
    }
    return fit->second;
}
//-----------------------------------------------------------------------
void TDevTool_Share::Add(int id, TModuleDev* pModule)
{
    if ( pModule ) {
        mMapID_PtrModules.insert(TMapIntPtrModuleVT(id, pModule));
    }
}
//-----------------------------------------------------------------------
void TDevTool_Share::Add(std::string name, int id)
{
    mMapNameID_Modules.insert(TMapStrIntVT(name, id));
}
//-----------------------------------------------------------------------
std::string TDevTool_Share::GetFileDescConveyer()
{
    std::string pathConveyer;
    if ( FindPath_GameEngine(nsDevTool_Share::sConveyer, 0, pathConveyer) == true ) {
        return pathConveyer;
    }

    BL_FIX_BUG();
    return "";
}
//-----------------------------------------------------------------------
void TDevTool_Share::EventGameEngine(int id, const std::string& sDesc)
{
    switch ( id ) {
        case nsGameEngine::eAfterCreateDevTool:
            Init();
            break;
        case nsGameEngine::eAfterCreateModules:
            // назначить логике компоненты
            SetComponentsForLogic();
            break;
        case nsGameEngine::eStartThreads:
            break;
        case nsGameEngine::eStopThreads:
            break;
        case nsGameEngine::eStopThreadsEnd:
            break;
        case nsGameEngine::eParseFileConveyerError:
        case nsGameEngine::eModuleNotMade:
        case nsGameEngine::eThreadsNotExist:
            BL_MessageBug_Utf8(sDesc.data());
            break;
    }
}
//-----------------------------------------------------------------------
void TDevTool_Share::SetupGraphicEngine()
{
    // настройка перед запуском
    if ( mGE_ForSetup->GetGE()->InitOGRE(mPluginsCfg, mOgreCfg) == false ) {
        _exit(-1);// либо ошибка, либо пользователь не хочет запускать приложение
        return;
    }
    // пути для ресурсов графического движка
    for ( auto& vtTypePath : mMapRGraphicEngine ) {
        for ( auto& type : vtTypePath.second ) {
            mGE_ForSetup->GetGE()->AddResource(type, vtTypePath.first);
        }
    }

    // оболочка и ядро для GUI
    std::string sSkin, sCore;
    //FindPath_GUI(nsDevTool_Share::sCore, 0, sCore);
    //FindPath_GUI(nsDevTool_Share::sSkin, 0, sSkin);
    //BL_ASSERT(sCore.length() && sSkin.length());
    mGE_ForSetup->GetGE()->InitMyGUI(sCore, sSkin);
}
//-----------------------------------------------------------------------
void TDevTool_Share::SetComponentsForLogic()
{
    TComponents components;
    components.pGraphicEngine = (TModuleGraphicEngine*) FindPtrModuleByID(ID_Modules::GraphicEngine);
    components.pMMOEngineClient = (TModuleMMOEngineClient*) FindPtrModuleByID(ID_Modules::MMOEngineClient);
    components.pMMOEngineSlave = (TModuleMMOEngineSlave*) FindPtrModuleByID(ID_Modules::MMOEngineSlave);
    components.pMMOEngineMaster = (TModuleMMOEngineMaster*) FindPtrModuleByID(ID_Modules::MMOEngineMaster);
    components.pMMOEngineSuperServer = (TModuleMMOEngineSuperServer*) FindPtrModuleByID(ID_Modules::MMOEngineSuperServer);
    components.pPhysicEngine = (TModulePhysicEngine*) FindPtrModuleByID(ID_Modules::PhysicEngine);
    components.pSoundEngine = (TModuleSoundEngine*) FindPtrModuleByID(ID_Modules::SoundEngine);
    components.pDataBase = (TModuleDataBase*) FindPtrModuleByID(ID_Modules::DataBase);
    components.pTimer = (TModuleTimer*) FindPtrModuleByID(ID_Modules::Timer);

    // ищем логику
    TModuleLogic* pLogic = (TModuleLogic*) FindPtrModuleByID(ID_Modules::Logic);
    if ( pLogic ) {
        int id_logic = pLogic->GetID();
        components.SetLogicID(id_logic);
        pLogic->SetComponents(components);
        pLogic->GetFGI()->Init_XML(mPathItems);
#ifdef _DEBUG
        pLogic->GetFGI()->ReloadFromStorageAll_XML();
#else
        // карта сама по цепочке ("раскрутит") загрузит итэмы
        pLogic->GetFGI()->ReloadFromStorageByType_XML(TFactoryGameItem::Map);
        pLogic->GetFGI()->ReloadFromStorageByType_XML(TFactoryGameItem::Model);
        pLogic->GetFGI()->ReloadFromStorageByType_XML(TFactoryGameItem::Shape);
#endif
        pLogic->InitLog();
        pLogic->ParseCmd(mVecArg);

        // настройки приложения
        mSettings.Init(mPathSettings);
        std::string nameApp = GetVariantConveyer();
        if ( nameApp.length() )
            mSettings.BeginApplication(nameApp);
        else {
            BL_FIX_BUG();
        }
        pLogic->SetSettings(&mSettings);
    } else {
        BL_FIX_BUG();
    }
}
//-----------------------------------------------------------------------
void TDevTool_Share::SetVectorParam(std::vector<std::string>& vecArg)
{
    mVecArg = vecArg;
}
//-----------------------------------------------------------------------
TModuleDev* TDevTool_Share::GetModuleByID(int id)
{
    TModuleDev* pModule = nullptr;
    switch ( id ) {
        // ядро
        case ID_Modules::Logic: pModule = GetModuleLogic(); ((TModuleLogic*) pModule)->SetTerrainPath(mTerrainPath); break;
            // периферия
        case ID_Modules::GraphicEngine:
            mGE_ForSetup = new TModuleGraphicEngine;
            pModule = mGE_ForSetup;
            ((TModuleGraphicEngine*) pModule)->GetCBStartEvent()->Register(&TDevTool_Share::SetupGraphicEngine, this);
            break;
            //case GraphicEngine:          pModule = new TModuleGraphicEngine; SetupGraphicEngine((TModuleGraphicEngine*)pModule); break;
        case ID_Modules::PhysicEngine:           pModule = new TModulePhysicEngine;                        break;
        case ID_Modules::MMOEngineClient:        pModule = new TModuleMMOEngineClient;                     break;
        case ID_Modules::MMOEngineSlave:         pModule = new TModuleMMOEngineSlave;                      break;
        case ID_Modules::MMOEngineMaster:        pModule = new TModuleMMOEngineMaster;                     break;
        case ID_Modules::MMOEngineSuperServer:   pModule = new TModuleMMOEngineSuperServer;                break;
        case ID_Modules::SoundEngine:            pModule = new TModuleSoundEngine;                         break;
        case ID_Modules::DataBase:               pModule = new TModuleDataBase;                            break;
        case ID_Modules::Timer:                  pModule = new TModuleTimer;                               break;
        default:BL_FIX_BUG();
    }
    return pModule;
}
//-----------------------------------------------------------------------
int TDevTool_Share::GetCountPathInMap(const char* type, TStrStrListMap& mapResource)
{
    return mapResource.count(type);
}
//-----------------------------------------------------------------------
bool TDevTool_Share::FindPath(const char* type, TStrStrListMap& mapResource, int index, std::string& result)
{
    auto fit = mapResource.find(type);
    if ( fit == mapResource.end() ) {
        return false;
    }
    for ( int i = 0; i < index; i++ ) {
        fit++;
        if ( fit == mapResource.end() ) {
            return false;
        }
    }
    result = *(fit->second.begin());
    return true;
}
//-----------------------------------------------------------------------
int TDevTool_Share::GetCountPathInMap_Game(const char* type)
{
    return GetCountPathInMap(type, mMapRGame);
}
//-----------------------------------------------------------------------
bool TDevTool_Share::FindPath_Game(const char* type, int index, std::string& result)
{
    return FindPath(type, mMapRGame, index, result);
}
//-----------------------------------------------------------------------
int TDevTool_Share::GetCountPathInMap_GUI(const char* type)
{
    return GetCountPathInMap(type, mMapRGUI);
}
//-----------------------------------------------------------------------
bool TDevTool_Share::FindPath_GUI(const char* type, int index, std::string& result)
{
    return FindPath(type, mMapRGUI, index, result);
}
//-----------------------------------------------------------------------
int TDevTool_Share::GetCountPathInMap_GameEngine(const char* type)
{
    return GetCountPathInMap(type, mMapRGameEngine);
}
//-----------------------------------------------------------------------
bool TDevTool_Share::FindPath_GameEngine(const char* type, int index, std::string& result)
{
    return FindPath(type, mMapRGameEngine, index, result);
}
//-----------------------------------------------------------------------
int TDevTool_Share::GetCountPathInMap_GraphicEngine(const char* type)
{
    return GetCountPathInMap(type, mMapRGraphicEngine);
}
//-----------------------------------------------------------------------
bool TDevTool_Share::FindPath_GraphicEngine(const char* type, int index, std::string& result)
{
    return FindPath(type, mMapRGraphicEngine, index, result);
}
//-----------------------------------------------------------------------
