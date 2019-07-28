/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <type_traits>
#include <tuple>

using namespace std;

template<size_t I, typename T>
struct TRemoveIthType
{
};

template<typename T, typename... Ts>
struct TRemoveIthType<0, std::tuple<T, Ts...>>
{
  typedef std::tuple<Ts...> type;
};

template<size_t I, typename T, typename... Ts>
struct TRemoveIthType<I, std::tuple<T, Ts...>>
{
  typedef decltype( std::tuple_cat( declval<std::tuple<T>>(),
    declval<typename TRemoveIthType<I - 1, std::tuple<Ts...>>::type>() ) ) type;
};