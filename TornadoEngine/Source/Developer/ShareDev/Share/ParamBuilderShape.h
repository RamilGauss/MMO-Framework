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

#if defined( TD_WINDOWS )
#pragma pack(push, 1)
#endif

namespace nsParamBuilderShape
{
  typedef enum
  {
    ePlastina,
    ePlastinaVarGeom,
    eSphere,
    eCone,
    eTrapezium,
    ePyramid3,
    ePyramid4,
    eCylinder,
    eTrianglePrism,
    eFlatRing,
  }eType;
  //--------------------------------------------------
  struct DllExport TBaseParam
  {
    eType type;
    TBaseParam(eType t){type=t;}
  }_PACKED;
  //--------------------------------------------------
  struct DllExport TPlastina : public TBaseParam
  {
    TPlastina();
    float width;
    float height;
    float lenght;
  }_PACKED;
  struct DllExport TPlastinaVarGeom : public TBaseParam
  {
    TPlastinaVarGeom();
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
    float cut;// срезка плоскостью - получится круг
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
  struct DllExport TPyramid3 : public TBaseParam
  {
    TPyramid3();
    float base0;
    float base1;
    float base2;
    float height;
    float cut;
  }_PACKED;
  struct DllExport TPyramid4 : public TBaseParam
  {
    TPyramid4();
    float base;
    float height;
    float cut;
  }_PACKED;
  struct DllExport TCylinder : public TBaseParam
  {
    TCylinder();
    int cnt_points_per_circle;// точность описания круговых поверхностей
    float radius_max;
    float radius_min;// получится труба
    float lenght;
  }_PACKED;
  struct DllExport TTrianglePrism : public TBaseParam
  {
    TTrianglePrism();
    float base0;
    float base1;
    float base2;
    float lenght;
  }_PACKED;
  struct DllExport TFlatRing : public TBaseParam
  {
    TFlatRing();
    float lenght;
    float width;
    int cnt_points_len;
    int cnt_points_width;
  }_PACKED;
}

#if defined( TD_WINDOWS )
#pragma pack(pop)
#endif

#endif
