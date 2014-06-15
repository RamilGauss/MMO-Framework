/*
	Эксперименты по замене DirectX математических функций в 
	Struct3D на свои.
*/

#include "MathTools.h"

#ifdef WIN32
  #include <d3dx9math.h>
#endif

using namespace nsMathTools;
//--------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
  D3DXMATRIX pOut;
	float det;  
	D3DXMATRIX pV;
	pV._11 = 1.0f; pV._12 = 1.0f; pV._13 = 0.0f; pV._14 = 0.0f;
	pV._21 = 0.0f; pV._22 = 1.0f;	pV._23 = 0.0f; pV._24 = 0.0f;
	pV._31 = 0.0f; pV._32 = 0.0f;	pV._33 = 1.0f; pV._34 = 0.0f;
	pV._41 = 0.0f; pV._42 = 0.0f;	pV._43 = 0.0f; pV._44 = 1.0f;
	D3DXMATRIX* pRet = D3DXMatrixInverse(&pOut, &det, &pV);

	TMatrix16 pMOut;
  TMatrix16 pMV;
	memcpy(&pMV, &pV, sizeof(TMatrix16));
	TMatrix16* pMRet = SetMatrixInverse(&pMOut, &det, &pMV);

  return 0;
}
//--------------------------------------------------------------------------------
