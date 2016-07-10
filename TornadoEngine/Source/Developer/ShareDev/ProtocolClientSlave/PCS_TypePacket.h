/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PCS_TypePacketH
#define PCS_TypePacketH

#include "TypeDef.h"
#include "ContainerTypes.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsPCS
{
  enum
  {
  // from Client
    ePacket_TryEnterRoom,// Клиент хочет зайти в бой
    ePacket_TryEnterGarage,// Клиент хочет выйти из боя
  // from Slave
    // переходы между состояниями
    ePacket_EnterGarage,
    ePacket_EnterQueue,
    ePacket_EnterRoom,
    // Room events
    ePacket_LoadMap,// Slave описывает карту для загрузки
    ePacket_CorrectGameObjects,// корректировка физических параметров игровых объектов
    ePacket_AddGameObjects,
    ePacket_EnableGameObjects,
    ePacket_DisableGameObjects,
  // from Client/Slave
    ePacket_AddFGIObject,// FGI - TFactoryGameItem
    ePacket_ModifyFGIObject,
    ePacket_DeleteFGIObject,
    // в Slave задача Update решается вызовом функции Паттерна
    // в Client через Паттерн из Model/Shape, готовится список задач для Паттерна, 
    // а он в каждом потоке применит их
    ePacket_UpdateGameObjectByFGI, // заново подгрузить из FGI
    ePacket_UpdateGameObjectByPattern, // заново подгрузить из Pattern
    // специфическое игровое событие (e.g. повысить мощность двигателя, 
    // направление вектора мыши(целеуказание),
    // событие GUI(чат,изменение счета, ХП), звуковые события)
    ePacket_GameImpl,
  };
  
  class DllExport TBasePacket_PCS
  {
    unsigned char mType;
  public:
    TBasePacket_PCS(unsigned char _type);

    TContainer Pack();
    void Unpack(TContainer c);
  protected:
    virtual TContainer PackInherit() = 0;
    virtual void UnpackInherit( char* p, int size ) = 0;
  }_PACKED;
}

#ifdef WIN32
#pragma pack(pop)
#endif

#endif
