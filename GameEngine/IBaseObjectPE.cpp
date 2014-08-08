/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IBaseObjectPE.h"
#include <memory.h>
#include <stddef.h>

IBaseObjectPE::IBaseObjectPE()
{
  //mType = type;
  //pUserData = NULL;
  //mUserDataSize = 0;
  //mArrDef = NULL;
  //mCntDef = 0;
}
//--------------------------------------------------------------------------
IBaseObjectPE::~IBaseObjectPE()
{
  //CleanUserData();
  //CleanArrDef();
}
////--------------------------------------------------------------------------
//unsigned short IBaseObjectPE::GetID()
//{
//  return mID;
//}
////--------------------------------------------------------------------------
//void IBaseObjectPE::SetID(unsigned short id)
//{
//  mID = id;
//}
//--------------------------------------------------------------------------
//unsigned int IBaseObjectPE::GetMaskState()
//{
//  return mMaskState;
//}
////--------------------------------------------------------------------------
//void IBaseObjectPE::SetUserData(char* pData, int size)
//{
//  CleanUserData();
//  mUserDataSize = size;
//  pUserData = new char[size];
//  memcpy(pUserData,pData,mUserDataSize);
//}
////--------------------------------------------------------------------------
//void IBaseObjectPE::GetUserData(char* pData, int& size)
//{
//  memcpy(pData,pUserData,mUserDataSize);
//}
////--------------------------------------------------------------------------
//void IBaseObjectPE::CleanUserData()
//{
//  delete[] pUserData;
//  pUserData = NULL;
//  mUserDataSize = 0;
//}
////--------------------------------------------------------------------------
//void IBaseObjectPE::CleanArrDef()
//{
//  delete []mArrDef;
//  mArrDef = NULL;
//  mCntDef = 0;
//}
////--------------------------------------------------------------------------
void IBaseObjectPE::SetupVectorNamePart()
{
  
}
//--------------------------------------------------------------------------