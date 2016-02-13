/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SerializerTableSoundItem_XMLH
#define SerializerTableSoundItem_XMLH

#include <string>
#include "TypeDef.h"
#include "BaseSerializerItem_XML.h"
#include "TableSoundItem.h"
#include <list>

struct TTableSoundItem;

class DllExport TSerializerTableSoundItem_XML : public TBaseSerializerItem_XML
{
	TTableSoundItem* mTableSound;

  TTableSoundItem::TMapStrInt       mMapCombination;
  TTableSoundItem::TVectorMapStrStr mVecMapStrStr;

  TTableSoundItem::TListCombiSound mListCombiSound;

  enum{MinIndex = 0, MaxIndex = 10,};
public:
	TSerializerTableSoundItem_XML();
	virtual ~TSerializerTableSoundItem_XML();

	virtual bool Load(TBaseItem* pItem);
	virtual bool Save(TBaseItem* pItem);
protected:

  void LoadRange();
  void LoadCollision();

  void LoadRangeVelocity();
  void LoadRangeAngle();
  void LoadRangeMass();
  void LoadRangeMaterial();

  void LoadSound();
  void LoadCombination();
  void LoadParam();

  void SaveRange();
  void SaveCollision();

  void SaveRangeVelocity();
  void SaveRangeAngle();
  void SaveRangeMass();
  void SaveRangeMaterial();

  void SaveSound(TTableSoundItem::TCombiSound& combiSound);
  void SaveCombination(TTableSoundItem::TMapStrInt& mapCombination);
  void SaveParam(TTableSoundItem::TVectorMapStrStr& vecSound);

  void MakeAndInsertSound();
  void MakeAndInsertCollision();

  bool CheckIndex(int index);
};

#endif