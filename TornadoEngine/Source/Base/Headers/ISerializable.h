/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ISerializableH
#define ISerializableH

#include "ContainerTypes.h"

class ISerializable
{
public:
	virtual ~ISerializable() = 0;
	virtual TContainer Serialize() = 0;
	virtual bool Deserialize( TContainer& c ) = 0;
}

#endif