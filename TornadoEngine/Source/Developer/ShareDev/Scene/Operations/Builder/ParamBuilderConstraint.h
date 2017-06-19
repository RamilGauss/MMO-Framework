/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ParamBuilderConstraintH
#define ParamBuilderConstraintH

#include "TypeDef.h"
#include <vector>
#include "ContainerTypes.h"
#include "MathTools.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsParamBuilderConstraint
{
  typedef enum
  {
    Generic6Dof,
		Universal,// non standard in bullet (has type Generic6DofSpring)
		Generic6DofSpring,
    Hinge2,   // non standard in bullet (has type Generic6DofSpring)
		Fixed,
    Slider,
    ConeTwist,
    Hinge,
    Point2Point,
    Gear,
		Contact,
  }eType;
  //--------------------------------------------------
  struct DllExport TBaseParam
  {
    eType type;
    float breakImpulse;
    TBaseParam(eType t){type=t;}
  }_PACKED;
  //--------------------------------------------------
  struct DllExport TGeneric6Dof : public TBaseParam
  {
    nsMathTools::TVector3 pointA;
    nsMathTools::TVector3 pointB;
    nsMathTools::TVector3 limitAngleLower;
    nsMathTools::TVector3 limitAngleUpper;
    nsMathTools::TVector3 limitLinearLower;
    nsMathTools::TVector3 limitLinearUpper;
    TGeneric6Dof();
  }_PACKED;
  //--------------------------------------------------
	struct DllExport TUniversal : public TGeneric6Dof
	{
		TUniversal();
	}_PACKED;
	//--------------------------------------------------
  struct DllExport TGeneric6DofSpring : public TBaseParam
  {
    nsMathTools::TVector3 pointA;
    nsMathTools::TVector3 pointB;
    nsMathTools::TVector3 limitAngleLower;
    nsMathTools::TVector3 limitAngleUpper;
    nsMathTools::TVector3 limitLinearLower;
    nsMathTools::TVector3 limitLinearUpper;
    float springStiffness;
    TGeneric6DofSpring();
  }_PACKED;
  //--------------------------------------------------
	struct DllExport THinge2 : public TBaseParam
	{
		nsMathTools::TVector3 pointA;
		nsMathTools::TVector3 pointB;
		nsMathTools::TVector3 axeA;
		nsMathTools::TVector3 axeB;
		float limitAngle_Min;
		float limitAngle_Max;
		float springStiffness;
		THinge2();
	}_PACKED;
	//--------------------------------------------------
  struct DllExport TFixed : public TBaseParam
  {
    nsMathTools::TVector3 pointA;
    nsMathTools::TVector3 pointB;
    TFixed();
    ~TFixed()
    {
      int a = 0;
    }
  }_PACKED;
  //--------------------------------------------------
  struct DllExport TSlider : public TBaseParam
  {
    nsMathTools::TVector3 pointA;
    nsMathTools::TVector3 pointB;
    float limitSliderMin;
    float limitSliderMax;
    TSlider();
  }_PACKED;
  //--------------------------------------------------
  struct DllExport TConeTwist : public TBaseParam
  {
    nsMathTools::TVector3 pointA;
    nsMathTools::TVector3 pointB;
    nsMathTools::TVector3 limitAngle;
    TConeTwist();
  }_PACKED;
  //--------------------------------------------------
  struct DllExport THinge : public TBaseParam
  {
    nsMathTools::TVector3 pointA;
    nsMathTools::TVector3 pointB;
    nsMathTools::TVector3 axeA;
    nsMathTools::TVector3 axeB;
    float limitAngle_Min;
    float limitAngle_Max;
    THinge();
  }_PACKED;
  //--------------------------------------------------
  struct DllExport TPoint2Point : public TBaseParam
  {
    nsMathTools::TVector3 pointA;
    nsMathTools::TVector3 pointB;
    TPoint2Point();
  }_PACKED;
  //--------------------------------------------------
  struct DllExport TGear : public TBaseParam
  {
    nsMathTools::TVector3 axeA;
    nsMathTools::TVector3 axeB;
    float ratio;
    TGear();
  }_PACKED;
  //--------------------------------------------------
	struct DllExport TContact : public TBaseParam
	{
		nsMathTools::TVector3 axeA;
		nsMathTools::TVector3 axeB;
		TContact();
	}_PACKED;
	//--------------------------------------------------
}

#ifdef WIN32
#pragma pack(pop)
#endif

#endif
