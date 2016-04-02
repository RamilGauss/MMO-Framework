/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryPreDestructorGameObjectH
#define FactoryPreDestructorGameObjectH

#include "TypeDef.h"
#include <string>
#include <vector>
#include <map>

class TGameObject;
class TPreDestructorGameObject;

class DllExport TFactoryPreDestructorGameObject
{
  typedef std::map<std::string, TPreDestructorGameObject*> TMapStrPtr;
  typedef TMapStrPtr::iterator   TMapStrPtrIt;
  typedef TMapStrPtr::value_type TMapStrPtrVT;

  TMapStrPtr mMapStrType_PreDestructor;
public:
  TFactoryPreDestructorGameObject();
  virtual ~TFactoryPreDestructorGameObject();

  TPreDestructorGameObject* GetPreDestructorByType(std::string type);
private:


};

#endif
