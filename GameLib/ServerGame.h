/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ServerGameH
#define ServerGameH

#include <vector>
#include <string>
#include <map>

#include "IGame.h"
#include "StatisticValue.h"

class TServerGame : public IGame
{
protected:
	TSaveOnHDD mLogLoad;

	typedef TStatType_double TStatLoad;
	TStatLoad mStatLoad;

  IServerDeveloperTool::TComponentServer mCServer;

	unsigned int mStartTime;
public:
  TServerGame(eTypeRealize type);
  virtual ~TServerGame();
protected:
	virtual bool Init(int variant_use, 
                    const char* sNameDLL, 
                    std::vector<std::string>& arg);
	virtual void Done();
  virtual bool Work();

	virtual void MakeVectorModule();

	virtual void CollectEvent();
	virtual void HandleEvent(nsEvent::TEvent* pEvent);

  bool HandleNetEngineEvent();
  bool HandleSceneEvent();
  bool HandleTimerFirstEvent();
  bool HandleTimerLastEvent();

  void CalcAndWaitRestTime();
	void SetLoad();
};
//---------------------------------------------------------
#endif
