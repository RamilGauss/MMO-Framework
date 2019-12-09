/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef SerializerParamBuilderShapeH
#define SerializerParamBuilderShapeH

#include "TypeDef.h"
#include <map>
#include <string>
#include "ParamBuilderShape.h"
#include "CallBackRegistrator.h"

class DllExport TSerializerParamBuilderShape
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

  TCallBackRegistrator0 mCB_PlateToStruct,               mCB_PlateToStr;
  TCallBackRegistrator0 mCB_PlateVarGeomToStruct,        mCB_PlateVarGeomToStr;
  TCallBackRegistrator0 mCB_SphereToStruct,              mCB_SphereToStr;
  TCallBackRegistrator0 mCB_ConeToStruct,                mCB_ConeToStr;
  TCallBackRegistrator0 mCB_TrapeziumToStruct,           mCB_TrapeziumToStr;
  TCallBackRegistrator0 mCB_TriangularPyramidToStruct,   mCB_TriangularPyramidToStr;
  TCallBackRegistrator0 mCB_QuadrangularPyramidToStruct, mCB_QuadrangularPyramidToStr;
  TCallBackRegistrator0 mCB_CylinderToStruct,            mCB_CylinderToStr;
  TCallBackRegistrator0 mCB_TriangularPrismToStruct,     mCB_TriangularPrismToStr;

public:
  TSerializerParamBuilderShape();
  virtual ~TSerializerParamBuilderShape();
  
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator              TMapStrStrIt;
  typedef TMapStrStr::value_type            TMapStrStrVT;

  nsParamBuilderShape::TBaseParam* GetParamByMap(TMapStrStr* pM);
  void GetMapByParam(nsParamBuilderShape::TBaseParam* p, TMapStrStr* pM);
private:
  void Init();
  float GetValueByName(const char* name);
  std::string FindStrByType(int type);
private:
  // временные параметры
  TMapStrStr*                      mMapKeyValue;
  nsParamBuilderShape::TBaseParam* mPtrParam;
private:
  void HandlerPlateToStruct();
  void HandlerPlateVarGeomToStruct();
  void HandlerSphereToStruct();
  void HandlerConeToStruct();
  void HandlerTrapeziumToStruct();
  void HandlerTriangularPyramidToStruct();
  void HandlerQuadrangularPyramidToStruct();
  void HandlerCylinderToStruct();
  void HandlerTriangularPrismToStruct();

  void HandlerPlateToStr();
  void HandlerPlateVarGeomToStr();
  void HandlerSphereToStr();
  void HandlerConeToStr();
  void HandlerTrapeziumToStr();
  void HandlerTriangularPyramidToStr();
  void HandlerQuadrangularPyramidToStr();
  void HandlerCylinderToStr();
  void HandlerTriangularPrismToStr();
};

#endif
