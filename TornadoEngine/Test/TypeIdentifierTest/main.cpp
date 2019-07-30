#include <stdio.h>
#include <typeinfo>
#include "RemoveIthType.h"
#include "HiTimer.h"
#include "MemoryObjectPoolAllocator.h"
#include "MemoryPool.h"

#include <functional>
#include <algorithm>

template<typename T>
void Print()
{
  auto s = typeid( T ).name();
  printf( "%s\n", s );
}
//---------------------------------------------------------------------------------------------
template<typename T0, typename T1, typename ... Args>
void Print()
{
  Print<T0>();
  Print<T1, Args...>();
}
//---------------------------------------------------------------------------------------------
template<typename ... Args>
void Func()
{
  Print<Args...>();
}
//---------------------------------------------------------------------------------------------
template<typename tuples, std::size_t... Is>
void PreFunc( std::index_sequence<Is...> )
{
  Func<std::tuple_element<Is, tuples>::type...>();
}
//---------------------------------------------------------------------------------------------

class A
{
};
class B
{
};
class C
{
};
class D
{
};
class E
{
};
class G
{
};
class H
{
};
class Z
{
};


int main()
{
  auto pTypeId = new TTypeIdentifier<>();
  auto a_ti = pTypeId->type<A>();
  auto b_ti = pTypeId->type<B>();
  auto c_ti = pTypeId->type<C>();
  auto d_ti = pTypeId->type<D>();
  auto e_ti = pTypeId->type<E>();
  auto g_ti = pTypeId->type<G>();
  auto h_ti = pTypeId->type<H>();
  auto z_ti = pTypeId->type<Z>();

  auto ab_ti = pTypeId->type<A, B>();
  auto ba_ti = pTypeId->type<B, A>();

  auto abcd_ti = pTypeId->type<A, B, C, D>();
  auto dbca_ti = pTypeId->type<D, B, C, A>();
  auto acbd_ti = pTypeId->type<A, C, B, D>();
  auto dcba_ti = pTypeId->type<D, C, B, A>();

  auto abcde_ti = pTypeId->type<A, B, C, D, E>();// huge type list

  auto hige_ti = pTypeId->type<A, B, C, D, E, G, H, Z>();// huge type list

  return 0;
}