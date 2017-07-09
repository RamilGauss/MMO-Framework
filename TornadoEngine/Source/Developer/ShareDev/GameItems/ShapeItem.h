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
#include <map>
#include <string>
#include <boost/smart_ptr/scoped_ptr.hpp>

#include "ParamBuilderShape.h"
#include "MathTools.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

struct DllExport TShapeItem : public TBaseItem
{
  struct DllExport TJoint
  {
    nsMathTools::TVector3    position;
		nsMathTools::TQuaternion orientation;
  };
  //---------------------------------------------------------
  struct DllExport TLOD
  {
    std::string color;
    std::string normal;
  };
  //---------------------------------------------------------
  typedef std::map<float,TLOD>       TMapFloatLayer;
  typedef TMapFloatLayer::iterator   TMapFloatLayerIt;
  typedef TMapFloatLayer::value_type TMapFloatLayerVT;
  //---------------------------------------------------------
  typedef std::map<std::string,TJoint> TMapStrJoint;
  typedef TMapStrJoint::iterator       TMapStrJointIt;
  typedef TMapStrJoint::value_type     TMapStrJointVT;
  //---------------------------------------------------------
  //---------------------------------------------------------
  TMapStrJoint                mMapNameJoint;    // места подсоединения других форм
  std::vector<TMapFloatLayer> mVecPaint;        // слои краски
  std::string                 mNameMaterial;    // имя материала
  bool                        flgUseNatureColor;// использовать ли цвет материала
  boost::scoped_ptr<nsParamBuilderShape::TBaseParam> mPtrGeometry;

  TShapeItem(std::string& name);
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif
