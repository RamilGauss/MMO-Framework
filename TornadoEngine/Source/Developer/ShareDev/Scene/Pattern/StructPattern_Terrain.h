/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef StructPattern_TerrainH
#define StructPattern_TerrainH

#include "TypeDef.h"
#include "ContainerArrObj.h"
#include "MathTools.h"

class btRigidBody;

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsStructPattern_Terrain
{
	// физика
	struct DllExport THeightMapTerrain
	{
		TContainerArrObj<float> cHeight;
		unsigned short size;
		float worldSize;
		float inputScale;
		float inputBias;
		nsMathTools::TVector3 pos;
	}_PACKED;

	struct DllExport TTerrainPart_Physic
	{
		THeightMapTerrain* pData;
		btRigidBody*       pRB;
		TTerrainPart_Physic();
	}_PACKED;
};

#ifdef WIN32
#pragma pack(pop)
#endif

#endif
