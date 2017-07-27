/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerModelItem_XML.h"
#include "IXML.h"
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

namespace nsSerializerModelItem_XML
{
  const char* sModel          = "Model";
  const char* sName           = "name";
  const char* sPattern        = "Pattern";
  const char* sHierarchy      = "Hierarchy";
	const char* sNameRoot       = "nameRoot";
  
  const char* sPosition       = "Position";
  const char* sOrientation    = "Orientation";
  const char* sLocation       = "Location";

	const char* sDistance   		= "Distance";
	const char* sConnection 		= "Connection";
	const char* sValue      		= "value";

	const char* sBase           = "Base";
  const char* sNamePart       = "part";
  const char* sBranch         = "Branch";
	const char* sNameJoint      = "nameJoint";
  const char* sLink           = "Link";
  const char* sJointBase      = "JointBase";
  const char* sJointBranch    = "JointBranch";

  const char* sConstraint     = "Constraint";
  const char* sCollection     = "Collection";
  const char* sPart           = "Part";

	const char* sVariant        = "Variant";
  const char* sNameItem       = "nameItem";
  const char* sMaterial       = "Material";
  const char* sType           = "type";

  const char* sScale          = "Scale";

	const char* sExternalJoining = "ExternalJoining";
	const char* sJoint           = "Joint";
  const char* sExternal        = "external";
  const char* sInternal        = "internal";

  const char* sTypeModel      = "Model";
  const char* sTypeShape      = "Shape";
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
	LoadExternalJoining();

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
	SaveExternalJoining();

  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadPattern()
{
  mModel->mNamePattern = mXML->ReadSectionAttr(sPattern, 0, sName);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadHierarchy()
{
  mModel->mNameRoot = mXML->ReadSectionAttr(sHierarchy, 0, sNameRoot);
	if(mXML->EnterSection(sHierarchy,0))
  {
    int cntLocation = mXML->GetCountSection(sLocation);
    for( int iLocation = 0 ; iLocation < cntLocation ; iLocation++ )
    {
      TModelItem::TLocation location;
      LoadLocation(location, iLocation);
      mModel->mMapNameBranchLocation.insert(TModelItem::TMMapStrLocationVT(location.nameBranch, location));
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadCollection()
{
  std::string type = mXML->ReadSectionAttr(sCollection, 0, sType);
  if( type==sTypeModel )
    mModel->mTypeCollection = TModelItem::eModel;
  else
    mModel->mTypeCollection = TModelItem::eShape;

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
void TSerializerModelItem_XML::LoadExternalJoining()
{
	if( mXML->EnterSection(sExternalJoining,0) )
	{
		int cntJoint = mXML->GetCountSection(sJoint);
		for( int iJoint = 0 ; iJoint < cntJoint ; iJoint++ )
		{
			std::string external = mXML->ReadSectionAttr(sJoint, iJoint, sExternal);
			TModelItem::TJoint joint;
			joint.nameInternalJoint = mXML->ReadSectionAttr(sJoint, iJoint, sInternal);
			joint.namePart          = mXML->ReadSectionAttr(sJoint, iJoint, sNamePart);
			mModel->mMapExternalJoint.insert(TModelItem::TMapExternalJointVT(external,joint));
		}
		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SavePattern()
{
  TAttrInfo attr;
  attr.Name  = sName;
  attr.Value = mModel->mNamePattern;
  mXML->AddSection(sPattern, 1, &attr);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SaveHierarchy()
{
	TAttrInfo attr;
	attr.Name  = sNameRoot;
	attr.Value = mModel->mNameRoot;
	if( mXML->AddSectionAndEnter(sHierarchy, 1, &attr) )
  {
    BOOST_FOREACH(TModelItem::TMMapStrLocationVT& bit, mModel->mMapNameBranchLocation)
      SaveLocation(bit.second);

    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SaveCollection()
{
  std::string type = sTypeShape;
  if( mModel->mTypeCollection==TModelItem::eModel )
    type = sTypeModel;

  TAttrInfo attr;
  attr.Name  = sType;
  attr.Value = type;
  if( mXML->AddSectionAndEnter(sCollection, 1, &attr) )
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
void TSerializerModelItem_XML::SaveExternalJoining()
{
	if( mXML->AddSectionAndEnter(sExternalJoining) )
	{
		int iJoint = 0;
		BOOST_FOREACH( TModelItem::TMapExternalJointVT& extJoint , mModel->mMapExternalJoint )
		{
			TAttrInfo attr[3];
			attr[0].Name  = sExternal;
			attr[0].Value = extJoint.first;
			attr[1].Name  = sNamePart;
			attr[1].Value = extJoint.second.namePart;
			attr[2].Name  = sInternal;
			attr[2].Value = extJoint.second.nameInternalJoint;
			mXML->AddSection(sJoint, iJoint, &attr[0]);
			iJoint++;
		}
		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadPart(TModelItem::TPart& part, int iPart)
{
  if(mXML->EnterSection(sPart,iPart))
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
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadVariant(TModelItem::TVariant& variant, int iVariant)
{
  variant.name  = mXML->ReadSectionAttr(sVariant, iVariant, sName);
  variant.nameItem = mXML->ReadSectionAttr(sVariant, iVariant, sNameItem);

  if(mXML->EnterSection(sVariant,iVariant))
  {
    variant.redefinitionMaterial = mXML->ReadSectionAttr(sMaterial, 0, sName);
    if(mXML->EnterSection(sScale,0))
    {
      LoadVector3ByProperty( variant.scale );
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadLocation(TModelItem::TLocation& location, int iLocation)
{
  if(mXML->EnterSection(sLocation, iLocation))
  {
    location.nameBase        = mXML->ReadSectionAttr(sBase, 0, sNamePart);
    location.nameJointBase   = mXML->ReadSectionAttr(sBase, 0, sNameJoint);
    location.nameBranch      = mXML->ReadSectionAttr(sBranch, 0, sNamePart);
    location.nameJointBranch = mXML->ReadSectionAttr(sBranch, 0, sNameJoint);

		if(mXML->EnterSection(sConnection, 0))
		{
			location.distance = boost::lexical_cast<float>(mXML->ReadSectionAttr(sDistance, 0, sValue));
			if(mXML->EnterSection(sOrientation,0))
			{
				LoadOrientationByProperty( location.orientation );
				mXML->LeaveSection();
			}
			mXML->LeaveSection();
		}
    int cntLink = mXML->GetCountSection(sLink);
    for( int iLink = 0 ; iLink < cntLink ; iLink++ )
    {
      TModelItem::TLink link;
      LoadLink(link, iLink);
      location.listLink.push_back(link);
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::LoadLink(TModelItem::TLink& link, int iLink)
{
  mMapNameValue_Constraint.clear();

  if(mXML->EnterSection(sLink, iLink))
  {
    link.nameJointBase   = mXML->ReadSectionAttr(sJointBase,   0, sName);
    link.nameJointBranch = mXML->ReadSectionAttr(sJointBranch, 0, sName);
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
  MakeConstraintByMap(link);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SaveLocation(TModelItem::TLocation& location)
{
  if( mXML->AddSectionAndEnter(sLocation) )
  {
    TAttrInfo attr[2];
    attr[0].Name  = sNamePart;
    attr[0].Value = location.nameBase;
		attr[1].Name  = sNameJoint;
		attr[1].Value = location.nameJointBase;
    mXML->AddSection(sBase, 2, &attr[0]);

		attr[0].Name  = sNamePart;
		attr[0].Value = location.nameBranch;
		attr[1].Name  = sNameJoint;
		attr[1].Value = location.nameJointBranch;
    mXML->AddSection(sBranch, 2, &attr[0]);

		if( mXML->AddSectionAndEnter(sConnection) )
		{
			TAttrInfo attrDistance;
			attrDistance.Name  = sValue;
			attrDistance.Value = boost::lexical_cast<std::string>(location.distance);
			mXML->AddSection(sDistance, 1, &attrDistance);

			if(mXML->AddSectionAndEnter(sOrientation))
			{
				SaveOrientationByProperty( location.orientation );
				mXML->LeaveSection();
			}
			mXML->LeaveSection();
		}
    BOOST_FOREACH(TModelItem::TLink& link, location.listLink)
      SaveLink(link);

    mXML->LeaveSection();
  }
}
//--------------------------------------------------------------------------------  
void TSerializerModelItem_XML::SaveLink(TModelItem::TLink& link)
{
  if( mXML->AddSectionAndEnter(sLink) )
  {
    TAttrInfo attr;
    attr.Name  = sName;
    attr.Value = link.nameJointBase;
    mXML->AddSection(sJointBase, 1, &attr);

    attr.Name  = sName;
    attr.Value = link.nameJointBranch;
    mXML->AddSection(sJointBranch, 1, &attr);

    MakeMapByConstraint(link);
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

    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::SavePart(TModelItem::TPart& part)
{
  BOOST_FOREACH(TModelItem::TVariant& variant, part.vecVariant)
  {
    TAttrInfo attr[2];
    attr[0].Name  = sName;
    attr[0].Value = variant.name;
    attr[1].Name  = sNameItem;
    attr[1].Value = variant.nameItem;
    if(mXML->AddSectionAndEnter(sVariant, 2, &attr[0]))
    {
      SaveVariant(variant);
      mXML->LeaveSection();
    }
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

  if(mXML->AddSectionAndEnter(sScale))
  {
    SaveVector3ByProperty(variant.scale);
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::MakeConstraintByMap(TModelItem::TLink& link)
{
  nsParamBuilderConstraint::TBaseParam* pParam = mSerParamConstraint.GetParamByMap(&mMapNameValue_Constraint);
  link.mPtrConstraint.reset(pParam);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_XML::MakeMapByConstraint(TModelItem::TLink& link)
{
  if( link.mPtrConstraint.get() )
    mSerParamConstraint.GetMapByParam(link.mPtrConstraint.get(), &mMapNameValue_Constraint);
}
//--------------------------------------------------------------------------------  
