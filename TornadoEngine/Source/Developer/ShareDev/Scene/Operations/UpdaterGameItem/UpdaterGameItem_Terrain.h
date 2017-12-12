/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef UpdaterGameItem_TerrainH
#define UpdaterGameItem_TerrainH

#include "TypeDef.h"
#include "Operation_Terrain.h"
#include "FactoryGameItem.h"

class DllExport TUpdaterGameItem_Terrain : public TOperation_Terrain
{
public:
  TUpdaterGameItem_Terrain();

  virtual bool Update( TFactoryGameItem::TypeGameItem type ) = 0;
private:
};

#endif
