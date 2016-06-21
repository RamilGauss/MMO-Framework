/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModelItemH
#define ModelItemH

#include "BaseItem.h"

#include <map>
#include <vector>
#include <memory>

#include "ParamBuilderConstraint.h"
#include "MathTools.h"
#include "ContainerArrObj.h"

struct DllExport TModelItem : public TBaseItem
{
  struct DllExport TJoint
  {
    std::string namePart;
    std::string nameJoint;
  };
  //---------------------------------------------------------
  typedef std::map<std::string,TJoint>     TMapExternalInternal;
  typedef TMapExternalInternal::iterator   TMapExternalInternalIt;
  typedef TMapExternalInternal::value_type TMapExternalInternalVT;
  //---------------------------------------------------------  
  struct DllExport TVariant
  {
    std::string type;
    std::string name;

    std::string           redefinitionMaterial;
    TMapExternalInternal  mapExternalInternal;
    nsMathTools::TVector3 scale;
  };
  //---------------------------------------------------------  
  struct DllExport TPart
  {
    std::vector<std::string> vecNameJoint;
    std::vector<TVariant>    vecVariant;
  };
  //---------------------------------------------------------  
  typedef std::map<std::string,TPart> TMapStrPart;
  typedef TMapStrPart::iterator   TMapStrPartIt;
  typedef TMapStrPart::value_type TMapStrPartVT;
  //---------------------------------------------------------  
  struct DllExport TBranch
  {
    TJoint joint0;
    TJoint joint1;
    nsMathTools::TVector3 position;
    nsMathTools::TVector3 rotation;
    std::auto_ptr<nsParamBuilderConstraint::TBaseParam> mPtrConstraint;

    TBranch();
    TBranch(const TBranch& c);
    ~TBranch();
  };
  //---------------------------------------------------------  
  typedef std::map<std::string,TBranch> TMapStrBranch;
  typedef TMapStrBranch::iterator       TMapStrBranchIt;
  typedef TMapStrBranch::value_type     TMapStrBranchVT;
  //---------------------------------------------------------
  struct DllExport TRoot
  {
    std::string           name;
    nsMathTools::TVector3 position;
    nsMathTools::TVector3 rotation;
  };
  //---------------------------------------------------------
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator              TMapStrStrIt;
  typedef TMapStrStr::value_type            TMapStrStrVT;
  //---------------------------------------------------------
  //---------------------------------------------------------
  std::string   mNamePattern;// поведение
  std::string   mVariantPattern;

  TRoot         mRoot;
  TMapStrBranch mMapNameBase_Branch;// иерархия
  TMapStrPart   mMapNamePart;       // набор
  
  TModelItem(std::string& name);
};

#endif
