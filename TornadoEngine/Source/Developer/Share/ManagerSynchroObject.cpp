/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerSynchroObject.h"
#include "ISynchroObject.h"

#include <boost/foreach.hpp>

TManagerSynchroObject::TManagerSynchroObject()
{

}
//--------------------------------------------------------------
TManagerSynchroObject::~TManagerSynchroObject()
{

}
//--------------------------------------------------------------
void TManagerSynchroObject::Synchro()
{
  BOOST_FOREACH(ISynchroObject*pObject, mListObject)
    pObject->Synchro();
}
//--------------------------------------------------------------
void TManagerSynchroObject::Add(ISynchroObject* pObject)
{
  mListObject.push_back(pObject);
}
//--------------------------------------------------------------
void TManagerSynchroObject::Clear()
{
  mListObject.clear();
}
//--------------------------------------------------------------
