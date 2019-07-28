//#pragma once
//
//#include <boost/dll/runtime_symbol_info.hpp>
//
//#include "TypeDef.h"
//#include "TypeIdentifier.h"
//#include "SingletonManager.h"
//
//// Для более чем одного объекта 
//class DllExport TEntityManagerPrototype
//{
//  typedef TTypeIdentifier<TEntityManagerPrototype> TTypeID;
//  TTypeID* mTypeIndex;
//public:
//  TEntityManagerPrototype();
//  // прототип для EntityManager Setup
//  void Setup( std::string path = boost::dll::this_line_location().string() );
//
//  template<typename ... Args >
//  DllExport unsigned int GetMultiMix()
//  {
//    return TypeIndex<Args...>();
//  }
//
//  template <typename ... Args>
//  DllExport unsigned int TypeIndex()
//  {
//    return mTypeIndex->type<Args...>();
//  }
//
//  template <typename T>
//  TEntityID GetByUnique( T& t)
//  {
//    return TEntityID::None;
//  }
//
//  template <typename ... Args>
//  std::list<TEntityID>* GetByValue( ... )
//  {
//    return nullptr;
//  }
//
//  template <typename ... Args>
//  std::list<TEntityID>* GetByHas()
//  {
//    return nullptr;
//  }
//};