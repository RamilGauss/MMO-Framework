/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef Builder_Model_LogicH
#define Builder_Model_LogicH

#include "TypeDef.h"
#include "Builder_Model.h"
#include "ModelItem.h"
#include "NodeLocation_Model.h"

class TBaseNode_Model;
class TNodeLocation_Model;
class TFactoryBehaviourPattern;
class TFactoryGameItem;

class TModelNode_Model;
class TShapeNode_Model;

class DllExport TBuilder_Model_Logic : public TBuilder_Model
{
  TFactoryBehaviourPattern* mFBP;
  TFactoryGameItem*         mFGI;

  TModelItem*               mModelItem;
public:
  TBuilder_Model_Logic();
  virtual ~TBuilder_Model_Logic();

  virtual void Build();

  void CalcGlobalLocation();
  void RankGlobalLocationCorrection();
protected:
  bool Init();

  void SetupCollectionNode();

  TBaseNode_Model* BuildModels(TModelItem::TVariant& variant);
  TBaseNode_Model* BuildShapes(TModelItem::TVariant& variant);

  void LinkHierarchy();
  void SetupJoint();

  void SetupJointForNode(TBaseNode_Model* pNode, TNodeLocation_Model* pNodeLocation);
  void SetupJointForNode_Model(TModelNode_Model* pModelNode, TNodeLocation_Model* pNodeLocation);
  void SetupJointForNode_Shape(TShapeNode_Model* pShapeNode, TNodeLocation_Model* pNodeLocation);

  void CalcLocation();
  void CalcLocalLocation();

  void CalcGlobalNode(TNodeLocation_Model* pNodeLocation);

  void RankBuildVariant();
  void DefineLocalLocationJoint();
};

#endif
