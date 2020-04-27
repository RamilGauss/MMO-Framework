#include "ORMEngine.h"


int main( int argc, char** argv )
{
  TORMEngine ormEngine( nullptr );

  auto opernRes = ormEngine.Open( "localhost", 5432, "login", "password" );

  return 0;
}