/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Synchronizer_Model_BulletH
#define Synchronizer_Model_BulletH

#include "TypeDef.h"

#include "Synchronizer_Model.h"

class DllExport TSynchronizer_Model_Bullet : public TSynchronizer_Model
{
public:
	TSynchronizer_Model_Bullet();

	virtual void Synchro();
private:
};

#endif
