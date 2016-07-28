/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PCS_PacketLevelGame.h"
#include "BreakPacket.h"
#include "BL_Debug.h"

using namespace nsPCS;

TPacket_TryEnterRoom::TPacket_TryEnterRoom() : TBasePacket_PCS(ePacket_TryEnterRoom)
{

}
//-----------------------------------------------------------------
TContainer TPacket_TryEnterRoom::PackInherit()
{
  TContainer sResult;
  sResult.SetData((char*)&mTypeRoom, sizeof(mTypeRoom));
  return sResult;
}
//-----------------------------------------------------------------
void TPacket_TryEnterRoom::UnpackInherit( char* p, int size )
{
  if( size >= sizeof(mTypeRoom) )
    mTypeRoom = *((TypeTryEnterRoom*)p);
}
//-----------------------------------------------------------------
TPacket_TryEnterGarage::TPacket_TryEnterGarage() : TBasePacket_PCS(ePacket_TryEnterGarage)
{

}
//-----------------------------------------------------------------
TPacket_EnterGarage::TPacket_EnterGarage() : TBasePacket_PCS(ePacket_EnterGarage)
{

}
//-----------------------------------------------------------------
TPacket_EnterQueue::TPacket_EnterQueue() : TBasePacket_PCS(ePacket_EnterQueue)
{

}
//-----------------------------------------------------------------
TPacket_EnterRoom::TPacket_EnterRoom() : TBasePacket_PCS(ePacket_EnterRoom)
{

}
//-----------------------------------------------------------------
TPacket_LoadMap::TPacket_LoadMap() : TBasePacket_PCS(ePacket_LoadMap)
{
  mID_Map = 0;
}
//-----------------------------------------------------------------
TContainer TPacket_LoadMap::PackInherit()
{
  TContainer result;
  result.SetData( (char*)&mID_Map, sizeof(mID_Map));
  return result;
}
//-----------------------------------------------------------------
void TPacket_LoadMap::UnpackInherit( char* p, int size )
{
  if( size >= sizeof(mID_Map) )
    mID_Map = *((unsigned int*)p);
}
//-----------------------------------------------------------------
TPacket_CorrectGameObjects::TPacket_CorrectGameObjects() : TBasePacket_PCS(ePacket_CorrectGameObjects)
{

}
//-----------------------------------------------------------------
TContainer TPacket_CorrectGameObjects::PackInherit()
{
  TContainer result;
  int cnt = mVector.size();
  TBreakPacket bp;
  for( int i = 0 ; i < cnt ; i++ )
  {
    bp.PushBack( (char*)&(mVector[i].mID_Object), sizeof(TypeID_GameOject));
    TypeSizeInternalState sizeInternalState = mVector[i].mInternalState.GetSize();
    bp.PushBack( (char*)&sizeInternalState, sizeof(TypeSizeInternalState), true);
    bp.PushBack( (char*)mVector[i].mInternalState.GetPtr(), sizeInternalState);
  }
  bp.Collect();
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_CorrectGameObjects::UnpackInherit( char* p, int size )
{
  mVector.clear();
  while( size > 0)
  {
    TDescCorrection desc;
    if( size < sizeof(TypeID_GameOject) )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mID_Object = *((TypeID_GameOject*)p);
    p    += sizeof(TypeID_GameOject);
    size -= sizeof(TypeID_GameOject);
    //---------------------------------------------------------------------
    if( size < sizeof(TypeSizeInternalState) )
    {
      BL_FIX_BUG();
      return;
    }
    TypeSizeInternalState sizeInternalSize = *((TypeSizeInternalState*)p);
    p    += sizeof(TypeSizeInternalState);
    size -= sizeof(TypeSizeInternalState);
    //---------------------------------------------------------------------
    if( size < sizeInternalSize )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mInternalState.SetData( p, sizeInternalSize);
    p    += sizeInternalSize;
    size -= sizeInternalSize;
    //---------------------------------------------------------------------
    mVector.push_back(desc);
  }
}
//-----------------------------------------------------------------
TPacket_AddGameObjects::TPacket_AddGameObjects() : TBasePacket_PCS(ePacket_AddGameObjects)
{

}
//-----------------------------------------------------------------
TContainer TPacket_AddGameObjects::PackInherit()
{
  TContainer result;
  int cnt = mVector.size();
  TBreakPacket bp;
  for( int i = 0 ; i < cnt ; i++ )
  {
    bp.PushBack( (char*)&(mVector[i].mID_Object), sizeof(TypeID_GameOject));

    TypeSizeNameType sizeNameType = mVector[i].mType.length();
    bp.PushBack( (char*)&sizeNameType, sizeof(TypeSizeNameType), true);
    bp.PushBack( (char*)mVector[i].mType.data(), sizeNameType );


    bp.PushBack( (char*)&mVector[i].mPos,    sizeof(nsMathTools::TVector3));
    bp.PushBack( (char*)&mVector[i].mOrient, sizeof(nsMathTools::TVector3));

    TypeSizeInternalState sizeInternalState = mVector[i].mInternalState.GetSize();
    bp.PushBack( (char*)&sizeInternalState, sizeof(TypeSizeInternalState), true);
    bp.PushBack( (char*)mVector[i].mInternalState.GetPtr(), sizeInternalState);
  }
  bp.Collect();
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_AddGameObjects::UnpackInherit( char* p, int size )
{
  mVector.clear();
  while( size > 0)
  {
    TDescAdd desc;
    //---------------------------------------------------------------------
    if( size < sizeof(TypeID_GameOject) )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mID_Object = *((TypeID_GameOject*)p);
    p    += sizeof(TypeID_GameOject);
    size -= sizeof(TypeID_GameOject);
    //---------------------------------------------------------------------
    if( size < sizeof(TypeSizeNameType) )
    {
      BL_FIX_BUG();
      return;
    }
    TypeSizeNameType sizeNameType = *((TypeSizeNameType*)p);
    p    += sizeof(TypeSizeNameType);
    size -= sizeof(TypeSizeNameType);
    //---------------------------------------------------------------------
    if( size < sizeNameType )
    {
      BL_FIX_BUG();
      return;
    }
    char str[256];
    strncpy(str, p, sizeNameType);
    str[sizeNameType] = '\0';
    desc.mType = str;
    p    += sizeNameType;
    size -= sizeNameType;
    //---------------------------------------------------------------------
    if( size < sizeof(nsMathTools::TVector3) )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mPos = *((nsMathTools::TVector3*)p);
    p    += sizeof(nsMathTools::TVector3);
    size -= sizeof(nsMathTools::TVector3);
    //---------------------------------------------------------------------
    if( size < sizeof(nsMathTools::TVector3) )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mOrient = *((nsMathTools::TVector3*)p);
    p    += sizeof(nsMathTools::TVector3);
    size -= sizeof(nsMathTools::TVector3);
    //---------------------------------------------------------------------
    if( size < sizeof(TypeSizeInternalState) )
    {
      BL_FIX_BUG();
      return;
    }
    TypeSizeInternalState sizeInternalSize = *((TypeSizeInternalState*)p);
    p    += sizeof(TypeSizeInternalState);
    size -= sizeof(TypeSizeInternalState);
    //---------------------------------------------------------------------
    if( size < sizeInternalSize )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mInternalState.SetData( p, sizeInternalSize);
    p    += sizeInternalSize;
    size -= sizeInternalSize;
    //---------------------------------------------------------------------
    mVector.push_back(desc);
  }
}
//-----------------------------------------------------------------
TPacket_EnableGameObjects::TPacket_EnableGameObjects() : TBasePacket_PCS(ePacket_EnableGameObjects)
{

}
//-----------------------------------------------------------------
TContainer TPacket_EnableGameObjects::PackInherit()
{
  TContainer result;
  int cnt = mVectorID_Object.size();
  TBreakPacket bp;
  for( int i = 0 ; i < cnt ; i++ )
    bp.PushBack( (char*)&(mVectorID_Object[i]), sizeof(TypeID_GameOject));

  bp.Collect();
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_EnableGameObjects::UnpackInherit( char* p, int size )
{
  mVectorID_Object.clear();
  while( size > 0)
  {
    TypeID_GameOject id;
    if( size < sizeof(TypeID_GameOject) )
    {
      BL_FIX_BUG();
      return;
    }
    id = *((TypeID_GameOject*)p);
    p    += sizeof(TypeID_GameOject);
    size -= sizeof(TypeID_GameOject);
    //---------------------------------------------------------------------
    mVectorID_Object.push_back(id);
  }
}
//-----------------------------------------------------------------
TPacket_DisableGameObjects::TPacket_DisableGameObjects() : TBasePacket_PCS(ePacket_DisableGameObjects)
{

}
//-----------------------------------------------------------------
TContainer TPacket_DisableGameObjects::PackInherit()
{
  TContainer result;
  int cnt = mVectorID_Object.size();
  TBreakPacket bp;
  for( int i = 0 ; i < cnt ; i++ )
    bp.PushBack( (char*)&(mVectorID_Object[i]), sizeof(TypeID_GameOject));

  bp.Collect();
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_DisableGameObjects::UnpackInherit( char* p, int size )
{
  mVectorID_Object.clear();
  while( size > 0)
  {
    TypeID_GameOject id;
    if( size < sizeof(TypeID_GameOject) )
    {
      BL_FIX_BUG();
      return;
    }
    id = *((TypeID_GameOject*)p);
    p    += sizeof(TypeID_GameOject);
    size -= sizeof(TypeID_GameOject);
    //---------------------------------------------------------------------
    mVectorID_Object.push_back(id);
  }
}
//-----------------------------------------------------------------
TPacket_AddFGIObject::TPacket_AddFGIObject() : TBasePacket_PCS(ePacket_AddFGIObject)
{

}
//-----------------------------------------------------------------
TContainer TPacket_AddFGIObject::PackInherit()
{
  TBreakPacket bp;
  bp.PushBack( (char*)&mTypeFGIObject, sizeof(TypeFGIObject));

  TypeSizeNameFGIObject sizeName = mNameObject.length();
  bp.PushBack( (char*)&sizeName, sizeof(TypeSizeNameFGIObject));
  bp.PushBack( (char*)mNameObject.data(), sizeName);

  TypeSizeDescFGIObject sizeDesc = mDesc.GetSize();
  bp.PushBack( (char*)&sizeDesc, sizeof(TypeSizeDescFGIObject));
  bp.PushBack( (char*)mDesc.GetPtr(), sizeDesc);

  bp.Collect();
  TContainer result;
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_AddFGIObject::UnpackInherit( char* p, int size )
{
  if( size < sizeof(TypeFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  mTypeFGIObject = *((TypeFGIObject*)p);
  p    += sizeof(TypeFGIObject);
  size -= sizeof(TypeFGIObject);
  //-------------------------------------------------
  if( size < sizeof(TypeSizeNameFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeNameFGIObject sizeName = *((TypeSizeNameFGIObject*)p);
  p    += sizeof(TypeSizeNameFGIObject);
  size -= sizeof(TypeSizeNameFGIObject);
  //-------------------------------------------------
  if( size < sizeName )
  {
    BL_FIX_BUG();
    return;
  }
  char str[256];
  strncpy(str, p, sizeName);
  str[sizeName] = '\0';
  mNameObject = str;
  p    += sizeName;
  size -= sizeName;
  //-------------------------------------------------
  if( size < sizeof(TypeSizeDescFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeDescFGIObject sizeDesc = *((TypeSizeDescFGIObject*)p);
  p    += sizeof(TypeSizeDescFGIObject);
  size -= sizeof(TypeSizeDescFGIObject);
  //-------------------------------------------------
  if( size < sizeDesc )
  {
    BL_FIX_BUG();
    return;
  }
  mDesc.SetData(p, sizeDesc);
  p    += sizeDesc;
  size -= sizeDesc;

  BL_ASSERT(size==0);
}
//-----------------------------------------------------------------
TPacket_ModifyFGIObject::TPacket_ModifyFGIObject() : TBasePacket_PCS(ePacket_ModifyFGIObject)
{

}
//-----------------------------------------------------------------
TContainer TPacket_ModifyFGIObject::PackInherit()
{
  TBreakPacket bp;
  bp.PushBack( (char*)&mTypeFGIObject, sizeof(TypeFGIObject));

  TypeSizeNameFGIObject sizeName = mNameObject.length();
  bp.PushBack( (char*)&sizeName, sizeof(TypeSizeNameFGIObject));
  bp.PushBack( (char*)mNameObject.data(), sizeName);

  TypeSizeDescFGIObject sizeDesc = mDesc.GetSize();
  bp.PushBack( (char*)&sizeDesc, sizeof(TypeSizeDescFGIObject));
  bp.PushBack( (char*)mDesc.GetPtr(), sizeDesc);

  bp.Collect();
  TContainer result;
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_ModifyFGIObject::UnpackInherit( char* p, int size )
{
  if( size < sizeof(TypeFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  mTypeFGIObject = *((TypeFGIObject*)p);
  p    += sizeof(TypeFGIObject);
  size -= sizeof(TypeFGIObject);
  //-------------------------------------------------
  if( size < sizeof(TypeSizeNameFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeNameFGIObject sizeName = *((TypeSizeNameFGIObject*)p);
  p    += sizeof(TypeSizeNameFGIObject);
  size -= sizeof(TypeSizeNameFGIObject);
  //-------------------------------------------------
  if( size < sizeName )
  {
    BL_FIX_BUG();
    return;
  }
  char str[256];
  strncpy(str, p, sizeName);
  str[sizeName] = '\0';
  mNameObject = str;
  p    += sizeName;
  size -= sizeName;
  //-------------------------------------------------
  if( size < sizeof(TypeSizeDescFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeDescFGIObject sizeDesc = *((TypeSizeDescFGIObject*)p);
  p    += sizeof(TypeSizeDescFGIObject);
  size -= sizeof(TypeSizeDescFGIObject);
  //-------------------------------------------------
  if( size < sizeDesc )
  {
    BL_FIX_BUG();
    return;
  }
  mDesc.SetData(p, sizeDesc);
  p    += sizeDesc;
  size -= sizeDesc;

  BL_ASSERT(size==0);
}
//-----------------------------------------------------------------
TPacket_DeleteFGIObject::TPacket_DeleteFGIObject() : TBasePacket_PCS(ePacket_DeleteFGIObject)
{

}
//-----------------------------------------------------------------
TContainer TPacket_DeleteFGIObject::PackInherit()
{
  TBreakPacket bp;
  bp.PushBack( (char*)&mTypeFGIObject, sizeof(TypeFGIObject));

  TypeSizeNameFGIObject sizeName = mNameObject.length();
  bp.PushBack( (char*)&sizeName, sizeof(TypeSizeNameFGIObject));
  bp.PushBack( (char*)mNameObject.data(), sizeName);

  bp.Collect();
  TContainer result;
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_DeleteFGIObject::UnpackInherit( char* p, int size )
{
  if( size < sizeof(TypeFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  mTypeFGIObject = *((TypeFGIObject*)p);
  p    += sizeof(TypeFGIObject);
  size -= sizeof(TypeFGIObject);
  //-------------------------------------------------
  if( size < sizeof(TypeSizeNameFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeNameFGIObject sizeName = *((TypeSizeNameFGIObject*)p);
  p    += sizeof(TypeSizeNameFGIObject);
  size -= sizeof(TypeSizeNameFGIObject);
  //-------------------------------------------------
  if( size < sizeName )
  {
    BL_FIX_BUG();
    return;
  }
  char str[256];
  strncpy(str, p, sizeName);
  str[sizeName] = '\0';
  mNameObject = str;
  p    += sizeName;
  size -= sizeName;
  //-------------------------------------------------

  BL_ASSERT(size==0);
}
//-----------------------------------------------------------------
TPacket_UpdateGameObjectByFGI::TPacket_UpdateGameObjectByFGI() : TBasePacket_PCS(ePacket_UpdateGameObjectByFGI)
{

}
//-----------------------------------------------------------------
TContainer TPacket_UpdateGameObjectByFGI::PackInherit()
{
  TBreakPacket bp;
  bp.PushBack( (char*)&mTypeFGIObject, sizeof(TypeFGIObject));

  TypeSizeNameFGIObject sizeName = mNameObject.length();
  bp.PushBack( (char*)&sizeName, sizeof(TypeSizeNameFGIObject));
  bp.PushBack( (char*)mNameObject.data(), sizeName);

  bp.Collect();
  TContainer result;
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_UpdateGameObjectByFGI::UnpackInherit( char* p, int size )
{
  if( size < sizeof(TypeFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  mTypeFGIObject = *((TypeFGIObject*)p);
  p    += sizeof(TypeFGIObject);
  size -= sizeof(TypeFGIObject);
  //-------------------------------------------------
  if( size < sizeof(TypeSizeNameFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeNameFGIObject sizeName = *((TypeSizeNameFGIObject*)p);
  p    += sizeof(TypeSizeNameFGIObject);
  size -= sizeof(TypeSizeNameFGIObject);
  //-------------------------------------------------
  if( size < sizeName )
  {
    BL_FIX_BUG();
    return;
  }
  char str[256];
  strncpy(str, p, sizeName);
  str[sizeName] = '\0';
  mNameObject = str;
  p    += sizeName;
  size -= sizeName;
  //-------------------------------------------------

  BL_ASSERT(size==0);
}
//-----------------------------------------------------------------
TPacket_UpdateGameObjectByPattern::TPacket_UpdateGameObjectByPattern() : TBasePacket_PCS(ePacket_UpdateGameObjectByPattern)
{

}
//-----------------------------------------------------------------
TContainer TPacket_UpdateGameObjectByPattern::PackInherit()
{
  TBreakPacket bp;
  bp.PushBack( (char*)&mTypeFGIObject, sizeof(TypeFGIObject));

  TypeSizeNameFGIObject sizeName = mNameObject.length();
  bp.PushBack( (char*)&sizeName, sizeof(TypeSizeNameFGIObject));
  bp.PushBack( (char*)mNameObject.data(), sizeName);

  TypeSizeDescFGIObject sizeDesc = mDesc.GetSize();
  bp.PushBack( (char*)&sizeDesc, sizeof(TypeSizeDescFGIObject));
  bp.PushBack( (char*)mDesc.GetPtr(), sizeDesc);

  bp.Collect();
  TContainer result;
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();
  return result;
}
//-----------------------------------------------------------------
void TPacket_UpdateGameObjectByPattern::UnpackInherit( char* p, int size )
{
  if( size < sizeof(TypeFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  mTypeFGIObject = *((TypeFGIObject*)p);
  p    += sizeof(TypeFGIObject);
  size -= sizeof(TypeFGIObject);
  //-------------------------------------------------
  if( size < sizeof(TypeSizeNameFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeNameFGIObject sizeName = *((TypeSizeNameFGIObject*)p);
  p    += sizeof(TypeSizeNameFGIObject);
  size -= sizeof(TypeSizeNameFGIObject);
  //-------------------------------------------------
  if( size < sizeName )
  {
    BL_FIX_BUG();
    return;
  }
  char str[256];
  strncpy(str, p, sizeName);
  str[sizeName] = '\0';
  mNameObject = str;
  p    += sizeName;
  size -= sizeName;
  //-------------------------------------------------
  if( size < sizeof(TypeSizeDescFGIObject) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeDescFGIObject sizeDesc = *((TypeSizeDescFGIObject*)p);
  p    += sizeof(TypeSizeDescFGIObject);
  size -= sizeof(TypeSizeDescFGIObject);
  //-------------------------------------------------
  if( size < sizeDesc )
  {
    BL_FIX_BUG();
    return;
  }
  mDesc.SetData(p, sizeDesc);
  p    += sizeDesc;
  size -= sizeDesc;

  BL_ASSERT(size==0);
}
//-----------------------------------------------------------------
TPacket_GameImpl::TPacket_GameImpl() : TBasePacket_PCS(ePacket_GameImpl)
{

}
//-----------------------------------------------------------------
