/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <memory>
#include <iostream>
#include <list>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/query.hxx>

#include "person-odb.hxx"
#include "ExecuteInstructionEngine.h"
#include "HiTimer.h"
#include "DataBase.h"

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

TExecuteInstructionEngine g_eie;
int lastID = 0;

class TSomeSystem
{
  std::list<int> idList;
public:
  void Do()
  {
    TExecuteInstructionEngine::Instruction* p = new TExecuteInstructionEngine::Instruction();
    {
      auto pList = &idList;
      TExecuteInstructionEngine::Instruction func = [pList]()// stack var
      {
        //ht_msleep( 1 );// simulate big latency SELECT
        int id = lastID++;// load from db
        auto success = [pList, id]()// use in calling thread
        {
          pList->push_back( id );
        };
        return new TExecuteInstructionEngine::InstructionResult{std::move( success )};
      };
      g_eie.Push( func );
    }
  }
};

int main( int argc, char* argv[] )
{
  //g_eie.Start();

  //TSomeSystem someSystem;
  //for ( int i = 0; i < 1/*0000000*/; i++ )
  //  someSystem.Do();

  //while ( true )
  //{
    //g_eie.Pop();
    //ht_msleep( 1000 );
    //someSystem.Do();
  //}
  try
  {
    OpenDB();
    AddPersons();
    AddAgePerson( g_sJane, 2 );
  }
  catch ( const odb::exception& e )
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
  catch ( const odb::exception& e )
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
  auto john_id = g_db->persist( john );
  auto jane_id = g_db->persist( jane );
  auto joe_id = g_db->persist( joe );

  t.commit();
}
//----------------------------------------------------------------------------------------------------------
void AddAgePerson( std::string firstName, int added_age )
{
  typedef odb::query<person> query;

l_Repeat:
  try
  {
    transaction t( g_db->begin() );
    std::shared_ptr<person> personItem( g_db->query_one<person>( query::first == firstName ) );

    if ( personItem.get() != 0 )
    {
      auto now_age = personItem->age();
      personItem->age( now_age + added_age );
      g_db->update( *personItem );
    }

    t.commit();
  }
  catch ( const object_changed& )
  {
    // данные в бд уже изменены, повторить
    goto l_Repeat;
  }
}
//----------------------------------------------------------------------------------------------------------
