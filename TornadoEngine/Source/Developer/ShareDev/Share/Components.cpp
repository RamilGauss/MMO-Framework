/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Components.h"

#include <stddef.h>

#include "ModuleGraphicEngine.h"
#include "ModuleMMOEngineClient.h"
#include "ModuleMMOEngineSlave.h"
#include "ModuleMMOEngineMaster.h"
#include "ModuleMMOEngineSuperServer.h"
#include "ModulePhysicEngine.h"
#include "ModuleSoundEngine.h"
#include "ModuleTimer.h"
#include "ModuleDatabase.h"

TComponents::TComponents()
{
  pDataBase = NULL;
  pGraphicEngine = NULL;
  pMMOEngineClient = NULL;
  pMMOEngineSlave = NULL;
  pMMOEngineMaster = NULL;
  pMMOEngineSuperServer = NULL;
  pPhysicEngine = NULL;
  pSoundEngine = NULL;
  pTimer = NULL;
}
//------------------------------------------------------------------------------------------
void TComponents::SetLogicID( int id )
{
  mVecComp.push_back( pDataBase );
  mVecComp.push_back( pGraphicEngine );
  mVecComp.push_back( pMMOEngineClient );
  mVecComp.push_back( pMMOEngineSlave );
  mVecComp.push_back( pMMOEngineMaster );
  mVecComp.push_back( pMMOEngineSuperServer );
  mVecComp.push_back( pPhysicEngine );
  mVecComp.push_back( pSoundEngine );
  mVecComp.push_back( pTimer );

  for( auto pM : mVecComp )
    if( pM )
      pM->SetLogicID( id );
}
//------------------------------------------------------------------------------------------
