/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IBaseObjectPrediction.h"
#include <memory.h>
#include <stddef.h>

IBaseObjectPrediction::IBaseObjectPrediction()
{
  //mType = type;
  //pUserData = NULL;
  //mUserDataSize = 0;
  //mArrDef = NULL;
  //mCntDef = 0;
}
//--------------------------------------------------------------------------
IBaseObjectPrediction::~IBaseObjectPrediction()
{
  //CleanUserData();
  //CleanArrDef();
}
////--------------------------------------------------------------------------
//unsigned short IBaseObjectPrediction::GetID()
//{
//  return mID;
//}
////--------------------------------------------------------------------------
//void IBaseObjectPrediction::SetID(unsigned short id)
//{
//  mID = id;
//}
//--------------------------------------------------------------------------
//unsigned int IBaseObjectPrediction::GetMaskState()
//{
//  return mMaskState;
//}
////--------------------------------------------------------------------------
//void IBaseObjectPrediction::SetUserData(char* pData, int size)
//{
//  CleanUserData();
//  mUserDataSize = size;
//  pUserData = new char[size];
//  memcpy(pUserData,pData,mUserDataSize);
//}
////--------------------------------------------------------------------------
//void IBaseObjectPrediction::GetUserData(char* pData, int& size)
//{
//  memcpy(pData,pUserData,mUserDataSize);
//}
////--------------------------------------------------------------------------
//void IBaseObjectPrediction::CleanUserData()
//{
//  delete[] pUserData;
//  pUserData = NULL;
//  mUserDataSize = 0;
//}
////--------------------------------------------------------------------------
//void IBaseObjectPrediction::CleanArrDef()
//{
//  delete []mArrDef;
//  mArrDef = NULL;
//  mCntDef = 0;
//}
////--------------------------------------------------------------------------
void IBaseObjectPrediction::SetupVectorNamePart()
{
  
}
//--------------------------------------------------------------------------