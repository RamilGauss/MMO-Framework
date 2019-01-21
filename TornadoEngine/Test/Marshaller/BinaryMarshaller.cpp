/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BinaryMarshaller.h"

using namespace nsBinary;

bool TBinaryMarshaller::flgNeedInit = true;

void TBinaryMarshaller::Init()
{


  flgNeedInit = false;
}
//-----------------------------------------------------------------------------
void TBinaryMarshaller::Deserialize( TContainerRise& c )
{

}
//-----------------------------------------------------------------------------
