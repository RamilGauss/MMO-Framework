#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/dll/smart_library.hpp>
#include <boost/dll/import_mangled.hpp>
#include <boost/dll/import_class.hpp>
#include <iostream>
#include <memory>

#include <string>

namespace dll = boost::dll;
namespace bexp = boost::dll::experimental;

namespace space
{
  class BOOST_SYMBOL_EXPORT my_plugin
  {
  public:
#pragma GCC push_options
#pragma GCC optimize ("O0")
    int TypeIndex()
    {
      return 42;
    }
    template<typename Arg>
    BOOST_SYMBOL_EXPORT int TypeIndex()
    {
      return 42;
    }
#pragma GCC pop_options
  };
}

void Test();

int main( int argc, char** argv )
{
  try
  {
    Test();
  }
  catch ( std::exception & e )
  {
    auto errorDesc = e.what();
    printf( errorDesc );
  }

  return 0;
}

using namespace space;

void Test()
{
  auto thisLineLocation = boost::dll::this_line_location();

  boost::dll::fs::path lib_path( thisLineLocation );
  dll::experimental::smart_library lib( lib_path );// smart library instance

  auto cl = new space::my_plugin();
  cl->TypeIndex<void>();
  cl->TypeIndex<float>();
  cl->TypeIndex<space::my_plugin>();
  int asd = cl->TypeIndex();
  double dasd = cl->TypeIndex();

  auto storage = lib.symbol_storage().get_storage();
  for ( auto& s : storage )
  {
    auto& demangled = s.demangled;
    auto pData = demangled.data();

    printf( "%s\n", demangled.data() ); 

    auto beginFound = demangled.find( "TypeIndex" );
    if ( beginFound == std::string::npos )
      continue;

    auto endFound = demangled.find( "(" );
    if ( endFound == std::string::npos )
      continue;

    auto funcName = demangled.substr( beginFound, endFound - beginFound );

    auto typeIndexFunc = bexp::import_mangled<space::my_plugin, int( void )>( lib, funcName.data() );
    std::cout << funcName.data() << "\t" << typeIndexFunc( cl ) << std::endl;
  }
}

