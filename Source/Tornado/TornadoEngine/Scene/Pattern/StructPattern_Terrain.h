/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef StructPattern_TerrainH
#define StructPattern_TerrainH

#include "TypeDef.h"
#include "ContainerArrObj.h"
#include "MathTools.h"

class btRigidBody;
class btHeightfieldTerrainShape;

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
        THeightMapTerrain();
    };

    struct DllExport TTerrainPart_Physic
    {
        THeightMapTerrain* pData;
        btRigidBody* pRB;
        btHeightfieldTerrainShape* pHeightfieldShape;
        TTerrainPart_Physic();

        void Init();
    };
};

#endif
