/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryBehaviourPatternH
#define FactoryBehaviourPatternH

#include "TypeDef.h"
#include "CallBackRegistrator.h"
#include <string>

class TBehaviourPattern;

class DllExport TFactoryBehaviourPattern
{
protected:
  typedef std::map<std::string,TCallBackRegistrator1<TBehaviourPattern*&>* > TMapStrCB;
  typedef TMapStrCB::iterator                                                TMapStrCBIt;
  typedef TMapStrCB::value_type                                              TMapStrCBVT;
private:
  TMapStrCB mMapNameMakerPattern;

  TCallBackRegistrator1<TBehaviourPattern*&> mCB_MapParameter;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Animated;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Light;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Model;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Sound;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Skybox;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Skydome;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Skyplane;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Terrain;
  TCallBackRegistrator1<TBehaviourPattern*&> mCB_Volume;
public:
  TFactoryBehaviourPattern();
  virtual ~TFactoryBehaviourPattern();

  TBehaviourPattern* GetPatternByName(std::string name);
  int GetCount();
  std::string GetNameByIndex(int index);

protected:
  void AddPattern(TMapStrCBVT& vt_cb);
private:
  void MakeMapParameter(TBehaviourPattern*& p);
  void MakeAnimated(TBehaviourPattern*& p);
  void MakeLight(TBehaviourPattern*& p);
  void MakeModel(TBehaviourPattern*& p);
  void MakeSkybox(TBehaviourPattern*& p);
  void MakeSkydome(TBehaviourPattern*& p);
  void MakeSkyplane(TBehaviourPattern*& p);
  void MakeSound(TBehaviourPattern*& p);
  void MakeTerrain(TBehaviourPattern*& p);
  void MakeVolume(TBehaviourPattern*& p);
private:
  TBehaviourPattern* MakePatternByName(std::string name);
  void Done();
};

#endif
