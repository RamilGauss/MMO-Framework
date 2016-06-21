/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerModelItem_XML.h"
#include "IXML.h"
#include <boost/foreach.hpp>

namespace nsSerializerModelItem_XML
{
  const char* sModel          = "Model";

  const char* sName           = "name";
  const char* sJoint          = "Joint";

  const char* sPattern        = "Pattern";
  const char* sVariantPattern = "variant";

  const char* sCollection     = "Collection";
  const char* sHierarchy      = "Hierarchy";
  
  const char* sRoot           = "Root";
  const char* sPosition       = "Position";
  const char* sRotation       = "Rotation";
  const char* sFormation      = "Formation";
  const char* sBranch         = "Branch";
  const char* sBase           = "base";
  const char* sBind           = "Bind";
  const char* sConstraint     = "Constraint";
  
  const char* sVariant        = "Variant";
  const char* sIncarnation    = "Incarnation";
  const char* sTranslation    = "Translation";
  const char* sScale          = "Scale";
  const char* sPart           = "Part";
  const char* sMaterial       = "Material";
  const char* sJoining        = "Joining";

  const char* sType           = "type";
  const char* sExternal       = "external";
  const char* sNamePart       = "part";
  const char* sInternal       = "internal";
}

using namespace nsSerializerModelItem_XML;

TSerializerModelItem_XML::TSerializerModelItem_XML():
TBaseSerializerItem_XML(sModel)
{
  mModel = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerModelItem_XML::~TSerializerModelItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerModelItem_XML::Load(TBaseItem* pItem)
{
  mModel = (TModelItem*)pItem;

  bool resEnter = EnterByType(mModel->mName);
  if(resEnter==false)
    return false;

  LoadPattern();
  LoadHierarchy();
  LoadCollection();

  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerModelItem_XML::Save(TBaseItem* pItem)
{
  mModel = (TModelItem*)pItem;
  RemoveSection(mModel->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = AddAndEnterByType(mModel->mName);
  if(resEnter==false)
    return false;

  SavePattern();
  SaveHierarchy();
  SaveCollection();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadPattern()
{
  mModel->mNamePattern    = mXML->ReadSectionAttr(sPattern, 0, sName);
  mModel->mVariantPattern = mXML->ReadSectionAttr(sPattern, 0, sVariantPattern);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadHierarchy()
{
  if(mXML->EnterSection(sHierarchy,0))
  {
    LoadRoot();
    if(mXML->EnterSection(sFormation,0))
    {
      int cntBranch = mXML->GetCountSection(sBranch);
      for( int iBranch = 0 ; iBranch < cntBranch ; iBranch++ )
      {
        TModelItem::TBranch branch;
        LoadBranch(branch, iBranch);

        std::string nameBranch = mXML->ReadSectionAttr(sBranch, iBranch, sBase);
        mModel->mMapNameBase_Branch.insert(TModelItem::TMapStrBranchVT(nameBranch, branch));
      }
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadCollection()
{
  if(mXML->EnterSection(sCollection,0))
  {
    int cntPart = mXML->GetCountSection(sPart);
    for( int iPart = 0 ; iPart < cntPart ; iPart++ )
    {
      TModelItem::TPart part;
      LoadPart(part, iPart);

      std::string namePart = mXML->ReadSectionAttr(sPart, iPart, sName);
      mModel->mMapNamePart.insert(TModelItem::TMapStrPartVT(namePart, part));
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SavePattern()
{
  TAttrInfo attr[2];
  attr[0].Name  = sName;
  attr[0].Value = mModel->mNamePattern;
  attr[1].Name  = sVariantPattern;
  attr[1].Value = mModel->mVariantPattern;
  mXML->AddSection(sPattern, 2, &attr[0]);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SaveHierarchy()
{
  if( mXML->AddSectionAndEnter(sHierarchy) )
  {
    SaveRoot();
    if(mXML->AddSectionAndEnter(sFormation))
    {
      BOOST_FOREACH(TModelItem::TMapStrBranchVT& bit, mModel->mMapNameBase_Branch)
      {
        TAttrInfo attr;
        attr.Name  = sBase;
        attr.Value = bit.first;
        if(mXML->AddSectionAndEnter(sBranch, 1, &attr))
        {
          SaveBranch(bit.second);
          mXML->LeaveSection();
        }
      }
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SaveCollection()
{
  if(mXML->AddSectionAndEnter(sCollection))
  {
    BOOST_FOREACH(TModelItem::TMapStrPartVT& bit, mModel->mMapNamePart)
    {
      TAttrInfo attr;
      attr.Name  = sName;
      attr.Value = bit.first;
      if(mXML->AddSectionAndEnter(sPart, 1, &attr))
      {
        SavePart(bit.second);
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadPart(TModelItem::TPart& part, int iPart)
{
  if(mXML->EnterSection(sPart,iPart))
  {
    if(mXML->EnterSection(sJoining,0))
    {
      int cntJoint = mXML->GetCountSection(sJoint);
      for( int iJoint = 0 ; iJoint < cntJoint ; iJoint++ )
      {
        std::string nameJoint = mXML->ReadSectionAttr(sJoint, iJoint, sName);
        part.vecNameJoint.push_back(nameJoint);
      }
      mXML->LeaveSection();
    }
    if(mXML->EnterSection(sIncarnation,0))
    {
      int cntVariant = mXML->GetCountSection(sVariant);
      for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
      {
        TModelItem::TVariant variant;
        LoadVariant(variant, iVariant);
        part.vecVariant.push_back(variant);
      }
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadVariant(TModelItem::TVariant& variant, int iVariant)
{
  variant.type = mXML->ReadSectionAttr(sVariant, iVariant, sType);
  variant.name = mXML->ReadSectionAttr(sVariant, iVariant, sName);

  if(mXML->EnterSection(sVariant,iVariant))
  {
    variant.redefinitionMaterial = mXML->ReadSectionAttr(sMaterial, 0, sName);
    if(mXML->EnterSection(sScale,0))
    {
      LoadVector3ByProperty( variant.scale );
      mXML->LeaveSection();
    }
    if(mXML->EnterSection(sTranslation,0))
    {
      int cntTransJoint = mXML->GetCountSection(sJoint);
      for( int iTransJoint = 0 ; iTransJoint < cntTransJoint ; iTransJoint++ )
      {
        TModelItem::TJoint internalJoint;
        std::string external    = mXML->ReadSectionAttr(sJoint, iTransJoint, sExternal);
        internalJoint.namePart  = mXML->ReadSectionAttr(sJoint, iTransJoint, sNamePart);
        internalJoint.nameJoint = mXML->ReadSectionAttr(sJoint, iTransJoint, sInternal);
        variant.mapExternalInternal.insert(TModelItem::TMapExternalInternalVT(external, internalJoint));
      }
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadRoot()
{
  mModel->mRoot.name = mXML->ReadSectionAttr(sRoot, 0, sName);
  if(mXML->EnterSection(sRoot,0))
  {
    if(mXML->EnterSection(sPosition,0))
    {
      LoadVector3ByProperty( mModel->mRoot.position );
      mXML->LeaveSection();
    }
    if(mXML->EnterSection(sRotation,0))
    {
      LoadVector3ByProperty( mModel->mRoot.rotation );
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadBranch(TModelItem::TBranch& branch, int iBranch)
{
  mMapNameValue_Constraint.clear();

  if(mXML->EnterSection(sBranch,iBranch))
  {
    if(mXML->EnterSection(sBind,0))
    {
      branch.joint0.namePart  = mXML->ReadSectionAttr(sJoint, 0, sNamePart);
      branch.joint0.nameJoint = mXML->ReadSectionAttr(sJoint, 0, sName);
      branch.joint1.namePart  = mXML->ReadSectionAttr(sJoint, 1, sNamePart);
      branch.joint1.nameJoint = mXML->ReadSectionAttr(sJoint, 1, sName);

      if(mXML->EnterSection(sPosition,0))
      {
        LoadVector3ByProperty( branch.position );
        mXML->LeaveSection();
      }
      if(mXML->EnterSection(sRotation,0))
      {
        LoadVector3ByProperty( branch.rotation );
        mXML->LeaveSection();
      }
      mXML->LeaveSection();
    }
    if(mXML->EnterSection(sConstraint,0))
    {
      int cntPropertyConstraint = GetCountProperty();
      for( int iPropertyConstraint = 0 ; iPropertyConstraint < cntPropertyConstraint ; iPropertyConstraint++ )
      {
        std::string key, value;
        if(LoadProperty(iPropertyConstraint, key, value))
          mMapNameValue_Constraint.insert(TMapStrStrVT(key,value));
      }
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
  MakeConstraintByMap(branch);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SaveRoot()
{
  TAttrInfo attr;
  attr.Name  = sName;
  attr.Value = mModel->mRoot.name;
  if(mXML->AddSectionAndEnter(sRoot, 1, &attr))
  {
    if(mXML->AddSectionAndEnter(sPosition))
    {
      SaveVector3ByProperty( mModel->mRoot.position );
      mXML->LeaveSection();
    }
    if(mXML->AddSectionAndEnter(sRotation))
    {
      SaveVector3ByProperty( mModel->mRoot.rotation );
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
}
//--------------------------------------------------------------------------------  
void TSerializerModelItem_XML::SaveBranch(TModelItem::TBranch& branch)
{
  if(mXML->AddSectionAndEnter(sBind))
  {
    TAttrInfo attr[2];
    attr[0].Name  = sNamePart;
    attr[0].Value = branch.joint0.namePart;
    attr[1].Name  = sName;
    attr[1].Value = branch.joint0.nameJoint;
    mXML->AddSection(sJoint, 2, &attr[0]);

    attr[0].Name  = sNamePart;
    attr[0].Value = branch.joint1.namePart;
    attr[1].Name  = sName;
    attr[1].Value = branch.joint1.nameJoint;
    mXML->AddSection(sJoint, 2, &attr[0]);

    if(mXML->AddSectionAndEnter(sPosition))
    {
      SaveVector3ByProperty( branch.position );
      mXML->LeaveSection();
    }
    if(mXML->AddSectionAndEnter(sRotation))
    {
      SaveVector3ByProperty( branch.rotation );
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
  
  MakeMapByConstraint(branch);
  if(mXML->AddSectionAndEnter(sConstraint))
  {
    BOOST_FOREACH(TMapStrStrVT& bit, mMapNameValue_Constraint)
    {
      std::string key, value;
      key   = bit.first; 
      value = bit.second;
      SaveProperty(key, value);
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SavePart(TModelItem::TPart& part)
{
  if(mXML->AddSectionAndEnter(sJoining))
  {
    BOOST_FOREACH(std::string& nameJoint, part.vecNameJoint)
    {
      TAttrInfo attr;
      attr.Name  = sName;
      attr.Value = nameJoint;
      mXML->AddSection(sJoint, 1, &attr);
    }
    mXML->LeaveSection();
  }
  if(mXML->AddSectionAndEnter(sIncarnation))
  {
    BOOST_FOREACH(TModelItem::TVariant& variant, part.vecVariant)
    {
      TAttrInfo attr[2];
      attr[0].Name  = sType;
      attr[0].Value = variant.type;
      attr[1].Name  = sName;
      attr[1].Value = variant.name;
      if(mXML->AddSectionAndEnter(sVariant, 2, &attr[0]))
      {
        SaveVariant(variant);
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SaveVariant(TModelItem::TVariant& variant)
{
  if(variant.redefinitionMaterial.length())
  {
    TAttrInfo attr;
    attr.Name  = sName;
    attr.Value = variant.redefinitionMaterial;
    mXML->AddSection(sMaterial, 1, &attr);
  }

  if(mXML->AddSectionAndEnter(sTranslation))
  {
    BOOST_FOREACH(TModelItem::TMapExternalInternalVT& bit, variant.mapExternalInternal)
    {
      TAttrInfo attr[3];
      attr[0].Name  = sExternal;
      attr[0].Value = bit.first;
      attr[1].Name  = sNamePart;
      attr[1].Value = bit.second.namePart;
      attr[2].Name  = sInternal;
      attr[2].Value = bit.second.nameJoint;
      mXML->AddSection(sJoint, 3, &attr[0]);
    }
    mXML->LeaveSection();
  }
  if(mXML->AddSectionAndEnter(sScale))
  {
    SaveVector3ByProperty(variant.scale);
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::MakeConstraintByMap(TModelItem::TBranch& branch)
{
  nsParamBuilderConstraint::TBaseParam* pParam = mSerParamConstraint.GetParamByMap(&mMapNameValue_Constraint);
  branch.mPtrConstraint.reset(pParam);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::MakeMapByConstraint(TModelItem::TBranch& branch)
{
  if(branch.mPtrConstraint.get())
    mSerParamConstraint.GetMapByParam(branch.mPtrConstraint.get(), &mMapNameValue_Constraint);
}
//--------------------------------------------------------------------------------  
