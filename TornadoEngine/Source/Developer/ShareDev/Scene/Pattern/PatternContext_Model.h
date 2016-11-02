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

struct TShapeItem;

class DllExport TPatternContext_Model : public TBehaviourPatternContext
{
protected:
  TPatternConfigItem::TMapStrStr mMapVariant;

  typedef std::map<std::string,TShapeItem*> TMapStrPtrShapeItem;
  typedef TMapStrPtrShapeItem::iterator     TMapStrPtrShapeItemIt;
  typedef TMapStrPtrShapeItem::value_type   TMapStrPtrShapeItemVT;

  typedef std::map<std::string,TPatternContext_Model*> TMapStrPtrContextModel;
  typedef TMapStrPtrContextModel::iterator             TMapStrPtrContextModelIt;
  typedef TMapStrPtrContextModel::value_type           TMapStrPtrContextModelVT;

  // набор форм
  TMapStrPtrShapeItem    mMapNameShape;
  // связь с другими моделями
  TMapStrPtrContextModel mMapNameCtxModel;
public:
  TPatternContext_Model(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Model();

  void SetMapVariant(TPatternConfigItem::TMapStrStr& mapVariant);

  void AddShapeItem(std::string name, TShapeItem* pShapeItem);
};

#endif
