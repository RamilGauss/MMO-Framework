/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "StatisticaClientInGroup.h"
#include <boost/foreach.hpp>
#include <algorithm>


using namespace nsMMOEngine;
using namespace std;


TStatisticaClientInGroup::TStatisticaClientInGroup()
{

}
//---------------------------------------------------------------------------------------------------
TStatisticaClientInGroup::~TStatisticaClientInGroup()
{

}
//---------------------------------------------------------------------------------------------------
bool TStatisticaClientInGroup::FindSlaveSessionByMinimumClient(unsigned int &id_session_slave)
{
	if(mMapSlaveSessionClientKey.size()==0)
		return false;

	mVecDesc.clear();
	BOOST_FOREACH(TMapUintSetUint::value_type& it, mMapSlaveSessionClientKey)
		mVecDesc.push_back(TDesc(it.second.size(),it.first));

	sort(mVecDesc.begin(), mVecDesc.end());
	
  id_session_slave = mVecDesc[0].id_session;
  //###
	// только для теста перекоммутаций
  //id_session_slave = mVecDesc[mVecDesc.size() - 1].id_session;// выдать последний
  //###
	return true;
}
//---------------------------------------------------------------------------------------------------
void TStatisticaClientInGroup::AddSlave(unsigned int id_session_slave)
{
	mMapSlaveSessionClientKey.insert(TMapUintSetUint::value_type(id_session_slave, TSetUint()));
}
//---------------------------------------------------------------------------------------------------
void TStatisticaClientInGroup::AddBySlaveSessionClientKey(unsigned int id_session_slave, 
																													unsigned int key)
{
	TMapUintSetUintIt fit = mMapSlaveSessionClientKey.find(id_session_slave);
	if(fit==mMapSlaveSessionClientKey.end())
		return;
	fit->second.insert(TSetUint::value_type(key));
}
//---------------------------------------------------------------------------------------------------
void TStatisticaClientInGroup::DeleteBySlaveSession(unsigned int id_session_slave)
{
	mMapSlaveSessionClientKey.erase(id_session_slave);
}
//---------------------------------------------------------------------------------------------------
void TStatisticaClientInGroup::DeleteByClientKey(unsigned int id_session_slave, unsigned int key)
{
	TMapUintSetUintIt fit = mMapSlaveSessionClientKey.find(id_session_slave);
	if(fit==mMapSlaveSessionClientKey.end())
		return;

	fit->second.erase(key);
}
//---------------------------------------------------------------------------------------------------
bool TStatisticaClientInGroup::FindCountClientBySlaveSession(unsigned int id_session_slave, 
                                                             int& countClient)
{
  TMapUintSetUintIt fit = mMapSlaveSessionClientKey.find(id_session_slave);
  if(fit==mMapSlaveSessionClientKey.end())
    return false;

  countClient = fit->second.size();
  return true;  
}
//---------------------------------------------------------------------------------------------------
