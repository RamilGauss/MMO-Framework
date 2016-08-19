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
#include <vector>
#include "MathTools.h"
#include "MapItem.h"

namespace nsPCS
{
  typedef int            TypeID_GameMap;
  typedef unsigned short TypeSizeParameter;
  typedef unsigned char  TypeSizeNamePattern;
  typedef unsigned char  TypeSizeNameFGIObject;
  typedef unsigned short TypeSizeDescFGIObject;
  typedef unsigned char  TypeFGIObject;
  typedef unsigned int   TypeTryEnterRoom;
  typedef unsigned short TypeCountParameterMap;
  typedef unsigned char  TypeSizeKeyParameterMap;
  typedef unsigned char  TypeSizeValueParameterMap;
  typedef enum
  {
    Material,
    Map,
    Model,
    Shape,
    Terrain,
    Pattern,
  }eTypeFGIObject;
  //-----------------------------------------------------------------
  class DllExport TPacket_TryEnterRoom : public TBasePacket_PCS
  {
  public:
    TPacket_TryEnterRoom();
    TypeTryEnterRoom mTypeRoom;// клиент выбирает какой тип боя ему нужен
    // 4 байта - запас под тренировочные бои, 4(например) + id_room - номер тренировочной комнаты
    // для Slave он ничего не значит, 
    // для Master - правила для создания, балансировки, выбора карты, условий боя (Игровая логика).
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
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
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EndLoadMap : public TBasePacket_PCS
  {
  public:
    TPacket_EndLoadMap();
  protected:
    virtual TContainer PackInherit(){return TContainer();};
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_AddGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_AddGameObjects();
    typedef std::vector<TMapItem::TObject> TVectorMapObject;
    TVectorMapObject mVectorObject;
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnableGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_EnableGameObjects();
    std::vector<TypeID_GameMap> mVectorID_Object;
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_DisableGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_DisableGameObjects();
    std::vector<TypeID_GameMap> mVectorID_Object;
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_AddFGIObject : public TBasePacket_PCS
  {
  public:
    TypeFGIObject mTypeFGIObject;
    std::string   mNameObject;
    TContainer    mDesc;
    TPacket_AddFGIObject();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_ModifyFGIObject : public TBasePacket_PCS
  {
  public:
    TypeFGIObject mTypeFGIObject;
    std::string   mNameObject;
    TContainer    mDesc;
    TPacket_ModifyFGIObject();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_DeleteFGIObject : public TBasePacket_PCS
  {
  public:
    TypeFGIObject mTypeFGIObject;
    std::string   mNameObject;
    TPacket_DeleteFGIObject();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_UpdateGameObjectByFGI : public TBasePacket_PCS
  {
  public:
    std::string mNameObject;
    TPacket_UpdateGameObjectByFGI();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_UpdateGameObjectByPattern : public TBasePacket_PCS
  {
  public:
    struct TDescCorrection
    {
      TypeID_GameMap mID_Object;
      TContainer     mParameter;
    };
    typedef std::vector<TDescCorrection> TVectorDescCorrection;
    TVectorDescCorrection mVector;

    TPacket_UpdateGameObjectByPattern();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
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
