/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PCS_PacketLevelGame.h"
#include "BreakPacket.h"
#include "BL_Debug.h"

using namespace nsPCS;

TPacket_TryEnterRoom::TPacket_TryEnterRoom() : TBasePacket_PCS( ePacket_TryEnterRoom )
{

}
//-----------------------------------------------------------------
TContainerRise TPacket_TryEnterRoom::PackInherit()
{
  TContainerRise sResult;
  sResult.Clear();
  sResult.Append( sizeof( mTypeRoom ), (char*) &mTypeRoom );
  return sResult;
}
//-----------------------------------------------------------------
void TPacket_TryEnterRoom::UnpackInherit( char* p, int size )
{
  if( size >= sizeof( mTypeRoom ) )
    mTypeRoom = *((TypeTryEnterRoom*) p);
}
//-----------------------------------------------------------------
TPacket_TryEnterGarage::TPacket_TryEnterGarage() : TBasePacket_PCS( ePacket_TryEnterGarage )
{

}
//-----------------------------------------------------------------
TPacket_EnterGarage::TPacket_EnterGarage() : TBasePacket_PCS( ePacket_EnterGarage )
{

}
//-----------------------------------------------------------------
TPacket_EnterQueue::TPacket_EnterQueue() : TBasePacket_PCS( ePacket_EnterQueue )
{

}
//-----------------------------------------------------------------
TPacket_EnterRoom::TPacket_EnterRoom() : TBasePacket_PCS( ePacket_EnterRoom )
{

}
//-----------------------------------------------------------------
TPacket_LoadMap::TPacket_LoadMap() : TBasePacket_PCS( ePacket_LoadMap )
{
  mID_Map = 0;
}
//-----------------------------------------------------------------
TContainerRise TPacket_LoadMap::PackInherit()
{
  TContainerRise result;
  result.Clear();
  result.Append( sizeof( mID_Map ), (char*) &mID_Map );
  return result;
}
//-----------------------------------------------------------------
void TPacket_LoadMap::UnpackInherit( char* p, int size )
{
  if( size >= sizeof( mID_Map ) )
    mID_Map = *((unsigned int*) p);
}
//-----------------------------------------------------------------
TPacket_EndLoadMap::TPacket_EndLoadMap() : TBasePacket_PCS( ePacket_EndLoadMap )
{

}
//-----------------------------------------------------------------
TPacket_AddGameObjects::TPacket_AddGameObjects() : TBasePacket_PCS( ePacket_AddGameObjects )
{

}
//-----------------------------------------------------------------
TContainerRise TPacket_AddGameObjects::PackInherit()
{
  TContainerRise result;
  /*TBreakPacket bp;
  BOOST_FOREACH(TMapItem::TObject& object, mVectorObject)
  {
    TypeSizeNamePattern sizeNamePattern = object.namePattern.length();
    bp.PushBack( (char*)&sizeNamePattern, sizeof(TypeSizeNamePattern), true);
    bp.PushBack( (char*)object.namePattern.data(), sizeNamePattern );

    bp.PushBack( (char*)&(object.id), sizeof(TypeID_GameMap));

    bp.PushBack( (char*)&object.position, sizeof(nsMathTools::TVector3));
    bp.PushBack( (char*)&object.orientation, sizeof(nsMathTools::TQuternion));

    TypeCountParameterMap cntParameter = object.parameterMap.size();
    bp.PushBack( (char*)&cntParameter, sizeof(TypeCountParameterMap), true);
    // перечисление
    BOOST_FOREACH(TMapItem::TMapStrStrVT& vt, object.parameterMap)
    {
      TypeSizeKeyParameterMap sizeKey = vt.first.length();
      bp.PushBack( (char*)&sizeKey, sizeof(TypeSizeKeyParameterMap), true);
      bp.PushBack( (char*)vt.first.data(), sizeKey);

      TypeSizeValueParameterMap sizeValue = vt.second.length();
      bp.PushBack( (char*)&sizeValue, sizeof(TypeSizeValueParameterMap), true);
      bp.PushBack( (char*)vt.second.data(), sizeValue);
    }
  }
  bp.Collect();
  result.SetData( (char*)bp.GetCollectPtr(), bp.GetSize() );
  bp.UnlinkCollect();*/
  return result;
}
//-----------------------------------------------------------------
void TPacket_AddGameObjects::UnpackInherit( char* p, int size )
{
  /*mVectorObject.clear();
  while( size > 0)
  {
    TMapItem::TObject object;
    //---------------------------------------------------------------------
    if( size < sizeof(TypeSizeNamePattern) )
    {
      BL_FIX_BUG();
      return;
    }
    TypeSizeNamePattern sizeNamePattern = *((TypeSizeNamePattern*)p);
    p    += sizeof(TypeSizeNamePattern);
    size -= sizeof(TypeSizeNamePattern);
    //---------------------------------------------------------------------
    if( size < sizeNamePattern )
    {
      BL_FIX_BUG();
      return;
    }
    char str[256];
    strncpy(str, p, sizeNamePattern);
    str[sizeNamePattern] = '\0';
    object.namePattern = str;
    p    += sizeNamePattern;
    size -= sizeNamePattern;
    //---------------------------------------------------------------------
    if( size < sizeof(TypeID_GameMap) )
    {
      BL_FIX_BUG();
      return;
    }
    object.id = *((TypeID_GameMap*)p);
    p    += sizeof(TypeID_GameMap);
    size -= sizeof(TypeID_GameMap);
    //---------------------------------------------------------------------
    if( size < sizeof(nsMathTools::TVector3) )
    {
      BL_FIX_BUG();
      return;
    }
    object.position = *((nsMathTools::TVector3*)p);
    p    += sizeof(nsMathTools::TVector3);
    size -= sizeof(nsMathTools::TVector3);
    //---------------------------------------------------------------------
    if( size < sizeof(nsMathTools::TVector3) )
    {
      BL_FIX_BUG();
      return;
    }
    object.orientation = *((nsMathTools::TQuaternion*)p);
    p    += sizeof(nsMathTools::TVector3);
    size -= sizeof(nsMathTools::TVector3);
    //---------------------------------------------------------------------
    if( size < sizeof(TypeCountParameterMap) )
    {
      BL_FIX_BUG();
      return;
    }
    TypeCountParameterMap cntParameter = *((TypeCountParameterMap*)p);
    p    += sizeof(TypeCountParameterMap);
    size -= sizeof(TypeCountParameterMap);
    //---------------------------------------------------------------------
    while(cntParameter)
    {
      TypeSizeKeyParameterMap sizeKey = *((TypeSizeKeyParameterMap*)p);
      p    += sizeof(TypeSizeKeyParameterMap);
      size -= sizeof(TypeSizeKeyParameterMap);
      if( size < sizeKey )
      {
        BL_FIX_BUG();
        return;
      }
      char str[256];
      strncpy(str, p, sizeKey);
      str[sizeKey] = '\0';
      std::string key = str;
      p    += sizeKey;
      size -= sizeKey;
      //---------------------------------------------------------------------
      TypeSizeValueParameterMap sizeValue = *((TypeSizeValueParameterMap*)p);
      p    += sizeof(TypeSizeValueParameterMap);
      size -= sizeof(TypeSizeValueParameterMap);
      if( size < sizeValue )
      {
        BL_FIX_BUG();
        return;
      }
      strncpy(str, p, sizeValue);
      str[sizeValue] = '\0';
      std::string value = str;
      p    += sizeValue;
      size -= sizeValue;
      //---------------------------------------------------------------------
      object.parameterMap.insert(TMapItem::TMapStrStrVT(key,value));

      cntParameter--;
    }
    //---------------------------------------------------------------------
    mVectorObject.push_back(object);
  }*/
}
//-----------------------------------------------------------------
TPacket_EnableGameObjects::TPacket_EnableGameObjects() : TBasePacket_PCS( ePacket_EnableGameObjects )
{

}
//-----------------------------------------------------------------
TContainerRise TPacket_EnableGameObjects::PackInherit()
{
  TContainerRise result;
  mBP.Reset();
  for( TypeID_GameMap& id : mVectorID_Object )
    mBP.PushBack( (char*) &id, sizeof( TypeID_GameMap ) );

  mBP.CopyInBuffer( result );
  return result;
}
//-----------------------------------------------------------------
void TPacket_EnableGameObjects::UnpackInherit( char* p, int size )
{
  mVectorID_Object.clear();
  while( size > 0 )
  {
    TypeID_GameMap id;
    if( size < sizeof( TypeID_GameMap ) )
    {
      BL_FIX_BUG();
      return;
    }
    id = *((TypeID_GameMap*) p);
    p += sizeof( TypeID_GameMap );
    size -= sizeof( TypeID_GameMap );
    //---------------------------------------------------------------------
    mVectorID_Object.push_back( id );
  }
}
//-----------------------------------------------------------------
TPacket_DisableGameObjects::TPacket_DisableGameObjects() : TBasePacket_PCS( ePacket_DisableGameObjects )
{

}
//-----------------------------------------------------------------
TContainerRise TPacket_DisableGameObjects::PackInherit()
{
  TContainerRise result;
  mBP.Reset();
  for( TypeID_GameMap& id : mVectorID_Object )
    mBP.PushBack( (char*) &id, sizeof( TypeID_GameMap ) );

  mBP.CopyInBuffer( result );
  return result;
}
//-----------------------------------------------------------------
void TPacket_DisableGameObjects::UnpackInherit( char* p, int size )
{
  mVectorID_Object.clear();
  while( size > 0 )
  {
    TypeID_GameMap id;
    if( size < sizeof( TypeID_GameMap ) )
    {
      BL_FIX_BUG();
      return;
    }
    id = *((TypeID_GameMap*) p);
    p += sizeof( TypeID_GameMap );
    size -= sizeof( TypeID_GameMap );
    //---------------------------------------------------------------------
    mVectorID_Object.push_back( id );
  }
}
//-----------------------------------------------------------------
TPacket_AddGameItem::TPacket_AddGameItem() : TBasePacket_PCS( ePacket_AddGameItem )
{

}
//-----------------------------------------------------------------
TContainerRise TPacket_AddGameItem::PackInherit()
{
  mBP.Reset();
  mBP.PushBack( (char*) &mTypeFGIObject, sizeof( TypeFGIObject ) );

  TypeSizeNameFGIObject sizeName = mNameObject.length();
  mBP.PushBack( (char*) &sizeName, sizeof( TypeSizeNameFGIObject ) );
  mBP.PushBack( (char*) mNameObject.data(), sizeName );

  TypeSizeDescFGIObject sizeDesc = mDesc.GetSize();
  mBP.PushBack( (char*) &sizeDesc, sizeof( TypeSizeDescFGIObject ) );
  mBP.PushBack( (char*) mDesc.GetPtr(), sizeDesc );

  TContainerRise result;
  mBP.CopyInBuffer( result );
  return result;
}
//-----------------------------------------------------------------
void TPacket_AddGameItem::UnpackInherit( char* p, int size )
{
  if( size < sizeof( TypeFGIObject ) )
  {
    BL_FIX_BUG();
    return;
  }
  mTypeFGIObject = *((TypeFGIObject*) p);
  p += sizeof( TypeFGIObject );
  size -= sizeof( TypeFGIObject );
  //-------------------------------------------------
  if( size < sizeof( TypeSizeNameFGIObject ) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeNameFGIObject sizeName = *((TypeSizeNameFGIObject*) p);
  p += sizeof( TypeSizeNameFGIObject );
  size -= sizeof( TypeSizeNameFGIObject );
  //-------------------------------------------------
  if( size < sizeName )
  {
    BL_FIX_BUG();
    return;
  }
  char str[256];
  strncpy( str, p, sizeName );
  str[sizeName] = '\0';
  mNameObject = str;
  p += sizeName;
  size -= sizeName;
  //-------------------------------------------------
  if( size < sizeof( TypeSizeDescFGIObject ) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeDescFGIObject sizeDesc = *((TypeSizeDescFGIObject*) p);
  p += sizeof( TypeSizeDescFGIObject );
  size -= sizeof( TypeSizeDescFGIObject );
  //-------------------------------------------------
  if( size < sizeDesc )
  {
    BL_FIX_BUG();
    return;
  }
  mDesc.SetData( p, sizeDesc );
  p += sizeDesc;
  size -= sizeDesc;

  BL_ASSERT( size == 0 );
}
//-----------------------------------------------------------------
TPacket_ModifyGameItem::TPacket_ModifyGameItem() : TBasePacket_PCS( ePacket_ModifyGameItem )
{

}
//-----------------------------------------------------------------
TContainerRise TPacket_ModifyGameItem::PackInherit()
{
  mBP.Reset();
  mBP.PushBack( (char*) &mTypeFGIObject, sizeof( TypeFGIObject ) );

  TypeSizeNameFGIObject sizeName = mNameObject.length();
  mBP.PushBack( (char*) &sizeName, sizeof( TypeSizeNameFGIObject ) );
  mBP.PushBack( (char*) mNameObject.data(), sizeName );

  TypeSizeDescFGIObject sizeDesc = mDesc.GetSize();
  mBP.PushBack( (char*) &sizeDesc, sizeof( TypeSizeDescFGIObject ) );
  mBP.PushBack( (char*) mDesc.GetPtr(), sizeDesc );

  TContainerRise result;
  mBP.CopyInBuffer( result );
  return result;
}
//-----------------------------------------------------------------
void TPacket_ModifyGameItem::UnpackInherit( char* p, int size )
{
  if( size < sizeof( TypeFGIObject ) )
  {
    BL_FIX_BUG();
    return;
  }
  mTypeFGIObject = *((TypeFGIObject*) p);
  p += sizeof( TypeFGIObject );
  size -= sizeof( TypeFGIObject );
  //-------------------------------------------------
  if( size < sizeof( TypeSizeNameFGIObject ) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeNameFGIObject sizeName = *((TypeSizeNameFGIObject*) p);
  p += sizeof( TypeSizeNameFGIObject );
  size -= sizeof( TypeSizeNameFGIObject );
  //-------------------------------------------------
  if( size < sizeName )
  {
    BL_FIX_BUG();
    return;
  }
  char str[256];
  strncpy( str, p, sizeName );
  str[sizeName] = '\0';
  mNameObject = str;
  p += sizeName;
  size -= sizeName;
  //-------------------------------------------------
  if( size < sizeof( TypeSizeDescFGIObject ) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeDescFGIObject sizeDesc = *((TypeSizeDescFGIObject*) p);
  p += sizeof( TypeSizeDescFGIObject );
  size -= sizeof( TypeSizeDescFGIObject );
  //-------------------------------------------------
  if( size < sizeDesc )
  {
    BL_FIX_BUG();
    return;
  }
  mDesc.SetData( p, sizeDesc );
  p += sizeDesc;
  size -= sizeDesc;

  BL_ASSERT( size == 0 );
}
//-----------------------------------------------------------------
TPacket_DeleteGameItem::TPacket_DeleteGameItem() : TBasePacket_PCS( ePacket_DeleteGameItem )
{

}
//-----------------------------------------------------------------
TContainerRise TPacket_DeleteGameItem::PackInherit()
{
  mBP.Reset();
  mBP.PushBack( (char*) &mTypeFGIObject, sizeof( TypeFGIObject ) );

  TypeSizeNameFGIObject sizeName = mNameObject.length();
  mBP.PushBack( (char*) &sizeName, sizeof( TypeSizeNameFGIObject ) );
  mBP.PushBack( (char*) mNameObject.data(), sizeName );

  TContainerRise result;
  mBP.CopyInBuffer( result );
  return result;
}
//-----------------------------------------------------------------
void TPacket_DeleteGameItem::UnpackInherit( char* p, int size )
{
  if( size < sizeof( TypeFGIObject ) )
  {
    BL_FIX_BUG();
    return;
  }
  mTypeFGIObject = *((TypeFGIObject*) p);
  p += sizeof( TypeFGIObject );
  size -= sizeof( TypeFGIObject );
  //-------------------------------------------------
  if( size < sizeof( TypeSizeNameFGIObject ) )
  {
    BL_FIX_BUG();
    return;
  }
  TypeSizeNameFGIObject sizeName = *((TypeSizeNameFGIObject*) p);
  p += sizeof( TypeSizeNameFGIObject );
  size -= sizeof( TypeSizeNameFGIObject );
  //-------------------------------------------------
  if( size < sizeName )
  {
    BL_FIX_BUG();
    return;
  }
  char str[256];
  strncpy( str, p, sizeName );
  str[sizeName] = '\0';
  mNameObject = str;
  p += sizeName;
  size -= sizeName;
  //-------------------------------------------------

  BL_ASSERT( size == 0 );
}
//-----------------------------------------------------------------
TPacket_UpdateGameObjectByPattern::TPacket_UpdateGameObjectByPattern() : TBasePacket_PCS( ePacket_UpdateGameObjectByPattern )
{

}
//-----------------------------------------------------------------
TContainerRise TPacket_UpdateGameObjectByPattern::PackInherit()
{
  TContainerRise result;
  mBP.Reset();
  for( TDescCorrection& desc : mVector )
  {
    mBP.PushBack( (char*)&(desc.mID_Object), sizeof( TypeID_GameMap ) );
    TypeSizeParameter sizeParameter = desc.mParameter.GetSize();
    mBP.PushBack( (char*) &sizeParameter, sizeof( TypeSizeParameter ) );
    mBP.PushBack( (char*) desc.mParameter.GetPtr(), sizeParameter );
  }
  mBP.CopyInBuffer( result );
  return result;
}
//-----------------------------------------------------------------
void TPacket_UpdateGameObjectByPattern::UnpackInherit( char* p, int size )
{
  mVector.clear();
  while( size > 0 )
  {
    TDescCorrection desc;
    if( size < sizeof( TypeID_GameMap ) )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mID_Object = *((TypeID_GameMap*) p);
    p += sizeof( TypeID_GameMap );
    size -= sizeof( TypeID_GameMap );
    //---------------------------------------------------------------------
    if( size < sizeof( TypeSizeParameter ) )
    {
      BL_FIX_BUG();
      return;
    }
    TypeSizeParameter sizeParameter = *((TypeSizeParameter*) p);
    p += sizeof( TypeSizeParameter );
    size -= sizeof( TypeSizeParameter );
    //---------------------------------------------------------------------
    if( size < sizeParameter )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mParameter.SetData( p, sizeParameter );
    p += sizeParameter;
    size -= sizeParameter;
    //---------------------------------------------------------------------
    mVector.push_back( desc );
  }
}
//-----------------------------------------------------------------
TPacket_GameImpl::TPacket_GameImpl() : TBasePacket_PCS( ePacket_GameImpl )
{

}
//-----------------------------------------------------------------
