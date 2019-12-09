/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ParamBuilderConstraint.h"
#include "BL_Debug.h"

using namespace nsParamBuilderConstraint;

//-------------------------------------------------------------------------------------------
TGeneric6Dof::TGeneric6Dof():TBaseParam(Generic6Dof)
{

}
//-------------------------------------------------------------------------------------------
TUniversal::TUniversal()
{
  type = Universal;
}
//-------------------------------------------------------------------------------------------
TGeneric6DofSpring::TGeneric6DofSpring():TBaseParam(Generic6DofSpring)
{

}
//-------------------------------------------------------------------------------------------
THinge2::THinge2():TBaseParam(Hinge2)
{

}
//-------------------------------------------------------------------------------------------
TFixed::TFixed():TBaseParam(Fixed)
{

}
//-------------------------------------------------------------------------------------------
TSlider::TSlider():TBaseParam(Slider)
{

}
//-------------------------------------------------------------------------------------------
TConeTwist::TConeTwist():TBaseParam(ConeTwist)
{

}
//-------------------------------------------------------------------------------------------
THinge::THinge():TBaseParam(Hinge)
{

}
//-------------------------------------------------------------------------------------------
TPoint2Point::TPoint2Point():TBaseParam(Point2Point)
{

}
//-------------------------------------------------------------------------------------------
TGear::TGear():TBaseParam(Gear)
{

}
//-------------------------------------------------------------------------------------------
TContact::TContact():TBaseParam(Contact)
{

}
//-------------------------------------------------------------------------------------------
namespace nsParamBuilderConstraint
{
#define COPY_CONSTRAINT(TypeConstraint) \
  case TypeConstraint: \
  { \
    T##TypeConstraint* pToTemp = new T##TypeConstraint; \
    T##TypeConstraint* pFromTemp = (T##TypeConstraint*)pFrom; \
    pTo = pToTemp; \
    *pToTemp = *pFromTemp; \
  } \
  break;

  bool CopyConstraint(TBaseParam* pFrom, TBaseParam*& pTo)
  {
    pTo = NULL;
    switch(pFrom->type)
    {
      COPY_CONSTRAINT(Generic6Dof)
      COPY_CONSTRAINT(Universal)
      COPY_CONSTRAINT(Generic6DofSpring)
      COPY_CONSTRAINT(Hinge2)
      COPY_CONSTRAINT(Fixed)
      COPY_CONSTRAINT(Slider)
      COPY_CONSTRAINT(ConeTwist)
      COPY_CONSTRAINT(Hinge)
      COPY_CONSTRAINT(Point2Point)
      COPY_CONSTRAINT(Gear)
      COPY_CONSTRAINT(Contact)
      default:
      {
        BL_FIX_BUG();
        return false;
      }
    }
    return true;
  }
}
//-------------------------------------------------------------------------------------------
