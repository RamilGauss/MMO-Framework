/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SET_ORDER_ELEMENT_H
#define SET_ORDER_ELEMENT_H

#include "TypeDef.h"
#include <boost/bimap/bimap.hpp>
#include <vector>

/*
  Множество элементов, каждый из которых может определить свой индекс,
  вне зависимости сколько элементов было удалено.
  Добавление всегда происходит в начало. 
  А удаление может происходить из по любому ключу массива.
*/

class SHARE_EI TSetOrderElement
{
	typedef boost::bimaps::bimap<unsigned int,unsigned int> bmUintUint;

  typedef std::vector<unsigned int> TVectorUint;

  bmUintUint   mMapKeyInnerIndex;
  TVectorUint  mVecSortInnerIndex; // сортированный

  unsigned int mNextAddInnerID;

public:
  TSetOrderElement();
  ~TSetOrderElement();
  
  // навигация
  bool FindIndexByClientKey(unsigned int key, int& index);

  // добавление/удаление
  void AddKeyAtEnd(unsigned int key);
  void DeleteKey(unsigned int key);
	bool DeleteFirst(unsigned int& key);

  void Clear();
private:
  bool FindByKey(unsigned int key);
  void ReserveForVector();
  void DeleteFromVectorByInnerIndex(unsigned int val);
	bool FindKeyByInnerIndex(unsigned int inner_index, unsigned int& key);
};

#endif

