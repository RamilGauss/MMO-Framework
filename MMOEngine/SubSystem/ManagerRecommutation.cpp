/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerRecommutation.h"
#include "BL_Debug.h"
#include "Base.h"
#include "Logger.h"

using namespace nsMMOEngine;
using namespace std;

TManagerRecommutation::TManagerRecommutation()
{

}
//----------------------------------------------------------------------------------
TManagerRecommutation::~TManagerRecommutation()
{

}
//----------------------------------------------------------------------------------
bool TManagerRecommutation::FindSessionByClientKey(unsigned int key,
                                                   unsigned int& id_session_donor,
                                                   unsigned int& id_session_recipient)
{
  TMapUintPairIt fit = mMapClientKey_Slaves.find(key);
  if(fit==mMapClientKey_Slaves.end())
    return false;

  id_session_donor     = fit->second.first;
  id_session_recipient = fit->second.second;
  return true;
}
//----------------------------------------------------------------------------------
int TManagerRecommutation::GetCountClientBySessionSlave(unsigned int id_session)
{
  TMapUintSetIt fit = mMapSlave_SetClient.find(id_session);
  if(fit==mMapSlave_SetClient.end())
    return 0;

  int count  = fit->second.donor.size() + fit->second.recipient.size();
  return count;
}
//----------------------------------------------------------------------------------
bool TManagerRecommutation::GetClientKeyByIndex(unsigned int id_session, 
                                                int index, 
                                                unsigned int& key)
{
  TMapUintSetIt fit = mMapSlave_SetClient.find(id_session);
  if(fit==mMapSlave_SetClient.end())
    return false;

  int countDonor     = int(fit->second.donor.size());
  int countRecipient = int(fit->second.recipient.size());
  if(countRecipient + countDonor <= index)
    return false;// за границей
  // сначала множество Доноров
  if(countDonor>index)
  {
    TSetUintIt dbit = fit->second.donor.begin();
    for( int i = 0 ; i < index ; i++)
      dbit++;
    key = *dbit;
    return true;
  }
  index -= countDonor;
  // потом множество Реципиентов
  TSetUintIt rbit = fit->second.recipient.begin();
  for( int i = 0 ; i < index ; i++)
    rbit++;
  key = *rbit;
  return true;
}
//----------------------------------------------------------------------------------
void TManagerRecommutation::AddClientKey(unsigned int key, 
                                         unsigned int id_session_donor,
                                         unsigned int id_session_recipient)
{
  if(id_session_donor==id_session_recipient)
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerRecommutation::AddClientKey(key=%u) donor==recipient.\n",key);
    BL_FIX_BUG();
    return;
  }
  //--------------------------------------------------------------
  TMapUintPairIt fit = mMapClientKey_Slaves.find(key);
  if(fit!=mMapClientKey_Slaves.end())
  {
    // запись уже есть, значит, ее не удалили
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerRecommutation::AddClientKey(key=%u) is exist.\n",key);
    BL_FIX_BUG();
    return;
  }
  // новая запись
  TPairUintUint session_d_r(id_session_donor,id_session_recipient);
  mMapClientKey_Slaves.insert(TMapUintPair::value_type(key,session_d_r));

  AddClientKeyBySession(key, id_session_donor    , eDonor);
  AddClientKeyBySession(key, id_session_recipient, eRecipient);
}
//----------------------------------------------------------------------------------
void TManagerRecommutation::DeleteByClientKey(unsigned int key)
{
  unsigned int donor, recipient;
  // ищем Донора и Реципиента, связанных с Клиентом
  if(FindSessionByClientKey(key, donor, recipient)==false)
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerRecommutation::DeleteByClientKey(key=%u) not found Slave.\n",key);
    BL_FIX_BUG();
    return;
  }
  // удалить из списка Донора
  DeleteClientKeyBySession(key, donor, eDonor);
  // и из списка Реципиента
  DeleteClientKeyBySession(key, recipient, eRecipient);
  // удалить Клиента
  mMapClientKey_Slaves.erase(key);
}
//----------------------------------------------------------------------------------
void TManagerRecommutation::AddClientKeyBySession(unsigned int key, 
                                                  unsigned int id_session,
                                                  Type type)
{
   //добавить Slave, может его еще не добавляли
   //в случае существования insert проигнорирует попытку вставки
  mMapSlave_SetClient.insert(TMapUintSet::value_type(id_session, TSetClient()));

  TMapUintSetIt fit = mMapSlave_SetClient.find(id_session);
  switch(type)
  {
    case eDonor:
      fit->second.donor.insert(key);
      break;
    case eRecipient:
      fit->second.recipient.insert(key);
      break;
  }
}
//----------------------------------------------------------------------------------
void TManagerRecommutation::DeleteClientKeyBySession(unsigned int key, 
                                                     unsigned int id_session,     
                                                     Type type)
{
  TMapUintSetIt fit = mMapSlave_SetClient.find(id_session);
  if(fit==mMapSlave_SetClient.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerRecommutation::DeleteInSessionMapByClientKey(id_session=%u) not found.\n",id_session);
    BL_FIX_BUG();
    return;
  }
  switch(type)
  {
    case eDonor:
      fit->second.donor.erase(key);
      break;
    case eRecipient:
      fit->second.recipient.erase(key);
      break;
  }
}
//----------------------------------------------------------------------------------
