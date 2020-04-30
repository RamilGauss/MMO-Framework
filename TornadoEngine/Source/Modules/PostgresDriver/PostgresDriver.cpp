/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <iostream>
#include <pqxx/pqxx>

#include "PostgresDriver.h"

bool TPostgresDriver::Open( std::string host, unsigned short port, std::string login, std::string password )
{
  try
  {
    pqxx::connection C;
    std::cout << "Connected to " << C.dbname() << std::endl;
    pqxx::work W{C};

    pqxx::result R{W.exec( "SELECT name FROM employee" )};

    std::cout << "Found " << R.size() << "employees:\n";
    for ( auto row : R )
      std::cout << row[0].c_str() << '\n';

    std::cout << "Doubling all employees' salaries...\n";
    W.exec0( "UPDATE employee SET salary = salary*2" );

    std::cout << "Making changes definite: ";
    W.commit();
    std::cout << "OK.\n";
  }
  catch ( std::exception const& e )
  {
    std::cerr << e.what() << '\n';
    return false;
  }

  return true;
}
//-----------------------------------------------------------------------------------------------------
void TPostgresDriver::Close()
{

}
//-----------------------------------------------------------------------------------------------------
void TPostgresDriver::Execute( std::string& str )
{

}
//-----------------------------------------------------------------------------------------------------