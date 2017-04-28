/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TerrainItemH
#define TerrainItemH

#include "BaseItem.h"
#include <map>

#ifdef WIN32
#pragma pack(push, 1)
#endif

struct DllExport TTerrainItem : public TBaseItem
{
	struct TGraphic
	{
		float maxPixelError;
		float compositeMapDistance;
	}_PACKED;

	TGraphic mGraphic;

	struct TConvention
	{
		int min;
		int max;
	}_PACKED;
	TConvention mX;
	TConvention mY;

  TTerrainItem(std::string& name);
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif
