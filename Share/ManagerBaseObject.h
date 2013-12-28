/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerBaseObjectH
#define ManagerBaseObjectH


#include <map>
#include "TreeJoint.h"
#include "LoaderTree.h"

class IBaseObject;

class TManagerBaseObject
{
  typedef std::map<unsigned int, std::string> TMapID_Path;
  typedef std::map<unsigned int, TTreeJoint::TLoadedJoint*> TMapID_Tree;

  TMapID_Path mMapID_Path;
  TMapID_Tree mMapID_Tree;

  TLoaderTree mLoaderTree;
public:
  TManagerBaseObject();
  virtual ~TManagerBaseObject();

  void AddObject(IBaseObject* pObject);  

protected:
  void Done();
  bool LoadListPath();
  void PrepareForTreeJoint();

  void SetTree(IBaseObject* pObject);

};

#endif
