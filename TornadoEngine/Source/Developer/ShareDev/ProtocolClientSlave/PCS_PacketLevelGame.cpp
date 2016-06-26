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
TPacket_TryEnterGarage::TPacket_TryEnterGarage() : TBasePacket_PCS(ePacket_TryEnterGarage)
{

}
//-----------------------------------------------------------------
TPacket_EnterGarage::TPacket_EnterGarage() : TBasePacket_PCS(ePacket_EnterGarage)
{

}
//-----------------------------------------------------------------
TPacket_LoadMapEnd::TPacket_LoadMapEnd() : TBasePacket_PCS(ePacket_LoadMapEnd)
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
    bp.PushBack( (char*)&sizeInternalState, sizeof(TypeSizeInternalState));
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
    TypeSizeNameModel sizeNameModel = mVector[i].mNameModel.length();
    bp.PushBack( (char*)&sizeNameModel, sizeof(TypeSizeNameModel)   );
    bp.PushBack( (char*)mVector[i].mNameModel.data(), sizeNameModel );

    bp.PushBack( (char*)&(mVector[i].mMovable), sizeof(TypeMovable));
    bp.PushBack( (char*)&(mVector[i].mID_Object), sizeof(TypeID_GameOject));

    TypeSizeInternalState sizeInternalState = mVector[i].mInternalState.GetSize();
    bp.PushBack( (char*)&sizeInternalState, sizeof(TypeSizeInternalState));
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
    if( size < sizeof(TypeSizeNameModel) )
    {
      BL_FIX_BUG();
      return;
    }
    TypeSizeNameModel sizeNameModel = *((TypeSizeNameModel*)p);
    p    += sizeof(TypeSizeNameModel);
    size -= sizeof(TypeSizeNameModel);
    //---------------------------------------------------------------------
    if( size < sizeNameModel )
    {
      BL_FIX_BUG();
      return;
    }
    char str[sizeof(TypeSizeNameModel)+1];
    strncpy(str, p, sizeNameModel);
    str[sizeNameModel] = '\0';
    desc.mNameModel = str;
    p    += sizeNameModel;
    size -= sizeNameModel;
    //---------------------------------------------------------------------
    if( size < sizeof(TypeMovable) )
    {
      BL_FIX_BUG();
      return;
    }
    desc.mMovable = *((TypeMovable*)p);
    p    += sizeof(TypeMovable);
    size -= sizeof(TypeMovable);
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
TPacket_GameImpl::TPacket_GameImpl() : TBasePacket_PCS(ePacket_GameImpl)
{

}
//-----------------------------------------------------------------
