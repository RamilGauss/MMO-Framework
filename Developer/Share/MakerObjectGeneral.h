/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MakerObjectGeneralH
#define MakerObjectGeneralH

#include <map>
#include "../GameLib/IMakerObjectGeneral.h"


class IBaseObjectGeneral;

class TMakerObjectGeneral : public IMakerObjectGeneral
{
public:
  TMakerObjectGeneral();
  virtual ~TMakerObjectGeneral();

  virtual void Delete(IBaseObjectGeneral* pObject);// просто вызвать delete pObject;
protected:
  virtual IBaseObjectGeneral* NewByID_Behavior(unsigned int id_behavior);

};

#endif
