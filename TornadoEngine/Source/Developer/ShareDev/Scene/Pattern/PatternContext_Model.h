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

class DllExport TPatternContext_Model : public TBehaviourPatternContext
{
public:
  struct TShape
  {
    std::string  namePart;
    std::string  nameVariant;
    std::string  nameShapeItem;
    std::string  nameMaterial; // реальный материал и переопределенный могут не совпадать
    // результат создания формы:
    unsigned int id_mesh_ogre;
    unsigned int id_mesh_bullet;
    TShape(){id_mesh_ogre=0;id_mesh_bullet=0;}
  };
protected:
  TPatternConfigItem::TMapStrStr mMapVariant;

  typedef std::map<std::string,TShape*> TMapStrPtrShape;
  typedef TMapStrPtrShape::iterator     TMapStrPtrShapeIt;
  typedef TMapStrPtrShape::value_type   TMapStrPtrShapeVT;
  
  typedef std::map<std::string,TMapStrPtrShape> TMapStrMapStrPtrShape;
  typedef TMapStrMapStrPtrShape::iterator       TMapStrMapStrPtrShapeIt;
  typedef TMapStrMapStrPtrShape::value_type     TMapStrMapStrPtrShapeVT;

  typedef std::multimap<std::string,TPatternContext_Model*> TMMapStrPtrContextModel;
  typedef TMMapStrPtrContextModel::iterator             TMMapStrPtrContextModelIt;
  typedef TMMapStrPtrContextModel::value_type           TMMapStrPtrContextModelVT;

  typedef std::map<std::string,TPatternContext_Model*> TMapStrPtrContextModel;
  typedef TMapStrPtrContextModel::iterator             TMapStrPtrContextModelIt;
  typedef TMapStrPtrContextModel::value_type           TMapStrPtrContextModelVT;

  // набор форм
  TMapStrMapStrPtrShape   mMapNamePart_MapNameVariantShape;

  TMMapStrPtrContextModel mMapNameContextModel;
  // связь с другими моделями
  TMapStrPtrContextModel mMapNameCtxModel;

  std::string mNameGameItem;
  std::string mNameVariantPatternConfig;
  bool        flgMobility;
public:
  TPatternContext_Model(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Model();

  void SetNameGameItem(std::string& name);
  std::string GetNameGameItem();

  void SetNameVariantPatternConfig(std::string& name);
  std::string GetNameVariantPatternConfig();

  void SetMobility(bool v);
  bool GetMobility();

  void SetMapVariant(TPatternConfigItem::TMapStrStr& mapVariant);

  void AddShape(TShape* pShape);
  TShape* GetShape(std::string namePart, std::string nameVariant);

  void AddContextModel(std::string name, TPatternContext_Model* pContextModel);
};

#endif
