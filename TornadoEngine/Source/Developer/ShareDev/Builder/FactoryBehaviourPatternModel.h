/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryBehaviourPatternModelH
#define FactoryBehaviourPatternModelH

#include "TypeDef.h"
#include "CallBackRegistrator.h"
#include <string>

class TBehaviourPatternModel;

class DllExport TFactoryBehaviourPatternModel
{
  typedef std::map<std::string,TBehaviourPatternModel*> TMapStrPtrModel;
  typedef TMapStrPtrModel::iterator   TMapStrPtrModelIt;
  typedef TMapStrPtrModel::value_type TMapStrPtrModelVT;

  TMapStrPtrModel mMapNamePtrModel;
protected:
  typedef std::map<std::string,TCallBackRegistrator1<TBehaviourPatternModel*&>* > TMapStrCB;
  typedef TMapStrCB::iterator                                                TMapStrCBIt;
  typedef TMapStrCB::value_type                                              TMapStrCBVT;
private:
  TMapStrCB mMapNameMakerPattern;

  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Animated;
  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Light;
  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Model;
  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Sound;
  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Skybox;
	TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Skydome;
	TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Skyplane;
  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Terrain;
  TCallBackRegistrator1<TBehaviourPatternModel*&> mCB_Zone;
public:
  TFactoryBehaviourPatternModel();
  virtual ~TFactoryBehaviourPatternModel();

  TBehaviourPatternModel* GetPatternByName(std::string name);
  int GetCount();
  std::string GetNameByIndex(int index);

protected:
  void AddPattern(TMapStrCBVT& vt_cb);
private:
  void MakeAnimated(TBehaviourPatternModel*& p);
  void MakeLight(TBehaviourPatternModel*& p);
  void MakeModel(TBehaviourPatternModel*& p);
  void MakeSkybox(TBehaviourPatternModel*& p);
	void MakeSkydome(TBehaviourPatternModel*& p);
	void MakeSkyplane(TBehaviourPatternModel*& p);
  void MakeSound(TBehaviourPatternModel*& p);
  void MakeTerrain(TBehaviourPatternModel*& p);
  void MakeZone(TBehaviourPatternModel*& p);
private:
  TBehaviourPatternModel* MakePatternByName(std::string name);
  void Done();
};

#endif
