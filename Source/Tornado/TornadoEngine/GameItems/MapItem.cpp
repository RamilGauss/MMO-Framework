/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MapItem.h"
#include "FactoryGameItem.h"

TMapItem::TMapItem(std::string& name):
TBaseItem(name, TFactoryGameItem::Map)
{

}
//--------------------------------------------------------------------------------
