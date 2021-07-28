///*
//Author: Gudakov Ramil Sergeevich a.k.a. Gauss
//Гудаков Рамиль Сергеевич
//Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
//See for more information LICENSE.md.
//*/
//
//#include "DevTool_Share.h"
//
//#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"
//
//#include "TextFile.h"
//#include "ShareDevJsonSerializer.h"
//
//#ifndef WIN32
//#include <unistd.h>
//#endif
//
//using namespace nsTornadoEngine;
//
//TDevTool_Share::TDevTool_Share()
//{
//    InitMapModules();
//}
////-----------------------------------------------------------------------
//void TDevTool_Share::Init()
//{
//    std::string file = nsDevTool_Share::sFileResources;
//
//    std::string str;
//    TTextFile::Load(file, str);
//    if (str.length() == 0) {
//        return;
//    }
//
//    TFrameworkResources frameworkResources;
//    std::string err;
//    nsTornadoEngine::TShareDevJsonSerializer::Deserialize(&frameworkResources, str, err);
//
//    mTerrainPath = frameworkResources.graphicEngine.terrainPath;
//    mPluginsCfg = frameworkResources.graphicEngine.pluginsCfg.Get();
//    mOgreCfg = frameworkResources.graphicEngine.ogreCfg.Get();
//
//    mMapRGame = frameworkResources.game.resources;
//    mMapRGameEngine = frameworkResources.gameEngine.resources;
//    mMapRGUI = frameworkResources.gui.resources;
//    mMapRGraphicEngine = frameworkResources.graphicEngine.resources;
//
//    FindPath_Game(nsDevTool_Share::sItems, 0, mPathItems);
//    FindPath_Game(nsDevTool_Share::sSettings, 0, mPathSettings);
//}
////-----------------------------------------------------------------------
//IModule* TDevTool_Share::GetModuleByName(const std::string& sName)
//{
//    int id = FindIDByNameModule(sName);
//    IModule* pModule = FindPtrModuleByID(id);
//    if (pModule) {
//        return pModule;
//    }
//
//    pModule = GetModuleByID(id);
//    Add(id, pModule);
//    return pModule;
//}
////-----------------------------------------------------------------------
//int TDevTool_Share::FindIDByNameModule(std::string name)
//{
//    TMapStrIntIt fit = mMapNameID_Modules.find(name);
//    if (fit == mMapNameID_Modules.end()) {
//        return ID_Modules::Undef;
//    }
//    return fit->second;
//}
////-----------------------------------------------------------------------
//IModule* TDevTool_Share::FindPtrModuleByID(int id)
//{
//    TMapIntPtrModuleIt fit = mMapID_PtrModules.find(id);
//    if (fit == mMapID_PtrModules.end()) {
//        return nullptr;
//    }
//    return fit->second;
//}
////-----------------------------------------------------------------------
//void TDevTool_Share::Add(int id, IModule* pModule)
//{
//    if (pModule) {
//        mMapID_PtrModules.insert(TMapIntPtrModuleVT(id, pModule));
//    }
//}
////-----------------------------------------------------------------------
//void TDevTool_Share::Add(std::string name, int id)
//{
//    mMapNameID_Modules.insert(TMapStrIntVT(name, id));
//}
////-----------------------------------------------------------------------
//std::string TDevTool_Share::GetFileDescConveyer()
//{
//    std::string pathConveyer;
//    if (FindPath_GameEngine(nsDevTool_Share::sConveyer, 0, pathConveyer) == true) {
//        return pathConveyer;
//    }
//
//    BL_FIX_BUG();
//    return "";
//}
////-----------------------------------------------------------------------
//void TDevTool_Share::SetupGraphicEngine(TModuleGraphicEngine* pGraphicModule)
//{
//    // настройка перед запуском
//    if (pGraphicModule->GetGE()->InitOGRE(mPluginsCfg, mOgreCfg) == false) {
//        _exit(-1);// либо ошибка, либо пользователь не хочет запускать приложение
//        return;
//    }
//    // пути для ресурсов графического движка
//    for (auto& vtTypePath : mMapRGraphicEngine) {
//        for (auto& type : vtTypePath.second) {
//            pGraphicModule->GetGE()->AddResource(type, vtTypePath.first);
//        }
//    }
//
//    pGraphicModule->GetGE()->InitMyGUI();
//}
////-----------------------------------------------------------------------
//void TDevTool_Share::SetComponentsForLogic()
//{
//    TComponents components;
//    components.pGraphicEngine = (TModuleGraphicEngine*) FindPtrModuleByID(ID_Modules::GraphicEngine);
//    components.pMMOEngineClient = (TModuleMMOEngineClient*) FindPtrModuleByID(ID_Modules::MMOEngine);
//    components.pPhysicEngine = (TModulePhysicEngine*) FindPtrModuleByID(ID_Modules::PhysicEngine);
//    components.pSoundEngine = (TModuleSoundEngine*) FindPtrModuleByID(ID_Modules::SoundEngine);
//    components.pDataBase = (TModuleDataBase*) FindPtrModuleByID(ID_Modules::DataBase);
//
//    // ищем логику
//    TModuleLogic* pLogic = (TModuleLogic*) FindPtrModuleByID(ID_Modules::Logic);
//    if (pLogic) {
//        pLogic->SetComponents(components);
//        pLogic->InitLog();
//        pLogic->ParseCmd(mVecArg);
//    } else {
//        BL_FIX_BUG();
//    }
//}
////-----------------------------------------------------------------------
//void TDevTool_Share::SetVectorParam(std::vector<std::string>& vecArg)
//{
//    mVecArg = vecArg;
//}
////-----------------------------------------------------------------------
//IModule* TDevTool_Share::GetModuleByID(int id)
//{
//    IModule* pModule = nullptr;
//    switch (id) {
//        // ядро
//        case ID_Modules::Logic: pModule = new TModuleLogic; ((TModuleLogic*) pModule)->SetTerrainPath(mTerrainPath); break;
//            // периферия
//        //case ID_Modules::GraphicEngine:
//        //    mGE_ForSetup = new TModuleGraphicEngine;
//        //    pModule = mGE_ForSetup;
//        //    ((TModuleGraphicEngine*) pModule)->GetCBStartEvent()->Register(&TDevTool_Share::SetupGraphicEngine, this);
//        //    break;
//        case ID_Modules::GraphicEngine:  
//            pModule = new TModuleGraphicEngine; SetupGraphicEngine((TModuleGraphicEngine*)pModule); break;
//        case ID_Modules::PhysicEngine:   pModule = new TModulePhysicEngine;      break;
//        //case ID_Modules::MMOEngine:    pModule = new TModuleMMOEngine;         break;
//        //case ID_Modules::NetTransport: pModule = new TModuleNetTransport;      break;
//        //case ID_Modules::SoundEngine:  pModule = new TModuleSoundEngine;       break;
//        //case ID_Modules::DataBase:     pModule = new TModuleDataBase;          break;
//        default:BL_FIX_BUG();
//    }
//    return pModule;
//}
////-----------------------------------------------------------------------
//int TDevTool_Share::GetCountPathInMap(const char* type, TStrStrListMap& mapResource)
//{
//    return mapResource.count(type);
//}
////-----------------------------------------------------------------------
//bool TDevTool_Share::FindPath(const char* type, TStrStrListMap& mapResource, int index, std::string& result)
//{
//    auto fit = mapResource.find(type);
//    if (fit == mapResource.end()) {
//        return false;
//    }
//    for (int i = 0; i < index; i++) {
//        fit++;
//        if (fit == mapResource.end()) {
//            return false;
//        }
//    }
//    result = *(fit->second.begin());
//    return true;
//}
////-----------------------------------------------------------------------
//int TDevTool_Share::GetCountPathInMap_Game(const char* type)
//{
//    return GetCountPathInMap(type, mMapRGame);
//}
////-----------------------------------------------------------------------
//bool TDevTool_Share::FindPath_Game(const char* type, int index, std::string& result)
//{
//    return FindPath(type, mMapRGame, index, result);
//}
////-----------------------------------------------------------------------
//int TDevTool_Share::GetCountPathInMap_GUI(const char* type)
//{
//    return GetCountPathInMap(type, mMapRGUI);
//}
////-----------------------------------------------------------------------
//bool TDevTool_Share::FindPath_GUI(const char* type, int index, std::string& result)
//{
//    return FindPath(type, mMapRGUI, index, result);
//}
////-----------------------------------------------------------------------
//int TDevTool_Share::GetCountPathInMap_GameEngine(const char* type)
//{
//    return GetCountPathInMap(type, mMapRGameEngine);
//}
////-----------------------------------------------------------------------
//bool TDevTool_Share::FindPath_GameEngine(const char* type, int index, std::string& result)
//{
//    return FindPath(type, mMapRGameEngine, index, result);
//}
////-----------------------------------------------------------------------
//int TDevTool_Share::GetCountPathInMap_GraphicEngine(const char* type)
//{
//    return GetCountPathInMap(type, mMapRGraphicEngine);
//}
////-----------------------------------------------------------------------
//bool TDevTool_Share::FindPath_GraphicEngine(const char* type, int index, std::string& result)
//{
//    return FindPath(type, mMapRGraphicEngine, index, result);
//}
////-----------------------------------------------------------------------
