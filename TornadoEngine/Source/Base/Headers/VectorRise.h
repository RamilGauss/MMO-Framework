/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <vector>
#include <algorithm>
#include <cstring>
#include "TypeDef.h"

template<typename Type>
class DllExport TVectorRise
{
public:
  std::vector<Type> mVec;
  size_t mCounter = 0;
  TVectorRise();

  void IncreaseVec();
  void Append(Type value);
  void PopBack();
  void Shuffle();
  void Sort();
  void DeleteDuplicates();
  void Clear();

  void Zero(size_t count);
};
//-----------------------------------------------------------------------------------------
template<typename Type>
TVectorRise<Type>::TVectorRise()
{
  mVec.resize(0xFF + 1);
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::IncreaseVec()
{
  mVec.resize(mVec.size() * 2 + 1);
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Append(Type value)
{
  mVec[mCounter] = value;
  mCounter++;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::PopBack()
{
  mCounter--;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Shuffle()
{
  std::random_shuffle(&mVec[0], &mVec[mCounter]);
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Sort()
{
  std::sort(&mVec[0], &mVec[mCounter]);
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::DeleteDuplicates()
{
  int uniqueCnt = 1;// ������ ���� ������
  Type unique = mVec[0];
  for (size_t i = 0; i < mCounter; i++)
  {
    // ����� ����������
    auto& value = mVec[i];
    if (unique != value)
    {
      mVec[uniqueCnt] = value;
      unique = value;
      uniqueCnt++;
    }
  }
  mCounter = uniqueCnt;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Clear()
{
  mCounter = 0;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Zero(size_t count)
{
  memset(&mVec[0], 0, sizeof(Type)*count);
}
//-----------------------------------------------------------------------------------------
