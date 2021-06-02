/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ClientMain.h"

#include "Precompiled.h"
#include <atlconv.h>
#include <boost/asio/ip/impl/address_v4.ipp>
#include <boost/lexical_cast.hpp>

#include "ResolverSelf_IP_v4.h"
#include "ModuleLogic.h"
#include "ListModules.h"
#include "MMOEngine/include/Client.h"
#include "ModuleMMOEngineClient.h"
#include "LogicEventCallBack.h"

TClientMain::TClientMain()
{
    IsOpen = false;
}
//------------------------------------------------------
TClientMain::~TClientMain()
{

}
//-------------------------------------------------------------------------------------
void TClientMain::Activate()
{
    assignWidget(bEnter, "bEnter");
    assignWidget(bExit, "bExit");

    assignWidget(ebIP, "ebIP");
    assignWidget(ebPort, "ebPort");
    assignWidget(ebLogin, "ebLogin");

    bEnter->eventMouseButtonClick += MyGUI::newDelegate(this, &TClientMain::sl_Enter);
    bExit->eventMouseButtonClick += MyGUI::newDelegate(this, &TClientMain::sl_Exit);

    LoadInputParam();
}
//-------------------------------------------------------------------------------------
void TClientMain::sl_Enter(MyGUI::Widget* _sender)
{
    USES_CONVERSION;
    std::string sPort = W2A((LPCWSTR) ebPort->getOnlyText().data());
    int port = boost::lexical_cast<int>(sPort.data());

    std::string sIP = W2A((LPCWSTR) ebIP->getOnlyText().data());
    ip = boost::asio::ip::address_v4::from_string(sIP.data()).to_ulong();

    sLogin = W2A((LPCWSTR) ebLogin->getOnlyText().data());
    mDescOpen = nsMMOEngine::TDescOpen(port);

    // настройка сети
    if (IsOpen == false)
        EnterServer();
}
//-------------------------------------------------------------------------------------
void TClientMain::sl_Exit(MyGUI::Widget* _sender)
{
    //IClientDeveloperTool::Singleton()->GetComponent()->mNetClient->LeaveQueue();
    TModuleLogic::Get()->Exit();
}
//-------------------------------------------------------------------------------------
const char* TClientMain::GetNameLayout()
{
    return "ClientMain.layout";
}
//-------------------------------------------------------------------------------------
void* TClientMain::GetParent()
{
    return nullptr;
}
//-------------------------------------------------------------------------------------
void TClientMain::SetupTabChild()
{
    mVectorChild_Tab.push_back(ebIP);
    mVectorChild_Tab.push_back(ebLogin);
    mVectorChild_Tab.push_back(ebPort);
}
//-------------------------------------------------------------------------------------
void TClientMain::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
    switch (_key.getValue())   {
        case MyGUI::KeyCode::Return:
            sl_Enter(_sender);
            break;
        default:;
    }
}
//-------------------------------------------------------------------------------------
void TClientMain::SaveInputParam(unsigned int ip, unsigned int port, const char* sLogin)
{
    //QSettings settings("RUSSIA","ClientMain");
    //settings.setValue("ip",   ip);
    //settings.setValue("port", port);
    //settings.setValue("Login",QString(sLogin));
}
//-------------------------------------------------------------------------------------
void TClientMain::LoadInputParam()
{
    //QSettings settings("RUSSIA","ClientMain");
    //bool ok = false;
    //unsigned char sIP4[4];
    //*(unsigned int*)(&sIP4[0]) = settings.value("ip", 0).toUInt(&ok);
    //if(ok==false) return;
    //unsigned int port = settings.value("port",0).toUInt(&ok);
    //if(ok==false) return;
    //QString sLogin    = settings.value("Login",QString()).toString();

    //char sIP[100];
    //sprintf(sIP, "%u.%u.%u.%u", 
    //   sIP4[3], sIP4[2], sIP4[1], sIP4[0]);
    //ebIP->setOnlyText(sIP);

    //char sPort[100];
    //sprintf(sPort,"%u",port);
    //ebPort->setOnlyText(sPort);

    //QByteArray ba = sLogin.toLocal8Bit();
    //ebLogin->setOnlyText(ba.data());
}
//-------------------------------------------------------------------------------------
void TClientMain::EnterServer()
{
    nsMMOEngine::TClient* pClient = TModuleLogic::Get()->GetC()->pMMOEngineClient->Get();

    IsOpen = pClient->Open(&mDescOpen);
    BL_ASSERT(IsOpen);
    std::string pasword = "1";
    pClient->Login(TIP_Port(ip, 0), sLogin, pasword);

    SaveInputParam(ip, mDescOpen.port, sLogin.data());
}
//-------------------------------------------------------------------------------------
