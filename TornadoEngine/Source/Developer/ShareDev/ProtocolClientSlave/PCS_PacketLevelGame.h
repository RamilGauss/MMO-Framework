/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PCS_PacketLevelGameH
#define PCS_PacketLevelGameH

#include "PCS_TypePacket.h"
#include <string>

namespace nsPCS
{
  typedef int            TypeID_GameMap;
  typedef unsigned short TypeID_GameOject;
  //-----------------------------------------------------------------
  class DllExport TPacket_TryEnterRoom : public TBasePacket_PCS
  {
  public:
    TPacket_TryEnterRoom();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_TryEnterGarage : public TBasePacket_PCS
  {
  public:
    TPacket_TryEnterGarage();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnterGarage : public TBasePacket_PCS
  {
  public:
    TPacket_EnterGarage();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnterQueue : public TBasePacket_PCS
  {
    TPacket_EnterQueue();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnterRoom : public TBasePacket_PCS
  {
    TPacket_EnterRoom();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_LoadMap : public TBasePacket_PCS
  {
  public:
    TPacket_LoadMap();
    TypeID_GameMap mID_Map;
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_CorrectGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_CorrectGameObjects();
    TypeID_GameOject mID_Object;
    TContainer       mInternalState;
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_AddGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_AddGameObjects();
    std::string      mNameModel;
    bool             mMovable;
    TypeID_GameOject mID_Object;
    TContainer       mIternalState;
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnableGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_EnableGameObjects();
    TypeID_GameOject mID_Object;
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_DisableGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_DisableGameObjects();
    TypeID_GameOject mID_Object;
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_DeleteGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_DeleteGameObjects();
    TypeID_GameOject mID_Object;
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_GameImpl : public TBasePacket_PCS
  {
  public:
    TPacket_GameImpl();
    // empty! add some members!
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
}

#endif
