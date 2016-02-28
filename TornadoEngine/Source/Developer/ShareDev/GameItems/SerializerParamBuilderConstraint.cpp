/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerParamBuilderConstraint.h"
#include "BL_Debug.h"

#include <boost/lexical_cast.hpp>

namespace nsSerializerParamBuilderConstraint
{
#define REGISTER_HANDLER(NAME_TYPE) \
mMapTypeName.insert(TMapIntStrVT(NAME_TYPE, #NAME_TYPE)); \
mCB_##NAME_TYPE##ToStruct.Register(&TSerializerParamBuilderConstraint::Handler##NAME_TYPE##ToStruct,this); \
mCB_##NAME_TYPE##ToStr.Register(&TSerializerParamBuilderConstraint::Handler##NAME_TYPE##ToStr,this); \
handler.toStruct = &mCB_##NAME_TYPE##ToStruct; \
handler.toStr    = &mCB_##NAME_TYPE##ToStr; \
mMapNameType_Handler.insert(TMapStrHandlerVT(#NAME_TYPE, handler));

  const char* sType              = "Type";

  const char* sBreakImpulse      = "BreakImpulse";
  
  const char* sPointA_X           = "PointA_X";
  const char* sPointA_Y           = "PointA_Y";
  const char* sPointA_Z           = "PointA_Z";
  const char* sPointB_X           = "PointB_X";
  const char* sPointB_Y           = "PointB_Y";
  const char* sPointB_Z           = "PointB_Z";
  const char* sLimitAngleLower_X  = "LimitAngleLower_X";
  const char* sLimitAngleLower_Y  = "LimitAngleLower_Y";
  const char* sLimitAngleLower_Z  = "LimitAngleLower_Z";
  const char* sLimitAngleUpper_X  = "LimitAngleUpper_X";
  const char* sLimitAngleUpper_Y  = "LimitAngleUpper_Y";
  const char* sLimitAngleUpper_Z  = "LimitAngleUpper_Z";
  const char* sLimitLinearLower_X = "LimitLinearLower_X";
  const char* sLimitLinearLower_Y = "LimitLinearLower_Y";
  const char* sLimitLinearLower_Z = "LimitLinearLower_Z";
  const char* sLimitLinearUpper_X = "LimitLinearUpper_X";
  const char* sLimitLinearUpper_Y = "LimitLinearUpper_Y";
  const char* sLimitLinearUpper_Z = "LimitLinearUpper_Z";
  const char* sSpringStiffness    = "SpringStiffness";
  const char* sLimitSlider_Min    = "LimitSlider_Min";
  const char* sLimitSlider_Max    = "LimitSlider_Max";
  const char* sLimitAngle_X       = "LimitAngle_X"; 
  const char* sLimitAngle_Y       = "LimitAngle_Y";
  const char* sLimitAngle_Z       = "LimitAngle_Z"; 
  const char* sAxeA_X             = "AxeA_X"; 
  const char* sAxeA_Y             = "AxeA_Y"; 
  const char* sAxeA_Z             = "AxeA_Z"; 
  const char* sAxeB_X             = "AxeB_X"; 
  const char* sAxeB_Y             = "AxeB_Y"; 
  const char* sAxeB_Z             = "AxeB_Z"; 
  const char* sLimitAngle_Min     = "LimitAngle_Min";
  const char* sLimitAngle_Max     = "LimitAngle_Max";
  const char* sRatio              = "Ratio";
}

using namespace nsSerializerParamBuilderConstraint;
using namespace nsParamBuilderConstraint;

TSerializerParamBuilderConstraint::TSerializerParamBuilderConstraint()
{
  Init();
}
//---------------------------------------------------------------------
TSerializerParamBuilderConstraint::~TSerializerParamBuilderConstraint()
{

}
//---------------------------------------------------------------------
nsParamBuilderConstraint::TBaseParam* TSerializerParamBuilderConstraint::GetParamByMap(TMapStrStr* pM)
{
  mMapKeyValue = pM;

  TMapStrStrIt fit = mMapKeyValue->find(sType);
  if(fit==mMapKeyValue->end())
  {
    BL_FIX_BUG();
    return NULL;
  }
  TMapStrHandlerIt fit_Handler = mMapNameType_Handler.find(fit->second);
  if(fit_Handler==mMapNameType_Handler.end())
  {
    BL_FIX_BUG();
    return NULL;
  }

  fit_Handler->second.toStruct->Notify();
  return mPtrParam;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::GetMapByParam(nsParamBuilderConstraint::TBaseParam* p, TMapStrStr* pM)
{
  mMapKeyValue = pM;
  mMapKeyValue->clear();

  mPtrParam = p;

  std::string strType = FindStrByType(p->type);
  TMapStrHandlerIt fit_Handler = mMapNameType_Handler.find(strType);
  if(fit_Handler==mMapNameType_Handler.end())
    return;

  fit_Handler->second.toStr->Notify();
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::Init()
{
  mMapKeyValue = NULL;
  mPtrParam = NULL;

  THandler handler;
  REGISTER_HANDLER(Generic6Dof);
  REGISTER_HANDLER(Generic6DofSpring);
  REGISTER_HANDLER(Fixed);
  REGISTER_HANDLER(Slider);
  REGISTER_HANDLER(ConeTwist);
  REGISTER_HANDLER(Hinge);
  REGISTER_HANDLER(Hinge2);
  REGISTER_HANDLER(Point2Point);
  REGISTER_HANDLER(Gear);
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerGeneric6DofToStruct()
{
  nsParamBuilderConstraint::TGeneric6Dof* pGeneric6Dof = new nsParamBuilderConstraint::TGeneric6Dof;
  pGeneric6Dof->breakImpulse = GetValueByName(sBreakImpulse);
  pGeneric6Dof->pointA.x = GetValueByName(sPointA_X);
  pGeneric6Dof->pointA.y = GetValueByName(sPointA_Y);
  pGeneric6Dof->pointA.z = GetValueByName(sPointA_Z);
  pGeneric6Dof->pointB.x = GetValueByName(sPointB_X);
  pGeneric6Dof->pointB.y = GetValueByName(sPointB_Y);
  pGeneric6Dof->pointB.z = GetValueByName(sPointB_Z);

  pGeneric6Dof->limitAngleLower.x = GetValueByName(sLimitAngleLower_X);
  pGeneric6Dof->limitAngleLower.y = GetValueByName(sLimitAngleLower_Y);
  pGeneric6Dof->limitAngleLower.z = GetValueByName(sLimitAngleLower_Z);

  pGeneric6Dof->limitAngleUpper.x = GetValueByName(sLimitAngleUpper_X);
  pGeneric6Dof->limitAngleUpper.y = GetValueByName(sLimitAngleUpper_Y);
  pGeneric6Dof->limitAngleUpper.z = GetValueByName(sLimitAngleUpper_Z);

  pGeneric6Dof->limitLinearLower.x = GetValueByName(sLimitLinearLower_X);
  pGeneric6Dof->limitLinearLower.y = GetValueByName(sLimitLinearLower_Y);
  pGeneric6Dof->limitLinearLower.z = GetValueByName(sLimitLinearLower_Z);

  pGeneric6Dof->limitLinearUpper.x = GetValueByName(sLimitLinearUpper_X);
  pGeneric6Dof->limitLinearUpper.y = GetValueByName(sLimitLinearUpper_Y);
  pGeneric6Dof->limitLinearUpper.z = GetValueByName(sLimitLinearUpper_Z);

  mPtrParam = pGeneric6Dof;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerGeneric6DofSpringToStruct()
{
  nsParamBuilderConstraint::TGeneric6DofSpring* pGeneric6DofSpring = new nsParamBuilderConstraint::TGeneric6DofSpring;
  pGeneric6DofSpring->breakImpulse = GetValueByName(sBreakImpulse);
  pGeneric6DofSpring->pointA.x = GetValueByName(sPointA_X);
  pGeneric6DofSpring->pointA.y = GetValueByName(sPointA_Y);
  pGeneric6DofSpring->pointA.z = GetValueByName(sPointA_Z);
  pGeneric6DofSpring->pointB.x = GetValueByName(sPointB_X);
  pGeneric6DofSpring->pointB.y = GetValueByName(sPointB_Y);
  pGeneric6DofSpring->pointB.z = GetValueByName(sPointB_Z);

  pGeneric6DofSpring->limitAngleLower.x = GetValueByName(sLimitAngleLower_X);
  pGeneric6DofSpring->limitAngleLower.y = GetValueByName(sLimitAngleLower_Y);
  pGeneric6DofSpring->limitAngleLower.z = GetValueByName(sLimitAngleLower_Z);

  pGeneric6DofSpring->limitAngleUpper.x = GetValueByName(sLimitAngleUpper_X);
  pGeneric6DofSpring->limitAngleUpper.y = GetValueByName(sLimitAngleUpper_Y);
  pGeneric6DofSpring->limitAngleUpper.z = GetValueByName(sLimitAngleUpper_Z);

  pGeneric6DofSpring->limitLinearLower.x = GetValueByName(sLimitLinearLower_X);
  pGeneric6DofSpring->limitLinearLower.y = GetValueByName(sLimitLinearLower_Y);
  pGeneric6DofSpring->limitLinearLower.z = GetValueByName(sLimitLinearLower_Z);

  pGeneric6DofSpring->limitLinearUpper.x = GetValueByName(sLimitLinearUpper_X);
  pGeneric6DofSpring->limitLinearUpper.y = GetValueByName(sLimitLinearUpper_Y);
  pGeneric6DofSpring->limitLinearUpper.z = GetValueByName(sLimitLinearUpper_Z);

  mPtrParam = pGeneric6DofSpring;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerFixedToStruct()
{
  nsParamBuilderConstraint::TFixed* pFixed = new nsParamBuilderConstraint::TFixed;
  pFixed->breakImpulse = GetValueByName(sBreakImpulse);
  pFixed->pointA.x = GetValueByName(sPointA_X);
  pFixed->pointA.y = GetValueByName(sPointA_Y);
  pFixed->pointA.z = GetValueByName(sPointA_Z);
  pFixed->pointB.x = GetValueByName(sPointB_X);
  pFixed->pointB.y = GetValueByName(sPointB_Y);
  pFixed->pointB.z = GetValueByName(sPointB_Z);

  mPtrParam = pFixed;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerSliderToStruct()
{
  nsParamBuilderConstraint::TSlider* pSlider = new nsParamBuilderConstraint::TSlider;
  pSlider->breakImpulse = GetValueByName(sBreakImpulse);
  pSlider->pointA.x = GetValueByName(sPointA_X);
  pSlider->pointA.y = GetValueByName(sPointA_Y);
  pSlider->pointA.z = GetValueByName(sPointA_Z);
  pSlider->pointB.x = GetValueByName(sPointB_X);
  pSlider->pointB.y = GetValueByName(sPointB_Y);
  pSlider->pointB.z = GetValueByName(sPointB_Z);

  pSlider->limitSliderMax = GetValueByName(sLimitSlider_Max);
  pSlider->limitSliderMin = GetValueByName(sLimitSlider_Min);

  mPtrParam = pSlider;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerConeTwistToStruct()
{
  nsParamBuilderConstraint::TConeTwist* pConeTwist = new nsParamBuilderConstraint::TConeTwist;
  pConeTwist->breakImpulse = GetValueByName(sBreakImpulse);
  pConeTwist->pointA.x = GetValueByName(sPointA_X);
  pConeTwist->pointA.y = GetValueByName(sPointA_Y);
  pConeTwist->pointA.z = GetValueByName(sPointA_Z);
  pConeTwist->pointB.x = GetValueByName(sPointB_X);
  pConeTwist->pointB.y = GetValueByName(sPointB_Y);
  pConeTwist->pointB.z = GetValueByName(sPointB_Z);

  pConeTwist->limitAngle.x = GetValueByName(sLimitAngle_X);
  pConeTwist->limitAngle.y = GetValueByName(sLimitAngle_Y);
  pConeTwist->limitAngle.y = GetValueByName(sLimitAngle_Z);

  mPtrParam = pConeTwist;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerHingeToStruct()
{
  nsParamBuilderConstraint::THinge* pHinge = new nsParamBuilderConstraint::THinge;
  pHinge->breakImpulse = GetValueByName(sBreakImpulse);
  pHinge->pointA.x = GetValueByName(sPointA_X);
  pHinge->pointA.y = GetValueByName(sPointA_Y);
  pHinge->pointA.z = GetValueByName(sPointA_Z);
  pHinge->pointB.x = GetValueByName(sPointB_X);
  pHinge->pointB.y = GetValueByName(sPointB_Y);
  pHinge->pointB.z = GetValueByName(sPointB_Z);

  pHinge->axeA.x = GetValueByName(sAxeA_X);
  pHinge->axeA.y = GetValueByName(sAxeA_X);
  pHinge->axeA.y = GetValueByName(sAxeA_X);

  pHinge->axeA.x = GetValueByName(sAxeB_X);
  pHinge->axeA.y = GetValueByName(sAxeB_X);
  pHinge->axeA.y = GetValueByName(sAxeB_X);

  pHinge->limitAngle_Max = GetValueByName(sLimitAngle_Max);
  pHinge->limitAngle_Min = GetValueByName(sLimitAngle_Min);

  mPtrParam = pHinge;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerHinge2ToStruct()
{
  nsParamBuilderConstraint::THinge2* pHinge2 = new nsParamBuilderConstraint::THinge2;
  pHinge2->breakImpulse = GetValueByName(sBreakImpulse);
  pHinge2->pointA.x = GetValueByName(sPointA_X);
  pHinge2->pointA.y = GetValueByName(sPointA_Y);
  pHinge2->pointA.z = GetValueByName(sPointA_Z);
  pHinge2->pointB.x = GetValueByName(sPointB_X);
  pHinge2->pointB.y = GetValueByName(sPointB_Y);
  pHinge2->pointB.z = GetValueByName(sPointB_Z);

  pHinge2->axeA.x = GetValueByName(sAxeA_X);
  pHinge2->axeA.y = GetValueByName(sAxeA_X);
  pHinge2->axeA.y = GetValueByName(sAxeA_X);

  pHinge2->axeA.x = GetValueByName(sAxeB_X);
  pHinge2->axeA.y = GetValueByName(sAxeB_X);
  pHinge2->axeA.y = GetValueByName(sAxeB_X);

  pHinge2->limitAngle_Max = GetValueByName(sLimitAngle_Max);
  pHinge2->limitAngle_Min = GetValueByName(sLimitAngle_Min);

  pHinge2->springStiffness = GetValueByName(sSpringStiffness);

  mPtrParam = pHinge2;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerPoint2PointToStruct()
{
  nsParamBuilderConstraint::TPoint2Point* pPoint2Point = new nsParamBuilderConstraint::TPoint2Point;
  pPoint2Point->breakImpulse = GetValueByName(sBreakImpulse);
  pPoint2Point->pointA.x = GetValueByName(sPointA_X);
  pPoint2Point->pointA.y = GetValueByName(sPointA_Y);
  pPoint2Point->pointA.z = GetValueByName(sPointA_Z);
  pPoint2Point->pointB.x = GetValueByName(sPointB_X);
  pPoint2Point->pointB.y = GetValueByName(sPointB_Y);
  pPoint2Point->pointB.z = GetValueByName(sPointB_Z);
  
  mPtrParam = pPoint2Point;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerGearToStruct()
{
  nsParamBuilderConstraint::TGear* pGear = new nsParamBuilderConstraint::TGear;
  pGear->breakImpulse = GetValueByName(sBreakImpulse);
  pGear->axeA.x = GetValueByName(sAxeA_X);
  pGear->axeA.y = GetValueByName(sAxeA_Y);
  pGear->axeA.z = GetValueByName(sAxeA_Z);
  pGear->axeB.x = GetValueByName(sAxeB_X);
  pGear->axeB.y = GetValueByName(sAxeB_Y);
  pGear->axeB.z = GetValueByName(sAxeB_Z);

  pGear->ratio = GetValueByName(sRatio);

  mPtrParam = pGear;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerGeneric6DofToStr()
{
  nsParamBuilderConstraint::TGeneric6Dof* pGeneric6Dof = (nsParamBuilderConstraint::TGeneric6Dof*)mPtrParam;

  std::string strType = FindStrByType(pGeneric6Dof->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pGeneric6Dof->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pGeneric6Dof->pointA.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->pointA.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->pointA.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6Dof->pointB.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->pointB.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->pointB.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitAngleLower.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleLower_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitAngleLower.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleLower_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitAngleLower.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleLower_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitAngleUpper.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleUpper_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitAngleUpper.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleUpper_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitAngleUpper.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleUpper_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitLinearLower.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearLower_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitLinearLower.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearLower_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitLinearLower.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearLower_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitLinearUpper.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearUpper_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitLinearUpper.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearUpper_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6Dof->limitLinearUpper.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearUpper_Z, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerGeneric6DofSpringToStr()
{
  nsParamBuilderConstraint::TGeneric6DofSpring* pGeneric6DofSpring = (nsParamBuilderConstraint::TGeneric6DofSpring*)mPtrParam;

  std::string strType = FindStrByType(pGeneric6DofSpring->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->pointA.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->pointA.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->pointA.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->pointB.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->pointB.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->pointB.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitAngleLower.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleLower_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitAngleLower.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleLower_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitAngleLower.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleLower_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitAngleUpper.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleUpper_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitAngleUpper.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleUpper_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitAngleUpper.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngleUpper_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitLinearLower.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearLower_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitLinearLower.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearLower_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitLinearLower.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearLower_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitLinearUpper.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearUpper_X, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitLinearUpper.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearUpper_Y, value));
  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->limitLinearUpper.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitLinearUpper_Z, value));

  value = boost::lexical_cast<std::string>(pGeneric6DofSpring->springStiffness);
  mMapKeyValue->insert(TMapStrStrVT(sSpringStiffness, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerFixedToStr()
{
  nsParamBuilderConstraint::TFixed* pFixed = (nsParamBuilderConstraint::TFixed*)mPtrParam;

  std::string strType = FindStrByType(pFixed->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pFixed->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pFixed->pointA.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_X, value));
  value = boost::lexical_cast<std::string>(pFixed->pointA.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Y, value));
  value = boost::lexical_cast<std::string>(pFixed->pointA.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Z, value));

  value = boost::lexical_cast<std::string>(pFixed->pointB.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_X, value));
  value = boost::lexical_cast<std::string>(pFixed->pointB.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Y, value));
  value = boost::lexical_cast<std::string>(pFixed->pointB.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Z, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerSliderToStr()
{
  nsParamBuilderConstraint::TSlider* pSlider = (nsParamBuilderConstraint::TSlider*)mPtrParam;

  std::string strType = FindStrByType(pSlider->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pSlider->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pSlider->pointA.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_X, value));
  value = boost::lexical_cast<std::string>(pSlider->pointA.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Y, value));
  value = boost::lexical_cast<std::string>(pSlider->pointA.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Z, value));

  value = boost::lexical_cast<std::string>(pSlider->pointB.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_X, value));
  value = boost::lexical_cast<std::string>(pSlider->pointB.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Y, value));
  value = boost::lexical_cast<std::string>(pSlider->pointB.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Z, value));

  value = boost::lexical_cast<std::string>(pSlider->limitSliderMax);
  mMapKeyValue->insert(TMapStrStrVT(sLimitSlider_Max, value));
  value = boost::lexical_cast<std::string>(pSlider->limitSliderMin);
  mMapKeyValue->insert(TMapStrStrVT(sLimitSlider_Min, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerConeTwistToStr()
{
  nsParamBuilderConstraint::TConeTwist* pConeTwist = (nsParamBuilderConstraint::TConeTwist*)mPtrParam;

  std::string strType = FindStrByType(pConeTwist->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pConeTwist->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pConeTwist->pointA.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_X, value));
  value = boost::lexical_cast<std::string>(pConeTwist->pointA.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Y, value));
  value = boost::lexical_cast<std::string>(pConeTwist->pointA.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Z, value));

  value = boost::lexical_cast<std::string>(pConeTwist->pointB.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_X, value));
  value = boost::lexical_cast<std::string>(pConeTwist->pointB.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Y, value));
  value = boost::lexical_cast<std::string>(pConeTwist->pointB.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Z, value));

  value = boost::lexical_cast<std::string>(pConeTwist->limitAngle.x);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngle_X, value));
  value = boost::lexical_cast<std::string>(pConeTwist->limitAngle.y);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngle_Y, value));
  value = boost::lexical_cast<std::string>(pConeTwist->limitAngle.z);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngle_Z, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerHingeToStr()
{
  nsParamBuilderConstraint::THinge* pHinge = (nsParamBuilderConstraint::THinge*)mPtrParam;

  std::string strType = FindStrByType(pHinge->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pHinge->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pHinge->pointA.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_X, value));
  value = boost::lexical_cast<std::string>(pHinge->pointA.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Y, value));
  value = boost::lexical_cast<std::string>(pHinge->pointA.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Z, value));

  value = boost::lexical_cast<std::string>(pHinge->pointB.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_X, value));
  value = boost::lexical_cast<std::string>(pHinge->pointB.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Y, value));
  value = boost::lexical_cast<std::string>(pHinge->pointB.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Z, value));

  value = boost::lexical_cast<std::string>(pHinge->axeA.x);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_X, value));
  value = boost::lexical_cast<std::string>(pHinge->axeA.y);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_Y, value));
  value = boost::lexical_cast<std::string>(pHinge->axeA.z);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_Z, value));

  value = boost::lexical_cast<std::string>(pHinge->axeB.x);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_X, value));
  value = boost::lexical_cast<std::string>(pHinge->axeB.y);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_Y, value));
  value = boost::lexical_cast<std::string>(pHinge->axeB.z);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_Z, value));

  value = boost::lexical_cast<std::string>(pHinge->limitAngle_Max);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngle_Max, value));
  value = boost::lexical_cast<std::string>(pHinge->limitAngle_Min);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngle_Min, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerHinge2ToStr()
{
  nsParamBuilderConstraint::THinge2* pHinge2 = (nsParamBuilderConstraint::THinge2*)mPtrParam;

  std::string strType = FindStrByType(pHinge2->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pHinge2->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pHinge2->pointA.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_X, value));
  value = boost::lexical_cast<std::string>(pHinge2->pointA.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Y, value));
  value = boost::lexical_cast<std::string>(pHinge2->pointA.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Z, value));

  value = boost::lexical_cast<std::string>(pHinge2->pointB.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_X, value));
  value = boost::lexical_cast<std::string>(pHinge2->pointB.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Y, value));
  value = boost::lexical_cast<std::string>(pHinge2->pointB.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Z, value));

  value = boost::lexical_cast<std::string>(pHinge2->axeA.x);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_X, value));
  value = boost::lexical_cast<std::string>(pHinge2->axeA.y);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_Y, value));
  value = boost::lexical_cast<std::string>(pHinge2->axeA.z);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_Z, value));

  value = boost::lexical_cast<std::string>(pHinge2->axeB.x);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_X, value));
  value = boost::lexical_cast<std::string>(pHinge2->axeB.y);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_Y, value));
  value = boost::lexical_cast<std::string>(pHinge2->axeB.z);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_Z, value));

  value = boost::lexical_cast<std::string>(pHinge2->limitAngle_Max);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngle_Max, value));
  value = boost::lexical_cast<std::string>(pHinge2->limitAngle_Min);
  mMapKeyValue->insert(TMapStrStrVT(sLimitAngle_Min, value));

  value = boost::lexical_cast<std::string>(pHinge2->springStiffness);
  mMapKeyValue->insert(TMapStrStrVT(sSpringStiffness, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerPoint2PointToStr()
{
  nsParamBuilderConstraint::TPoint2Point* pPoint2Point = (nsParamBuilderConstraint::TPoint2Point*)mPtrParam;

  std::string strType = FindStrByType(pPoint2Point->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pPoint2Point->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pPoint2Point->pointA.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_X, value));
  value = boost::lexical_cast<std::string>(pPoint2Point->pointA.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Y, value));
  value = boost::lexical_cast<std::string>(pPoint2Point->pointA.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointA_Z, value));

  value = boost::lexical_cast<std::string>(pPoint2Point->pointB.x);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_X, value));
  value = boost::lexical_cast<std::string>(pPoint2Point->pointB.y);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Y, value));
  value = boost::lexical_cast<std::string>(pPoint2Point->pointB.z);
  mMapKeyValue->insert(TMapStrStrVT(sPointB_Z, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderConstraint::HandlerGearToStr()
{
  nsParamBuilderConstraint::TGear* pGear = (nsParamBuilderConstraint::TGear*)mPtrParam;

  std::string strType = FindStrByType(pGear->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pGear->breakImpulse);
  mMapKeyValue->insert(TMapStrStrVT(sBreakImpulse, value));

  value = boost::lexical_cast<std::string>(pGear->axeA.x);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_X, value));
  value = boost::lexical_cast<std::string>(pGear->axeA.y);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_Y, value));
  value = boost::lexical_cast<std::string>(pGear->axeA.z);
  mMapKeyValue->insert(TMapStrStrVT(sAxeA_Z, value));

  value = boost::lexical_cast<std::string>(pGear->axeB.x);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_X, value));
  value = boost::lexical_cast<std::string>(pGear->axeB.y);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_Y, value));
  value = boost::lexical_cast<std::string>(pGear->axeB.z);
  mMapKeyValue->insert(TMapStrStrVT(sAxeB_Z, value));

  value = boost::lexical_cast<std::string>(pGear->ratio);
  mMapKeyValue->insert(TMapStrStrVT(sRatio, value));
}
//---------------------------------------------------------------------
float TSerializerParamBuilderConstraint::GetValueByName(const char* name)
{
  TMapStrStrIt fit = mMapKeyValue->find(name);
  if(fit==mMapKeyValue->end()) 
    return 0.0;

  return atof(fit->second.data());
}
//---------------------------------------------------------------------
std::string TSerializerParamBuilderConstraint::FindStrByType(int type)
{
  TMapIntStrIt fit = mMapTypeName.find(type);
  if(fit==mMapTypeName.end())
    return "";
  return fit->second;
}
//---------------------------------------------------------------------
