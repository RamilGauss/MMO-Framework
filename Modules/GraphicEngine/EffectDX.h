/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EffectDXH
#define EffectDXH

#include <string>
#include <d3dx9effect.h>
#include <d3dx9mesh.h>
#include <vector>

class TModelDX;

class TEffectDX
{
  //--------------------------------------------------------------------------------------
  // Effect parameter handles
  // Шейдер
  //--------------------------------------------------------------------------------------
  D3DXHANDLE  hAmbient;
  D3DXHANDLE  hDiffuse;
  D3DXHANDLE  hSpecular;
  D3DXHANDLE  hOpacity;
  D3DXHANDLE  hSpecularPower;
  D3DXHANDLE  hLightColor;
  D3DXHANDLE  hLightPosition;
  D3DXHANDLE  hCameraPosition;
  D3DXHANDLE  hTexture;
  D3DXHANDLE  hTime;
  D3DXHANDLE  hWorld;
  D3DXHANDLE  hProjection;
  D3DXHANDLE  hView;
  //----------------------------------------------------------------------------------------
	D3DXHANDLE  hTexCubeMap;
  //----------------------------------------------------------------------------------------

public:

  // Material format 
  struct Material
  {
		bool flgUseCubeMap;

    std::string strName;
    int         mNumUse;// в массиве может быть несколько частей с одинаковым именем, этот параметр поможет выбрать одну из частей

    D3DXVECTOR3 vAmbient;
    D3DXVECTOR3 vDiffuse;
    D3DXVECTOR3 vSpecular;

    int nShininess;
    float fAlpha;

    bool bSpecular;
    
    std::wstring strShader;
    std::string  strTechnique;

    std::wstring strTexture;
    IDirect3DTexture9* pTexture;
    D3DXHANDLE hTechnique;

    Material()
    {
      pTexture = NULL;
      hTechnique = NULL;
			flgUseCubeMap = false;
    }
  };
  // Vertex format
#pragma pack(push, 1)
  struct VERTEX
  {
    D3DXVECTOR3 position;
    D3DXVECTOR3 normal;
    D3DXVECTOR2 texcoord;
  };
#pragma pack(pop)
  TEffectDX();
  ~TEffectDX();
  
  void SetInnerShaderParam();
  void SetAlphaTransparency(float alphaTransparency);

  void Init();
  void Destroy();
  void LostDevice();
  void ResetDevice();

	void SetTexCubeMap(IDirect3DCubeTexture9** pTexture);
	void SetTexture(IDirect3DTexture9* pTexture);	// назначить загруженную текстуру
	void SetTexture(const char* nameTexture, IDirect3DTexture9* pTexture);

	void SetBool(const char* nameTexture, bool v);
	void SetFloat(const char* nameTexture, float v);

  HRESULT SetMatrixWorld(D3DXMATRIXA16* matrix);
  HRESULT Begin(UINT* cPasses , DWORD flag);
  HRESULT BeginPass(UINT iPass);
  HRESULT EndPass();
  HRESULT End();
	//----------------------------------------------------------
	bool UseCubeMap();
	//----------------------------------------------------------
  ID3DXMesh* GetMesh(){return pMesh;}
  void SetMesh(ID3DXMesh* pM){pMesh=pM;}

  ID3DXEffect* GetEffect(){return p;}
  void SetEffect(ID3DXEffect* pE){p=pE;}

  Material      mMaterial;

  unsigned char mTypeLOD;
  bool          mflgNormal;

protected:
  ID3DXMesh*    pMesh;
  ID3DXEffect*  p;// функция шейдера

};


#endif