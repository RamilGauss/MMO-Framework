/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BaseServer.h"
#include "SessionManager.h"

using namespace nsMMOEngine;

TBaseServer::TBaseServer()
{

}
//-------------------------------------------------------------------------
TBaseServer::~TBaseServer()
{

}
//-------------------------------------------------------------------------
void TBaseServer::Accept(int sessionID, std::string& password)
{
    mSessionManager->Accept(sessionID, password);
}
//-------------------------------------------------------------------------
void TBaseServer::Reject(int sessionID)
{
    mSessionManager->Reject(sessionID);
}
//-------------------------------------------------------------------------
//###
void TBaseServer::DisconnectByClientKey(unsigned int clientKey)
{

}
//-------------------------------------------------------------------------
//###
