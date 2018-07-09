/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#define _USE_MATH_DEFINES

#include <cmath>

#include "NodeLocation_Model.h"
#include "BL_Debug.h"

TNodeLocation_Model::TNodeLocation_Model()
{

}
//---------------------------------------------------------------------------------
TNodeLocation_Model::~TNodeLocation_Model()
{
  ClearListLink();
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::AddJoint( std::string nameJoint )
{
  TJoint joint;
  joint.name = nameJoint;
  mMapNameJoint.insert( TMapStrJointVT( nameJoint, joint ) );
}
//---------------------------------------------------------------------------------
int TNodeLocation_Model::GetCountJoint()
{
  return mMapNameJoint.size();
}
//---------------------------------------------------------------------------------
TNodeLocation_Model::TJoint* TNodeLocation_Model::GetJoint( int index )
{
  if( index < 0 ||
    index >= GetCountJoint() )
    return NULL;
  TMapStrJointIt bit = mMapNameJoint.begin();
  for( int i = 0; i < index; i++ )
    bit++;
  return &(bit->second);
}
//---------------------------------------------------------------------------------
TNodeLocation_Model::TJoint* TNodeLocation_Model::GetJoint( std::string nameJoint )
{
  TMapStrJointIt fit = mMapNameJoint.find( nameJoint );
  if( fit == mMapNameJoint.end() )
    return NULL;
  return &(fit->second);
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::RemoveJoint( std::string nameJoint )
{
  mMapNameJoint.erase( nameJoint );
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::RemoveAllJoint()
{
  mMapNameJoint.clear();
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::ClearListLink()
{
  for( TLink*& pLink : mListLink )
    delete pLink;
  mListLink.clear();
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::CalcGlobalJoint()
{
  for( auto& vtNameJoint : mMapNameJoint )
  {
    TJoint* pJoint = &(vtNameJoint.second);
    // позиция нода рассчитывается с учётом крючков своих и родителя
    nsMathTools::TVector3 vResult;
    SetVec3TransformCoord( &vResult, &pJoint->mLocalRelativeNode.mPos, &mGlobal.mOrient );

    pJoint->mGlobal.mPos = mGlobal.mPos + vResult;
    // домножить на вращение относительно родителя
    pJoint->mGlobal.mOrient = pJoint->mLocalRelativeNode.mOrient*mGlobal.mOrient;// такой порядок
  }
}
//---------------------------------------------------------------------------------
// по правилам математики поворот против часовой стрелки - положительный
void TNodeLocation_Model::CalcGlobal( TNodeLocation_Model* pNodeLocationParent )
{
  TJoint* pJointParent = pNodeLocationParent->GetJoint( nameJointParent );
  TJoint* pMyJoint = GetJoint( nameMyJointToParent );
  if( pJointParent == NULL || pMyJoint == NULL )
  {
    BL_FIX_BUG();
    return;
  }

  // вращение крючка родителя с учетом параметров соединения
  nsMathTools::TMatrix16 qJointParentConnection = pJointParent->mLocalRelativeNode.mOrient*mOrientRelativeJointToJointParent;
  qJointParentConnection = qJointParentConnection * pNodeLocationParent->mGlobal.mOrient;
  //  nsMathTools::TMatrix16 qJointParentConnection = 
    //  pJointParent->mGlobal.mOrient * mOrientRelativeJointToJointParent;

  nsMathTools::TVector3 Forward( 1, 0, 0 );
  nsMathTools::TVector3 Up( 0, 1, 0 );
  nsMathTools::TVector3 Right( 0, 0, 1 );

  nsMathTools::TVector3 vUpRelativeJointParent( 0, 0, 0 );// локальные координаты вектора Вверх с учётом вращения
  nsMathTools::TVector3 vForwardRelativeJointParent( 0, 0, 0 );// локальные координаты вектора Вперед с учётом вращения

  SetVec3TransformCoord( &vUpRelativeJointParent, &Up, &qJointParentConnection );
  SetVec3TransformCoord( &vForwardRelativeJointParent, &Forward, &qJointParentConnection );

  nsMathTools::TVector3 lineHointToJoint = vForwardRelativeJointParent * mDistanceRelativeJointToJointParent;// растягиваем до расстояния между крючками

  nsMathTools::TVector3 globalPosJointChild =
    pJointParent->mGlobal.mPos + lineHointToJoint;

  nsMathTools::TVector3 vUpRelativeJointChild( 0, 0, 0 );// локальные координаты вектора Вверх с учётом вращения
  nsMathTools::TVector3 vForwardRelativeJointChild( 0, 0, 0 );// локальные координаты вектора Вперед с учётом вращения

  SetVec3TransformCoord( &vUpRelativeJointChild, &Up, &pMyJoint->mLocalRelativeNode.mOrient );
  SetVec3TransformCoord( &vForwardRelativeJointChild, &Forward, &pMyJoint->mLocalRelativeNode.mOrient );
  // найти матрицу вращения так что бы vUpRelativeJointChild и vUpRelativeJointParent были равны
  // а vForwardRelativeJointParent и vForwardRelativeJointChild были полностью противоположны
  nsMathTools::TVector3 negativevForwardRelativeJointParent = vForwardRelativeJointParent * -1;// к этому вектору нужно попасть

  CalcMatrixByMoveVectors( &mGlobal.mOrient,
    &vUpRelativeJointParent, &negativevForwardRelativeJointParent,
    &vUpRelativeJointChild, &vForwardRelativeJointChild );

  nsMathTools::TVector3 posChildRelativeJoint;
  SetVec3TransformCoord( &posChildRelativeJoint, &pMyJoint->mLocalRelativeNode.mPos, &mGlobal.mOrient );

  mGlobal.mPos = globalPosJointChild - posChildRelativeJoint;
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
struct TDescTestPoint
{
  nsMathTools::TVector3 pos;
  nsMathTools::TOrientation orient;
};
//---------------------------------------------------------------------------------
struct TTestData
{
  TDescTestPoint testParent;
  TDescTestPoint testJointParent;
  TDescTestPoint testJointChild;
};
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
void TestParam( TDescTestPoint* pTestParent, TDescTestPoint* pTestJointParent,
  TDescTestPoint* pTestJointChild )
{
  // разбор конкретного случая
  TNodeLocation_Model parent, child;
  parent.name = "Parent";
  parent.mGlobal.mPos = pTestParent->pos;
  SetMatrixRotationAxis( &parent.mGlobal.mOrient,
    &pTestParent->orient.axis, pTestParent->orient.angle );

  parent.AddJoint( "0" );
  TNodeLocation_Model::TJoint* pJointParent = parent.GetJoint( "0" );
  pJointParent->mLocalRelativeNode.mPos = pTestJointParent->pos;
  SetMatrixRotationAxis( &pJointParent->mLocalRelativeNode.mOrient,
    &pTestJointParent->orient.axis, pTestJointParent->orient.angle );// подготовка

  parent.CalcGlobalJoint();

  child.name = "Child";
  child.nameMyJointToParent = "0";
  child.nameJointParent = "0";
  child.mDistanceRelativeJointToJointParent = 4;
  nsMathTools::TVector3 axisOrientRelativeJointToJointParent( 1, 0, 0 );
  float angleOrientRelativeJointToJointParent = 0;
  SetMatrixRotationAxis( &child.mOrientRelativeJointToJointParent,
    &axisOrientRelativeJointToJointParent, angleOrientRelativeJointToJointParent );// подготовка

  child.AddJoint( "0" );
  TNodeLocation_Model::TJoint* pJointChild = child.GetJoint( "0" );
  pJointChild->mLocalRelativeNode.mPos = pTestJointChild->pos;
  SetMatrixRotationAxis( &pJointChild->mLocalRelativeNode.mOrient,
    &pTestJointChild->orient.axis, pTestJointChild->orient.angle );// подготовка

  child.CalcGlobal( &parent );
  child.CalcGlobalJoint();
}
//---------------------------------------------------------------------------------
void TestNodeLocation()
{
  const int countTest = 8;
  TTestData td[countTest];
  //====================================
  td[0].testParent.pos = nsMathTools::TVector3( 0, 0, 0 );
  td[0].testParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[0].testParent.orient.angle = 0;

  td[0].testJointParent.pos = nsMathTools::TVector3( 1, 0, 0 );
  td[0].testJointParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[0].testJointParent.orient.angle = 0;

  td[0].testJointChild.pos = nsMathTools::TVector3( 1, 0, 0 );
  td[0].testJointChild.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[0].testJointChild.orient.angle = 0;
  //====================================
  td[1].testParent.pos = nsMathTools::TVector3( 0, 0, 0 );
  td[1].testParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[1].testParent.orient.angle = 0;

  td[1].testJointParent.pos = nsMathTools::TVector3( 1, 0, 0 );
  td[1].testJointParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[1].testJointParent.orient.angle = 0;

  td[1].testJointChild.pos = nsMathTools::TVector3( -1, 0, 0 );
  td[1].testJointChild.orient.axis = nsMathTools::TVector3( 0, 1, 0 );
  td[1].testJointChild.orient.angle = float( M_PI );
  //====================================
  td[2].testParent.pos = nsMathTools::TVector3( 0, 0, 0 );
  td[2].testParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[2].testParent.orient.angle = 0;

  td[2].testJointParent.pos = nsMathTools::TVector3( 1, 0, 0 );
  td[2].testJointParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[2].testJointParent.orient.angle = 0;

  td[2].testJointChild.pos = nsMathTools::TVector3( -1, 0, 0 );
  td[2].testJointChild.orient.axis = nsMathTools::TVector3( 0, 0, 1 );
  td[2].testJointChild.orient.angle = float( M_PI );
  //====================================
  td[3].testParent.pos = nsMathTools::TVector3( 1, 40, 1 );
  td[3].testParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[3].testParent.orient.angle = 0;

  td[3].testJointParent.pos = nsMathTools::TVector3( 0, 0, 1 );
  td[3].testJointParent.orient.axis = nsMathTools::TVector3( 0, 1, 0 );
  td[3].testJointParent.orient.angle = -float( M_PI / 2 );

  td[3].testJointChild.pos = nsMathTools::TVector3( 1, 0, 0 );
  td[3].testJointChild.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[3].testJointChild.orient.angle = 0;
  //====================================
  td[4].testParent.pos = nsMathTools::TVector3( 0, 0, 0 );
  td[4].testParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[4].testParent.orient.angle = 0;

  td[4].testJointParent.pos = nsMathTools::TVector3( -1, 0, 0 );
  td[4].testJointParent.orient.axis = nsMathTools::TVector3( 0, 1, 0 );
  td[4].testJointParent.orient.angle = float( M_PI );

  td[4].testJointChild.pos = nsMathTools::TVector3( 1, 0, 0 );
  td[4].testJointChild.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[4].testJointChild.orient.angle = 0;
  //====================================
  td[5].testParent.pos = nsMathTools::TVector3( 0, 0, 0 );
  td[5].testParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[5].testParent.orient.angle = 0;

  td[5].testJointParent.pos = nsMathTools::TVector3( -1, 0, 0 );
  td[5].testJointParent.orient.axis = nsMathTools::TVector3( 0, 1, 0 );
  td[5].testJointParent.orient.angle = float( M_PI );

  td[5].testJointChild.pos = nsMathTools::TVector3( -1, 0, 0 );
  td[5].testJointChild.orient.axis = nsMathTools::TVector3( 0, 1, 0 );
  td[5].testJointChild.orient.angle = float( M_PI );
  //====================================
  td[6].testParent.pos = nsMathTools::TVector3( 0, 0, 0 );
  td[6].testParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[6].testParent.orient.angle = 0;

  td[6].testJointParent.pos = nsMathTools::TVector3( 1, 0, 0 );
  td[6].testJointParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[6].testJointParent.orient.angle = 0;

  td[6].testJointChild.pos = nsMathTools::TVector3( 0, 1, 0 );
  td[6].testJointChild.orient.axis = nsMathTools::TVector3( 0, 0, 1 );
  td[6].testJointChild.orient.angle = float( M_PI / 2 );
  //====================================
  td[7].testParent.pos = nsMathTools::TVector3( 0, 0, 0 );
  td[7].testParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[7].testParent.orient.angle = 0;

  td[7].testJointParent.pos = nsMathTools::TVector3( 1, 0, 0 );
  td[7].testJointParent.orient.axis = nsMathTools::TVector3( 1, 0, 0 );
  td[7].testJointParent.orient.angle = float( M_PI );

  td[7].testJointChild.pos = nsMathTools::TVector3( 0, 1, 0 );
  td[7].testJointChild.orient.axis = nsMathTools::TVector3( 0, 0, 1 );
  td[7].testJointChild.orient.angle = float( M_PI / 2 );
  //====================================
  int targetIndex = 0;
  //TestParam(&td[targetIndex].testParent, &td[targetIndex].testJointParent, 
    //&td[targetIndex].testJointChild);
  targetIndex = 7;
  TestParam( &td[targetIndex].testParent, &td[targetIndex].testJointParent,
    &td[targetIndex].testJointChild );
}
//--------------------------------------------------------------------

