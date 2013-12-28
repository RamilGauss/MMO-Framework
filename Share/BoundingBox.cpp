/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BoundingBox.h"
#include <stdlib.h>
#include <stdio.h>

using namespace nsStruct3D;

TBoundingBox::TBoundingBox()
{
  mMin.x = 0;
  mMin.y = 0;
  mMin.z = 0;

  mMax.x = -1;
  mMax.y = -1;
  mMax.z = -1;
}
//-------------------------------------------------------------------------------------
TBoundingBox::~TBoundingBox()
{

}
//-------------------------------------------------------------------------------------
void TBoundingBox::SetBound(TVector3& min,TVector3& max)
{
  mMin = min;
  mMax = max;
}
//-------------------------------------------------------------------------------------
void TBoundingBox::AddBound(TVector3& min,TVector3& max)
{
  if(min.x<mMin.x) mMin.x = min.x;
  if(min.y<mMin.y) mMin.y = min.y;
  if(min.z<mMin.z) mMin.z = min.z;

  if(max.x>mMax.x) mMax.x = max.x;
  if(max.y>mMax.y) mMax.y = max.y;
  if(max.z>mMax.z) mMax.z = max.z;
}
//-------------------------------------------------------------------------------------
bool TBoundingBox::IsCorrect()
{
  if((mMax.x>=mMin.x)&&
     (mMax.y>=mMin.y)&&
     (mMax.z>=mMin.z))
     return true;
  return false;
}
//-------------------------------------------------------------------------------------
bool TBoundingBox::Contains(TVector3& point)
{
  if((mMin.x<point.x&&point.x<mMax.x)&&
     (mMin.y<point.y&&point.y<mMax.y)&&
     (mMin.z<point.z&&point.z<mMax.z))
    return true;
  return false;
}
//-------------------------------------------------------------------------------------
bool TBoundingBox::Collision(TBoundingBox& bb)
{
  // проверка по перекрытию плоскостей X:
  if(((mMin.x > bb.Min().x)&&(mMin.x > bb.Max().x))||
     ((mMax.x < bb.Min().x)&&(mMax.x < bb.Max().x)))
    return false;
  if(((mMin.y > bb.Min().y)&&(mMin.y > bb.Max().y))||
     ((mMax.y < bb.Min().y)&&(mMax.y < bb.Max().y)))
    return false;
  if(((mMin.z > bb.Min().z)&&(mMin.z > bb.Max().z))||
     ((mMax.z < bb.Min().z)&&(mMax.z < bb.Max().z)))
    return false;
  return true;
}
//-------------------------------------------------------------------------------------
float TBoundingBox::VolumeCollision(TBoundingBox& bb)
{
  float collision = 0;
  //// проверка по перекрытию плоскостей X:
  if(Collision(bb)==false)  
    return 0;
  float crossX, crossY, crossZ;
  float minLenX = __min(mMax.x-mMin.x,bb.Max().x-bb.Min().x);
  float minLenY = __min(mMax.y-mMin.y,bb.Max().y-bb.Min().y);
  float minLenZ = __min(mMax.z-mMin.z,bb.Max().z-bb.Min().z);

  float crossX0 = mMax.x - bb.Min().x;
  float crossX1 = bb.Max().x - mMin.x;

  float crossY0 = mMax.y - bb.Min().y;
  float crossY1 = bb.Max().y - mMin.y;

  float crossZ0 = mMax.z - bb.Min().z;
  float crossZ1 = bb.Max().z - mMin.z;

  crossX = __min(minLenX,__min(crossX0,crossX1));
  crossY = __min(minLenY,__min(crossY0,crossY1));
  crossZ = __min(minLenZ,__min(crossZ0,crossZ1));

  collision = crossX*crossY*crossZ;

  return collision;
}
//-------------------------------------------------------------------------------------
