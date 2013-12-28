/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef LoaderTreeH
#define LoaderTreeH


#include "TreeJoint.h"
#include "IXML.h"
#include "TypeDef.h"

class SHARE_EI TLoaderTree
{
  TTreeJoint::TLoadedJoint* pLoadedTree;
  
  IXML* mXML;
public:

  TLoaderTree();
  ~TLoaderTree();

  bool Load(char* sPath);
  TTreeJoint::TLoadedJoint* TakeTree();

protected:
  bool LoadMatrix4x4(const char* name,int num, nsStruct3D::TMatrix16* pM);
  bool LoadJoint(int i);

};

#endif