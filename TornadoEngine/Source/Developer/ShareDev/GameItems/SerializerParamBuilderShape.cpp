/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerParamBuilderShape.h"
#include "BL_Debug.h"

#include <boost/lexical_cast.hpp>

namespace nsSerializerParamBuilderShape
{
#define REGISTER_HANDLER(NAME_TYPE) \
mMapTypeName.insert(TMapIntStrVT(NAME_TYPE, #NAME_TYPE)); \
mCB_##NAME_TYPE##ToStruct.Register(&TSerializerParamBuilderShape::Handler##NAME_TYPE##ToStruct,this); \
mCB_##NAME_TYPE##ToStr.Register(&TSerializerParamBuilderShape::Handler##NAME_TYPE##ToStr,this); \
handler.toStruct = &mCB_##NAME_TYPE##ToStruct; \
handler.toStr    = &mCB_##NAME_TYPE##ToStr; \
mMapNameType_Handler.insert(TMapStrHandlerVT(#NAME_TYPE, handler));


  const char* sType               = "Type";

  const char* sRadius             = "Radius";
  const char* sHeight             = "Height";
  const char* sCut                = "Cut";
  const char* sCntPointsPerCircle = "CntPointsPerCircle";
  const char* sLength             = "Length";
  const char* sWidth              = "Width";
  const char* sRadiusMax          = "RadiusMax";
  const char* sRadiusMin          = "RadiusMin";
  const char* sCntCoord           = "CntCoord";
  const char* sCoord              = "Coord";
  const char* sThickless          = "Thickless";
  const char* sLenDownBase        = "LenDownBase";
  const char* sLenUpBase          = "LenUpBase";
  const char* sShiftUpDown        = "ShiftUpDown";
  const char* sBase               = "Base";
  const char* sBase0              = "Base0";
  const char* sBase1              = "Base1";
  const char* sBase2              = "Base2";
}

using namespace nsSerializerParamBuilderShape;
using namespace nsParamBuilderShape;

TSerializerParamBuilderShape::TSerializerParamBuilderShape()
{
  Init();
}
//---------------------------------------------------------------------
TSerializerParamBuilderShape::~TSerializerParamBuilderShape()
{

}
//---------------------------------------------------------------------
nsParamBuilderShape::TBaseParam* TSerializerParamBuilderShape::GetParamByMap(TMapStrStr* pM)
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
    return NULL;

  fit_Handler->second.toStruct->Notify();
  return mPtrParam;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::GetMapByParam(nsParamBuilderShape::TBaseParam* p, TMapStrStr* pM)
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
void TSerializerParamBuilderShape::Init()
{
  mMapKeyValue = NULL;
  mPtrParam = NULL;

  THandler handler;
  REGISTER_HANDLER(Plate);
  REGISTER_HANDLER(PlateVarGeom);
  REGISTER_HANDLER(Sphere);
  REGISTER_HANDLER(Cone);
  REGISTER_HANDLER(Trapezium);
  REGISTER_HANDLER(TriangularPyramid);
  REGISTER_HANDLER(QuadrangularPyramid);
  REGISTER_HANDLER(Cylinder);
  REGISTER_HANDLER(TriangularPrism);
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerPlateToStruct()
{
  nsParamBuilderShape::TPlate* pPlate = new nsParamBuilderShape::TPlate;
  pPlate->length = GetValueByName(sLength);
  pPlate->height = GetValueByName(sHeight);
  pPlate->width  = GetValueByName(sWidth);

  mPtrParam = pPlate;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerPlateVarGeomToStruct()
{
  nsParamBuilderShape::TPlateVarGeom* pPlateVarGeom = new nsParamBuilderShape::TPlateVarGeom;
  pPlateVarGeom->height = GetValueByName(sHeight);
  pPlateVarGeom->width  = GetValueByName(sWidth);

  int cnt = GetValueByName(sCntCoord);
  for(int i = 0 ; i < cnt ; i++ )
  {
    char strCoord[100];
    sprintf(strCoord, "%s%d", sCoord, i);

    TMapStrStrIt fit = mMapKeyValue->find(strCoord);
    if(fit==mMapKeyValue->end()) 
    {
      BL_FIX_BUG();
      continue;
    }
    float v[2];
    if(sscanf(fit->second.data(),"%f;%f",&v[0],&v[1])!=2)
    {
      BL_FIX_BUG();
      continue;
    }
    nsParamBuilderShape::TPlateVarGeom::coord c;
    c.x = v[0];
    c.y = v[1];
    pPlateVarGeom->vecCoord.push_back(c);
  }
  mPtrParam = pPlateVarGeom;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerSphereToStruct()
{
  nsParamBuilderShape::TSphere* pSphere = new nsParamBuilderShape::TSphere;
  pSphere->cnt_points_per_circle = GetValueByName(sCntPointsPerCircle);
  pSphere->cut                   = GetValueByName(sCut);
  pSphere->radius_max            = GetValueByName(sRadiusMax);
  pSphere->radius_min            = GetValueByName(sRadiusMin);

  mPtrParam = pSphere;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerConeToStruct()
{
  nsParamBuilderShape::TCone* pCone = new nsParamBuilderShape::TCone;
  pCone->radius = GetValueByName(sRadius);
  pCone->height = GetValueByName(sHeight);
  pCone->cut    = GetValueByName(sCut);
  pCone->cnt_points_per_circle = GetValueByName(sCntPointsPerCircle);
  
  mPtrParam = pCone;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTrapeziumToStruct()
{
  nsParamBuilderShape::TTrapezium* pTrapezium = new nsParamBuilderShape::TTrapezium;
  pTrapezium->height        = GetValueByName(sHeight);
  pTrapezium->thickless     = GetValueByName(sThickless);
  pTrapezium->len_down_base = GetValueByName(sLenDownBase);
  pTrapezium->len_up_base   = GetValueByName(sLenUpBase);
  pTrapezium->shift_up_down = GetValueByName(sShiftUpDown);

  mPtrParam = pTrapezium;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTriangularPyramidToStruct()
{
  nsParamBuilderShape::TTriangularPyramid* pTriangularPyramid = new nsParamBuilderShape::TTriangularPyramid;
  pTriangularPyramid->base0  = GetValueByName(sBase0);
  pTriangularPyramid->base1  = GetValueByName(sBase1);
  pTriangularPyramid->base2  = GetValueByName(sBase2);
  pTriangularPyramid->cut    = GetValueByName(sCut);
  pTriangularPyramid->height = GetValueByName(sHeight);

  mPtrParam = pTriangularPyramid;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerQuadrangularPyramidToStruct()
{
  nsParamBuilderShape::TQuadrangularPyramid* pQuadrangularPyramid = new nsParamBuilderShape::TQuadrangularPyramid;
  pQuadrangularPyramid->base   = GetValueByName(sBase);
  pQuadrangularPyramid->cut    = GetValueByName(sCut);
  pQuadrangularPyramid->height = GetValueByName(sHeight);

  mPtrParam = pQuadrangularPyramid;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerCylinderToStruct()
{
  nsParamBuilderShape::TCylinder* pCylinder = new nsParamBuilderShape::TCylinder;
  pCylinder->cnt_points_per_circle = GetValueByName(sCntPointsPerCircle);
  pCylinder->length                = GetValueByName(sLength);
  pCylinder->radius_max            = GetValueByName(sRadiusMax);
  pCylinder->radius_min            = GetValueByName(sRadiusMin);

  mPtrParam = pCylinder;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTriangularPrismToStruct()
{
  nsParamBuilderShape::TTriangularPrism* pTriangularPrism = new nsParamBuilderShape::TTriangularPrism;
  pTriangularPrism->base0  = GetValueByName(sBase0);
  pTriangularPrism->base1  = GetValueByName(sBase1);
  pTriangularPrism->base2  = GetValueByName(sBase2);
  pTriangularPrism->length = GetValueByName(sLength);

  mPtrParam = pTriangularPrism;
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerPlateToStr()
{
  nsParamBuilderShape::TPlate* pPlate = (nsParamBuilderShape::TPlate*)mPtrParam;

  std::string strType = FindStrByType(pPlate->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pPlate->length);
  mMapKeyValue->insert(TMapStrStrVT(sLength, value));

  value = boost::lexical_cast<std::string>(pPlate->height);
  mMapKeyValue->insert(TMapStrStrVT(sHeight, value));

  value = boost::lexical_cast<std::string>(pPlate->width);
  mMapKeyValue->insert(TMapStrStrVT(sWidth, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerPlateVarGeomToStr()
{
  nsParamBuilderShape::TPlateVarGeom* pPlateVarGeom = (nsParamBuilderShape::TPlateVarGeom*)mPtrParam;

  std::string strType = FindStrByType(pPlateVarGeom->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pPlateVarGeom->height);
  mMapKeyValue->insert(TMapStrStrVT(sHeight, value));

  value = boost::lexical_cast<std::string>(pPlateVarGeom->width);
  mMapKeyValue->insert(TMapStrStrVT(sWidth, value));

  int cnt = pPlateVarGeom->vecCoord.size();
  value = boost::lexical_cast<std::string>(cnt);
  mMapKeyValue->insert(TMapStrStrVT(sCntCoord, value));

  for(int i = 0 ; i < cnt ; i++ )
  {
    char strCoord[100];
    sprintf(strCoord, "%s%d", sCoord, i);

    std::string strValue;

    strValue = boost::lexical_cast<std::string>(pPlateVarGeom->vecCoord[i].x);
    strValue += ";";
    strValue += boost::lexical_cast<std::string>(pPlateVarGeom->vecCoord[i].y);

    mMapKeyValue->insert(TMapStrStrVT(strCoord, strValue));
  }
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerSphereToStr()
{
  nsParamBuilderShape::TSphere* pSphere = (nsParamBuilderShape::TSphere*)mPtrParam;

  std::string strType = FindStrByType(pSphere->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pSphere->radius_max);
  mMapKeyValue->insert(TMapStrStrVT(sRadiusMax, value));

  value = boost::lexical_cast<std::string>(pSphere->radius_min);
  mMapKeyValue->insert(TMapStrStrVT(sRadiusMin, value));

  value = boost::lexical_cast<std::string>(pSphere->cut);
  mMapKeyValue->insert(TMapStrStrVT(sCut, value));

  value = boost::lexical_cast<std::string>(pSphere->cnt_points_per_circle);
  mMapKeyValue->insert(TMapStrStrVT(sCntPointsPerCircle, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerConeToStr()
{
  nsParamBuilderShape::TCone* pCone = (nsParamBuilderShape::TCone*)mPtrParam;
  
  std::string strType = FindStrByType(pCone->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));
  
  std::string value;

  value = boost::lexical_cast<std::string>(pCone->radius);
  mMapKeyValue->insert(TMapStrStrVT(sRadius, value));

  value = boost::lexical_cast<std::string>(pCone->height);
  mMapKeyValue->insert(TMapStrStrVT(sHeight, value));

  value = boost::lexical_cast<std::string>(pCone->cut);
  mMapKeyValue->insert(TMapStrStrVT(sCut, value));

  value = boost::lexical_cast<std::string>(pCone->cnt_points_per_circle);
  mMapKeyValue->insert(TMapStrStrVT(sCntPointsPerCircle, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTrapeziumToStr()
{
  nsParamBuilderShape::TTrapezium* pTrapezium = (nsParamBuilderShape::TTrapezium*)mPtrParam;

  std::string strType = FindStrByType(pTrapezium->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pTrapezium->height);
  mMapKeyValue->insert(TMapStrStrVT(sHeight, value));

  value = boost::lexical_cast<std::string>(pTrapezium->len_down_base);
  mMapKeyValue->insert(TMapStrStrVT(sLenDownBase, value));

  value = boost::lexical_cast<std::string>(pTrapezium->len_up_base);
  mMapKeyValue->insert(TMapStrStrVT(sLenUpBase, value));

  value = boost::lexical_cast<std::string>(pTrapezium->shift_up_down);
  mMapKeyValue->insert(TMapStrStrVT(sShiftUpDown, value));

  value = boost::lexical_cast<std::string>(pTrapezium->thickless);
  mMapKeyValue->insert(TMapStrStrVT(sThickless, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTriangularPyramidToStr()
{
  nsParamBuilderShape::TTriangularPyramid* pTriangularPyramid = (nsParamBuilderShape::TTriangularPyramid*)mPtrParam;

  std::string strType = FindStrByType(pTriangularPyramid->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pTriangularPyramid->base0);
  mMapKeyValue->insert(TMapStrStrVT(sBase0, value));

  value = boost::lexical_cast<std::string>(pTriangularPyramid->base1);
  mMapKeyValue->insert(TMapStrStrVT(sBase1, value));

  value = boost::lexical_cast<std::string>(pTriangularPyramid->base2);
  mMapKeyValue->insert(TMapStrStrVT(sBase2, value));

  value = boost::lexical_cast<std::string>(pTriangularPyramid->cut);
  mMapKeyValue->insert(TMapStrStrVT(sCut, value));

  value = boost::lexical_cast<std::string>(pTriangularPyramid->height);
  mMapKeyValue->insert(TMapStrStrVT(sHeight, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerQuadrangularPyramidToStr()
{
  nsParamBuilderShape::TQuadrangularPyramid* pQuadrangularPyramid = (nsParamBuilderShape::TQuadrangularPyramid*)mPtrParam;

  std::string strType = FindStrByType(pQuadrangularPyramid->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pQuadrangularPyramid->base);
  mMapKeyValue->insert(TMapStrStrVT(sBase, value));

  value = boost::lexical_cast<std::string>(pQuadrangularPyramid->cut);
  mMapKeyValue->insert(TMapStrStrVT(sCut, value));

  value = boost::lexical_cast<std::string>(pQuadrangularPyramid->height);
  mMapKeyValue->insert(TMapStrStrVT(sHeight, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerCylinderToStr()
{
  nsParamBuilderShape::TCylinder* pCylinder = (nsParamBuilderShape::TCylinder*)mPtrParam;

  std::string strType = FindStrByType(pCylinder->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pCylinder->cnt_points_per_circle);
  mMapKeyValue->insert(TMapStrStrVT(sCntPointsPerCircle, value));

  value = boost::lexical_cast<std::string>(pCylinder->length);
  mMapKeyValue->insert(TMapStrStrVT(sLength, value));

  value = boost::lexical_cast<std::string>(pCylinder->radius_max);
  mMapKeyValue->insert(TMapStrStrVT(sRadiusMax, value));

  value = boost::lexical_cast<std::string>(pCylinder->radius_min);
  mMapKeyValue->insert(TMapStrStrVT(sRadiusMin, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTriangularPrismToStr()
{
  nsParamBuilderShape::TTriangularPrism* pTriangularPrism = (nsParamBuilderShape::TTriangularPrism*)mPtrParam;

  std::string strType = FindStrByType(pTriangularPrism->type);
  mMapKeyValue->insert(TMapStrStrVT(sType,strType));

  std::string value;

  value = boost::lexical_cast<std::string>(pTriangularPrism->base0);
  mMapKeyValue->insert(TMapStrStrVT(sBase0, value));

  value = boost::lexical_cast<std::string>(pTriangularPrism->base1);
  mMapKeyValue->insert(TMapStrStrVT(sBase1, value));

  value = boost::lexical_cast<std::string>(pTriangularPrism->base2);
  mMapKeyValue->insert(TMapStrStrVT(sBase2, value));

  value = boost::lexical_cast<std::string>(pTriangularPrism->length);
  mMapKeyValue->insert(TMapStrStrVT(sLength, value));
}
//---------------------------------------------------------------------
float TSerializerParamBuilderShape::GetValueByName(const char* name)
{
  TMapStrStrIt fit = mMapKeyValue->find(name);
  if(fit==mMapKeyValue->end()) 
    return 0.0;

  return atof(fit->second.data());
}
//---------------------------------------------------------------------
std::string TSerializerParamBuilderShape::FindStrByType(int type)
{
  TMapIntStrIt fit = mMapTypeName.find(type);
  if(fit==mMapTypeName.end())
    return "";
  return fit->second;
}
//---------------------------------------------------------------------
