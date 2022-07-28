#pragma once

// https://academy.realm.io/posts/how-we-beat-cpp-stl-binary-search/

#include <vector>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cfloat>
#include <fstream>
#include <ostream>
#include <string>
#include <sstream>
#include <time.h>  

#ifndef _MSC_VER
#   define UNLIKELY(expr) __builtin_expect(!!(expr), 0)
#   define LIKELY(expr)   __builtin_expect(!!(expr), 1)
#else
#   define UNLIKELY(expr) (expr)
#   define LIKELY(expr)   (expr)
#endif

#if defined(__GNUC__) || defined(__HP_aCC) || defined(__clang__)
#define INLINE inline __attribute__((always_inline))
#else
#define INLINE __forceinline
#endif

// Force clang to use conditional move instead of branches. For other types of T than 64-bit integers, please
// rewrite the assembly or use the ternary operator below instead.
template <typename T> INLINE size_t choose(T a, T b, size_t src1, size_t src2)
{
#if defined(__clang__) && defined(__x86_64)
    size_t res = src1;
    asm("cmpq %1, %2; cmovaeq %4, %0"
        :
    "=q" (res)
        :
        "q" (a),
        "q" (b),
        "q" (src1),
        "q" (src2),
        "0" (res)
        :
        "cc");
    return res;
#else
    return b >= a ? src2 : src1;
#endif
}

template <typename T> INLINE size_t fast_upper_bound0(const std::vector<T>& vec, T value)
{
    return std::upper_bound(vec.begin(), vec.end(), value) - vec.begin();
}

template <typename T> INLINE size_t fast_upper_bound1(const std::vector<T>& vec, size_t size, T value)
{
    size_t i = 0;
    size_t size_2 = size;

    while (size_2 > 0) {
        size_t half = size_2 / 2;
        size_t mid = i + half;
        T probe = vec[mid];
        if (value >= probe) {
            i = mid + 1;
            size_2 -= half + 1;
        } else {
            size_2 = half;
        }
    }
    return i;
}

template <typename T> INLINE size_t fast_upper_bound2(const std::vector<T>& vec, size_t size, T value)
{
    size_t low = -1;
    size_t high = size;

    while (high - low > 1) {
        size_t probe = (low + high) / 2;
        T v = vec[probe];
        if (v > value)
            high = probe;
        else
            low = probe;
    }

    if (high == size)
        return size;
    else
        return high;
}

template <typename T> INLINE size_t fast_upper_bound3(const std::vector<T>& vec, size_t size, T value)
{
    size_t low = 0;

    while (size > 0) {
        size_t half = size / 2;
        size_t other_half = size - half;
        size_t probe = low + half;
        size_t other_low = low + other_half;
        T v = vec[probe];
        size = half;
        // clang won't use conditional move here, so we have made a choose() function instead
        // low = v <= value ? other_low : low; 
        low = choose(v, value, low, other_low);
    }

    return low;
}

template <typename T> INLINE size_t fast_upper_bound4(const std::vector<T>& vec, size_t size, T value)
{
    size_t low = 0;

    while (size >= 8) {
        size_t half = size / 2;
        size_t other_half = size - half;
        size_t probe = low + half;
        size_t other_low = low + other_half;
        T v = vec[probe];
        size = half;
        low = choose(v, value, low, other_low);

        half = size / 2;
        other_half = size - half;
        probe = low + half;
        other_low = low + other_half;
        v = vec[probe];
        size = half;
        low = choose(v, value, low, other_low);

        half = size / 2;
        other_half = size - half;
        probe = low + half;
        other_low = low + other_half;
        v = vec[probe];
        size = half;
        low = choose(v, value, low, other_low);
    }

    while (size > 0) {
        size_t half = size / 2;
        size_t other_half = size - half;
        size_t probe = low + half;
        size_t other_low = low + other_half;
        T v = vec[probe];
        size = half;
        low = choose(v, value, low, other_low);
    };

    return low;
}
