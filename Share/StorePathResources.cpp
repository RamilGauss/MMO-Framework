/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "StorePathResources.h"
#include "MapXML_Field.h"

TMapXML_Field g_MapXML_Field;

//-----------------------------------------------------------------
TMapXML_Field* GetStorePathResources()
{
  return &g_MapXML_Field;
}
//-----------------------------------------------------------------