#include "DataBase.h"

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/query.hxx>

#include "person-odb.hxx"

#define DB \
((odb::database*)pDB)

#define TRANSACTION \
((odb::transaction*)pTransaction)

#define RESET(x) \
auto odb_db = DB; \
delete odb_db; \
odb_db = x;

TDataBase::TDataBase()
{
  pDB = nullptr;
  pTransaction = new odb::transaction();
}
//--------------------------------------------------------------------------------------------------
TDataBase::~TDataBase()
{
  RESET( nullptr );
  delete pTransaction;
}
//--------------------------------------------------------------------------------------------------
bool TDataBase::Open( std::string login, std::string password, std::string dbName, std::string host, unsigned int port )
{
  RESET( new odb::pgsql::database( login, password, dbName, host, port ) );

  //try
  //{
  //  transaction t( g_db->begin() );
  //  g_db->query<person>( false );
  //  t.commit();
  //}
  //catch ( const odb::exception& e )
  //{
  //  transaction t( g_db->begin() );
  //  schema_catalog::create_schema( *g_db );
  //  t.commit();
  //}
  return false;
}
//--------------------------------------------------------------------------------------------------
bool TDataBase::Begin()
{
  try
  {
    TRANSACTION->reset( DB->begin() );
    return true;
  }
  catch ( const odb::exception& e )
  {
    return false;
  }
}
//--------------------------------------------------------------------------------------------------
bool TDataBase::Commit()
{
  try
  {
    TRANSACTION->commit();
    return true;
  }
  catch ( const odb::exception& e )
  {
    return false;
  }
}
//--------------------------------------------------------------------------------------------------
unsigned long TDataBase::Persist( person& obj )
{
  return DB->persist( obj );
}
//--------------------------------------------------------------------------------------------------
