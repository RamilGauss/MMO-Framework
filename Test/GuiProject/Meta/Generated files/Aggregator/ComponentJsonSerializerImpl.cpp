/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:55.071
#include "ComponentJsonSerializerImpl.h"

#include "TornadoEngine\Generated files\Container\ComponentJson.h"
#include "Generated files\Container\ComponentJson.h"

using namespace nsTornadoEditor;

TComponentJsonSerializerImpl::TComponentJsonSerializerImpl()
{

}
//--------------------------------------------------------------------------------------------------
TComponentJsonSerializerImpl::~TComponentJsonSerializerImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TComponentJsonSerializerImpl::Init()
{
    TComponentJson::Init();
    nsTornadoEngine::TComponentJson::Init();
    }
    //--------------------------------------------------------------------------------------------------
    void TComponentJsonSerializerImpl::Serialize(void* p, std::string & json, int rtti)
    {
        if (TComponentJson::Has(rtti)) {
            TComponentJson::Serialize(p, json, rtti);
            return;
        }
        if (nsTornadoEngine::TComponentJson::Has(rtti)) {
            nsTornadoEngine::TComponentJson::Serialize(p, json, rtti);
        }
    }
    //--------------------------------------------------------------------------------------------------
    bool TComponentJsonSerializerImpl::Deserialize(void* p, const std::string & json, int rtti, std::string & err)
    {
        if (TComponentJson::Has(rtti)) {
            return TComponentJson::Deserialize(p, json, rtti, err);
        }
        if (nsTornadoEngine::TComponentJson::Has(rtti)) {
            return nsTornadoEngine::TComponentJson::Deserialize(p, json, rtti, err);
        }
        return false;
    }
    //--------------------------------------------------------------------------------------------------
    