/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Builder_ModelH
#define Builder_ModelH

#include "TypeDef.h"

#include "Operation_Model.h"

class TFactoryGameItem;
class btDiscreteDynamicsWorld;

class DllExport TBuilder_Model : public TOperation_Model
{
protected:
	TFactoryGameItem*        mFGI;
	btDiscreteDynamicsWorld* mWorld;
public:
	TBuilder_Model();
  
	virtual void Build();
private:
};

#endif
