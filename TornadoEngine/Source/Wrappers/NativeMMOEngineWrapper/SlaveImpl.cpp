/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SlaveImpl.h"

namespace NativeMMOEngineWrapper
{
  TSlaveImpl::TSlaveImpl() 
    : TActiveServerImpl( new nsMMOEngine::TSlave() )
  {
    mSlave = (nsMMOEngine::TSlave*)GetBase();
  }
  //----------------------------------------------------------------------------------
  void TSlaveImpl::SaveContext(unsigned int id_session, void* data, int size)
  {
    mSlave->SaveContext(id_session, data, size);
  }
  //----------------------------------------------------------------------------------
  bool TSlaveImpl::FindClientKeyBySession(unsigned int id_session, unsigned int &id)
  {
    return mSlave->FindClientKeyBySession( id_session, id);
  }
  //----------------------------------------------------------------------------------
  bool TSlaveImpl::FindSessionByClientKey(unsigned int id, unsigned int& id_session)
  {
    return mSlave->FindSessionByClientKey( id, id_session);
  }
  //----------------------------------------------------------------------------------
}
