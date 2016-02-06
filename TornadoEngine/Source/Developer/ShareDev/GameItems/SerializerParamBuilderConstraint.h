/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerParamBuilderConstraintH
#define SerializerParamBuilderConstraintH

#include "TypeDef.h"
#include <map>
#include <string>

#include "ParamBuilderConstraint.h"
#include "CallBackRegistrator.h"

class DllExport TSerializerParamBuilderConstraint
{
  typedef std::map<int,std::string> TMapIntStr;
  typedef TMapIntStr::iterator      TMapIntStrIt;
  typedef TMapIntStr::value_type    TMapIntStrVT;

  TMapIntStr mMapTypeName;

  struct THandler
  {
    TCallBackRegistrator0* toStruct;
    TCallBackRegistrator0* toStr;
  };

  typedef std::map<std::string,THandler> TMapStrHandler;
  typedef TMapStrHandler::iterator       TMapStrHandlerIt;
  typedef TMapStrHandler::value_type     TMapStrHandlerVT;

  TMapStrHandler mMapNameType_Handler;

  TCallBackRegistrator0 mCB_Generic6DofToStruct,       mCB_Generic6DofToStr;
  TCallBackRegistrator0 mCB_Generic6DofSpringToStruct, mCB_Generic6DofSpringToStr;
  TCallBackRegistrator0 mCB_FixedToStruct,             mCB_FixedToStr;
  TCallBackRegistrator0 mCB_SliderToStruct,            mCB_SliderToStr;
  TCallBackRegistrator0 mCB_ConeTwistToStruct,         mCB_ConeTwistToStr;
  TCallBackRegistrator0 mCB_HingeToStruct,             mCB_HingeToStr;
  TCallBackRegistrator0 mCB_Hinge2ToStruct,            mCB_Hinge2ToStr;
  TCallBackRegistrator0 mCB_Point2PointToStruct,       mCB_Point2PointToStr;
  TCallBackRegistrator0 mCB_GearToStruct,              mCB_GearToStr;

public:
  TSerializerParamBuilderConstraint();
  virtual ~TSerializerParamBuilderConstraint();
  
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator              TMapStrStrIt;
  typedef TMapStrStr::value_type            TMapStrStrVT;

  nsParamBuilderConstraint::TBaseParam* GetParamByMap(TMapStrStr* pM);
  void GetMapByParam(nsParamBuilderConstraint::TBaseParam* p, TMapStrStr* pM);
private:
  void Init();
  float GetValueByName(const char* name);
  std::string FindStrByType(int type);
private:
  // временные параметры
  TMapStrStr*                           mMapKeyValue;
  nsParamBuilderConstraint::TBaseParam* mPtrParam;
private:
  void HandlerGeneric6DofToStruct();
  void HandlerGeneric6DofSpringToStruct();
  void HandlerFixedToStruct();
  void HandlerSliderToStruct();
  void HandlerConeTwistToStruct();
  void HandlerHingeToStruct();
  void HandlerHinge2ToStruct();
  void HandlerPoint2PointToStruct();
  void HandlerGearToStruct();

  void HandlerGeneric6DofToStr();
  void HandlerGeneric6DofSpringToStr();
  void HandlerFixedToStr();
  void HandlerSliderToStr();
  void HandlerConeTwistToStr();
  void HandlerHingeToStr();
  void HandlerHinge2ToStr();
  void HandlerPoint2PointToStr();
  void HandlerGearToStr();
};

#endif
