/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ManagerSerializerItem_XML.h"

#include "FactoryGameItem.h"

#include "IXML.h"

TManagerSerializerItem_XML::TManagerSerializerItem_XML()
{
    mSerializerPatternConfig.reset(new TSerializerPatternConfigItem_XML);
    mSerializerShape.reset(new TSerializerShapeItem_XML);
    mSerializerModel.reset(new TSerializerModelItem_XML);
    mSerializerMaterial.reset(new TSerializerMaterialItem_XML);
    mSerializerTerrain.reset(new TSerializerTerrainItem_XML);
    mSerializerMap.reset(new TSerializerMapItem_XML);
    mSerializerTableSound.reset(new TSerializerTableSoundItem_XML);

    mXML = NULL;

    mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::PatternConfig, mSerializerPatternConfig.get()));
    mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Material, mSerializerMaterial.get()));
    mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Shape, mSerializerShape.get()));
    mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Model, mSerializerModel.get()));
    mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Terrain, mSerializerTerrain.get()));
    mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Map, mSerializerMap.get()));
    mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::TableSound, mSerializerTableSound.get()));

    for (auto& vtTypePtrSer : mMapTypeSerializer)
        mMapStrType.insert(vtTypePtrSer.second->Type(), vtTypePtrSer.first);
}
//--------------------------------------------------------------------------------------
void TManagerSerializerItem_XML::Init(IXML* xml)
{
    mXML = xml;

    for (auto& vt : mMapTypeSerializer)
        vt.second->Init(mXML);
}
//--------------------------------------------------------------------------------------
bool TManagerSerializerItem_XML::Load(TBaseItem* pItem)
{
    TBaseSerializerItem_XML* p = Find(pItem->mType);
    if (p == NULL)
        return false;
    return p->Load(pItem);
}
//--------------------------------------------------------------------------------------
bool TManagerSerializerItem_XML::Save(TBaseItem* pItem)
{
    TBaseSerializerItem_XML* p = Find(pItem->mType);
    if (p == NULL)
        return false;
    return p->Save(pItem);
}
//--------------------------------------------------------------------------------------
bool TManagerSerializerItem_XML::Remove(int type, std::string& name)
{
    TBaseSerializerItem_XML* p = Find(type);
    if (p == NULL)
        return false;
    return p->RemoveSection(name);
}
//--------------------------------------------------------------------------------------
bool TManagerSerializerItem_XML::Remove(TBaseItem* pItem)
{
    return Remove(pItem->mType, pItem->mName);
}
//--------------------------------------------------------------------------------------
bool TManagerSerializerItem_XML::Save()
{
    bool res = false;
    if (mXML)
        res = mXML->Save();
    return res;
}
//--------------------------------------------------------------------------------------
TBaseSerializerItem_XML* TManagerSerializerItem_XML::Find(int type)
{
    TMapIntPtrSerilizerIt fit = mMapTypeSerializer.find(type);
    if (fit == mMapTypeSerializer.end())
        return NULL;
    return fit->second;
}
//--------------------------------------------------------------------------------------
bool TManagerSerializerItem_XML::Str2Type(std::string& strType, int& type)
{
    auto fit = mMapStrType.left.find(strType);
    if (fit == mMapStrType.left.end()) {
        return false;
    }
    type = fit->second;
    return true;
}
//--------------------------------------------------------------------------------------
bool TManagerSerializerItem_XML::Type2Str(int type, std::string& strType)
{
    auto fit = mMapStrType.right.find(type);
    if (fit == mMapStrType.right.end()) {
        return false;
    }
    strType = fit->second;
    return true;
}
//--------------------------------------------------------------------------------------

