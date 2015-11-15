/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ParamBuilderShape.h"
#include "BreakPacket.h"

using namespace nsParamBuilderShape;

TPlastina::TPlastina():TBaseParam(ePlastina)
{

}
//-------------------------------------------------------------------------------------------
TPlastinaVarGeom::TPlastinaVarGeom():TBaseParam(ePlastinaVarGeom)
{

}
//-------------------------------------------------------------------------------------------
TContainer TPlastinaVarGeom::Get()
{
  TContainer c;
  TBreakPacket bp;
  bp.PushBack((char*)&width, sizeof(width));
  bp.PushBack((char*)&height, sizeof(height));
  if(vecCoord.size())
    bp.PushBack((char*)&vecCoord[0], vecCoord.size()*sizeof(coord));

  bp.Collect();
  c.SetData((char*)bp.GetCollectPtr(), bp.GetSize());
  return c;
}
//-------------------------------------------------------------------------------------------
bool TPlastinaVarGeom::Set(TContainer& c)
{
  vecCoord.clear();

  int size = c.GetSize();
  if(size < sizeof(width) + sizeof(height))
    return false;
  float* p = (float*)c.GetPtr();
  width  = p[0];
  height = p[1];

  size -= sizeof(width) + sizeof(height);
  p    += 2;
  if(size==0)
    return true;
  
  int cnt = size/sizeof(coord);
  vecCoord.reserve(cnt);
  vecCoord.resize(cnt);
  memcpy(&vecCoord[0], p, cnt*sizeof(coord));
  return true;
}
//-------------------------------------------------------------------------------------------
TSphere::TSphere():TBaseParam(eSphere)
{

}
//-------------------------------------------------------------------------------------------
TCone::TCone():TBaseParam(eCone)
{

}
//-------------------------------------------------------------------------------------------
TTrapezium::TTrapezium():TBaseParam(eTrapezium)
{

}
//-------------------------------------------------------------------------------------------
TPyramid3::TPyramid3():TBaseParam(ePyramid3)
{

}
//-------------------------------------------------------------------------------------------
TPyramid4::TPyramid4():TBaseParam(ePyramid4)
{

}
//-------------------------------------------------------------------------------------------
TCylinder::TCylinder():TBaseParam(eCylinder)
{

}
//-------------------------------------------------------------------------------------------
