/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleAloneGUIH
#define ModuleAloneGUIH

#include "ModuleDev.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include "ModuleComponent.h"
#include "QtEngine.h"

class TQtEngine;

class DllExport TModuleAloneGUI : public TModuleComponent
{
  boost::scoped_ptr<TQtEngine> mQt;

  int    mArgc; 
  char** mArgv;
public:
  TModuleAloneGUI();

  virtual void StartEvent();
  virtual bool Work();
  virtual void StopEvent();

  void SetArg(int argc, char** argv);
protected:
	virtual void Input(int id_sender, void* p, int size);
};


#endif