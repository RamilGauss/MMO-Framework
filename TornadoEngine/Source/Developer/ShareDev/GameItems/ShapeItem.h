/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ShapeItemH
#define ShapeItemH

#include "BaseItem.h"

#include <vector>
#include <string>

#include <boost/smart_ptr/scoped_ptr.hpp>
#include "ParamBuilderShape.h"
#include "TypeDef.h"

struct DllExport TShapeItem : public TBaseItem
{
  struct TLOD
  {
    float distance;
    std::string color;
    std::string normal;
  };

  typedef std::vector<TLOD> TLayer;

  std::vector<TLayer> mVecPaint;// слои краски
  std::string mNameMaterial;    // имя материала
  bool flgUseNatureColor;       // использовать ли цвет материала
  boost::scoped_ptr<nsParamBuilderShape::TBaseParam> mPtrGeometry;

  TShapeItem(std::string& name);
};

#endif
