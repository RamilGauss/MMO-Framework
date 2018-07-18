/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "HandlerMMO.h"

#define SLAVE_PORT        1234
#define MASTER_PORT       2235
#define SUPER_SERVER_PORT 2236
#define CLIENT_PORT       2237

#define CLIENT_PASSWORD "1"

#define SLAVE_LOGIN     "Slave"
#define SLAVE_PASSWORD  "1"

#define MASTER_LOGIN    "Master"
#define MASTER_PASSWORD "1"

#define SERVER_QUANT_TIME 100 // мс

#define CLIENT_QUANT_TIME 100 // мс
#define STEP_LOGIN        100

#define ServerLog "Server"
#define ClientLog "Client"

void InitLogger( char* loggerName );
