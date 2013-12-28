/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ClientDeveloperTool_ViewerModelH
#define ClientDeveloperTool_ViewerModelH

#include "../GameLib/IClientDeveloperTool.h"

class TClientDeveloperTool_ViewerModel : public IClientDeveloperTool
{
  bool flgDragCamera;
  int mOldX;
  int mOldY;

  unsigned int mIDkey;

  int mIndexCurObj;

public:
  TClientDeveloperTool_ViewerModel();
  virtual ~TClientDeveloperTool_ViewerModel();

  virtual void Init(TComponentClient* pComponent, std::vector<std::string>& arg);

  virtual std::string GetTitleWindow();
  
  virtual void Event(nsEvent::TEvent* pEvent);

  virtual void Done();
  
	virtual IMakerObjectCommon* GetMakerObjectCommon();
  virtual std::string GetPathXMLFile();

protected:
  void CreateObjects(int cntK,int cntJ,int cntI);
  void CreateHangar();

  void InitLog();

	void MouseEvent(nsEvent::TMouseEvent* pEvent);
	void KeyEvent(nsEvent::TKeyEvent* pEvent);
};

#endif
