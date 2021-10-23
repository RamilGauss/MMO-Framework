/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEditor_HandlerContainer.h"

using namespace nsTornadoEditor;

TTornadoEditor_HandlerContainer::TTornadoEditor_HandlerContainer()
{
    //mTypeFactory = new ;
    //mTypeInfo = new ;
}
//-------------------------------------------------------------------------------------
TTornadoEditor_HandlerContainer::~TTornadoEditor_HandlerContainer()
{
    delete mTypeFactory;
    delete mTypeInfo;
}
//-------------------------------------------------------------------------------------