/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ViewerModelH
#define DevTool_ViewerModelH

#include "DevTool_Client.h"

class TDevTool_ViewerModel : public TDevTool_Client
{
  bool flgDragCamera;
  int mOldX;
  int mOldY;

  unsigned int mIDkey;

  int mIndexCurObj;

public:
  TDevTool_ViewerModel();
  virtual ~TDevTool_ViewerModel();

  virtual void Init(std::vector<std::string>& arg);
  virtual void Event(nsEvent::TEvent* pEvent);
  virtual void Done();
protected:
  void CreateObjects(int cntK,int cntJ,int cntI);
  void CreateHangar();

  void InitLog();

	void MouseEvent(nsEvent::TMouseEvent* pEvent);
	void KeyEvent(nsEvent::TKeyEvent* pEvent);

  virtual std::string GetTitleWindow(){return "Просмоторщик";}
};

#endif
