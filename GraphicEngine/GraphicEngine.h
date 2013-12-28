/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#ifdef WIN32
//-------------------------------
// WIN32
  #include "DXUT.h"
  #include "DispTextDX.h"
  #include "ManagerModelDX.h"
  #include "ManagerResourceDX.h"
  #include "EffectDX.h"
//end WIN32

#include <list>
#include <set>
#include <map>

#include "Struct3D.h"
#include "ShaderStack.h"
#include "IGraphicEngine.h"
#include "StateMachine.h"
#include "MapSystemKey.h"


class IBaseObjectGE;
class IDirectX_Realize;

// BigJack - графический движок
class TGraphicEngine : public IGraphicEngine
{
protected:

  // Depth-stencil buffer для рендера Cube map
	IDirect3DSurface9* mSurfaceDepthStencilCube;       // для рендера Cube map

  IDirectX_Realize* mDXUT;
  TManagerResourceDX mManagerResourceDX;
  TManagerModelDX mManagerModelDX;

  TDispTextDX mViewerFPS;

	struct TDescTexturePostEffect
	{
		IDirect3DTexture9* pSrc;
		IDirect3DTexture9* pDst;

		TDescTexturePostEffect()
		{
			pSrc = NULL;
			pDst = NULL;
		}
	};

  typedef std::vector<IDirect3DTexture9*> TVectorPtr;
  typedef std::map<IBaseObjectGE*, TDescTexturePostEffect> TMapPtrDescTPE;


	TShaderStack mMainShaderStack;

  int mShHandleView;
  int mShHandleProj;
  int mShHandleCameraPosition;
	// для освещения
	int mShHandleLightPosition;
	int mShHandleLightColor;

  typedef std::list<IBaseObjectGE*> TListPtr;
  // все объекты
  TListPtr mListAllObject;// движок не освобождает память из-под этих объектов
  // список на отрисовку
  TListPtr mListReadyRender;// временный список

  TListPtr mListAnimateObject;// только анимированные. создаются движком(эффект движка), движок сам должен освободить память

  TListPtr mListTransparencyObject;// прозрачные объекты, временный список, только на этапе создания списка на отображение

  bool flgNeedResizeGUI;

  // для независимости от платформы, мэппинг клавиатурных событий
  TMapSystemKey mMapSysytemKeys;

  ICamera* pCameraInnerNeed;

  //------------------------------------
  // PostEffect
  TMapPtrDescTPE mMapObjTexturePostEffect;

//-------------------------------------------------------
	IDirect3DVertexDeclaration9* mVertDeclPP;

  IDirect3DSurface9 *mDepthSurfaceForMainRender;

	IDirect3DTexture9* mTextureMainRender;
	IDirect3DTexture9* mTextureSecondRender;

	typedef std::list<TEffectDX*> TListPtrEffect;
	TListPtrEffect mListPtrEffect;
  // подготовка
  TEffectDX mEffectPreGlow_black;
  TEffectDX mEffectPreGlow_white;
	// post
	TEffectDX mEffectEdgeDetect;
	TEffectDX mEffectDownFilter4x;
	TEffectDX mEffectUpFilter4x;
	TEffectDX mEffectBloomH;
	TEffectDX mEffectBloomV;
	TEffectDX mEffectCombine4x;
	// создание и вывод
	TEffectDX mEffectBlend;
	TEffectDX mEffectScene;

	bool flgViewPostEffectInMirror;
//-------------------------------------------------------

public:
  //----------------------------------------------------------------
  //                              INTERFACE
  //----------------------------------------------------------------
  TGraphicEngine(ICamera* pCamera);
  virtual ~TGraphicEngine();

  //------------------------------------------------------------------------
  virtual void Init();
  virtual void Work(unsigned int time_ms);
  virtual bool HandleInternalEvent();
  virtual void Done();

  virtual bool IsFullScreen();
  virtual void ToggleFullScreen();
  virtual void SetTitleWindow(const char* sTitle);

  virtual void  GetResolutionFrame(int& h, int& w );// формат X8R8G8B8
  virtual void  SetResolutionFrame(int  h, int  w );// формат X8R8G8B8
  //------------------------------------------------------------------------
  virtual void AddObject(IBaseObjectGE* pObject);
  virtual void Clear();

  // клиентские эффекты движка, не влияют на физические параметры объектов
  virtual void SetEffect(unsigned short id_effect/*уникальный эффект, см. таблицу эффектов*/,
    nsStruct3D::TVector3* coord3,     // где
    nsStruct3D::TVector3* orient3,    // ориентация эффекта
    unsigned int time_past/* прошло времени, мс*/ = 0);
  virtual void SetViewFPS(bool val);
  // источники освещения
  // ввод освещение накладывает условия на шейдер. он обязан содержать интерфейс
	virtual void SetLightEnable(int index, bool v);
	virtual bool GetLightEnable(int index);
	virtual int  GetCountAllLight();

	virtual const nsStruct3D::TVector3* GetLightPosition(int index);	
	virtual void SetLightPosition(int index,nsStruct3D::TVector3* m3);
	virtual const nsStruct3D::TVector3* GetLightColor(int index);
	virtual void SetLightColor(int index, nsStruct3D::TVector3* color);

	virtual bool GetPostEffectMirror();
	virtual void SetPostEffectMirror(bool v);
  //----------------------------------------------------------------
  //                             ~INTERFACE
  //----------------------------------------------------------------
protected:
  //----------------------------------------------------------------
  // Для внутренних событий движка.
  //----------------------------------------------------------------
  friend class TDXUT;
  bool IsDeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, bool bWindowed,void* pUserContext );
  bool ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext );
  HRESULT OnCreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,void* pUserContext );
  HRESULT OnResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,void* pUserContext );
  void OnFrameMove( double fTime, float fElapsedTime, void* pUserContext );
  void OnFrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext );
  LRESULT MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing,void* pUserContext );
  void OnLostDevice( void* pUserContext );
  void OnDestroyDevice( void* pUserContext );
  
  void OnKeyEvent( UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext );
  void OnMouseEvent( int state, 
                     int nMouseWheelDelta, 
                     int xPos, int yPos, void* pUserContext );

protected:

  void RegisterSet  (std::set<void*>* setCallback, void* pFunc);
  void UnregisterSet(std::set<void*>* setCallback, void* pFunc);

protected:
  
  void MakeVectorOnRender();
  void Optimize();
  void Render(IDirect3DDevice9* pd3dDevice);
  void Animate();// для анимации и подготовки стека шейдера

	void RenderCubeMap(IDirect3DDevice9* pd3dDevice);// для реализации технологии CubeMap

  // указать объект, для которого делаем текстуру
  // добавится текстура, потом когда будет готова сцена надо блендить все текстуры на экран
  
  // для данной точки обзора
  void RenderBlendTexturePostEffect(const nsStruct3D::TMatrix16* pView, 
                                    const nsStruct3D::TMatrix16* pProj,
                                    const nsStruct3D::TVector3* pPosCamera);
  void RenderSrcTextureForPostEffect(IBaseObjectGE* pObj, 
                                     const nsStruct3D::TMatrix16* view, 
                                     const nsStruct3D::TMatrix16* pProj,
                                     const nsStruct3D::TVector3* pPosCamera);
	void RenderGlow(IBaseObjectGE* pObject);// подготовить устройство для отрисовки с помощью шейдера
	void RenderByEffect(ID3DXEffect* g_pEffect);
  void BlendTextureFromPostEffect(IDirect3DTexture9* pTextureScreen, bool UsePostEffectTexture);

	void SetParamShaderForCubeMap();
	void SetParamShaderForMainRender();


  void LostEventForSurfacePestEffect();
  void ResetEventForSurfacePestEffect();
  void InitEffectForGlow();
	void DestroyEffectForGlow();
	void ResetShader(ID3DXEffect* m_pEffect, DWORD dwWidth, DWORD dwHeight);

  void PrepareForPostEffect(IBaseObjectGE* pObject);
  void RenderObject(IBaseObjectGE* pObject, const nsStruct3D::TMatrix16* view);

	void SetCommonShaderStack(const nsStruct3D::TMatrix16* pView, const nsStruct3D::TMatrix16* pProj, const nsStruct3D::TVector3* pCameraPos);

  virtual bool InitGUI();

  void SaveRenderState();
  void RestoreRenderState();


  // подстройка под глюк DXUT 21.12.2012 Gauss
  bool IsNeedResizeGUI(){return flgNeedResizeGUI;}
  void SetNeedResizeGUI(bool val){flgNeedResizeGUI=val;}

  void DispFPS();


  void GetMatrixForCubeMap(int nFace, nsStruct3D::TMatrix16& view);

  void InitLightArr();

  void HandleGUI();

	//void ZBufferOn();
	//void ZBufferOff();

protected:
	void SaveTexture(const char* name,IDirect3DTexture9* pTexture);
	void SaveSurface(const char* name, IDirect3DSurface9* pSurfaсe);
protected:
	// освещение
	enum{eCountLight=4,};
  struct TLight
  {
    nsStruct3D::TVector3 color;
    nsStruct3D::TVector3 position;
    bool active;
    TLight()
    {
      active   = false;
      color    = nsStruct3D::TVector3(1.0f,1.0f,1.0f);
      position = nsStruct3D::TVector3(0.0f,0.0f,2.4f);
    }
  };
  TLight mArrLight[eCountLight];

  // формируется перед отправкой в шейдер
  nsStruct3D::TVector3 mArrLightColor[eCountLight];
  nsStruct3D::TVector3 mArrLightPosition[eCountLight];

};

#endif
#endif