/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NAMESPACE_ID_BEHAVIOR_H
#define NAMESPACE_ID_BEHAVIOR_H

namespace nsID_BEHAVIOR
{
  enum{
    ID_NULL               = 0,// недействительное значение
    
    ID_TREE               = 1,
    ID_OBJECT_SCENE       = 2,
    ID_TERRAIN            = 3,
    ID_BUSH               = 4,
    // bullet
    ID_BULLET_EXPLOSION   = 5,
    ID_BULLET_UNEXPLOSION = 6,
    // tank
    ID_TANK_TOWER         = 7,
    
    // visible
    ID_UFO                = 8,
    ID_BIRD               = 9,
    // invisible
    ID_WALL               = 10,

    ID_EXPLOSION          = 11,
    
    ID_LIGHT              = 12,
  };
  

}

#endif