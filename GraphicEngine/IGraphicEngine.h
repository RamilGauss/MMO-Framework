/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGraphicEngineH
#define IGraphicEngineH

#include <list>

#include "TypeDef.h"
#include "Struct3D.h"
#include "SrcEvent.h"

#define STR_NAME_GE "GE"

class IBaseObjectGE;
class IGUI_Core;
class ICamera;

class GRAPHIC_ENGINE_EI IGraphicEngine : public TSrcEvent
{
  bool flgCreateWindow;

protected:
  unsigned int mTime_ms;// время для рендера, используется для анимации
  
  IGUI_Core* mGUI;// NOT Thread Safe

  ICamera* mICamera;                                // кросс платформенная камера

public:
	enum{
        eEnvMapSizeCubemap   = 312,// размер для буфера под CubeMap
        };

  IGraphicEngine(ICamera* pCamera);
  virtual ~IGraphicEngine();

  void SetGUI(IGUI_Core* pGUI);
  void ZeroGUI();

  virtual bool IsFullScreen() = 0;
  virtual void ToggleFullScreen() = 0;
  virtual void SetTitleWindow(const char* sTitle) = 0;
  //------------------------------------------------------------------------
  virtual void Init() = 0;
  virtual void Work(unsigned int time_ms) = 0;
  virtual bool HandleInternalEvent() = 0;// true - success, false - exit
  virtual void Done() = 0;
  virtual void GetResolutionFrame(int& h, int& w ) = 0;// формат X8R8G8B8
  virtual void SetResolutionFrame(int  h, int  w ) = 0;// формат X8R8G8B8
  //------------------------------------------------------------------------
  virtual void AddObject(IBaseObjectGE* pObject) = 0;
  virtual void Clear() = 0;

  // клиентские эффекты движка, не влияют на физические параметры объектов
  virtual void SetEffect(unsigned short id_effect/*уникальный эффект, см. таблицу эффектов*/,
    nsStruct3D::TVector3* coord3,     // где
    nsStruct3D::TVector3* orient3,    // ориентация эффекта
    unsigned int time_past/* прошло времени, мс*/ = 0) = 0;
  virtual void SetViewFPS(bool val) = 0;
  // источники освещения
  // ввод освещения накладывает условия на шейдер. он обязан содержать интерфейс
  virtual void SetLightEnable(int index, bool v) = 0;
  virtual bool GetLightEnable(int index) = 0;
  virtual int  GetCountAllLight() = 0;

	virtual const nsStruct3D::TVector3* GetLightPosition(int index) = 0;	
	virtual void SetLightPosition(int index,nsStruct3D::TVector3* m3) = 0;
	virtual const nsStruct3D::TVector3* GetLightColor(int index) = 0;
	virtual void SetLightColor(int index, nsStruct3D::TVector3* color) = 0;

	virtual bool GetPostEffectMirror() = 0;
	virtual void SetPostEffectMirror(bool v) = 0;

protected:

  // работа с GUI
  virtual bool InitGUI() = 0;

  void SetIsCreateWindow(bool val){flgCreateWindow=val;}
  bool IsCreateWindow(){return flgCreateWindow;}
  void RenderGUI();
  void ResizeGUI();
  void LostDeviceGUI();

};


#endif

