/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContextMachineH
#define ContextMachineH

#include <map>

template <class Key, class Value>
class TContextMachine
{
public:
  typedef std::map< Key, Value > TMapKeyValue;

protected:
  typedef std::multimap< Key, TMapKeyValue > TMultiMapKeyMap;
  TMultiMapKeyMap mMultiMapKeyMap;

public:

  TContextMachine();
  virtual ~TContextMachine();

  // добавить событие - получить реакцию (реакции может и не быть)
  bool Action(Key k, Value& v);

  // для инициализации
  void AddState(Key k, TMapKeyValue* mKV);
  int GetStateCount() const;

protected:
  void Done();

  int GetCountByKey(Key& k);
  void UpdateMapKeyCount(Key& k, int count);
  
  void ActionForSameKey(Key& k);
  void ActionForOtherKey(Key& k);

  typedef std::map<Key, int> TMapKeyInt;

  // для оптимизации
  TMapKeyInt mMapKeyCount; 
  int mCurCount;
  bool flgFirstUse;
  typename TMultiMapKeyMap::iterator mBeginSameIt;
  typename TMultiMapKeyMap::iterator mCurSameIt;

  TMapKeyValue* mCurrentMap;
  int mCurSameState;
  Key mSameState;
};
//---------------------------------------------------------------------
//---------------------------------------------------------------------
template <class Key, class Value>
TContextMachine<Key,Value>::TContextMachine()
{
  mCurrentMap = NULL;
  mCurSameState = 0;
  flgFirstUse = true;
}
//---------------------------------------------------------------------
template <class Key, class Value>
TContextMachine<Key,Value>::~TContextMachine()
{
  Done();
}
//---------------------------------------------------------------------
template <class Key, class Value>
bool TContextMachine<Key,Value>::Action(Key k, Value& v)
{
  // определить состояние
  if(mSameState==k)// то же значение состояния
    ActionForSameKey(k);
  else
    ActionForOtherKey(k);
  //------------------------------------------------------------------
  // поиск для состояния
  TMapKeyValue::iterator ffit = mCurrentMap->find(k);
  if(ffit!=mCurrentMap->end())
  {
    v = ffit->second;
    return true;
  }
  return false;
}
//---------------------------------------------------------------------
template <class Key, class Value>
void TContextMachine<Key,Value>::AddState(Key k,TMapKeyValue* pMKV)
{
  mMultiMapKeyMap.insert(TMultiMapKeyMap::value_type(k,*pMKV));
  if(mCurrentMap==NULL)
  {
    mCurrentMap = &(mMultiMapKeyMap.begin()->second);
    mSameState  = k;
  }
  UpdateMapKeyCount(k,mMultiMapKeyMap.count(k));
}
//---------------------------------------------------------------------
template <class Key, class Value>
int TContextMachine<Key,Value>::GetStateCount() const
{
  return mMultiMapKeyMap.size();
}
//---------------------------------------------------------------------
template <class Key, class Value>
void TContextMachine<Key,Value>::Done()
{
  mMultiMapKeyMap.clear();
  mMapKeyCount.clear();
  mCurrentMap = NULL;
  mCurSameState = 0;
}
//---------------------------------------------------------------------
template <class Key, class Value>
int TContextMachine<Key,Value>::GetCountByKey(Key& k)
{
  TMapKeyInt::iterator fit = mMapKeyCount.find(k);
  if(fit!=mMapKeyCount.end())
    return fit->second;

  return 0;
}
//---------------------------------------------------------------------
template <class Key, class Value>
void TContextMachine<Key,Value>::UpdateMapKeyCount(Key& k, int count)
{
  TMapKeyInt::iterator fit = mMapKeyCount.find(k);
  if(fit!=mMapKeyCount.end())
    fit->second = count;
  else
    mMapKeyCount.insert(TMapKeyInt::value_type(k,count));
}
//---------------------------------------------------------------------
template <class Key, class Value>
void TContextMachine<Key,Value>::ActionForSameKey(Key& k)
{
  if(flgFirstUse)
  {
    TMultiMapKeyMap::iterator fit = mMultiMapKeyMap.lower_bound(k);
    if(fit!=mMultiMapKeyMap.end())
    if(fit->first==k)
    {
      mBeginSameIt = fit;
      mCurCount    = GetCountByKey(k);

      mCurSameIt = mBeginSameIt;
    }
    flgFirstUse = false;
  }
  //------------------------------------
  mCurSameState++;
  if(mCurSameState==mCurCount)
  {
    mCurSameState = 0;
    mCurSameIt = mBeginSameIt;
  }
  else
    mCurSameIt++;
  mCurrentMap = &(mCurSameIt->second);
}
//---------------------------------------------------------------------
template <class Key, class Value>
void TContextMachine<Key,Value>::ActionForOtherKey(Key& k)
{
  TMultiMapKeyMap::iterator fit = mMultiMapKeyMap.lower_bound(k);
  if(fit!=mMultiMapKeyMap.end())
  if(fit->first==k)
  {
    mSameState      = k;
    mCurSameState   = 0;
    mCurCount       = GetCountByKey(k);
    mBeginSameIt    = fit;
    flgFirstUse = false;

    mCurSameIt = mBeginSameIt;

    mCurrentMap = &(mCurSameIt->second);
  }
}
//---------------------------------------------------------------------

#endif
