/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_ModelH
#define PatternContext_ModelH

#include "TypeDef.h"
#include "BehaviourPatternContext.h"

#include "PatternConfigItem.h"
#include "ModelItem.h"
#include <OgreEntity.h>

class btRigidBody;
class TPatternModel_Model;

class DllExport TPatternContext_Model : public TBehaviourPatternContext
{
  TModelItem::eType mTypeContent;
public:
  struct TBaseDesc
  {
    TModelItem::eType type;
    std::string  namePart;
    std::string  nameVariant;
  };
  struct TModelDesc : public TBaseDesc
  {
    TPatternModel_Model* pModel;
    TModelDesc(){type=TModelItem::eModel;pModel=NULL;}
    ~TModelDesc();
  };
  struct TShapeDesc : public TBaseDesc
  {
    std::string  nameShapeItem;
    std::string  nameMaterial; // реальный материал и переопределенный могут не совпадать
    // результат создания формы:
		Ogre::Entity* pEntity;
		btRigidBody* pRigidBody;
    TShapeDesc(){type=TModelItem::eShape;pRigidBody=NULL;pEntity=NULL;}
  };
protected:
  TPatternConfigItem::TMapStrStr mMapVariantPatternConfig;

  typedef std::map<std::string,TBaseDesc*> TMapStrPtrDesc;
  typedef TMapStrPtrDesc::iterator         TMapStrPtrDescIt;
  typedef TMapStrPtrDesc::value_type       TMapStrPtrDescVT;
  
  typedef std::map<std::string,TMapStrPtrDesc> TMapStr_StrPtrDesc;
  typedef TMapStr_StrPtrDesc::iterator        TMapStr_StrPtrDescIt;
  typedef TMapStr_StrPtrDesc::value_type      TMapStr_StrPtrDescVT;

  // набор форм или моделей
  TMapStr_StrPtrDesc mMapNamePart_NameVariantDesc;

  std::string mNameGameItem;
  std::string mNameVariantPatternConfig;
  bool        flgMobility;
public:
  TPatternContext_Model(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Model();
  
  TModelItem::eType GetTypeContent();
  void SetTypeContent(TModelItem::eType type);

  // игровой итэм для загрузки и управления частями
  void SetNameGameItem(std::string& name);
  std::string GetNameGameItem();
  // имя вариант паттерна
  void SetNameVariantPatternConfig(std::string& name);
  std::string GetNameVariantPatternConfig();
  // подвижность
  void SetMobility(bool v);
  bool GetMobility();
  // вариант паттерна
  void SetMapVariant(TPatternConfigItem::TMapStrStr& mapVariant);
  
  void AddDesc(TBaseDesc* pDesc);
  TBaseDesc* GetDesc(std::string& namePart, std::string& nameVariant);

  int GetCountPart();
  std::string GetNamePart(int index);

  int GetCountVariant(std::string& namePart);
  std::string GetNameVariant(std::string& namePart, int index);

protected:
  TMapStrPtrDesc* FindMapByNamePart(std::string& namePart);
};

#endif
