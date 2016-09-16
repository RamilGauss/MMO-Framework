/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "CacheTableSound.h"

TCacheTableSound::TCacheTableSound()
{

}
//----------------------------------------------------------------------
TCacheTableSound::~TCacheTableSound()
{

}
//----------------------------------------------------------------------
void TCacheTableSound::Set(TTableSoundItem* pTableSoundItem)
{
  mTableSoundItem = pTableSoundItem;
}
//----------------------------------------------------------------------
void TCacheTableSound::WorkFromThread_OpenAL()
{
  
}
//----------------------------------------------------------------------
