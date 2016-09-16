/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_ModelH
#define Pattern_ModelH

#include "TypeDef.h"
#include "BehaviourPattern.h"
#include "DataExchange2Thread.h"

class DllExport TPattern_Model : public TBehaviourPattern
{
  TDataExchange2Thread<nsMathTools::TVector3> mPipePositionLogic2Bullet;
  TDataExchange2Thread<nsMathTools::TVector3> mPipeOrientationLogic2Bullet;

public:
  TPattern_Model();
  virtual ~TPattern_Model();

  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TContainer c);// L
  virtual TContainer GetParameterToPattern();// B - Slave

  // меняет физику
  virtual void SetPosition(nsMathTools::TVector3& v);// L
  virtual bool GetPosition(nsMathTools::TVector3& v);// B, мгновенное значение
  virtual void SetOrientation(nsMathTools::TVector3& v);// L
  virtual bool GetOrientation(nsMathTools::TVector3& v);// B, мгновенное значение

  virtual bool LoadFromParameterMap();// L
  virtual bool UpdateFromGameItem(TBaseItem* pBI);// L
  virtual bool Unload();// L

  // Выполнить задания в каждом из потоков
  virtual void LoadFromThread_Ogre(bool fast = true);
  virtual void LoadFromThread_Bullet(bool fast = true);
  virtual void LoadFromThread_OpenAL(bool fast = true);

  virtual void UnloadFromThread_Ogre(bool fast = true);
  virtual void UnloadFromThread_Bullet(bool fast = true);
  virtual void UnloadFromThread_OpenAL(bool fast = true);

  virtual void SynchroFromThread_Logic(); // внешняя синхронизация
  virtual void SynchroFromThread_Ogre();  // графика от физики
  virtual void SynchroFromThread_Bullet();// внутренняя синхронизация
  virtual void SynchroFromThread_OpenAL();// звук от физики
protected:

  bool GetFromPipe(nsMathTools::TVector3& v, TDataExchange2Thread<nsMathTools::TVector3>* pPipe);
};

#endif
