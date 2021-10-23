/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEditor_ComponentContainer.h"
#include "TornadoEditor_Component_JsonSerializer.h"

using namespace nsTornadoEditor;

TTornadoEditor_ComponentContainer::TTornadoEditor_ComponentContainer()
{
    mJson = new TTornadoEditor_Component_JsonSerializer();
    //mBin = new ;
    //mImGui = new ;
    //mEntMng = new ;
    //mTypeFactory = new ;
    //mTypeInfo = new ;
}
//------------------------------------------------------------------------
TTornadoEditor_ComponentContainer::~TTornadoEditor_ComponentContainer()
{
    delete mJson;
    delete mBin;
    delete mImGui;
    delete mEntMng;
    delete mTypeFactory;
    delete mTypeInfo;
}
//------------------------------------------------------------------------
