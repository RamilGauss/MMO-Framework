/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MakerObjectH
#define MakerObjectH

#include <map>
#include "../GameLib/IMakerObjectCommon.h"


class IBaseObjectCommon;

class TMakerObjectCommon : public IMakerObjectCommon
{
public:
  TMakerObjectCommon();
  virtual ~TMakerObjectCommon();

  virtual void Delete(IBaseObjectCommon* pObject);// просто вызвать delete pObject;
protected:
  virtual IBaseObjectCommon* NewByID_Behavior(unsigned int id_behavior);

};

#endif
