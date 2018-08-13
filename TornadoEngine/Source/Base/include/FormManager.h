/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include <boost/bimap/bimap.hpp>
#include "TypeDef.h"

class DllExport TFormManager
{
  typedef boost::bimaps::bimap< std::string, void* > bmStrPtr;
  bmStrPtr mMapNameForm;
public:

  // реализация класса не зависит от GUI
  TFormManager();
  virtual ~TFormManager();

  // добавление
  void Add(std::string& name, void* pForm);

  // поиск
  void* GetFormByName(std::string& name);
  std::string GetNameForm(void* pForm);// если не найдет вернет NULL

  // удаление
  void RemoveFormByName(std::string name);
  void RemoveForm(void*);

  // чистка
  void Clear();
};