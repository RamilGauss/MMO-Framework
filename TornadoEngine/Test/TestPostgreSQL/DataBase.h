/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <string>
#include "person.hxx"

class TDataBase
{
  void* pDB;
  void* pTransaction;

public:
  TDataBase();
  ~TDataBase();

  bool Open( std::string login, std::string password,
    std::string dbName, std::string host, unsigned int port );

  bool Begin();
  bool Commit();

  unsigned long Persist( person& obj );

};
