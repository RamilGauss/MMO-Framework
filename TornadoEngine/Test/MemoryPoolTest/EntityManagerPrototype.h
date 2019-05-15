#pragma once

#include <boost/dll/runtime_symbol_info.hpp>

#include "TypeDef.h"
#include "TypeIdentifier.h"
#include "SingletonManager.h"

class DllExport TEntityManagerPrototype
{
  typedef TTypeIdentifier<TEntityManagerPrototype> TTypeID;
  TTypeID* mTypeIndex;
public:
  TEntityManagerPrototype();
  // прототип для EntityManager Setup
  void Setup( std::string path = boost::dll::this_line_location().string() );

  template<typename ... Args >
  DllExport unsigned int GetMultiMix()
  {
    return TypeIndex<Args...>();
  }

  template <typename ... Args>
  DllExport unsigned int TypeIndex()
  {
    return mTypeIndex->type<Args...>();
  }
};