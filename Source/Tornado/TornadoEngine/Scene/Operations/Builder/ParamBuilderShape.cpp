/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ParamBuilderShape.h"
#include "BreakPacket.h"

using namespace nsParamBuilderShape;

TPlate::TPlate():TBaseParam(Plate)
{

}
//-------------------------------------------------------------------------------------------
TPlateVarGeom::TPlateVarGeom():TBaseParam(PlateVarGeom)
{

}
//-------------------------------------------------------------------------------------------
//TContainer TPlateVarGeom::Get()
//{
//  TContainer c;
//  TBreakPacket bp;
//  bp.PushBack((char*)&type, sizeof(type));
//  bp.PushBack((char*)&width, sizeof(width));
//  bp.PushBack((char*)&height, sizeof(height));
//  if(vecCoord.size())
//    bp.PushBack((char*)&vecCoord[0], vecCoord.size()*sizeof(coord));
//
//  bp.Collect();
//  c.SetData((char*)bp.GetCollectPtr(), bp.GetSize());
//  return c;
//}
////-------------------------------------------------------------------------------------------
//bool TPlateVarGeom::Set(TContainer& c)
//{
//  vecCoord.clear();
//
//  int size = c.GetSize();
//  if(size < sizeof(type) + sizeof(width) + sizeof(height))
//    return false;
//  char* p = c.GetPtr();
//  p += sizeof(type);
//  width  = *((float*)p);
//  p += sizeof(width);
//  height = *((float*)p);
//  p += sizeof(height);
//
//  size -= sizeof(type) + sizeof(width) + sizeof(height);
//  if(size==0)
//    return true;
//  
//  int cnt = size/sizeof(coord);
//  vecCoord.reserve(cnt);
//  vecCoord.resize(cnt);
//  memcpy(&vecCoord[0], p, cnt*sizeof(coord));
//  return true;
//}
//-------------------------------------------------------------------------------------------
TSphere::TSphere():TBaseParam(Sphere)
{

}
//-------------------------------------------------------------------------------------------
TCone::TCone():TBaseParam(Cone)
{

}
//-------------------------------------------------------------------------------------------
TTrapezium::TTrapezium():TBaseParam(Trapezium)
{

}
//-------------------------------------------------------------------------------------------
TTriangularPyramid::TTriangularPyramid():TBaseParam(TriangularPyramid)
{

}
//-------------------------------------------------------------------------------------------
TQuadrangularPyramid::TQuadrangularPyramid():TBaseParam(QuadrangularPyramid)
{

}
//-------------------------------------------------------------------------------------------
TCylinder::TCylinder():TBaseParam(Cylinder)
{

}
//-------------------------------------------------------------------------------------------
TTriangularPrism::TTriangularPrism():TBaseParam(TriangularPrism)
{

}
//-------------------------------------------------------------------------------------------
