/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Operation_Terrain.h"
#include <stddef.h>

TOperation_Terrain::TOperation_Terrain()
{
	mPatternTerrain = NULL;
}
//-----------------------------------------------------------------------------------
TOperation_Terrain::~TOperation_Terrain()
{

}
//-----------------------------------------------------------------------------------
void TOperation_Terrain::SetPattern(TBehaviourPattern* pPattern)
{
	mPatternTerrain = (TPattern_Terrain*)pPattern;
}
//-----------------------------------------------------------------------------------
