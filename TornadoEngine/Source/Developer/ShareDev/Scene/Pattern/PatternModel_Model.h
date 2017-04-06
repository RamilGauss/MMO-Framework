/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternModel_ModelH
#define PatternModel_ModelH

#include "TypeDef.h"
#include "BehaviourPatternModel.h"
#include "DataExchange2Thread.h"
#include "ModelItem.h"
#include "PatternContext_Model.h"

class DllExport TPatternModel_Model : public TBehaviourPatternModel
{
  TDataExchange2Thread<nsMathTools::TVector3> mPipePositionLogic2Bullet;
  TDataExchange2Thread<nsMathTools::TVector3> mPipeOrientationLogic2Bullet;

  TMapItem::TMapStrStr mDefaultParameterMap;
public:
  TPatternModel_Model();
  virtual ~TPatternModel_Model();

  // создать контекст для работы с этой моделью
  virtual TBehaviourPatternContext* MakeNewConext();
    
  virtual void GetDefaultParameterMap(TMapItem::TMapStrStr& m);// L

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
  virtual void LoadByModule_Logic();
  virtual bool LoadByModule_Graphic(bool fast = false);
  virtual bool LoadByModule_Physic(bool fast = false);
  virtual bool LoadByModule_Sound(bool fast = false);

  virtual void UnloadByModule_Logic();
  virtual bool UnloadByModule_Graphic(bool fast = false);
  virtual bool UnloadByModule_Physic(bool fast = false);
  virtual bool UnloadByModule_Sound(bool fast = false);

  virtual void SynchroByModule_Logic();  // внешняя синхронизация
  virtual void SynchroByModule_Graphic();// графика от физики
  virtual void SynchroByModule_Physic(); // внутренняя синхронизация
  virtual void SynchroByModule_Sound();  // звук от физики
protected:

  bool GetFromPipe(nsMathTools::TVector3& v, TDataExchange2Thread<nsMathTools::TVector3>* pPipe);

  void LoadModelsFromThread_Logic(TModelItem::TMapStrPart& mapNamePart);
  void LoadShapesFromThread_Logic(TModelItem::TMapStrPart& mapNamePart);

  void LoadShapeFromThread_Ogre(TPatternContext_Model::TShapeDesc* pShapeDesc);
	void PostLoadFromThread_Ogre();

	void LoadShapeFromThread_Bullet(TPatternContext_Model::TShapeDesc* pShapeDesc);
	void PostLoadFromThread_Bullet();
protected:

};

#endif
