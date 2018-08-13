/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <memory>   // std::auto_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/query.hxx>

#include "person.hxx"
#include "person-odb.hxx"

using namespace odb::core;

const std::string g_sJohn = "John";
const std::string g_sDoe = "Doe";
const std::string g_sJane = "Jane";
const std::string g_sJoe = "Joe";
const std::string g_sDirt = "Dirt";

const std::string g_sUser = "postgres";
const std::string g_sPassword = "12345678";
const std::string g_sDatabase = "postgres";
const std::string g_sHost = "";
auto g_Port = 5432;

std::shared_ptr<odb::database> g_db;

void OpenDB();
void AddPersons();
void AddAgePerson( std::string firstName, int added_age );

int main( int argc, char* argv [] )
{
  try
  {
    OpenDB();

    //AddPersons();

    AddAgePerson( g_sJane, 2 );
  }
  catch( const odb::exception& e )
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
//----------------------------------------------------------------------------------------------------------
void OpenDB()
{
  g_db.reset( new odb::pgsql::database( g_sUser, g_sPassword, g_sDatabase, g_sHost, g_Port ) );
  try
  {
    transaction t( g_db->begin() );
    g_db->query<person>( false );
    t.commit();
  }
  catch( const odb::exception& e )
  {
    transaction t( g_db->begin() );
    schema_catalog::create_schema( *g_db );
    t.commit();
  }
}
//----------------------------------------------------------------------------------------------------------
void AddPersons()
{
  person john( g_sJohn, g_sDoe, 33 );
  person jane( g_sJane, g_sDoe, 32 );
  person joe( g_sJoe, g_sDirt, 30 );

  transaction t( g_db->begin() );

  bool has_current = t.has_current();
  // Make objects persistent and save their ids for later use.
  //
  auto john_id = g_db->persist( john );
  auto jane_id = g_db->persist( jane );
  auto joe_id = g_db->persist( joe );

  t.commit();
}
//----------------------------------------------------------------------------------------------------------
void AddAgePerson( std::string firstName, int added_age )
{
  typedef odb::query<person> query;
  typedef odb::result<person> result;

l_Repeat:
  try
  {
    transaction t( g_db->begin() );
    std::shared_ptr<person> personItem( g_db->query_one<person>( query::first == firstName ) );

    if( personItem.get() != 0 )
    {
      auto now_age = personItem->age();
      personItem->age( now_age + added_age );
      g_db->update( *personItem );
    }

    t.commit();
  }
  catch( const object_changed& )
  {
    // ������� ���� ���� ��� ��������� �� ����������
    goto l_Repeat;
  }
}
//----------------------------------------------------------------------------------------------------------
