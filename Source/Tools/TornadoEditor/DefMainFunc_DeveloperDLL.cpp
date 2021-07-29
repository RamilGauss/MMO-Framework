/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DeveloperTool_DLL.h"

using namespace nsTornadoEngine;


//###
class T : public TScenePartsContainer
{

};
//###

DllExport_C TScenePartsContainer* GetScenePartsContainer()
{
    return new T();
}
//-------------------------------------------------------------------
DllExport_C void FreeScenePartsContainer(TScenePartsContainer* p)
{
    delete p;
}
//-------------------------------------------------------------------