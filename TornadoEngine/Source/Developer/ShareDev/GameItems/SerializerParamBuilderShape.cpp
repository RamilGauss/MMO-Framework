/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerParamBuilderShape.h"
#include "BL_Debug.h"

namespace nsSerializerParamBuilderShape
{
#define REGISTER_HANDLER(NAME_TYPE) \
mMapTypeName.insert(TMapIntStrVT(NAME_TYPE, #NAME_TYPE)); \
mCB_##NAME_TYPE##ToStruct.Register(&TSerializerParamBuilderShape::Handler##NAME_TYPE##ToStruct,this); \
mCB_##NAME_TYPE##ToStr.Register(&TSerializerParamBuilderShape::Handler##NAME_TYPE##ToStr,this); \
handler.toStruct = &mCB_##NAME_TYPE##ToStruct; \
handler.toStr    = &mCB_##NAME_TYPE##ToStr; \
mMapNameType_Handler.insert(TMapStrHandlerVT(#NAME_TYPE, handler));


  const char* sName               = "Name";

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
  mMapNameValue_Geometry = pM;

  TMapStrStrIt fit = mMapNameValue_Geometry->find(sName);
  if(fit==mMapNameValue_Geometry->end())
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
  mMapNameValue_Geometry = pM;
  mMapNameValue_Geometry->clear();

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
  mMapNameValue_Geometry = NULL;
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

    TMapStrStrIt fit = mMapNameValue_Geometry->find(strCoord);
    if(fit==mMapNameValue_Geometry->end()) 
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
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));

  char value[100];

  _gcvt_s(value, sizeof(value), pPlate->length, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sLength, value));

  _gcvt_s(value, sizeof(value), pPlate->height, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sHeight, value));

  _gcvt_s(value, sizeof(value), pPlate->width, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sWidth, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerPlateVarGeomToStr()
{
  nsParamBuilderShape::TPlateVarGeom* pPlateVarGeom = (nsParamBuilderShape::TPlateVarGeom*)mPtrParam;

  std::string strType = FindStrByType(pPlateVarGeom->type);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));

  char value[100];

  _gcvt_s(value, sizeof(value), pPlateVarGeom->height, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sHeight, value));

  _gcvt_s(value, sizeof(value), pPlateVarGeom->width, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sWidth, value));

  int cnt = pPlateVarGeom->vecCoord.size();
  sprintf(value, "%d", cnt);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sCntCoord, value));

  for(int i = 0 ; i < cnt ; i++ )
  {
    char strCoord[100];
    sprintf(strCoord, "%s%d", sCoord, i);

    std::string strValue;

    _gcvt_s(value, sizeof(value), pPlateVarGeom->vecCoord[i].x, 9);
    strValue = value;
    strValue += ";";
    
    _gcvt_s(value, sizeof(value), pPlateVarGeom->vecCoord[i].y, 9);
    strValue += value;

    mMapNameValue_Geometry->insert(TMapStrStrVT(strCoord, strValue));
  }
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerSphereToStr()
{
  nsParamBuilderShape::TSphere* pSphere = (nsParamBuilderShape::TSphere*)mPtrParam;

  std::string strType = FindStrByType(pSphere->type);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));

  char value[100];

  _gcvt_s(value, sizeof(value), pSphere->radius_max, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sRadiusMax, value));

  _gcvt_s(value, sizeof(value), pSphere->radius_min, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sRadiusMin, value));

  _gcvt_s(value, sizeof(value), pSphere->cut, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sCut, value));

  _gcvt_s(value, sizeof(value), pSphere->cnt_points_per_circle, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sCntPointsPerCircle, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerConeToStr()
{
  nsParamBuilderShape::TCone* pCone = (nsParamBuilderShape::TCone*)mPtrParam;
  
  std::string strType = FindStrByType(pCone->type);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));
  
  char value[100];

  _gcvt_s(value, sizeof(value), pCone->radius, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sRadius, value));

  _gcvt_s(value, sizeof(value), pCone->height, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sHeight, value));

  _gcvt_s(value, sizeof(value), pCone->cut, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sCut, value));

  _gcvt_s(value, sizeof(value), pCone->cnt_points_per_circle, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sCntPointsPerCircle, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTrapeziumToStr()
{
  nsParamBuilderShape::TTrapezium* pTrapezium = (nsParamBuilderShape::TTrapezium*)mPtrParam;

  std::string strType = FindStrByType(pTrapezium->type);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));

  char value[100];

  _gcvt_s(value, sizeof(value), pTrapezium->height, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sHeight, value));

  _gcvt_s(value, sizeof(value), pTrapezium->len_down_base, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sLenDownBase, value));

  _gcvt_s(value, sizeof(value), pTrapezium->len_up_base, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sLenUpBase, value));

  _gcvt_s(value, sizeof(value), pTrapezium->shift_up_down, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sShiftUpDown, value));

  _gcvt_s(value, sizeof(value), pTrapezium->thickless, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sThickless, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTriangularPyramidToStr()
{
  nsParamBuilderShape::TTriangularPyramid* pTriangularPyramid = (nsParamBuilderShape::TTriangularPyramid*)mPtrParam;

  std::string strType = FindStrByType(pTriangularPyramid->type);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));

  char value[100];

  _gcvt_s(value, sizeof(value), pTriangularPyramid->base0, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sBase0, value));

  _gcvt_s(value, sizeof(value), pTriangularPyramid->base1, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sBase1, value));

  _gcvt_s(value, sizeof(value), pTriangularPyramid->base2, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sBase2, value));

  _gcvt_s(value, sizeof(value), pTriangularPyramid->cut, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sCut, value));

  _gcvt_s(value, sizeof(value), pTriangularPyramid->height, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sHeight, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerQuadrangularPyramidToStr()
{
  nsParamBuilderShape::TQuadrangularPyramid* pQuadrangularPyramid = (nsParamBuilderShape::TQuadrangularPyramid*)mPtrParam;

  std::string strType = FindStrByType(pQuadrangularPyramid->type);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));

  char value[100];

  _gcvt_s(value, sizeof(value), pQuadrangularPyramid->base, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sBase, value));

  _gcvt_s(value, sizeof(value), pQuadrangularPyramid->cut, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sCut, value));

  _gcvt_s(value, sizeof(value), pQuadrangularPyramid->height, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sHeight, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerCylinderToStr()
{
  nsParamBuilderShape::TCylinder* pCylinder = (nsParamBuilderShape::TCylinder*)mPtrParam;

  std::string strType = FindStrByType(pCylinder->type);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));

  char value[100];

  _gcvt_s(value, sizeof(value), pCylinder->cnt_points_per_circle, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sCntPointsPerCircle, value));

  _gcvt_s(value, sizeof(value), pCylinder->length, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sLength, value));

  _gcvt_s(value, sizeof(value), pCylinder->radius_max, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sRadiusMax, value));

  _gcvt_s(value, sizeof(value), pCylinder->radius_min, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sRadiusMin, value));
}
//---------------------------------------------------------------------
void TSerializerParamBuilderShape::HandlerTriangularPrismToStr()
{
  nsParamBuilderShape::TTriangularPrism* pTriangularPrism = (nsParamBuilderShape::TTriangularPrism*)mPtrParam;

  std::string strType = FindStrByType(pTriangularPrism->type);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sName,strType));

  char value[100];

  _gcvt_s(value, sizeof(value), pTriangularPrism->base0, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sBase0, value));

  _gcvt_s(value, sizeof(value), pTriangularPrism->base1, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sBase1, value));

  _gcvt_s(value, sizeof(value), pTriangularPrism->base2, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sBase2, value));

  _gcvt_s(value, sizeof(value), pTriangularPrism->length, 9);
  mMapNameValue_Geometry->insert(TMapStrStrVT(sLength, value));
}
//---------------------------------------------------------------------
float TSerializerParamBuilderShape::GetValueByName(const char* name)
{
  TMapStrStrIt fit = mMapNameValue_Geometry->find(name);
  if(fit==mMapNameValue_Geometry->end()) 
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
