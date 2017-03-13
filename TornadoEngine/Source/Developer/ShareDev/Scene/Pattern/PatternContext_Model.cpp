/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternContext_Model.h"
#include "ManagerNamePattern.h"
#include "BL_Debug.h"

TPatternContext_Model::TPatternContext_Model(TBehaviourPatternModel* pModel):
TBehaviourPatternContext(pModel)
{
  flgMobility = false;
  mTypeContent = TModelItem::eModel;
}
//--------------------------------------------------------------------------
TPatternContext_Model::~TPatternContext_Model()
{

}
//--------------------------------------------------------------------------
TModelItem::eType TPatternContext_Model::GetTypeContent()
{
  return mTypeContent;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetTypeContent(TModelItem::eType type)
{
  mTypeContent = type;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetMapVariant(TPatternConfigItem::TMapStrStr& mapVariant)
{
  mMapVariantPatternConfig = mapVariant;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::AddDesc(TBaseDesc* pDesc)
{
  TMapStrPtrDesc* pMap = FindMapByNamePart(pDesc->namePart);
  if( pMap==NULL )
  {
    mMapNamePart_NameVariantDesc.insert(TMapStr_StrPtrDescVT(pDesc->namePart, TMapStrPtrDesc()));
    pMap = FindMapByNamePart(pDesc->namePart);
  }
  if( pMap->find(pDesc->nameVariant)==pMap->end() )
    pMap->insert(TMapStrPtrDescVT(pDesc->nameVariant, pDesc));
  else
  {
    BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------
TPatternContext_Model::TBaseDesc* TPatternContext_Model::GetDesc(std::string& namePart, std::string& nameVariant)
{
  TMapStrPtrDesc* pMap = FindMapByNamePart(namePart);
  if( pMap==NULL )
    return NULL;
  TMapStrPtrDescIt fitVariant = pMap->find(nameVariant);
  if( fitVariant==pMap->end() )
    return NULL;
  return fitVariant->second;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetNameGameItem(std::string& name)
{
  mNameGameItem = name;
}
//--------------------------------------------------------------------------
std::string TPatternContext_Model::GetNameGameItem()
{
  return mNameGameItem;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetNameVariantPatternConfig(std::string& name)
{
  mNameVariantPatternConfig = name;
}
//--------------------------------------------------------------------------
std::string TPatternContext_Model::GetNameVariantPatternConfig()
{
  return mNameVariantPatternConfig;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetMobility(bool v)
{
  flgMobility = v;
}
//--------------------------------------------------------------------------
bool TPatternContext_Model::GetMobility()
{
  return flgMobility;
}
//--------------------------------------------------------------------------
int TPatternContext_Model::GetCountPart()
{
  return mMapNamePart_NameVariantDesc.size();
}
//--------------------------------------------------------------------------
std::string TPatternContext_Model::GetNamePart(int index)
{
  std::string namePart = "";
  if( index >= GetCountPart() || index < 0 )
    return namePart;
  TMapStr_StrPtrDescIt bit = mMapNamePart_NameVariantDesc.begin();
  for( int i = 0 ; i < index ; i++ )
    bit++;
  namePart = bit->first;
  return namePart;
}
//--------------------------------------------------------------------------
int TPatternContext_Model::GetCountVariant(std::string& namePart)
{
  TMapStrPtrDesc* pMap = FindMapByNamePart(namePart);
  if( pMap==NULL )
    return 0;
  return pMap->size();
}
//--------------------------------------------------------------------------
std::string TPatternContext_Model::GetNameVariant(std::string& namePart, int index)
{
  std::string nameVariant = "";
  TMapStrPtrDesc* pMap = FindMapByNamePart(namePart);
  if( pMap==NULL )
    return nameVariant;
  if( index >= GetCountVariant(namePart) || index < 0 )
    return nameVariant;

  TMapStrPtrDescIt bit = pMap->begin();
  for( int i = 0 ; i < index ; i++ )
    bit++;
  nameVariant = bit->first;
  return nameVariant;
}
//--------------------------------------------------------------------------
TPatternContext_Model::TMapStrPtrDesc* TPatternContext_Model::FindMapByNamePart(std::string& namePart)
{
  TMapStr_StrPtrDescIt fit = mMapNamePart_NameVariantDesc.find(namePart);
  if( fit==mMapNamePart_NameVariantDesc.end() )
    return NULL;
  return &(fit->second);
}
//--------------------------------------------------------------------------
