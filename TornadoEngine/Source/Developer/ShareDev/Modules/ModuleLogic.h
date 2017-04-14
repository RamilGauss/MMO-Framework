/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleLogicH
#define ModuleLogicH

#include "ModuleDev.h"
#include "Components.h"
#include "LogicEventCallBack.h"
#include "FactoryGameItem.h"
#include "FactoryBehaviourPattern.h"
#include <set>

class DllExport TModuleLogic : public TModuleDev
{
  volatile bool flgNeedExit;

	std::string mTerrainPath;
  TFactoryBehaviourPattern mFBP;
protected:
  TComponents      mComp;
  TFactoryGameItem mFGI;

	std::set<int> mSetUseID_Module;
public:
  TModuleLogic();
  virtual void ParseCmd(std::vector<std::string>& arg) = 0;
  virtual void InitLog();

	std::set<int> GetUseID_Module();

	void SetTerrainPath(std::string& path);
	std::string GetTerrainPath();

  void SetComponents(TComponents components);
  TComponents* GetC();
  TFactoryGameItem* GetFGI();
  virtual TFactoryBehaviourPattern* GetFBP();

  static TModuleLogic* Get();

  void Exit( int reason = 0);

  //template <typename F>
  //void CallBackModule(int id_module, F pFunc);
  //template <typename F, class A1>
  //void CallBackModule(int id_module, F pFunc, A1 pObject);
  //
  //// параметризованная
  //template <typename F, typename P>
  //void CallBackModuleParam(int id_module, F pFunc, P* p);
  //template <typename F, class A1, typename P>
  //void CallBackModuleParam(int id_module, F pFunc, A1 pObject, P* p);
protected:
  bool NeedExit();
};
//---------------------------------------------------------------------------
//template <typename Func>
//void TModuleLogic::CallBackModule(int id_module, Func pFunc)
//{
//  TLogicEventCallBack0* pLCB = new TLogicEventCallBack0;
//  pLCB->mCB.Register( pFunc, this );
//  TSynchroAbonent::AddEventWithoutCopy(id_module, pLCB);
//}
////---------------------------------------------------------------------------
//template <typename Func, class A1>
//void TModuleLogic::CallBackModule(int id_module, Func pFunc, A1 pObject)
//{
//  TLogicEventCallBack0* pLCB = new TLogicEventCallBack0;
//  pLCB->mCB.Register( pFunc, pObject );
//  TSynchroAbonent::AddEventWithoutCopy(id_module, pLCB);
//}
////---------------------------------------------------------------------------
//template <typename F, typename P>
//void TModuleLogic::CallBackModuleParam(int id_module, F pFunc, P* p)
//{
//  TLogicEventCallBack1<P>* pLCB = new TLogicEventCallBack1<P>;
//  pLCB->mCB.Register( pFunc, this );
//  pLCB->pParam = p;
//  TSynchroAbonent::AddEventWithoutCopy(id_module, pLCB);
//}
////---------------------------------------------------------------------------
//template <typename F, class A1, typename P>
//void TModuleLogic::CallBackModuleParam(int id_module, F pFunc, A1 pObject, P* p)
//{
//  TLogicEventCallBack1<P>* pLCB = new TLogicEventCallBack1<P>;
//  pLCB->mCB.Register( pFunc, pObject );
//  pLCB->pParam = p;
//  TSynchroAbonent::AddEventWithoutCopy(id_module, pLCB);
//}
////---------------------------------------------------------------------------
#endif
