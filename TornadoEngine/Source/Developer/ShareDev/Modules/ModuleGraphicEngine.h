/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleGraphicEngineH
#define ModuleGraphicEngineH

#include <boost/smart_ptr/scoped_ptr.hpp>

#include "CallBackRegistrator.h"
#include "ModuleComponent.h"
#include "GraphicEngine_OGRE_MyGUI.h"

class TGraphicEngine_OGRE_MyGUI;

class DllExport TModuleGraphicEngine : public TModuleComponent
{
	boost::scoped_ptr<TGraphicEngine_OGRE_MyGUI> mGE;

  TCallBackRegistrator1<TModuleDev*>* mCBSetup;
public:
  TModuleGraphicEngine();

  virtual void StartEvent();
  virtual bool Work();
  virtual void StopEvent();

  TGraphicEngine_OGRE_MyGUI* GetGE();

  // графический движок требуется настраивать в том же потоке, в котором он работает
  void SetFuncForSetup(TCallBackRegistrator1<TModuleDev*>* pCBSetup);
protected:
};

#endif
