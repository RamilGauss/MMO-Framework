/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "VectorRise.h"
#include <boost/bimap/bimap.hpp>
#include <vector>
#include "ContainerRise.h"

/*
Множество элементов, каждый из которых может определить свой индекс,
вне зависимости сколько элементов было удалено.
Добавление всегда происходит в конец.
А удаление может происходить по любому ключу массива.
*/

class DllExport TSortedVecWithKeyMap
{
  typedef boost::bimaps::bimap<unsigned int, unsigned int> bmUintUint;

  TVectorRise<unsigned int> mIDVec;// сортированный

  bmUintUint mKeyIDMap;
public:
  int GetSize();
  unsigned int GetFirstID();

  void PushBack( unsigned int key, unsigned int ID );
  void Insert( unsigned int key, unsigned int ID );

  void RemoveFirst();// неважно в группе или простой
  void RemoveByKey( unsigned int key );// удалить по ключу

  bool GetFirst( unsigned int& key );
  bool Get( int index, unsigned int& key );
  bool GetIndex( unsigned int key, int& index );

  bool FindKeyByID( unsigned int ID, unsigned int& key );
  bool FindIDByKey( unsigned int key, unsigned int& ID );
  bool FindIndexByID( unsigned int ID, int& index );
private:
  void DeleteFromVectorByID( unsigned int ID );
};


