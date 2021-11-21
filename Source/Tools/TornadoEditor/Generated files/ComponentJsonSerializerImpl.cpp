/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ComponentJsonSerializerImpl.h"

#include "ComponentJsonSerializer.h"
#include "TornadoEngine/Generated files/ComponentJsonSerializer.h"

using namespace nsTornadoEditor;

TComponentJsonSerializerImpl::TComponentJsonSerializerImpl()
{

}
//--------------------------------------------------------------------------------------------
TComponentJsonSerializerImpl::~TComponentJsonSerializerImpl()
{

}
//--------------------------------------------------------------------------------------------
void TComponentJsonSerializerImpl::Serialize(void* p, std::string& json, int rtti)
{
    if (TComponentJsonSerializer::Has(rtti)) {
        TComponentJsonSerializer::Serialize(p, json, rtti);
        return;
    }

    if (nsTornadoEngine::TComponentJsonSerializer::Has(rtti)) {
        nsTornadoEngine::TComponentJsonSerializer::Serialize(p, json, rtti);
    }
}
//--------------------------------------------------------------------------------------------
bool TComponentJsonSerializerImpl::Deserialize(void* p, const std::string& json, int rtti, std::string& err)
{
    if (TComponentJsonSerializer::Has(rtti)) {
        return TComponentJsonSerializer::Deserialize(p, json, rtti, err);
    }
    if (nsTornadoEngine::TComponentJsonSerializer::Has(rtti)) {
        return nsTornadoEngine::TComponentJsonSerializer::Deserialize(p, json, rtti, err);
    }
    return false;
}
//--------------------------------------------------------------------------------------------
