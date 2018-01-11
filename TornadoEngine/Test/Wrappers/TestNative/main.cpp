/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ImplementationProvider.h"
#include "MakerNetTransport.h"

int main(int argc, char** argv)
{
  NativeMMOEngineWrapper::IBase* pClient = (NativeMMOEngineWrapper::IBase*)NativeMMOEngineWrapper::TImplementationProvider::MakeClient(); 
  TMakerNetTransport* pMaker = new TMakerNetTransport();
  pClient->Init(pMaker);

  NativeMMOEngineWrapper::TImplementationProvider::Delete(pClient);
  delete pMaker;

  return 0;
}
//-----------------------------------------------------------------------
