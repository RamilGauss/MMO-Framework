/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include <boost/smart_ptr/scoped_ptr.hpp>

#ifdef WIN32
//-------------------------------
#include "DXUT.h"
#include "DispTextDX.h"
#include "ManagerModelDX.h"
#include "ManagerResourceDX.h"
//#include "EffectDX.h"

#include <list>
#include <set>
#include <map>

#include "MathTools.h"
#include "ShaderStack.h"
#include "StateMachine.h"
#include "MapSystemKey.h"
#include "ControlCamera.h"
#include "SrcEvent.h"
#include "TypeDef.h"

class TObjectGE;
class IDirectX_Realize;
class IGUI_Core;
class TEffectDX;

#define STR_NAME_GE "GE"

// BigJack - графический движок
class DllExport TGraphicEngine : public TSrcEvent
{
  bool flgCreateWindow;
protected:
  unsigned int mTime_ms;// время для рендера, используется для анимации
  IGUI_Core* mGUI;// NOT Thread Safe
  TControlCamera mControlCamera;

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
  typedef std::map<TObjectGE*, TDescTexturePostEffect> TMapPtrDescTPE;

	TShaderStack mMainShaderStack;

  int mShHandleView;
  int mShHandleProj;
  int mShHandleCameraPosition;
	// для освещения
	int mShHandleLightPosition;
	int mShHandleLightColor;

  typedef std::list<TObjectGE*> TListPtr;
  // все объекты
  TListPtr mListAllObject;// движок не освобождает память из-под этих объектов
  // список на отрисовку
  TListPtr mListReadyRender;// временный список

  TListPtr mListAnimateObject;// только анимированные. создаются движком(эффект движка), движок сам должен освободить память

  TListPtr mListTransparencyObject;// прозрачные объекты, временный список, только на этапе создания списка на отображение

  bool flgNeedResizeGUI;

  // для независимости от платформы, мэппинг клавиатурных событий
  TMapSystemKey mMapSysytemKeys;

  TCamera mCameraInnerNeed ;
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
  boost::scoped_ptr<TEffectDX> mEffectPreGlow_black;
  boost::scoped_ptr<TEffectDX> mEffectPreGlow_white;
	// post
	boost::scoped_ptr<TEffectDX> mEffectEdgeDetect;
	boost::scoped_ptr<TEffectDX> mEffectDownFilter4x;
	boost::scoped_ptr<TEffectDX> mEffectUpFilter4x;
	boost::scoped_ptr<TEffectDX> mEffectBloomH;
	boost::scoped_ptr<TEffectDX> mEffectBloomV;
	boost::scoped_ptr<TEffectDX> mEffectCombine4x;
	// создание и вывод
	boost::scoped_ptr<TEffectDX> mEffectBlend;
	boost::scoped_ptr<TEffectDX> mEffectScene;

	bool flgViewPostEffectInMirror;
//-------------------------------------------------------

public:
  enum
  {
    eEnvMapSizeCubemap   = 312,// размер для буфера под CubeMap
  };
  //----------------------------------------------------------------
  //                              INTERFACE
  //----------------------------------------------------------------
  TGraphicEngine();
  virtual ~TGraphicEngine();

  virtual TCamera* GetCamera();
  virtual TControlCamera* GetControlCamera();
  //------------------------------------------------------------------------
  virtual void Init();
  virtual bool Work();
  virtual void SetTimeAnimate(unsigned int time_ms);
  virtual bool HandleInternalEvent();
  virtual void Done();

  virtual bool IsFullScreen();
  virtual void ToggleFullScreen();
  virtual void SetTitleWindow(const char* sTitle);

  virtual void  GetResolutionFrame(int& h, int& w );// формат X8R8G8B8
  virtual void  SetResolutionFrame(int  h, int  w );// формат X8R8G8B8
  //------------------------------------------------------------------------
  virtual void AddObject(TObjectGE* pObject);
  virtual void Clear();

  // клиентские эффекты движка, не влияют на физические параметры объектов
  virtual void SetEffect(unsigned short id_effect/*уникальный эффект, см. таблицу эффектов*/,
    nsMathTools::TVector3* coord3,     // где
    nsMathTools::TVector3* orient3,    // ориентация эффекта
    unsigned int time_past/* прошло времени, мс*/ = 0);
  virtual void SetViewFPS(bool val);
  // источники освещения
  // ввод освещение накладывает условия на шейдер. он обязан содержать интерфейс
	virtual void SetLightEnable(int index, bool v);
	virtual bool GetLightEnable(int index);
	virtual int  GetCountAllLight();

	virtual const nsMathTools::TVector3* GetLightPosition(int index);	
	virtual void SetLightPosition(int index,nsMathTools::TVector3* m3);
	virtual const nsMathTools::TVector3* GetLightColor(int index);
	virtual void SetLightColor(int index, nsMathTools::TVector3* color);

	virtual bool GetPostEffectMirror();
	virtual void SetPostEffectMirror(bool v);

  virtual void Resize();

  virtual void SetGUI(IGUI_Core* pGUI);
  virtual void ZeroGUI();

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
  void RenderBlendTexturePostEffect(const nsMathTools::TMatrix16* pView, 
                                    const nsMathTools::TMatrix16* pProj,
                                    const nsMathTools::TVector3* pPosCamera);
  void RenderSrcTextureForPostEffect(TObjectGE* pObj, 
                                     const nsMathTools::TMatrix16* view, 
                                     const nsMathTools::TMatrix16* pProj,
                                     const nsMathTools::TVector3* pPosCamera);
	void RenderGlow(TObjectGE* pObject);// подготовить устройство для отрисовки с помощью шейдера
	void RenderByEffect(ID3DXEffect* g_pEffect);
  void BlendTextureFromPostEffect(IDirect3DTexture9* pTextureScreen, bool UsePostEffectTexture);

	void SetParamShaderForCubeMap();
	void SetParamShaderForMainRender();


  void LostEventForSurfacePestEffect();
  void ResetEventForSurfacePestEffect();
  void InitEffectForGlow();
	void DestroyEffectForGlow();
	void ResetShader(ID3DXEffect* m_pEffect, DWORD dwWidth, DWORD dwHeight);

  void PrepareForPostEffect(TObjectGE* pObject);
  void RenderObject(TObjectGE* pObject, const nsMathTools::TMatrix16* view);

	void SetCommonShaderStack(const nsMathTools::TMatrix16* pView, 
                            const nsMathTools::TMatrix16* pProj, 
                            const nsMathTools::TVector3* pCameraPos);

  virtual bool InitGUI();

  void SaveRenderState();
  void RestoreRenderState();


  // подстройка под глюк DXUT 21.12.2012 Gauss
  bool IsNeedResizeGUI(){return flgNeedResizeGUI;}
  void SetNeedResizeGUI(bool val){flgNeedResizeGUI=val;}

  void DispFPS();

  void GetMatrixForCubeMap(int nFace, nsMathTools::TMatrix16& view);

  void InitLightArr();

  void HandleGUI();

protected:
	void SaveTexture(const char* name,IDirect3DTexture9* pTexture);
	void SaveSurface(const char* name, IDirect3DSurface9* pSurfaсe);
protected:
	// освещение
	enum{eCountLight=4,};
  struct TLight
  {
    nsMathTools::TVector3 color;
    nsMathTools::TVector3 position;
    bool active;
    TLight()
    {
      active   = false;
      color    = nsMathTools::TVector3(1.0f,1.0f,1.0f);
      position = nsMathTools::TVector3(0.0f,0.0f,2.4f);
    }
  };
  TLight mArrLight[eCountLight];

  // формируется перед отправкой в шейдер
  nsMathTools::TVector3 mArrLightColor[eCountLight];
  nsMathTools::TVector3 mArrLightPosition[eCountLight];

protected:
  void SetIsCreateWindow(bool val){flgCreateWindow=val;}
  bool IsCreateWindow(){return flgCreateWindow;}
  void RenderGUI();
  void ResizeGUI();
  void LostDeviceGUI();
};

#endif
#endif