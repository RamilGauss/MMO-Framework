/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Mesh.h"

using namespace nsGraphicEngine;

const float* TMesh::GetPointData() const
{
    return &mVertices[0];
}
//-------------------------------------------------------------------------------
int TMesh::GetPointCount() const
{
    return GetDataSize() / sizeof(TPoint);
}
//-------------------------------------------------------------------------------
int TMesh::GetDataSize() const
{
    return mVertices.size() * sizeof(float);
}
//-------------------------------------------------------------------------------
void TMesh::AddPoint(const TPoint& point)
{
    mVertices.push_back(point.x);
    mVertices.push_back(point.y);
    mVertices.push_back(point.z);
    mVertices.push_back(point.u);
    mVertices.push_back(point.v);
}
//-------------------------------------------------------------------------------
