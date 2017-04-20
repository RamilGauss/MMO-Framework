/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ParamBuilderShapeH
#define ParamBuilderShapeH

#include "TypeDef.h"
#include <vector>
#include "ContainerTypes.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsParamBuilderShape
{
  typedef enum
  {
    Plate,
    PlateVarGeom,
    Sphere,
    Cone,
    Trapezium,
    TriangularPyramid,
    QuadrangularPyramid,
    Cylinder,
    TriangularPrism,
  }eType;
  //--------------------------------------------------
  struct DllExport TBaseParam
  {
    eType type;
    TBaseParam(eType t){type=t;}
  }_PACKED;
  //--------------------------------------------------
  struct DllExport TPlate : public TBaseParam
  {
    TPlate();
    float width;
    float height;
    float length;
  }_PACKED;
  struct DllExport TPlateVarGeom : public TBaseParam
  {
    TPlateVarGeom();
    float width;
    float height;

    struct coord{float x;float y;};
    std::vector<coord> vecCoord;

    TContainer Get();
    bool Set(TContainer& c);
  }_PACKED;
  struct DllExport TSphere : public TBaseParam
  {
    TSphere();
    int cnt_points_per_circle;// точность описания круговых поверхностей
    float radius_max;
    float radius_min;
    // срезка плоскостью - получится круг
    float cut0;// первый срез
    float cut1;// второй срез
  }_PACKED;
  struct DllExport TCone : public TBaseParam
  {
    TCone();
    int cnt_points_per_circle;// точность описания круговых поверхностей
    float radius;
    float height;
    float cut;
  }_PACKED;
  struct DllExport TTrapezium : public TBaseParam
  {
    TTrapezium();
    float thickless;
    float len_up_base;
    float len_down_base;
    float height;
    float shift_up_down;
  }_PACKED;
  struct DllExport TTriangularPyramid : public TBaseParam
  {
    TTriangularPyramid();
    float base0;
    float base1;
    float base2;
    float height;
    float cut;
  }_PACKED;
  struct DllExport TQuadrangularPyramid : public TBaseParam
  {
    TQuadrangularPyramid();
    // основание - прямоугольник
    float width;// ширина
    float length;// длина
    float height;// высота
    float cut;// срез
  }_PACKED;
  struct DllExport TCylinder : public TBaseParam
  {
    TCylinder();
    int cnt_points_per_circle;// точность описания круговых поверхностей
    float radius_max;
    float radius_min;// получится труба
    float length;
  }_PACKED;
  struct DllExport TTriangularPrism : public TBaseParam
  {
    TTriangularPrism();
    float base0;
    float base1;
    float base2;
    float length;
  }_PACKED;
}

#ifdef WIN32
#pragma pack(pop)
#endif

#endif
