/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryPreBuilderGameObjectH
#define FactoryPreBuilderGameObjectH

#include "TypeDef.h"
#include <string>
#include <vector>
#include <map>

class TGameObject;
class TPreBuilderGameObject;

class DllExport TFactoryPreBuilderGameObject
{
  typedef std::map<std::string, TPreBuilderGameObject*> TMapStrPtr;
  typedef TMapStrPtr::iterator   TMapStrPtrIt;
  typedef TMapStrPtr::value_type TMapStrPtrVT;

  typedef std::vector<TPreBuilderGameObject*> TVectorPtr;

  TMapStrPtr mMapStrType_PreBuilder;
  TVectorPtr mVecPreBuilder;
public:
  TFactoryPreBuilderGameObject();
  virtual ~TFactoryPreBuilderGameObject();

  int GetCountType();
  TPreBuilderGameObject* GetPreBuilderByIndex(int index);
  TPreBuilderGameObject* GetPreBuilderByType(std::string type);
private:


};

#endif
