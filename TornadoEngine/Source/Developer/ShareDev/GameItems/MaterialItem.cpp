/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MaterialItem.h"
#include "FactoryGameItem.h"

TMaterialItem::TMaterialItem(std::string& name):
TBaseItem(name, TFactoryGameItem::Material)
{

}
//--------------------------------------------------------------------------------
