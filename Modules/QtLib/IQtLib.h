/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IQtLibH
#define IQtLibH

#include "TypeDef.h"
#include "CallBackRegistrator.h"

#define STR_NAME_QT "Qt"

class DllExport IQtLib
{
public:
  IQtLib(){};
  virtual ~IQtLib(){};

  virtual void Init(int argc, char** argv) = 0;
  // запрос на квант времени потока Qt
	template <typename F, class A1>
  void CallFromQtThreadByFunc(F pFunc, A1 pObject)
	{
		TCallBackRegistrator0* pCallBack = new TCallBackRegistrator0;
		pCallBack->Register(pFunc, pObject);
		CallFromQtThread(pCallBack);
	}
protected:
	virtual void CallFromQtThread(TCallBackRegistrator0* pCallBack) = 0;
};


#endif