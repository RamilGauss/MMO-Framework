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
  virtual void LoadFromThread_Logic(TBehaviourPatternContext* pContext);
  virtual bool LoadFromThread_Ogre(TBehaviourPatternContext* pContext, bool fast = true);
  virtual bool LoadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast = true);
  virtual bool LoadFromThread_OpenAL(TBehaviourPatternContext* pContext, bool fast = true);

  virtual void UnloadFromThread_Logic(TBehaviourPatternContext* pContext);
  virtual bool UnloadFromThread_Ogre(TBehaviourPatternContext* pContext, bool fast = true);
  virtual bool UnloadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast = true);
  virtual bool UnloadFromThread_OpenAL(TBehaviourPatternContext* pContext, bool fast = true);

  virtual void SynchroFromThread_Logic(TBehaviourPatternContext* pContext); // внешняя синхронизация
  virtual void SynchroFromThread_Ogre(TBehaviourPatternContext* pContext);  // графика от физики
  virtual void SynchroFromThread_Bullet(TBehaviourPatternContext* pContext);// внутренняя синхронизация
  virtual void SynchroFromThread_OpenAL(TBehaviourPatternContext* pContext);// звук от физики
protected:

  bool GetFromPipe(nsMathTools::TVector3& v, TDataExchange2Thread<nsMathTools::TVector3>* pPipe);

  void LoadModelsFromThread_Logic(TPatternContext_Model* pContextModel, TModelItem::TMapStrPart& mapNamePart);
  void LoadShapesFromThread_Logic(TPatternContext_Model* pContextModel, TModelItem::TMapStrPart& mapNamePart);

  void LoadShapeFromThread_Ogre(TPatternContext_Model* pContextModel, TPatternContext_Model::TShapeDesc* pShapeDesc);

protected:

};

#endif
